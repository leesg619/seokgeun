package Playgame;
import java.util.Scanner;
import Unit.*;
import Boarding.*;

public class KingGame {
	Scanner input = new Scanner(System.in);
	
	
	public static void main(String[] args) {
		Korea korea = new Korea();
		Japan japan= new Japan();
		Board myBoard = new Board();
		createGame creategame = new createGame(myBoard);
		KingGame game = new KingGame();
		
		int firstplayer ; //1 : �ѱ� 2: �Ϻ�
		int secondplayer ;  //1: �ѱ� 2: �Ϻ�
		int turn=1; //�÷��̾� 1, 2 ���ʷ� ���ư��鼭 �ϴº���
		
		K K1=null,K2=null;
		A A1[],A2[];
		I I1[],I2[];
		C C1[],C2[];
		//�ڿ� 1 �� ������ player1�� �� ����, 2�� ���� �� player2�� �� ����
		firstplayer=game.SelectCivil(1); //����ڿ��� ���� 1 �Ǵ� 2�� �޴´�.
			
		if (firstplayer==1){
			K1 = new K(1,'k'); 
			A1= new A[korea.getA()];
			I1= new I[korea.getI()];
			C1= new C[korea.getC()];
			creategame.makingK(1,K1, A1, I1, C1);
		}
		if (firstplayer==2){
			K1 = new K(1,'j'); 
			A1= new A[japan.getA()];
			I1= new I[japan.getI()];
			C1= new C[japan.getC()];
			creategame.makingJ(1,K1, A1, I1, C1);
		}
		//player1 �����Ϸ�
		secondplayer = game.SelectCivil(2);

		if (secondplayer==1){
			K2 = new K(2,'k'); 
			A2= new A[korea.getA()];
			I2= new I[korea.getI()];
			C2= new C[korea.getC()];
			creategame.makingK(2,K2, A2, I2, C2); /////����
		}
		if (secondplayer==2){
			K2 = new K(2,'j'); 
			A2= new A[japan.getA()];
			I2= new I[japan.getI()];
			C2= new C[japan.getC()];
			creategame.makingJ(2,K2, A2, I2, C2);
		}
		//player2 �����Ϸ�
		
			while(true) {
				myBoard.print_Board();
				if(turn==1) {
					game.DoTurn(turn,myBoard);
					if(K2.isDead()) {
						System.out.println("Player["+turn+"] Win!");
						break;}
					turn = 2;
				}
				else {
					game.DoTurn(turn, myBoard);
					if(K1.isDead()) {
						System.out.println("Player["+turn+"] Win!");
						break;}
					turn = 1;
				}
			}
			
		System.out.println("The game is over");
		//while ������ Ż���ϸ� main method�� ����
	}

	
	
	void DoTurn(int turn, Board myBoard) { //���� �ְ�޴� �޼ҵ�
			int option;
			System.out.println("Player"+turn+"'s turn");
			System.out.println("1. Move my unit");
			System.out.println("2. Attack enemy");
			System.out.println("3. Change Turn");
			System.out.print(">>>");
			option = input.nextInt();
			
			switch(option) {
			case 1:
				MoveUnit(myBoard);
				break;
			case 2:
				AttackUnit(myBoard);
				break;
			case 3:
				System.out.println("You Choose [3. Change Turn] .");
				break;
			}
		
	}
	public void MoveUnit(Board myBoard) { //1�� �޴� �̵�
		int x,y,toX,toY;
		UnitShape myunit=null;
		
		System.out.println("You Choose [1. Move my unit]");
		System.out.println("Input the Location Of your Unit.");
		System.out.print("x >>>");
			x = input.nextInt();
			x=x-1;
		System.out.print("y >>>");
			y = input.nextInt();
			y=y-1;
		myunit = myBoard.getUnit(x, y); //�ǿ��� �� ������ �ҷ���
		System.out.println("you choose "+ myunit.getName()+ myunit.Playernum);
		myunit.showInform(); //�� ���� �������

		System.out.println("Input the Location you want to go."); //�̵��ϰ� ���� �� �Է�
		System.out.print("x >>>");
		toX = input.nextInt();
		toX = toX-1;
		System.out.print("y >>>");
		toY = input.nextInt();
		toY = toY-1;
		System.out.println(myunit.unitCtr+myunit.getName()+myunit.Playernum+ "is located ("+ (x+1)+","+(y+1)+ ") --> "+(toX+1)+","+(toY+1)+")");
		myBoard.setPosition(toX, toY, myunit);//���� �̵��� ���� ��ġ
		myBoard.clear(x, y); //���� �ִ� �ڸ��� ������
		
	}
	
	public void AttackUnit(Board myBoard) {
		int x,y,toX,toY;
		UnitShape myunit=null , enemy=null;
		System.out.println("You Choose [2. Attack Enemy]");
		System.out.println("Input the Location Of your Unit."); //������ ����
		System.out.print("x >>>");
		x = input.nextInt();
		x=x-1;
		System.out.print("y >>>");
		y = input.nextInt();
		y=y-1;
		myunit = myBoard.getUnit(x, y); 
		System.out.println("you choose "+ myunit.getName()+ myunit.Playernum);
		myunit.showInform();
		//������ ���ÿϷ�
		System.out.println("Input the Location Of Enemy's Unit."); //��� ������ �����ϰ� ��
		System.out.print("x >>>");
		toX = input.nextInt();
		toX = toX-1;
		System.out.print("y >>>");
		toY = input.nextInt();
		toY = toY-1;
		enemy = myBoard.getUnit(toX, toY);
		System.out.println("you choose "+ enemy.getName()+ enemy.Playernum);
		System.out.println(myunit.unitCtr+myunit.getName()+myunit.Playernum+" 's power : ["+myunit.getPower()+"] ");
		System.out.println("The Unit on ( "+(toX+1)+","+(toY+1)+") is attacked.");
		enemy.hp-=myunit.getPower();
		System.out.println("remain hp : "+enemy.hp); //�� ������ ���� h.p���
		
		if(enemy.isDead()) { //��� ���� �׾�����
			System.out.println(" Attacked Unit is dead.");
			myBoard.clear(toX, toY);
		}
	}
	int SelectCivil(int player) { //���� 1 or 2�� ���� �޼ҵ�
		int option;
		System.out.println("Select Player"+(player)+"'s Civilization");
		System.out.println("1. Korean\t2. Japanese");
		System.out.print(">>>>");
		option = input.nextInt();
		if(option == 1) {
			System.out.println("You choose Korean");
			return 1;
		}
		else {
			System.out.println("You choose Japan");
			return 2;
		}
	}


}