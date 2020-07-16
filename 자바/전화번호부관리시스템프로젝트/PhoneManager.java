import java.util.Scanner;


public class PhoneManager {
	public static void main(String[] args) throws Exception {
		PhoneList list = new PhoneList();
		list.open();
	}
}

class PhoneList{
	Scanner sc = new Scanner(System.in);
	
	Person user[] = new Person[5];		//����ó �ִ� �ο� = 5��
	int i = 0;
	
	String name = null;
	String phone = null;
	String age = null;
	
	//0. ����
	void open() throws Exception { 
		int inputNum = 0;	//�޴� ������ �ޱ����� ����
		boolean re = false;	//�Է¹��� ���ڰ� ��Ͽ� ���� ��� �ٽ� �Է� �ޱ� ����
		while(!re) {
			System.out.println("\n########## ����ó ���� ##########");
			re = true;
			System.out.println("1. ����ó ���");
			System.out.println("2. ����ó ���");
			System.out.println("3. ����ó ����");
			System.out.println("4. ����ó �˻�");
			System.out.println("5. ����ó ����");
			System.out.println("6. ������");
			
			System.out.print("���� : ");
			inputNum = sc.nextInt();
			
			switch(inputNum) {
			case 1 : display(); open(); break;
			case 2 : inputPerson(); open(); break;
			case 3 : delete(); open(); break;
			case 4 : search(); open(); break;
			case 5 : edit(); open(); break;
			case 6 : end(); break;
			default : {System.out.println("�ٽ� �Է����ּ���."); re = false; break;}
			}
		}
	}
	
	//1. ���(��ü)
	void display() {
		System.out.println("\n-----------------------------");
		
		if(user[0] == null) {System.out.println("���� ����� ����ó�� �����ϴ�.");}
		for(int q = 0; q < user.length; q++) {
			if(user[q] != null) {
			System.out.println("[" + (q + 1) + "] "
					+ user[q].getName() + " "
					+ user[q].getAge() + " "
					+ user[q].getPhone());
			}
			else {break;}
		}
		System.out.println("-----------------------------");
	}
	
	//1. ���(1��)
	void display1(int q) {
		if(user[q] != null) {
			System.out.println("[" + (q + 1) + "] "
					+ user[q].getName() + " "
					+ user[q].getAge() + " "
					+ user[q].getPhone());
		}
	}
	
	//2. ���
		void inputPerson() throws Exception {
		
			//�ּҷ� ����Ʈ�� ������� Ȯ��
			for (int j = 0; j <= user.length; j++) {
				if(j == user.length) {System.out.println("\n��� �� �� �ִ� �ο����� �ʰ��Ǿ����ϴ�."); return;}
				if(user[j] == null) {i = j; break;}
			}
			
			System.out.print("�̸� : ");
			name = sc.next();
			
			System.out.print("���� : ");
			age = sc.next();
			
			System.out.print("��ȭ��ȣ : ");
			phone = sc.next();
			
			Person person = new Person(name, phone, age);	//��� ��ü ����
			
			//��� ��ü�� �迭�� ����
			if(i < user.length) {
				user[i] = person;
			}
			for(int j = 0; j <user.length; j++) {
				if(i == j) {System.out.println("�����ϵǾ����ϴ�."); break;}
				if(user[i].getPhone().equals(user[j].getPhone())) {
					System.out.println("[" + (j + 1) +"]�� ����ó�� �̹� ��ϵǾ� �ִ� ��ȣ�Դϴ�.\n��Ͻ����Ͽ����ϴ�.");
					user[i] = null; break;
				}
			}
		}
	
	//3. ����
	void delete() {
		display();
		System.out.print("\n������ �� ��ȣ : ");		//����2: ���ڸ� �Է��Ѵ�, ���� �Է�x
		int x = sc.nextInt();
		if(user[x-1] == null) {
			System.out.println("�Է��Ͻ� �࿡ ����� ����ó�� �����ϴ�.");
		}
		else {
			System.out.println("[" + user[x-1].getName() + " "
					+ user[x-1].getAge() + " "
					+ user[x-1].getPhone() + "]�� �����Ǿ����ϴ�.");
			user[x-1] = null;
			for(int i = x; i < user.length; i++) {
				user[i-1] = user[i];
				user[i] = null;
			}
		}
	}
	
	//4. �˻�
	void search(){
		System.out.println("\n�˻��� �����ϼ̽��ϴ�.");
		while (true) {
			System.out.print("�˻��� : ");
			String input = sc.next();
			int j = 0;
			int n = 0;
			for(j = 0; j < user.length; j++) {
				if(user[j] == null) {break;}
				else {
					if(user[j].getName().contains(input)) {n += 1; display1(j);}
					else if(user[j].getPhone().contains(input)) {n += 1; display1(j);}
					else if(user[j].getAge().contains(input)) {n += 1; display1(j);}
				}
			}
			if (n == 0) {System.out.println("�˻���� : 0��\n"); break;}
			else {System.out.println("�˻���� : "+n+"��\n"); break;}
		}
	}
	
	//5. ����
	void edit() throws Exception {
		if(user[0] == null) {
			System.out.println("\n���� �� ����ó�� �����ϴ�.\n����ó�� ���� ����ϼ���.\n");
		}
		else {
			display();
			System.out.print("������ ����ó�� ���ȣ�� �Է��ϼ��� : ");		//����3: ���ڸ� �Է��Ѵ�, �����Է�x
			int x = Integer.parseInt(sc.next());
			if(user[x-1] == null) {
				System.out.println(x + "���� ����� ����ó�� �����ϴ�.");
				edit();
			}
			System.out.print("�̸� ������ 1, ���� ������ 2, ��ȭ��ȣ ������ 3�� �Է��ϼ��� : ");
			int y = Integer.parseInt(sc.next());
				
			if (y == 1) {
				System.out.print("�̸� : ");
				String input = sc.next();
				user[x-1].setName(input);
				System.out.println("�����Ǿ����ϴ�.");
				open();
			}
			else if (y == 2) {
				System.out.print("���� : ");
				String input = sc.next();
				user[x-1].setAge(input);
				System.out.println("�����Ǿ����ϴ�.");
				open();
			}
			else if (y == 3) {
				System.out.print("��ȭ��ȣ : ");
				String input = sc.next();
				user[x-1].setPhone(input);
				System.out.println("�����Ǿ����ϴ�.");
				open();
			}
			else {System.out.print("�ٽ� �Է����ּ���.");}
		}
	}
	
	//6. ����
	void end() {
		System.out.println("�����ϰڽ��ϴ�.");
		System.exit(1);
	}
}

class Person {
	private String name;
	private String phone;
	private String age;
	
	Person() {}
	Person(String name, String phone, String age) {
		this.name = name;
		this.phone = phone;
		this.age = age;
	}
	public String getName() {
		return name;
	}
	public String getPhone() {
		return phone;
	}
	public String getAge() {
		return age;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	public void setPhone(String phone) {
		this.phone = phone;
	}
	public void setAge(String age) {
		this.age = age;
	}
}