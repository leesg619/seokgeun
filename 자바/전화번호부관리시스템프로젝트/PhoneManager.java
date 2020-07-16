import java.util.Scanner;


public class PhoneManager {
	public static void main(String[] args) throws Exception {
		PhoneList list = new PhoneList();
		list.open();
	}
}

class PhoneList{
	Scanner sc = new Scanner(System.in);
	
	Person user[] = new Person[5];		//연락처 최대 인원 = 5명
	int i = 0;
	
	String name = null;
	String phone = null;
	String age = null;
	
	//0. 시작
	void open() throws Exception { 
		int inputNum = 0;	//메뉴 선택을 받기위한 변수
		boolean re = false;	//입력받은 숫자가 목록에 없을 경우 다시 입력 받기 위함
		while(!re) {
			System.out.println("\n########## 연락처 관리 ##########");
			re = true;
			System.out.println("1. 연락처 출력");
			System.out.println("2. 연락처 등록");
			System.out.println("3. 연락처 삭제");
			System.out.println("4. 연락처 검색");
			System.out.println("5. 연락처 수정");
			System.out.println("6. 끝내기");
			
			System.out.print("선택 : ");
			inputNum = sc.nextInt();
			
			switch(inputNum) {
			case 1 : display(); open(); break;
			case 2 : inputPerson(); open(); break;
			case 3 : delete(); open(); break;
			case 4 : search(); open(); break;
			case 5 : edit(); open(); break;
			case 6 : end(); break;
			default : {System.out.println("다시 입력해주세요."); re = false; break;}
			}
		}
	}
	
	//1. 출력(전체)
	void display() {
		System.out.println("\n-----------------------------");
		
		if(user[0] == null) {System.out.println("현재 저장된 연락처가 없습니다.");}
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
	
	//1. 출력(1개)
	void display1(int q) {
		if(user[q] != null) {
			System.out.println("[" + (q + 1) + "] "
					+ user[q].getName() + " "
					+ user[q].getAge() + " "
					+ user[q].getPhone());
		}
	}
	
	//2. 등록
		void inputPerson() throws Exception {
		
			//주소록 리스트가 비었는지 확인
			for (int j = 0; j <= user.length; j++) {
				if(j == user.length) {System.out.println("\n등록 할 수 있는 인원수가 초과되었습니다."); return;}
				if(user[j] == null) {i = j; break;}
			}
			
			System.out.print("이름 : ");
			name = sc.next();
			
			System.out.print("나이 : ");
			age = sc.next();
			
			System.out.print("전화번호 : ");
			phone = sc.next();
			
			Person person = new Person(name, phone, age);	//사람 객체 생성
			
			//사람 객체를 배열에 저장
			if(i < user.length) {
				user[i] = person;
			}
			for(int j = 0; j <user.length; j++) {
				if(i == j) {System.out.println("정상등록되었습니다."); break;}
				if(user[i].getPhone().equals(user[j].getPhone())) {
					System.out.println("[" + (j + 1) +"]번 연락처에 이미 등록되어 있는 번호입니다.\n등록실패하였습니다.");
					user[i] = null; break;
				}
			}
		}
	
	//3. 삭제
	void delete() {
		display();
		System.out.print("\n삭제할 행 번호 : ");		//가정2: 숫자만 입력한다, 문자 입력x
		int x = sc.nextInt();
		if(user[x-1] == null) {
			System.out.println("입력하신 행에 저장된 연락처가 없습니다.");
		}
		else {
			System.out.println("[" + user[x-1].getName() + " "
					+ user[x-1].getAge() + " "
					+ user[x-1].getPhone() + "]가 삭제되었습니다.");
			user[x-1] = null;
			for(int i = x; i < user.length; i++) {
				user[i-1] = user[i];
				user[i] = null;
			}
		}
	}
	
	//4. 검색
	void search(){
		System.out.println("\n검색을 선택하셨습니다.");
		while (true) {
			System.out.print("검색어 : ");
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
			if (n == 0) {System.out.println("검색결과 : 0건\n"); break;}
			else {System.out.println("검색결과 : "+n+"건\n"); break;}
		}
	}
	
	//5. 수정
	void edit() throws Exception {
		if(user[0] == null) {
			System.out.println("\n수정 할 연락처가 없습니다.\n연락처를 먼저 등록하세요.\n");
		}
		else {
			display();
			System.out.print("수정할 연락처의 행번호를 입력하세요 : ");		//가정3: 숫자만 입력한다, 문자입력x
			int x = Integer.parseInt(sc.next());
			if(user[x-1] == null) {
				System.out.println(x + "번에 저장된 연락처가 없습니다.");
				edit();
			}
			System.out.print("이름 수정은 1, 나이 수정은 2, 전화번호 수정은 3을 입력하세요 : ");
			int y = Integer.parseInt(sc.next());
				
			if (y == 1) {
				System.out.print("이름 : ");
				String input = sc.next();
				user[x-1].setName(input);
				System.out.println("수정되었습니다.");
				open();
			}
			else if (y == 2) {
				System.out.print("나이 : ");
				String input = sc.next();
				user[x-1].setAge(input);
				System.out.println("수정되었습니다.");
				open();
			}
			else if (y == 3) {
				System.out.print("전화번호 : ");
				String input = sc.next();
				user[x-1].setPhone(input);
				System.out.println("수정되었습니다.");
				open();
			}
			else {System.out.print("다시 입력해주세요.");}
		}
	}
	
	//6. 종료
	void end() {
		System.out.println("종료하겠습니다.");
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