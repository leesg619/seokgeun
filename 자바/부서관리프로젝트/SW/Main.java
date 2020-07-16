package SW;

import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

import Person.Employee;
import Person.SW_Developer;
import Person.SW_Tester;
import Person.Staff;

public class Main {
	public static void main(String[] args) {
		HRSW.loadFromFile("Data.txt");
		
		int exitFlag = 0;
		int saveFlag = 0; // 저장 후 변경이 있는지 확인하는 변수 0이면 변경후 미저장

		Scanner s = null;
		try {
			s = new Scanner(System.in);
			while (exitFlag == 0) {
				printMenu(); // 메뉴 출력
				int input = s.nextInt();
				switch (input) {
				case 1:
					addUser(s);
					saveFlag = 0;
					break;
				case 2:
					deleteOrCorrectUser(s);
					saveFlag = 0;
					break;
				case 3:
					showList();
					break;
				case 4:
					searchUser(s);
					break;
				case 5:
					printLog();
					break;
				case 6:
					saveToFile();
					saveFlag = 1;
					break;
				case 7:
					sortList(s);
					saveFlag = 0;
					break;
				case 0:
					if (saveFlag == 0) {
						System.out.println("변경 후 저장되지 않았습니다. 정말 종료하시겠습니까? (y/n)");
						String answer = s.next();
						if (answer.equals("y"))
							exitFlag = 1; // 정말 종료
						else {
							System.out.println("종료되지 않았습니다.");
							continue;
						}
					} else
						exitFlag = 1;
					break;
				default:
					System.out.println("메뉴에 있는 번호를 입력해주세요");
				}
			}
		} catch (Exception e) {
			System.out.println("예외 발생");
		} finally {
			s.close();
		}
	}

	static void printMenu() {
		System.out.println("=== 경기 S/W 직원 관리 프로그램 ===");
		System.out.println("1. 신규 직원 추가");
		System.out.println("2. 기존 직원 삭제 및 수정");
		System.out.println("3. 직원 목록 보기");
		System.out.println("4. 직원 검색");
		System.out.println("5. 로그 출력");
		System.out.println("6. 파일에 저장");
		System.out.println("7. 목록 정렬");
		System.out.println("0. 프로그램 종료");
		System.out.print("입력 >> ");
	}

	static void addUser(Scanner s) {
		String id;
		String name;
		String depart;
		System.out.println("-- 신규 직원 추가 --");
		System.out.println("ID는 다른 사용자와 중복될 수 없습니다.");
		System.out.print("ID 입력 >> ");
		id = s.next();
		if (UserTable.checkId(id)) {		// 중복 검사
			System.out.print("이름 입력 >> ");
			name = s.next();
			System.out.println("부서는 비서실, 총무팀, 인사팀, 개발1팀, 개발2팀, 개발3팀 이 존재합니다.");
			System.out.print("부서 입력 >> ");
			depart = s.next();
			if (depart.equals("비서실") || depart.equals("총무팀") || depart.equals("인사팀")) {
				UserTable.User.addElement(new Staff(id, name, depart));
				System.out.printf("*** [%s], [%s], [%s] 추가완료 ***", id, name,depart);
				HRSW.logging(", 신규 직원 추가 : 직원ID(" + id + ")");
			} 
			else if (depart.equals("개발1팀") || depart.equals("개발2팀") || depart.equals("개발3팀")) {
				int type;
				System.out.println("개발부서에는 SW Developer와 SW Tester가 있습니다.");
				System.out.println("(1) SW Developer (2) SW Tester");
				System.out.print("직책 입력 >> ");
				type = s.nextInt();
				if (type == 1) {
					UserTable.User.addElement(new SW_Developer(id, name, depart));
					System.out.printf("*** [%s], [%s], [%s] 추가완료 ***", id, name, depart);
					HRSW.logging(", 신규 직원 추가 : 직원ID(" + id + ")");
				} else if (type == 2) {
					UserTable.User.addElement(new SW_Tester(id, name, depart));
					System.out.printf("*** [%s], [%s], [%s] 추가완료 ***", id, name, depart);
					HRSW.logging(", 신규 직원 추가 : 직원ID(" + id + ")");
				} else
					System.out.println("E : 올바른 번호를 입력해 주세요.");
			} else
				System.out.println("E : 올바른 부서명을 입력해 주세요.");
		}
	}

	static void deleteOrCorrectUser(Scanner s) {
		System.out.println("-- 기존 직원 삭제 및 수정 --");
		System.out.println("직원 ID 또는 이름으로 직원을 선택한 후 삭제 또는 수정을 할 수 있습니다.");
		System.out.println("어느 기준으로 선택하시겠습니까 ?");
		System.out.println("(1) ID (2) 이름");
		System.out.print("입력 >> ");
		int crit = s.nextInt();
		String str = null;
		System.out.println("Debug : crit = " + crit);
		if (crit == 1) {
			System.out.println("ID를 선택하셨습니다. 삭제 또는 수정할 직원의 ID를 입력해주세요.");
			System.out.print(" ID 입력 >> ");
			str = s.next();
		} else if (crit == 2) {
			System.out.println("이름을 선택하셨습니다. 삭제 또는 수정할 직원의 이름을 입력해주세요.");
			System.out.print(" 이름 입력 >> ");
			str = s.next();
		} else
			System.out.println("E : 올바른 숫자를 입력해주세요");
		if (str != null)
			UserTable.deleteOrCorrectUser(s, str, crit);
	}

	static void showList() {
		for (int i = 0; i < 63; i++)
			System.out.print("-");
		System.out.println();
		System.out.printf("|         ID |        이름 |          부서 |           직책 | M |\n");
		for (int i = 0; i < 63; i++)
			System.out.print("-");
		System.out.println();
		for (int i = 0; i < UserTable.User.size(); i++)
			UserTable.printUser(i);
		for (int i = 0; i < 63; i++)
			System.out.print("-");
		System.out.println();
		HRSW.logging(", 직원 목록 보기");
	}

	static void searchUser(Scanner s) {
		System.out.println("-- 직원 검색 --");
		System.out.println("직원 검색은 다음 세 가지 기준으로 검색이 가능합니다.");
		System.out.println("(1) 이름 (2) 부서명 (3) Manager 명");
		System.out.println("어떤 기준으로 검색하시겠습니까?");
		System.out.print(" 검색 기준 >> ");
		int input = s.nextInt();
		String str = null;
		switch (input) {
		case 1:
			System.out.println("이름으로 검색을 선택하셨습니다.");
			System.out.println("어떤 이름으로 검색하시겠습니까?");
			System.out.print(" 검색할 이름 입력 >> ");
			str = s.next();
			HRSW.logging(", 직원 검색 : 기준 - 이름(" + str + ")");
			break;
		case 2:
			System.out.println("부서명으로 검색을 선택하셨습니다.");
			System.out.println("어떤 부서명으로 검색하시겠습니까?");
			System.out
					.println("※ 부서는 비서실, 총무팀, 인사팀, 개발1팀, 개발2팀, 개발3팀 이 존재합니다.");
			System.out.print(" 검색할 부서명 입력 >> ");
			str = s.next();
			HRSW.logging(", 직원 검색 : 기준 - 부서명(" + str + ")");
			break;
		case 3:
			System.out.println("Manager 명으로 검색을 선택하셨습니다.");
			System.out.println("어떤 Manager 명으로 검색하시겠습니까");
			System.out.print(" 검색할 Manager 이름 입력 >> ");
			str = s.next();
			HRSW.logging(", 직원 검색 : 기준 - Manager 이름(" + str + ")");
			break;
		}
		if (str == null)
			System.out.println("E : 잘못된 검색 기준입니다.");
		else
			UserTable.searchUser(str, input);
	}

	static void printLog() {
		System.out.println("-- 로그 출력 --");
		System.out.println(HRSW.loadLog());
	}
	
	static void sortList(Scanner s) {
		System.out.println("어떤 기준으로 정렬하시겠습니까?");
		System.out.println("(1) ID (2) 이름 (3) 부서 (4) 직책 (5) 매니저");
		System.out.print(" 정렬 기준 >> ");
		int input = s.nextInt();
		System.out.println("(1) 오름차순 (2) 내림차순");
		System.out.print(" 기준 입력 >> ");
		int order = s.nextInt();
		if(order == 1) {	// 오름차순
			switch(input) {
			case 1:	// ID
				Collections.sort(UserTable.User, new IdAscComparator());break;
			case 2:	// 이름
				Collections.sort(UserTable.User, new NameAscComparator());break;
			case 3:	// 부서
				Collections.sort(UserTable.User, new DepartAscComparator());break;
			case 4:	// 직책
				Collections.sort(UserTable.User, new TypeAscComparator());break;
			case 5:	// 매니저
				Collections.sort(UserTable.User, new ManagerAscComparator());break;
			default:
				System.out.println(" E : 올바른 정렬 기준을 입력하세요.");
			}
		}
		else if(order == 2) {
			switch(input) {	// 내림차순
			case 1:	// ID
				Collections.sort(UserTable.User, new IdDescComparator());break;
			case 2:	// 이름
				Collections.sort(UserTable.User, new NameDescComparator());break;
			case 3:	// 부서
				Collections.sort(UserTable.User, new DepartDescComparator());break;
			case 4:	// 직책
				Collections.sort(UserTable.User, new TypeDescComparator());break;
			case 5:	// 매니저
				Collections.sort(UserTable.User, new ManagerDescComparator());break;
			default:
				System.out.println(" E : 올바른 정렬 기준을 입력하세요.");
			}
		}
	}

	static void saveToFile() {
		/*
		 * Data.txt를 파일명으로 사용함
		 */
			for(int i = 0; i < UserTable.User.size(); i++) {
				Object tempObject[] = new Object[5];
				
				tempObject[0] = UserTable.User.elementAt(i).getId();
				tempObject[1] = UserTable.User.elementAt(i).getName();
				tempObject[2] = UserTable.User.elementAt(i).getDepart();
				tempObject[3] = UserTable.User.elementAt(i).getType();
				tempObject[4] = UserTable.User.elementAt(i).getManager();
				
				HRSW.makeString(tempObject);
			}
			HRSW.saveToFile("Data.txt");
			HRSW.logging(", 파일에 저장");
		}
}

/*
 * Comparator...
 */

class IdAscComparator implements Comparator {
	public int compare(Object arg0, Object arg1) {
		return ((Employee)arg0).getId().compareTo(((Employee)arg1).getId());
	}
}

class IdDescComparator implements Comparator {
	public int compare(Object arg0, Object arg1) {
		return ((Employee)arg1).getId().compareTo(((Employee)arg0).getId());
	}
}

class NameAscComparator implements Comparator {
	public int compare(Object arg0, Object arg1) {
		return ((Employee)arg0).getName().compareTo(((Employee)arg1).getName());
	}
}

class NameDescComparator implements Comparator {
	public int compare(Object arg0, Object arg1) {
		return ((Employee)arg1).getName().compareTo(((Employee)arg0).getName());
	}
}

class DepartAscComparator implements Comparator {
	public int compare(Object arg0, Object arg1) {
		return ((Employee)arg0).getDepart().compareTo(((Employee)arg1).getDepart());
	}
}

class DepartDescComparator implements Comparator {
	public int compare(Object arg0, Object arg1) {
		return ((Employee)arg1).getDepart().compareTo(((Employee)arg0).getDepart());
	}
}

class TypeAscComparator implements Comparator {
	public int compare(Object arg0, Object arg1) {
		return ((Employee)arg0).getType().compareTo(((Employee)arg1).getType());
	}
}

class TypeDescComparator implements Comparator {
	public int compare(Object arg0, Object arg1) {
		return ((Employee)arg1).getType().compareTo(((Employee)arg0).getType());
	}
}

class ManagerAscComparator implements Comparator {
	public int compare(Object arg0, Object arg1) {
		return ((Employee)arg1).getManager().compareTo(((Employee)arg0).getManager());
	}
}

class ManagerDescComparator implements Comparator {
	public int compare(Object arg0, Object arg1) {
		return ((Employee)arg0).getManager().compareTo(((Employee)arg1).getManager());
	}
}