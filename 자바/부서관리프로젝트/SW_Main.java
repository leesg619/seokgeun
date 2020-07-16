import java.util.*;

public class SW_Main 
{	
	
	public static void main(String []args)
	{
		int choice;
		
		String name;
		String depart;
		String position;
		
		Vector <SW_UserManagement> v = new Vector();
		
		Basic(v);
		
		
		while(true)
		{
			choice = Menu();
			
			switch(choice)
			{
			case 1:
				AddUser(v);
				break;
				
			case 2:
				DeleteOrEditUser(v);
				break;
				
			case 3:
				SearchUser(v);
				break;
				
			case 4:
				PrintUser(v);
				break;
				
			case 5:
				break;
				
			case 6:
				break;
				
			case 7:
				break;
				
			default:
				System.out.println("      �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.");
				
			}
			
			

		}

	}
	
	public static void Basic(Vector v)
	{
		v.add(new SW_UserManagement("�񼭸�", "�񼭽�", "Staff", "[M]"));
		v.add(new SW_UserManagement("����", "�񼭽�", "Staff", ""));
		v.add(new SW_UserManagement("�ѹ���", "�ѹ���", "Staff", "[M]"));
		v.add(new SW_UserManagement("�ѹ���", "�ѹ���", "Staff", ""));
		v.add(new SW_UserManagement("�λ��", "�λ���", "Staff", "[M]"));
		v.add(new SW_UserManagement("�λ���", "�λ���", "Staff", ""));
		v.add(new SW_UserManagement("����1��", "����1��", "Tester", "[M]"));
		v.add(new SW_UserManagement("����1��", "����1��", "Developer", ""));
		v.add(new SW_UserManagement("����2��", "����2��", "Tester", "[M]"));
		v.add(new SW_UserManagement("����2��", "����2��", "Developer", ""));
		v.add(new SW_UserManagement("����3��", "����3��", "Tester", "[M]"));
		v.add(new SW_UserManagement("����3��", "����3��", "Developer", ""));
	}
	
	public static int Menu()
	{
		Scanner S = new Scanner(System.in);
		
		int choice;
		
		System.out.println("----------------------------------------------------------");
		System.out.println("");
		System.out.println("      <��� S/W ���� ���� ���α׷�> ");
		System.out.println("");
		System.out.println("    1. �ű� ���� �߰�");
		System.out.println("    2. ���� ���� ���� �� ����");
		System.out.println("    3. ���� �˻�");
		System.out.println("    4. ���� ��� ���");
		System.out.println("    5. ");
		System.out.println("    6. ");
		System.out.println("    7. ");
		System.out.println("");
		
		System.out.print("      �޴��� �����ϼ���.(��ȣ�Է�) : ");
		choice = S.nextInt();
		System.out.println("");
		System.out.println("----------------------------------------------------------");
		
		return choice;
	}
	
	
	public static void AddUser(Vector v)
	{
		Scanner S = new Scanner(System.in);
		
		String name;
		
		int departNum;
		String depart = null;
		
		int positionNum;
		String position = null;
	
		int num=0;
		
		System.out.println("<#1 �ű� ���� �߰�>");
		System.out.println("");
		System.out.print("�ű� ������ �̸� : ");
		name = S.next();
		
		
		while(true)
		{
			System.out.println("");
			System.out.println("");
			System.out.println("�μ� ���) 1.�񼭽�   2.�ѹ���   3.�λ���   4.����1��   5.����2��   6.����3��");
			System.out.println("");
			System.out.print("�ű� ������ �� �μ��� �����ϼ���.(��ȣ�Է�) : ");
			departNum = S.nextInt();
			
		
			if(departNum == 1)
			{
				depart = "�񼭽�";
				position = "Staff";
			
				break;
			}
		
			else if(departNum == 2)
			{
				depart = "�ѹ���";
				position = "Staff";
			
				break;
			}
		
			else if(departNum == 3)
			{
				depart = "�λ���";
				position = "Staff";
			
				break;
			}
	
		
			else if(departNum == 4)
			{
				depart = "����1��";
			
				System.out.println("");
				System.out.println("");
				System.out.println("��å ���) 1.������  2.�׽���");
				System.out.println("");
				System.out.print("�ű� ������ ��å�� �����ϼ���.(��ȣ�Է�) : ");
				positionNum = S.nextInt();
			
				if(positionNum == 1)
					position = "Developer";
			
				else if(positionNum == 2)
					position = "Tester";
			
				break;
			}

			else if(departNum == 5)
			{
				depart = "����2��";
			
				System.out.println("");
				System.out.println("");
				System.out.println("��å ���) 1.������  2.�׽���");
				System.out.println("");
				System.out.print("�ű� ������ ��å�� �����ϼ���.(��ȣ�Է�) : ");
				positionNum = S.nextInt();
			
				if(positionNum == 1)
					position = "Developer";
		
				else if(positionNum == 2)
					position = "Tester";
			
				break;
			}
	
			else if(departNum == 6)
			{
				depart = "����3��";
			
				System.out.println("");
				System.out.println("");
				System.out.println("��å ���) 1.������  2.�׽���");
				System.out.println("");
				System.out.print("�ű� ������ ��å�� �����ϼ���.(��ȣ�Է�) : ");
				positionNum = S.nextInt();
			
				if(positionNum == 1)
					position = "Developer";
		
				else if(positionNum == 2)
					position = "Tester";
			
				break;
			}
		
		
			else
			{
				System.out.println("");
				System.out.println("      �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.");
				continue;	
			}
		}
		
		v.add(new SW_UserManagement(name, depart, position, ""));
	}

	public static void DeleteOrEditUser(Vector v)
	{
		Scanner S  = new Scanner(System.in);
		
		int SearchNum;
		
		String ID=null;
		String name=null;
		
		int DENum;
		String newName;
		String moveto;
		
		int positionNum;
		
		
		for(int i=0 ; ; i++)
		{
			System.out.println("");
			System.out.println("�˻� ���) 1.ID �˻�   2.�̸� �˻�   0. ����");
			System.out.println("");
			System.out.print("���� �Ǵ� ������ ������ �˻��� ����� �����ϼ���.(��ȣ�Է�) : ");
			
			SearchNum = S.nextInt();
			System.out.println("");
			
			
			if(SearchNum == 0)
			{
				System.out.println("�˻� ����� ����Ǿ����ϴ�.");
				break;
			}
			
			else if(SearchNum == 1)  // ID �˻�
			{
				System.out.print("ID �Է� : ");
				ID = S.next();
					
				System.out.println("");
				
				System.out.println("���) 1.����  2.����");
				System.out.print("����� �����ϼ���.(��ȣ�Է�) : ");
				
				DENum = S.nextInt();
				System.out.println("");
				
				if(DENum == 1)  // ID �˻� - ����
				{
					int count=0;
					for(int j=0; j<v.size(); j++)
					{		
						SW_UserManagement ID_D =  (SW_UserManagement) v.get(j);
						
						
						if(ID_D.ID.equals(ID))
						{
							v.remove(j);
							System.out.println("'"+v.toString()+"'�� �����Ǿ����ϴ�.");
							count++;
							break; //ID�� ������ȣ�̹Ƿ� �� �̻� �ݺ��� �ʿ� ����
						}
					
					}
					
					if(count==0)
						System.out.println("�ش��ϴ� ID�� ���� ������ ã�� �� �����ϴ�.");
				}
				
				else if(DENum == 2)  // ID �˻� - ����
				{
					int NDNum;
					int count=0;
					for(int j=0; j<v.size(); j++)
					{		
						SW_UserManagement ID_E = (SW_UserManagement) v.get(j);
						
						
						if(ID_E.ID.equals(ID))
						{
							count++;
							System.out.println("");
							System.out.println("������ ����) 1.�̸�  2.�μ�(&��å)");
							System.out.print("������ ������ �����ϼ���.(��ȣ �Է�) : ");
							
							NDNum = S.nextInt();
							
							if(NDNum == 1)  // ID �˻� - ���� - �̸� ����
							{
								System.out.print("���ο� �̸��� �Է��ϼ��� : ");
								
								newName = S.next();
								((SW_UserManagement) v.elementAt(j)).SetName(newName);
								
								System.out.println("");
								System.out.println("�����Ǿ����ϴ�.");
							}
							
							else if(NDNum == 2)  // ID �˻� - ���� - �μ� ����
							{
								System.out.println("�μ� ���) �񼭽� / �ѹ��� / �λ��� / ����1�� / ����2�� / ����3��");
								System.out.print("�ű� �μ��� �Է��ϼ���. : ");
								
								moveto = S.next();
								
								if(ID_E.depart.equals(moveto))
								{
									System.out.println("������ �Ҽӵ� �μ��δ� �̵��� �� �����ϴ�. �ٽ� �������ּ���");
									System.out.println("");
									j--;
									continue;
								}
								
								else if(moveto.equals("�񼭽�"))
								{
									((SW_UserManagement) v.elementAt(j)).SetDepart(moveto);
									((SW_UserManagement) v.elementAt(j)).SetPosition("Staff");
									
									System.out.println("");
									System.out.println("�����Ǿ����ϴ�.");
									
								}
								
								else if(moveto.equals("�ѹ���"))
								{
									((SW_UserManagement) v.elementAt(j)).SetDepart(moveto);
									((SW_UserManagement) v.elementAt(j)).SetPosition("Staff");
									
									System.out.println("");
									System.out.println("�����Ǿ����ϴ�.");
									
								}
								
								else if(moveto.equals("�λ���"))
								{
									((SW_UserManagement) v.elementAt(j)).SetDepart(moveto);
									((SW_UserManagement) v.elementAt(j)).SetPosition("Staff");
									
									System.out.println("");
									System.out.println("�����Ǿ����ϴ�.");
								}
								
								else if(moveto.equals("����1��"))
								{
									((SW_UserManagement) v.elementAt(j)).SetDepart(moveto);
									
									System.out.println("");
									System.out.println("������ ��å ���) 1.������  2.�׽���");
									System.out.println("");
									System.out.print("�ű� ������ ��å�� �����ϼ���.(��ȣ�Է�) : ");
									positionNum = S.nextInt();
								
									if(positionNum == 1)
										((SW_UserManagement) v.elementAt(j)).SetPosition("Developer");
							
									else if(positionNum == 2)
										((SW_UserManagement) v.elementAt(j)).SetPosition("Tester");
									
									System.out.println("");
									System.out.println("�����Ǿ����ϴ�.");
								}
								
								else if(moveto.equals("����2��"))
								{
									((SW_UserManagement) v.elementAt(j)).SetDepart(moveto);
									
									System.out.println("");
									System.out.println("������ ��å ���) 1.������  2.�׽���");
									System.out.println("");
									System.out.print("�ű� ������ ��å�� �����ϼ���.(��ȣ�Է�) : ");
									positionNum = S.nextInt();
								
									if(positionNum == 1)
										((SW_UserManagement) v.elementAt(j)).SetPosition("Developer");
							
									else if(positionNum == 2)
										((SW_UserManagement) v.elementAt(j)).SetPosition("Tester");
									
									System.out.println("");
									System.out.println("�����Ǿ����ϴ�.");
								}
								
								else if(moveto.equals("����3��"))
								{
									((SW_UserManagement) v.elementAt(j)).SetDepart(moveto);
									
									System.out.println("");
									System.out.println("������ ��å ���) 1.������  2.�׽���");
									System.out.println("");
									System.out.print("�ű� ������ ��å�� �����ϼ���.(��ȣ�Է�) : ");
									positionNum = S.nextInt();
								
									if(positionNum == 1)
										((SW_UserManagement) v.elementAt(j)).SetPosition("Developer");
							
									else if(positionNum == 2)
										((SW_UserManagement) v.elementAt(j)).SetPosition("Tester");
									
									System.out.println("");
									System.out.println("�����Ǿ����ϴ�.");
								}
							}
						}	
					}
					if(count==0)
						System.out.println("�ش��ϴ� ID�� ���� ������ ã�� �� �����ϴ�.");
					
				}
			
			}
			
			
			else if(SearchNum == 2)  //  �̸� �˻�
			{
				int NumOfSamePerson = 0;
				int Choice;
				int Numj[]= new int[10];
				
				System.out.print("�̸� �Է� : ");
				name = S.next();
					
				System.out.println("");
				
				
				
				System.out.println("");
				
				System.out.println("���) 1.����  2.����");
				System.out.print("����� �����ϼ���.(��ȣ�Է�) : ");
				
				DENum = S.nextInt();
				System.out.println("");
				
				
				if(DENum == 1)  //  �̸� �˻� - ����
				{
					for(int j=0; j<v.size(); j++)
					{		
						SW_UserManagement Name_D =  (SW_UserManagement) v.get(j);
						
						if(Name_D.name.equals(name))
						{
							NumOfSamePerson++;
							
							Numj[NumOfSamePerson-1] = j;
						}
					}
					
					if(NumOfSamePerson==0)
						System.out.println("�ش��ϴ� �̸��� ���� ������ ã�� �� �����ϴ�.");
					
					else if(NumOfSamePerson==1)
					{
						System.out.println("'"+v.elementAt(Numj[0]).toString()+"'�� �����Ǿ����ϴ�.");
						v.remove(Numj[0]);
					}
					
					else if(NumOfSamePerson>=2)
					{
						System.out.println("");
						System.out.println("�� "+NumOfSamePerson+"���� ' "+name+" ' �̸��� ���� ������ �ֽ��ϴ�.");
						
						for(int j=0 ; j<NumOfSamePerson ; j++)
						{
							System.out.println((j+1)+". "+v.elementAt(Numj[j]).toString());
						}
						
						System.out.println("");
						System.out.println("�� ��° ������ ������ �����Ͻðڽ��ϱ�?");
						System.out.print("�Է�(��ȣ �Է�) : ");
						Choice = S.nextInt();
						
						System.out.println("'"+v.elementAt(Numj[Choice-1]).toString()+"'�� �����Ǿ����ϴ�.");
						
						v.remove(Numj[Choice-1]);
					}
						
				}
				

				else if(DENum == 2)  //  �̸� �˻� - ����
				{
					int NDNum;
					
					for(int j=0; j<v.size(); j++)
					{		
						SW_UserManagement Name_E =  (SW_UserManagement) v.get(j);
						
						if(Name_E.name.equals(name))
						{
							NumOfSamePerson++;
							
							Numj[NumOfSamePerson-1] = j;
						}
					}
					
					if(NumOfSamePerson==0)
						System.out.println("�ش��ϴ� �̸��� ���� ������ ã�� �� �����ϴ�.");
					
					else if(NumOfSamePerson==1)
					{
						System.out.println("");
						System.out.println("������ ����) 1.�̸�  2.�μ�(&��å)");
						System.out.print("������ ������ �����ϼ���.(��ȣ �Է�) : ");
						
						NDNum = S.nextInt();
						
						if(NDNum == 1)  //  �̸� �˻� - ���� - �̸� ����
						{
							System.out.print("���ο� �̸��� �Է��ϼ��� : ");
							
							newName = S.next();
							((SW_UserManagement) v.elementAt(Numj[0])).SetName(newName);
							
							System.out.println("");
							System.out.println("�����Ǿ����ϴ�.");
						}
						
						else if(NDNum == 2)  //  �̸� �˻� - ���� - �μ� ����
						{
							for(int j = 0; ; j++)
							{
								System.out.println("�μ� ���) �񼭽� / �ѹ��� / �λ��� / ����1�� / ����2�� / ����3��");
								System.out.print("�ű� �μ��� �Է��ϼ���. : ");
								
								moveto = S.next();
								
								if(((SW_UserManagement) v.elementAt(Numj[0])).depart.equals(moveto))
								{
									System.out.println("������ �Ҽӵ� �μ��δ� �̵��� �� �����ϴ�.");
									System.out.println("");
									continue;
								}
								
								else if(moveto.equals("�񼭽�"))
								{
									((SW_UserManagement) v.elementAt(Numj[0])).SetDepart(moveto);
									((SW_UserManagement) v.elementAt(Numj[0])).SetPosition("Staff");
									
									System.out.println("");
									System.out.println("�����Ǿ����ϴ�.");
									break;
								}
								
								else if(moveto.equals("�ѹ���"))
								{
									((SW_UserManagement) v.elementAt(Numj[0])).SetDepart(moveto);
									((SW_UserManagement) v.elementAt(Numj[0])).SetPosition("Staff");
									
									System.out.println("");
									System.out.println("�����Ǿ����ϴ�.");
									break;
								}
								
								else if(moveto.equals("�λ���"))
								{
									((SW_UserManagement) v.elementAt(Numj[0])).SetDepart(moveto);
									((SW_UserManagement) v.elementAt(Numj[0])).SetPosition("Staff");
									
									System.out.println("");
									System.out.println("�����Ǿ����ϴ�.");
									break;
								}
								
								else if(moveto.equals("����1��"))
								{
									((SW_UserManagement) v.elementAt(Numj[0])).SetDepart(moveto);
									
									System.out.println("");
									System.out.println("������ ��å ���) 1.������  2.�׽���");
									System.out.println("");
									System.out.print("�ű� ������ ��å�� �����ϼ���.(��ȣ�Է�) : ");
									positionNum = S.nextInt();
								
									if(positionNum == 1)
										((SW_UserManagement) v.elementAt(Numj[0])).SetPosition("Developer");
							
									else if(positionNum == 2)
										((SW_UserManagement) v.elementAt(Numj[0])).SetPosition("Tester");
									
									System.out.println("");
									System.out.println("�����Ǿ����ϴ�.");
									break;
								}
								
								else if(moveto.equals("����2��"))
								{
									((SW_UserManagement) v.elementAt(Numj[0])).SetDepart(moveto);
									
									System.out.println("");
									System.out.println("������ ��å ���) 1.������  2.�׽���");
									System.out.println("");
									System.out.print("�ű� ������ ��å�� �����ϼ���.(��ȣ�Է�) : ");
									positionNum = S.nextInt();
								
									if(positionNum == 1)
										((SW_UserManagement) v.elementAt(Numj[0])).SetPosition("Developer");
							
									else if(positionNum == 2)
										((SW_UserManagement) v.elementAt(Numj[0])).SetPosition("Tester");
									
									System.out.println("");
									System.out.println("�����Ǿ����ϴ�.");
									break;
								}
								
								else if(moveto.equals("����3��"))
								{
									((SW_UserManagement) v.elementAt(Numj[0])).SetDepart(moveto);
									
									System.out.println("");
									System.out.println("������ ��å ���) 1.������  2.�׽���");
									System.out.println("");
									System.out.print("�ű� ������ ��å�� �����ϼ���.(��ȣ�Է�) : ");
									positionNum = S.nextInt();
								
									if(positionNum == 1)
										((SW_UserManagement) v.elementAt(Numj[0])).SetPosition("Developer");
							
									else if(positionNum == 2)
										((SW_UserManagement) v.elementAt(Numj[0])).SetPosition("Tester");
									
									System.out.println("");
									System.out.println("�����Ǿ����ϴ�.");
									break;
								}
							}
						}
					}
					
					
					else if(NumOfSamePerson>=2)
					{
						System.out.println("");
						System.out.println("�� "+NumOfSamePerson+"����'"+name+"'�̸��� ���� ������ �ֽ��ϴ�.");
						
						for(int j=0 ; j<NumOfSamePerson ; j++)
						{
							System.out.println((j+1)+". "+v.elementAt(Numj[j]).toString());
						}
						
						System.out.println("");
						System.out.println("�� ��° ������ ������ �����Ͻðڽ��ϱ�?");
						System.out.print("�Է�(��ȣ �Է�) : ");
						Choice = S.nextInt();
						
						System.out.println("' "+v.elementAt(Numj[Choice-1]).toString()+" '�� �����ϼ̽��ϴ�.");
						
						System.out.println("");
						System.out.println("������ ����) 1.�̸�  2.�μ�(&��å)");
						System.out.print("������ ������ �����ϼ���.(��ȣ �Է�) : ");
						
						NDNum = S.nextInt();
						
						if(NDNum == 1)  //  �̸� �˻� - ���� - �̸� ����
						{
							System.out.print("���ο� �̸��� �Է��ϼ��� : ");
							
							newName = S.next();
							((SW_UserManagement) v.elementAt(Numj[Choice-1])).SetName(newName);
							
							System.out.println("");
							System.out.println("�����Ǿ����ϴ�.");
						}
						
						else if(NDNum == 2)  //  �̸� �˻� - ���� - �μ� ����
						{
							for(int j=0 ; ; j++)
							{
								System.out.println("�μ� ���) �񼭽� / �ѹ��� / �λ��� / ����1�� / ����2�� / ����3��");
								System.out.print("�ű� �μ��� �Է��ϼ���. : ");
								
								moveto = S.next();
								
								if(((SW_UserManagement) v.elementAt(Numj[Choice-1])).depart.equals(moveto))
								{
									System.out.println("������ �Ҽӵ� �μ��δ� �̵��� �� �����ϴ�. �ٽ� �������ּ���");
									System.out.println("");
									continue;
									
								}
								
								else if(moveto.equals("�񼭽�"))
								{
									((SW_UserManagement) v.elementAt(Numj[Choice-1])).SetDepart(moveto);
									((SW_UserManagement) v.elementAt(Numj[Choice-1])).SetPosition("Staff");
									
									System.out.println("");
									System.out.println("�����Ǿ����ϴ�.");
									break;
								}
								
								else if(moveto.equals("�ѹ���"))
								{
									((SW_UserManagement) v.elementAt(Numj[Choice-1])).SetDepart(moveto);
									((SW_UserManagement) v.elementAt(Numj[Choice-1])).SetPosition("Staff");
									
									System.out.println("");
									System.out.println("�����Ǿ����ϴ�.");
									break;
								}
								
								else if(moveto.equals("�λ���"))
								{
									((SW_UserManagement) v.elementAt(Numj[Choice-1])).SetDepart(moveto);
									((SW_UserManagement) v.elementAt(Numj[Choice-1])).SetPosition("Staff");
									
									System.out.println("");
									System.out.println("�����Ǿ����ϴ�.");
									break;
								}
								
								else if(moveto.equals("����1��"))
								{
									((SW_UserManagement) v.elementAt(Numj[Choice-1])).SetDepart(moveto);
									
									System.out.println("");
									System.out.println("������ ��å ���) 1.������  2.�׽���");
									System.out.println("");
									System.out.print("�ű� ������ ��å�� �����ϼ���.(��ȣ�Է�) : ");
									positionNum = S.nextInt();
								
									if(positionNum == 1)
										((SW_UserManagement) v.elementAt(Numj[Choice-1])).SetPosition("Developer");
							
									else if(positionNum == 2)
										((SW_UserManagement) v.elementAt(Numj[Choice-1])).SetPosition("Tester");
									
									System.out.println("");
									System.out.println("�����Ǿ����ϴ�.");
									break;
								}
								
								else if(moveto.equals("����2��"))
								{
									((SW_UserManagement) v.elementAt(Numj[Choice-1])).SetDepart(moveto);
									
									System.out.println("");
									System.out.println("������ ��å ���) 1.������  2.�׽���");
									System.out.println("");
									System.out.print("�ű� ������ ��å�� �����ϼ���.(��ȣ�Է�) : ");
									positionNum = S.nextInt();
								
									if(positionNum == 1)
										((SW_UserManagement) v.elementAt(Numj[Choice-1])).SetPosition("Developer");
							
									else if(positionNum == 2)
										((SW_UserManagement) v.elementAt(Numj[Choice-1])).SetPosition("Tester");
									
									System.out.println("");
									System.out.println("�����Ǿ����ϴ�.");
									break;
								}
								
								else if(moveto.equals("����3��"))
								{
									((SW_UserManagement) v.elementAt(Numj[Choice-1])).SetDepart(moveto);
									
									System.out.println("");
									System.out.println("������ ��å ���) 1.������  2.�׽���");
									System.out.println("");
									System.out.print("�ű� ������ ��å�� �����ϼ���.(��ȣ�Է�) : ");
									positionNum = S.nextInt();
								
									if(positionNum == 1)
										((SW_UserManagement) v.elementAt(Numj[Choice-1])).SetPosition("Developer");
							
									else if(positionNum == 2)
										((SW_UserManagement) v.elementAt(Numj[Choice-1])).SetPosition("Tester");
									
									System.out.println("");
									System.out.println("�����Ǿ����ϴ�.");
									break;
								}
							}
						}
					}
				}
			
			}
			
		}
	}
	
	public static void SearchUser(Vector v)
	{
		Scanner S = new Scanner(System.in);
		
		int SearchNum;
		
		String name;
		String depart = null;
		
		for(int i=0 ; ; i++)
		{
			int count=0;
		
			System.out.println("");
			System.out.println("");
			System.out.println("�˻� ���) 1.�̸� �˻�   2.�μ� �˻�   3.�Ŵ��������� �˻�     0. ����");
			System.out.println("");
			System.out.print("�˻� ����� �����ϼ���.(��ȣ�Է�) : ");
			
			SearchNum = S.nextInt();
			System.out.println("");
			
			if(SearchNum == 0)
			{
				System.out.println("����Ǿ����ϴ�.");
				break;
			}
			
			else if(SearchNum == 1)
			{
				System.out.print("�̸��� �Է��ϼ���. : ");
				name = S.next();
				System.out.println("");
				
	
				for(int j=0; j<v.size(); j++)
				{		
					SW_UserManagement SN =  (SW_UserManagement) v.get(j);
					
					
					if(SN.name.equals(name))
					{
						System.out.println(SN.toString());
						count++;
					}
				}
				
				if(count == 0)
				{
					System.out.println("");
					System.out.println("�ش��ϴ� �̸��� ���� ������ ã�� �� �����ϴ�.");
				}
				
				else
				{
					System.out.println("");
					System.out.println("�� "+count+"���� ������ �˻��Ǿ����ϴ�.");
				}
	
			}
			
			else if(SearchNum == 2)
			{
				System.out.print("�μ����� �Է��ϼ���. : ");
				depart = S.next();
				System.out.println("");
				
				for(int j=0; j<v.size(); j++)
				{		
					SW_UserManagement SD =  (SW_UserManagement) v.get(j);
					
					if(SD.depart.equals(depart))
					{
						System.out.println(SD.toString());
						count++;
					}
				}
				
				if(count == 0)
				{
					System.out.println("");
					System.out.println("�ش��ϴ� �̸��� ���� �μ��� ã�� �� �����ϴ�.");
				}
				
				else
				{
					System.out.println("");
					System.out.println("�� "+count+"���� "+depart+" ������ �˻��Ǿ����ϴ�.");
				}
			}
			
			else if(SearchNum == 3)
			{
				System.out.print("�Ŵ������� �Է��ϼ���. : ");
				
				name = S.next();
				System.out.println("");
				
				for(int j=0; j<v.size(); j++)
				{		
					SW_UserManagement SM =  (SW_UserManagement) v.get(j);
					
					
					if(SM.name.equals(name))
					{
						depart = SM.depart;
						count++;
						break;
					}
				}
				
				if(count == 0)
				{
					System.out.println("");
					System.out.println("�ش��ϴ� �̸��� ���� �Ŵ����� ã�� �� �����ϴ�.");
				}
				
				else
				{
					for(int j=0; j<v.size(); j++)
					{		
						SW_UserManagement SM =  (SW_UserManagement) v.get(j);
						
						if(SM.depart.equals(depart))
						{
							System.out.println(SM.toString());
							count++;
						}
					}
					System.out.println("");
					System.out.println("�� "+(count-1)+"���� "+depart+" ������ �˻��Ǿ����ϴ�.");
				}
			}
			
			
			
			
			
		}
		
	}
	
	public static void PrintUser(Vector v)
	{
		System.out.println(" No.   ID   �̸�    �μ�    ��å");
		for(int i=0;i<v.size();i++)
		{ 
			SW_UserManagement P =  (SW_UserManagement) v.get(i);
			System.out.println(" "+(i+1)+".  "+P.toString());
		}
	}
}


