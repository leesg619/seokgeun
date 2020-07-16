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
		int saveFlag = 0; // ���� �� ������ �ִ��� Ȯ���ϴ� ���� 0�̸� ������ ������

		Scanner s = null;
		try {
			s = new Scanner(System.in);
			while (exitFlag == 0) {
				printMenu(); // �޴� ���
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
						System.out.println("���� �� ������� �ʾҽ��ϴ�. ���� �����Ͻðڽ��ϱ�? (y/n)");
						String answer = s.next();
						if (answer.equals("y"))
							exitFlag = 1; // ���� ����
						else {
							System.out.println("������� �ʾҽ��ϴ�.");
							continue;
						}
					} else
						exitFlag = 1;
					break;
				default:
					System.out.println("�޴��� �ִ� ��ȣ�� �Է����ּ���");
				}
			}
		} catch (Exception e) {
			System.out.println("���� �߻�");
		} finally {
			s.close();
		}
	}

	static void printMenu() {
		System.out.println("=== ��� S/W ���� ���� ���α׷� ===");
		System.out.println("1. �ű� ���� �߰�");
		System.out.println("2. ���� ���� ���� �� ����");
		System.out.println("3. ���� ��� ����");
		System.out.println("4. ���� �˻�");
		System.out.println("5. �α� ���");
		System.out.println("6. ���Ͽ� ����");
		System.out.println("7. ��� ����");
		System.out.println("0. ���α׷� ����");
		System.out.print("�Է� >> ");
	}

	static void addUser(Scanner s) {
		String id;
		String name;
		String depart;
		System.out.println("-- �ű� ���� �߰� --");
		System.out.println("ID�� �ٸ� ����ڿ� �ߺ��� �� �����ϴ�.");
		System.out.print("ID �Է� >> ");
		id = s.next();
		if (UserTable.checkId(id)) {		// �ߺ� �˻�
			System.out.print("�̸� �Է� >> ");
			name = s.next();
			System.out.println("�μ��� �񼭽�, �ѹ���, �λ���, ����1��, ����2��, ����3�� �� �����մϴ�.");
			System.out.print("�μ� �Է� >> ");
			depart = s.next();
			if (depart.equals("�񼭽�") || depart.equals("�ѹ���") || depart.equals("�λ���")) {
				UserTable.User.addElement(new Staff(id, name, depart));
				System.out.printf("*** [%s], [%s], [%s] �߰��Ϸ� ***", id, name,depart);
				HRSW.logging(", �ű� ���� �߰� : ����ID(" + id + ")");
			} 
			else if (depart.equals("����1��") || depart.equals("����2��") || depart.equals("����3��")) {
				int type;
				System.out.println("���ߺμ����� SW Developer�� SW Tester�� �ֽ��ϴ�.");
				System.out.println("(1) SW Developer (2) SW Tester");
				System.out.print("��å �Է� >> ");
				type = s.nextInt();
				if (type == 1) {
					UserTable.User.addElement(new SW_Developer(id, name, depart));
					System.out.printf("*** [%s], [%s], [%s] �߰��Ϸ� ***", id, name, depart);
					HRSW.logging(", �ű� ���� �߰� : ����ID(" + id + ")");
				} else if (type == 2) {
					UserTable.User.addElement(new SW_Tester(id, name, depart));
					System.out.printf("*** [%s], [%s], [%s] �߰��Ϸ� ***", id, name, depart);
					HRSW.logging(", �ű� ���� �߰� : ����ID(" + id + ")");
				} else
					System.out.println("E : �ùٸ� ��ȣ�� �Է��� �ּ���.");
			} else
				System.out.println("E : �ùٸ� �μ����� �Է��� �ּ���.");
		}
	}

	static void deleteOrCorrectUser(Scanner s) {
		System.out.println("-- ���� ���� ���� �� ���� --");
		System.out.println("���� ID �Ǵ� �̸����� ������ ������ �� ���� �Ǵ� ������ �� �� �ֽ��ϴ�.");
		System.out.println("��� �������� �����Ͻðڽ��ϱ� ?");
		System.out.println("(1) ID (2) �̸�");
		System.out.print("�Է� >> ");
		int crit = s.nextInt();
		String str = null;
		System.out.println("Debug : crit = " + crit);
		if (crit == 1) {
			System.out.println("ID�� �����ϼ̽��ϴ�. ���� �Ǵ� ������ ������ ID�� �Է����ּ���.");
			System.out.print(" ID �Է� >> ");
			str = s.next();
		} else if (crit == 2) {
			System.out.println("�̸��� �����ϼ̽��ϴ�. ���� �Ǵ� ������ ������ �̸��� �Է����ּ���.");
			System.out.print(" �̸� �Է� >> ");
			str = s.next();
		} else
			System.out.println("E : �ùٸ� ���ڸ� �Է����ּ���");
		if (str != null)
			UserTable.deleteOrCorrectUser(s, str, crit);
	}

	static void showList() {
		for (int i = 0; i < 63; i++)
			System.out.print("-");
		System.out.println();
		System.out.printf("|         ID |        �̸� |          �μ� |           ��å | M |\n");
		for (int i = 0; i < 63; i++)
			System.out.print("-");
		System.out.println();
		for (int i = 0; i < UserTable.User.size(); i++)
			UserTable.printUser(i);
		for (int i = 0; i < 63; i++)
			System.out.print("-");
		System.out.println();
		HRSW.logging(", ���� ��� ����");
	}

	static void searchUser(Scanner s) {
		System.out.println("-- ���� �˻� --");
		System.out.println("���� �˻��� ���� �� ���� �������� �˻��� �����մϴ�.");
		System.out.println("(1) �̸� (2) �μ��� (3) Manager ��");
		System.out.println("� �������� �˻��Ͻðڽ��ϱ�?");
		System.out.print(" �˻� ���� >> ");
		int input = s.nextInt();
		String str = null;
		switch (input) {
		case 1:
			System.out.println("�̸����� �˻��� �����ϼ̽��ϴ�.");
			System.out.println("� �̸����� �˻��Ͻðڽ��ϱ�?");
			System.out.print(" �˻��� �̸� �Է� >> ");
			str = s.next();
			HRSW.logging(", ���� �˻� : ���� - �̸�(" + str + ")");
			break;
		case 2:
			System.out.println("�μ������� �˻��� �����ϼ̽��ϴ�.");
			System.out.println("� �μ������� �˻��Ͻðڽ��ϱ�?");
			System.out
					.println("�� �μ��� �񼭽�, �ѹ���, �λ���, ����1��, ����2��, ����3�� �� �����մϴ�.");
			System.out.print(" �˻��� �μ��� �Է� >> ");
			str = s.next();
			HRSW.logging(", ���� �˻� : ���� - �μ���(" + str + ")");
			break;
		case 3:
			System.out.println("Manager ������ �˻��� �����ϼ̽��ϴ�.");
			System.out.println("� Manager ������ �˻��Ͻðڽ��ϱ�");
			System.out.print(" �˻��� Manager �̸� �Է� >> ");
			str = s.next();
			HRSW.logging(", ���� �˻� : ���� - Manager �̸�(" + str + ")");
			break;
		}
		if (str == null)
			System.out.println("E : �߸��� �˻� �����Դϴ�.");
		else
			UserTable.searchUser(str, input);
	}

	static void printLog() {
		System.out.println("-- �α� ��� --");
		System.out.println(HRSW.loadLog());
	}
	
	static void sortList(Scanner s) {
		System.out.println("� �������� �����Ͻðڽ��ϱ�?");
		System.out.println("(1) ID (2) �̸� (3) �μ� (4) ��å (5) �Ŵ���");
		System.out.print(" ���� ���� >> ");
		int input = s.nextInt();
		System.out.println("(1) �������� (2) ��������");
		System.out.print(" ���� �Է� >> ");
		int order = s.nextInt();
		if(order == 1) {	// ��������
			switch(input) {
			case 1:	// ID
				Collections.sort(UserTable.User, new IdAscComparator());break;
			case 2:	// �̸�
				Collections.sort(UserTable.User, new NameAscComparator());break;
			case 3:	// �μ�
				Collections.sort(UserTable.User, new DepartAscComparator());break;
			case 4:	// ��å
				Collections.sort(UserTable.User, new TypeAscComparator());break;
			case 5:	// �Ŵ���
				Collections.sort(UserTable.User, new ManagerAscComparator());break;
			default:
				System.out.println(" E : �ùٸ� ���� ������ �Է��ϼ���.");
			}
		}
		else if(order == 2) {
			switch(input) {	// ��������
			case 1:	// ID
				Collections.sort(UserTable.User, new IdDescComparator());break;
			case 2:	// �̸�
				Collections.sort(UserTable.User, new NameDescComparator());break;
			case 3:	// �μ�
				Collections.sort(UserTable.User, new DepartDescComparator());break;
			case 4:	// ��å
				Collections.sort(UserTable.User, new TypeDescComparator());break;
			case 5:	// �Ŵ���
				Collections.sort(UserTable.User, new ManagerDescComparator());break;
			default:
				System.out.println(" E : �ùٸ� ���� ������ �Է��ϼ���.");
			}
		}
	}

	static void saveToFile() {
		/*
		 * Data.txt�� ���ϸ����� �����
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
			HRSW.logging(", ���Ͽ� ����");
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