package Unit;

public class UnitShape{
	public int hp;//체력 게임중 계속 바뀌어서 public으로
	public int Playernum; //첫번째플레이어인지, 두번째인지
	public char unitCtr; //유닛의 국가
	
	String unitname;//유닛이름
	int power;//공격력
	int MoveRange;//이동범위
	int MoveDirection;//이동방향 
	int AttackRange;//공격범위
	int AttackDirection;//공격방향

	/*방향을 0 , 4, 8 세가지로 나눌수있는데, 0은 0방향,
	 4는 동서남북4방향, 8은 대각선까지 8방향*/
	
	public String getName(){
		return unitname;
	}
	
	public int getPower() {
		return power;
	}
	
	public void showInform() {//갈 수 있는 범위 , 공격범위 표시하자
		System.out.println("MoveRange: ["+MoveRange+"] MoveDirection: ["+MoveDirection+"]");
		System.out.println("AttackRange: ["+AttackRange+"] AttackDirection: ["+AttackDirection+"]");
	}
	
	public boolean isDead() { //죽었는지
		if(hp<=0) return true;
		else return false;
	}
	
}
