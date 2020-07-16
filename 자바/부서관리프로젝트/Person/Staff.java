package Person;
public class Staff extends Employee {
	public Staff(String id, String name, String depart) {
		super(id, name, depart);
		this.type = "Staff";
	}

}
