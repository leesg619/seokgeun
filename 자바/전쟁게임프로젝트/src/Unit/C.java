package Unit;


public class C extends UnitShape{
	public C(int Playernum, char ctr){
		unitname = "C";
		hp=15;
		power=6;
		unitCtr=ctr;
		this.MoveRange=3;
		this.MoveDirection=8;
		this.AttackRange=1;
		this.AttackDirection=8;
		this.Playernum=Playernum;
		
		

	}
	
}