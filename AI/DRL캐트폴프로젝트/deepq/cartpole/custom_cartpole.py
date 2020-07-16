import gym
import sys
import itertools
import numpy as np
import tensorflow as tf
import tensorflow.contrib.layers as layers
import baselines.common.tf_util as U
from baselines import logger
from baselines import deepq
from baselines.deepq.replay_buffer import ReplayBuffer
from baselines.deepq.utils import ObservationInput
from baselines.common.schedules import LinearSchedule


def model(inpt, num_actions, scope, reuse=False):
    """This model takes as input an observation and returns values of all actions."""
    with tf.variable_scope(scope, reuse=reuse):
        out = inpt

        ### num_outputs 값 수정(32, 64, 128)
        out = layers.fully_connected(out, num_outputs=64, activation_fn=tf.nn.tanh)
        ################

        out = layers.fully_connected(out, num_outputs=num_actions, activation_fn=None)
        return out


if __name__ == '__main__':
    with U.make_session(num_cpu=1):
        # Create the environment
        env = gym.make("CartPole-v0")
        # Create all the functions necessary to train the model
        act, train, update_target, debug = deepq.build_train(
            make_obs_ph=lambda name: ObservationInput(env.observation_space, name=name),
            q_func=model,
            num_actions=env.action_space.n,
            optimizer=tf.train.AdamOptimizer(learning_rate=5e-4),
        )
        # Create the replay buffer
        replay_buffer = ReplayBuffer(50000)
        # Create the schedule for exploration starting from 1 (every action is random) down to
        # 0.02 (98% of actions are selected according to values predicted by the model).
        exploration = LinearSchedule(schedule_timesteps=10000, initial_p=1.0, final_p=0.02)

        # Initialize the parameters and copy them to the target network.
        U.initialize()
        update_target()
        reward_list = []  ###list for saving sum of reward to file
        episode_rewards = [0.0]
        obs = env.reset()
        for t in itertools.count():
            # Take action and update exploration to the newest value
            action = act(obs[None], update_eps=exploration.value(t))[0]
            new_obs, rew, done, _ = env.step(action)
            # Store transition in the replay buffer.
            replay_buffer.add(obs, action, rew, new_obs, float(done))
            reward_list.append(rew)  ###append reward to list
            obs = new_obs

            episode_rewards[-1] += rew
            if done:
                obs = env.reset()
                episode_rewards.append(0)

                ###Reward 파일에 저장(파일명 변경)
                with open("../../FILENAME1.txt", "a") as f:
                    f.write(str(sum(reward_list)) + "\n")
                reward_list = []  ###init reward list

            is_solved = t > 100 and np.mean(episode_rewards[-101:-1]) >= 200
            is_finished = len(episode_rewards) > 2000 and is_solved

            if is_solved:
                if len(episode_rewards) > 1998:
                    # Show off the result
                    env.render()
                if is_finished:
                    sys.exit(0)

            else:
                # Minimize the error in Bellman's equation on a batch sampled from replay buffer.
                if t > 1000:
                    ###Replay Buffer Sample 수 수정(16, 32, 64)
                    obses_t, actions, rewards, obses_tp1, dones = replay_buffer.sample(32)
                    ################
                    train(obses_t, actions, rewards, obses_tp1, dones, np.ones_like(rewards))

                # Update target network periodically.
                # Target Update 주기 수정(250, 500, 1000)
                if t % 1000 == 0:
                    #################
                    update_target()

            if done and len(episode_rewards) % 10 == 0:
                logger.record_tabular("steps", t)
                logger.record_tabular("episodes", len(episode_rewards))
                logger.record_tabular("mean episode reward", round(np.mean(episode_rewards[-101:-1]), 1))
                logger.record_tabular("% time spent exploring", int(100 * exploration.value(t)))
                logger.dump_tabular()

