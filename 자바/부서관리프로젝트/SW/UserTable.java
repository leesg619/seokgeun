package SW;

import java.util.Scanner;
import java.util.Vector;

import Person.*;

public class UserTable {
	static Vector<Employee> User = new Vector<Employee>(30);
	
	public static String departTable[][] = {
		{ "�񼭽�", null },
		{ "�ѹ���", null },
		{ "�λ���", null },
		{ "����1��", null },
		{ "����2��", null },
		{ "����3��", null }
	};	// ���� ���´� {�μ���, �̸�}
	
	public static void deleteOrCorrectUser(Scanner s, String str, int crit) {
		/* 
		 * ���� -	ID : 1
		 * 			�̸� : 2
		 */
		int index = -1;
		int count = 0;
		
		switch(crit) {
		case 1:
			for(int i = 0; i < User.size(); i++) {
				if(User.elementAt(i).getId().equals(str)) {
					printUser(i);
					index = i;
					break;			// ID�� �����ϹǷ� break ���ѵ� ��.
				}
			}
			if(index == -1)
				System.out.println("E : �ش��ϴ� ID�� ������ ã�� �� �����ϴ�.");
			else {
				System.out.println("�ش� ������ ���� �Ǵ� ������ �� �ֽ��ϴ�.");
				System.out.println("(1) ���� (2) ����");
				System.out.print(" �Է� >> ");
				int answer1 = s.nextInt();
				if(answer1 == 1) 
					correctUser(s, index);
				else if(answer1 == 2) {
					HRSW.logging(", ���� ���� ID(" + User.elementAt(index).getId() + ")");
					User.removeElementAt(index);
				}
				else
					System.out.println("E : �߸��� �Է��Դϴ�.");
				
			}
			break;
		case 2:
			for(int i = 0; i < User.size(); i++) {
				if(User.elementAt(i).getName().equals(str)) {
					printUser(i);
					index = i;
					count++;				// �θ� �̻� ������ ��� �̸����� ������ ������ �� ����.
				}
			}
			if(count > 1) {
				System.out.println("������ �̸��� ������ 2�� �̻� �����մϴ�.");
				System.out.println("��µ� ������ ����� ���� ID�� ������ �ּ���.");
			}
			else if(count == 1) {
				System.out.println("�ش� ������ ���� �Ǵ� ������ �� �ֽ��ϴ�.");
				System.out.println("(1) ���� (2) ����");
				System.out.print(" �Է� >> ");
				int answer2 = s.nextInt();
				if(answer2 == 1)
					correctUser(s, index);
				else if(answer2 == 2)
					User.remove(index);
				else
					System.out.println("E : �߸��� �Է��Դϴ�.");
			}
			break;
		}
	}
	
	public static void correctUser(Scanner s, int index) {
		System.out.println("� ������ �����Ͻðڽ��ϱ�?");
		System.out.println("(1) ID (2) �̸� (3) �μ� (4) ��å");
		System.out.print(" �Է� >> ");
		int answer = s.nextInt();
		Employee tempEmployee = null;
		switch(answer) {
		case 1: 
			System.out.println("ID : " + User.elementAt(index).getId() + "�� �������� �ٲٽðڽ��ϱ�?");
			System.out.print(" �ٲ� ID >> ");
			String id = s.next();
			if(checkId(id)) {
				HRSW.logging(", ���� ���� ID(" + User.elementAt(index).getId() + " -> " + id + ")");
				User.elementAt(index).setId(id);
				System.out.println(id + "���� ID�� ����Ǿ����ϴ�.");
			}
			else
				System.out.println("E : ������ ID�� �����մϴ�.");
			break;
		case 2:
			System.out.println("�̸� : " + User.elementAt(index).getName() + "�� �������� �ٲٽðڽ��ϱ�?");
			System.out.print(" �ٲ� �̸� >> ");
			String name = s.next();
			HRSW.logging(", ���� ���� �̸�(" + User.elementAt(index).getName() + " -> " + name + ")");
			User.elementAt(index).setName(name);
			System.out.println(name + "���� �̸��� ����Ǿ����ϴ�.");
			break;
		case 3:
			String currentDepart1 = User.elementAt(index).getDepart();
			System.out.println("�μ� : " + currentDepart1 + "�� �������� �ٲٽðڽ��ϱ�?");
			System.out.println("�� �μ��� �񼭽�, �ѹ���, �λ���, ����1��, ����2��, ����3�� �� �����մϴ�.");
			System.out.print(" �ٲ� �μ��� >> ");
			String depart = s.next();
			HRSW.logging(", ���� ���� �μ�(" + User.elementAt(index).getDepart() + " -> " + depart + ")");
			
			if(checkDepart(currentDepart1) == checkDepart(depart)) {		// ���������� => ���������� or ������ => ������
				User.elementAt(index).setDepart(depart);
				System.out.println(depart + "���� �μ��� ����Ǿ����ϴ�.");
			}
			else {		// ���������� => ������ or ������ => ���������� // ���������� => �������� �⺻������ SW_Tester�� ��.
				if(checkDepart(depart))	{	// �������� true, ������������ false
					tempEmployee = new SW_Tester(User.elementAt(index).getId(), 
							User.elementAt(index).getName(), depart);
				}
				else {	// ����������
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
			if(checkDepart(currentDepart2)) {		// ������
				System.out.println("��å : " + currentType + "�� �����Ͻðڽ��ϱ�?");
				System.out.println("SW Developer <=> SW Tester , (y/n)");
				System.out.print("�Է� >> ");
				String type = s.next();
				if(type.equals("y")) {
					if(User.elementAt(index).getType().equals("SW Developer")) {		// ���簡 SW Developer�� ���
						HRSW.logging(", ���� ���� ��å(" + "SW Developer" + " -> " + "SW Tester" + ")");
						tempEmployee = new SW_Tester(User.elementAt(index).getId(), 
								User.elementAt(index).getName(), User.elementAt(index).getDepart());
					}
					else {			// ���簡 SW Tester�� ���
						HRSW.logging(", ���� ���� �μ�(" + "SW Tester" + " -> " + "SW Developer" + ")");
						tempEmployee = new SW_Developer(User.elementAt(index).getId(), 
								User.elementAt(index).getName(), User.elementAt(index).getDepart());
					}
					User.remove(index);
					User.add(index, tempEmployee);
				}
			}
			break;
		default:
			System.out.println("E : �߸��� �Է��Դϴ�.");
		}
	}
	
	public static void searchUser(String str, int crit) {
		/*
		 *  ���� - 	�̸� : 1
		 *  		�μ��� : 2
		 *  		Manager �� : 3
		 */
		String depart = null;
		for (int i = 0; i < 63; i++)
			System.out.print("-");
		System.out.println();
		System.out.printf("|         ID |        �̸� |          �μ� |           ��å | M |\n");
		for (int i = 0; i < 63; i++)
			System.out.print("-");
		System.out.println();
		switch(crit) {
		case 1:
			for(int i = 0; i < User.size(); i++) {
				if(User.elementAt(i).getName().equals(str))
					printUser(i);
			}
			HRSW.logging(", ���� �˻� " + "�̸�(" + str + ")");
			break;
		case 2:
			for(int i = 0; i < User.size(); i++) {
				if(User.elementAt(i).getDepart().equals(str))
					printUser(i);
			}
			HRSW.logging(", ���� �˻� " + "�μ���(" + str + ")");
			break;
		case 3:
			for(int i = 0; i < departTable.length; i++) {
				if(str.equals(departTable[i][1]))
					depart = departTable[i][0];		// Manager �� �´� �μ��� str�� ����
			}
			if(depart == null) {
				System.out.println("E : �Է��Ͻ� Manager ���� ã�� �� �����ϴ�.");
				break;
			}
			for(int i = 0; i < User.size(); i++) {
				if(User.elementAt(i).getDepart().equals(depart))
					printUser(i);
			}
			HRSW.logging(", ���� �˻� " + "Manager�̸�(" + str + ")");
			break;
		}
		for (int i = 0; i < 63; i++)
			System.out.print("-");
		System.out.println();
	}
	
	public static void printUser(int i) {		// i��° ���� ���
		System.out.printf("| %10s | %8s | %10s | %14s | %1s |\n", User.elementAt(i).getId(),
				User.elementAt(i).getName(), User.elementAt(i).getDepart(), 
				User.elementAt(i).getType(), User.elementAt(i).getManager());
		
	}
	
	public static boolean checkId(String id) {
		for(int i = 0; i < User.size(); i++)
			if(User.elementAt(i).getId().equals(id))
				return false;				// �ߺ� ����.
		return true;						// �ߺ� ����.
	}
	
	public static boolean checkDepart(String depart) {
		if(depart.equals("�񼭽�") || depart.equals("�ѹ���") || depart.equals("�λ���"))
			return false;				// ���� �������� false
		return true;					// �������� true
	}
	
	public static void setDepartTable(String depart, String name) {
		for(int i = 0; i < departTable.length; i++)
			if(departTable[i][0].equals(depart))
				departTable[i][1] = name;
	}
}