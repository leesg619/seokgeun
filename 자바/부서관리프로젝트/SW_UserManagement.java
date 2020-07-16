
public class SW_UserManagement
{
	String name;
	String ID = "ID_";
	String position;
	String depart;
	static int num=0;
	String manager=" ";
	
	SW_UserManagement(String name, String depart, String position, String manager)
	{
		this.name = name;
		ID = ID + num++;
		this.depart = depart;
		this.position = position;
		this.manager = manager;
	}
	
	public String toString(){
		return ID+"  "+name+"  "+depart+"  "+position+"  "+manager;
	}

	public void SetName(String name){
		this.name=name;
	}
	
	public void SetDepart(String depart){
		this.depart=depart;
	}
	
	public void SetPosition(String position){
		this.position=position;
	}
}
