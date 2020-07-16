package Unit;


public class I extends UnitShape{
	public I(int Playernum, char ctr){
		unitname = "I";
		hp=24;
		power=4;
		unitCtr=ctr;
		this.MoveRange=1;
		this.MoveDirection=8;
		this.AttackRange=1;
		this.AttackDirection=8;
		this.Playernum=Playernum;
		
		
		

	}
	
}