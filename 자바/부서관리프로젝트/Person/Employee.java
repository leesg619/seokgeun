package Person;
public abstract class Employee {
	private String id;
	private String name;
	private String depart;		// ºÎ¼­
	protected String type;		// SW Developer, SW Tester, Staff 
	private String Manager;	// true => Manager
	
	public Employee(String id, String name, String depart) {
		this.id = id;
		this.name = name;
		this.depart = depart;
		this.Manager = " ";
	}
	
	public String getId() {
		return this.id;
	}
	public String getName() {
		return this.name;
	}
	public String getDepart() {
		return this.depart;
	}
	public String getType() {
		return this.type;
	}
	public String getManager() {
		return this.Manager;
	}
	
	public void setId(String id) {
		this.id = id;
	}
	public void setName(String name) {
		this.name = name;
	}
	public void setDepart(String depart) {
		this.depart = depart;
	}
	public void setType(String type) {
		this.type = type;
	}
	public void setManager() {
		this.Manager = "O";
	}
	
	public String toString() {
		return this.id + "/" + this.name + "/" + this.depart + "/" + this.type + "/" + this.Manager;
	}
}
