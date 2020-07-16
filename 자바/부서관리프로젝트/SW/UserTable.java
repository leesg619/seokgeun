package SW;

import java.util.Scanner;
import java.util.Vector;

import Person.*;

public class UserTable {
	static Vector<Employee> User = new Vector<Employee>(30);
	
	public static String departTable[][] = {
		{ "비서실", null },
		{ "총무팀", null },
		{ "인사팀", null },
		{ "개발1팀", null },
		{ "개발2팀", null },
		{ "개발3팀", null }
	};	// 저장 형태는 {부서명, 이름}
	
	public static void deleteOrCorrectUser(Scanner s, String str, int crit) {
		/* 
		 * 기준 -	ID : 1
		 * 			이름 : 2
		 */
		int index = -1;
		int count = 0;
		
		switch(crit) {
		case 1:
			for(int i = 0; i < User.size(); i++) {
				if(User.elementAt(i).getId().equals(str)) {
					printUser(i);
					index = i;
					break;			// ID는 유일하므로 break 시켜도 됨.
				}
			}
			if(index == -1)
				System.out.println("E : 해당하는 ID의 직원을 찾을 수 없습니다.");
			else {
				System.out.println("해당 직원을 수정 또는 삭제할 수 있습니다.");
				System.out.println("(1) 수정 (2) 삭제");
				System.out.print(" 입력 >> ");
				int answer1 = s.nextInt();
				if(answer1 == 1) 
					correctUser(s, index);
				else if(answer1 == 2) {
					HRSW.logging(", 직원 삭제 ID(" + User.elementAt(index).getId() + ")");
					User.removeElementAt(index);
				}
				else
					System.out.println("E : 잘못된 입력입니다.");
				
			}
			break;
		case 2:
			for(int i = 0; i < User.size(); i++) {
				if(User.elementAt(i).getName().equals(str)) {
					printUser(i);
					index = i;
					count++;				// 두명 이상 존재할 경우 이름으로 직원을 선택할 수 없음.
				}
			}
			if(count > 1) {
				System.out.println("동일한 이름의 직원이 2명 이상 존재합니다.");
				System.out.println("출력된 직원의 명단을 보고 ID로 선택해 주세요.");
			}
			else if(count == 1) {
				System.out.println("해당 직원을 수정 또는 삭제할 수 있습니다.");
				System.out.println("(1) 수정 (2) 삭제");
				System.out.print(" 입력 >> ");
				int answer2 = s.nextInt();
				if(answer2 == 1)
					correctUser(s, index);
				else if(answer2 == 2)
					User.remove(index);
				else
					System.out.println("E : 잘못된 입력입니다.");
			}
			break;
		}
	}
	
	public static void correctUser(Scanner s, int index) {
		System.out.println("어떤 내용을 수정하시겠습니까?");
		System.out.println("(1) ID (2) 이름 (3) 부서 (4) 직책");
		System.out.print(" 입력 >> ");
		int answer = s.nextInt();
		Employee tempEmployee = null;
		switch(answer) {
		case 1: 
			System.out.println("ID : " + User.elementAt(index).getId() + "를 무엇으로 바꾸시겠습니까?");
			System.out.print(" 바꿀 ID >> ");
			String id = s.next();
			if(checkId(id)) {
				HRSW.logging(", 직원 수정 ID(" + User.elementAt(index).getId() + " -> " + id + ")");
				User.elementAt(index).setId(id);
				System.out.println(id + "으로 ID가 변경되었습니다.");
			}
			else
				System.out.println("E : 동일한 ID가 존재합니다.");
			break;
		case 2:
			System.out.println("이름 : " + User.elementAt(index).getName() + "를 무엇으로 바꾸시겠습니까?");
			System.out.print(" 바꿀 이름 >> ");
			String name = s.next();
			HRSW.logging(", 직원 수정 이름(" + User.elementAt(index).getName() + " -> " + name + ")");
			User.elementAt(index).setName(name);
			System.out.println(name + "으로 이름이 변경되었습니다.");
			break;
		case 3:
			String currentDepart1 = User.elementAt(index).getDepart();
			System.out.println("부서 : " + currentDepart1 + "를 무엇으로 바꾸시겠습니까?");
			System.out.println("※ 부서는 비서실, 총무팀, 인사팀, 개발1팀, 개발2팀, 개발3팀 이 존재합니다.");
			System.out.print(" 바꿀 부서명 >> ");
			String depart = s.next();
			HRSW.logging(", 직원 수정 부서(" + User.elementAt(index).getDepart() + " -> " + depart + ")");
			
			if(checkDepart(currentDepart1) == checkDepart(depart)) {		// 개발지원팀 => 개발지원팀 or 개발팀 => 개발팀
				User.elementAt(index).setDepart(depart);
				System.out.println(depart + "으로 부서가 변경되었습니다.");
			}
			else {		// 개발지원팀 => 개발팀 or 개발팀 => 개발지원팀 // 개발지원팀 => 개발팀은 기본적으로 SW_Tester가 됨.
				if(checkDepart(depart))	{	// 개발팀은 true, 개발지원팀은 false
					tempEmployee = new SW_Tester(User.elementAt(index).getId(), 
							User.elementAt(index).getName(), depart);
				}
				else {	// 개발지원팀
					tempEmployee = new Staff(User.elementAt(index).getId(),
							User.elementAt(index).getName(), depart);
				}
				User.remove(index);
				User.add(index, tempEmployee);
			}
			break;
		case 4:
			String currentDepart2 = User.elementAt(index).getDepart();
			String currentType = User.elementAt(index).getType();
			if(checkDepart(currentDepart2)) {		// 개발팀
				System.out.println("직책 : " + currentType + "를 변경하시겠습니까?");
				System.out.println("SW Developer <=> SW Tester , (y/n)");
				System.out.print("입력 >> ");
				String type = s.next();
				if(type.equals("y")) {
					if(User.elementAt(index).getType().equals("SW Developer")) {		// 현재가 SW Developer일 경우
						HRSW.logging(", 직원 수정 직책(" + "SW Developer" + " -> " + "SW Tester" + ")");
						tempEmployee = new SW_Tester(User.elementAt(index).getId(), 
								User.elementAt(index).getName(), User.elementAt(index).getDepart());
					}
					else {			// 현재가 SW Tester일 경우
						HRSW.logging(", 직원 수정 부서(" + "SW Tester" + " -> " + "SW Developer" + ")");
						tempEmployee = new SW_Developer(User.elementAt(index).getId(), 
								User.elementAt(index).getName(), User.elementAt(index).getDepart());
					}
					User.remove(index);
					User.add(index, tempEmployee);
				}
			}
			break;
		default:
			System.out.println("E : 잘못된 입력입니다.");
		}
	}
	
	public static void searchUser(String str, int crit) {
		/*
		 *  기준 - 	이름 : 1
		 *  		부서명 : 2
		 *  		Manager 명 : 3
		 */
		String depart = null;
		for (int i = 0; i < 63; i++)
			System.out.print("-");
		System.out.println();
		System.out.printf("|         ID |        이름 |          부서 |           직책 | M |\n");
		for (int i = 0; i < 63; i++)
			System.out.print("-");
		System.out.println();
		switch(crit) {
		case 1:
			for(int i = 0; i < User.size(); i++) {
				if(User.elementAt(i).getName().equals(str))
					printUser(i);
			}
			HRSW.logging(", 직원 검색 " + "이름(" + str + ")");
			break;
		case 2:
			for(int i = 0; i < User.size(); i++) {
				if(User.elementAt(i).getDepart().equals(str))
					printUser(i);
			}
			HRSW.logging(", 직원 검색 " + "부서명(" + str + ")");
			break;
		case 3:
			for(int i = 0; i < departTable.length; i++) {
				if(str.equals(departTable[i][1]))
					depart = departTable[i][0];		// Manager 명에 맞는 부서를 str에 저장
			}
			if(depart == null) {
				System.out.println("E : 입력하신 Manager 명을 찾을 수 없습니다.");
				break;
			}
			for(int i = 0; i < User.size(); i++) {
				if(User.elementAt(i).getDepart().equals(depart))
					printUser(i);
			}
			HRSW.logging(", 직원 검색 " + "Manager이름(" + str + ")");
			break;
		}
		for (int i = 0; i < 63; i++)
			System.out.print("-");
		System.out.println();
	}
	
	public static void printUser(int i) {		// i번째 직원 출력
		System.out.printf("| %10s | %8s | %10s | %14s | %1s |\n", User.elementAt(i).getId(),
				User.elementAt(i).getName(), User.elementAt(i).getDepart(), 
				User.elementAt(i).getType(), User.elementAt(i).getManager());
		
	}
	
	public static boolean checkId(String id) {
		for(int i = 0; i < User.size(); i++)
			if(User.elementAt(i).getId().equals(id))
				return false;				// 중복 있음.
		return true;						// 중복 없음.
	}
	
	public static boolean checkDepart(String depart) {
		if(depart.equals("비서실") || depart.equals("총무팀") || depart.equals("인사팀"))
			return false;				// 개발 지원팀은 false
		return true;					// 개발팀은 true
	}
	
	public static void setDepartTable(String depart, String name) {
		for(int i = 0; i < departTable.length; i++)
			if(departTable[i][0].equals(depart))
				departTable[i][1] = name;
	}
}