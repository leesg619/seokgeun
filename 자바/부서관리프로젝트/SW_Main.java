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
				System.out.println("      잘못 입력하셨습니다. 다시 입력해주세요.");
				
			}
			
			

		}

	}
	
	public static void Basic(Vector v)
	{
		v.add(new SW_UserManagement("비서맨", "비서실", "Staff", "[M]"));
		v.add(new SW_UserManagement("비서직", "비서실", "Staff", ""));
		v.add(new SW_UserManagement("총무맨", "총무팀", "Staff", "[M]"));
		v.add(new SW_UserManagement("총무직", "총무팀", "Staff", ""));
		v.add(new SW_UserManagement("인사맨", "인사팀", "Staff", "[M]"));
		v.add(new SW_UserManagement("인사직", "인사팀", "Staff", ""));
		v.add(new SW_UserManagement("개발1맨", "개발1팀", "Tester", "[M]"));
		v.add(new SW_UserManagement("개발1직", "개발1팀", "Developer", ""));
		v.add(new SW_UserManagement("개발2맨", "개발2팀", "Tester", "[M]"));
		v.add(new SW_UserManagement("개발2직", "개발2팀", "Developer", ""));
		v.add(new SW_UserManagement("개발3맨", "개발3팀", "Tester", "[M]"));
		v.add(new SW_UserManagement("개발3직", "개발3팀", "Developer", ""));
	}
	
	public static int Menu()
	{
		Scanner S = new Scanner(System.in);
		
		int choice;
		
		System.out.println("----------------------------------------------------------");
		System.out.println("");
		System.out.println("      <경기 S/W 직원 관리 프로그램> ");
		System.out.println("");
		System.out.println("    1. 신규 직원 추가");
		System.out.println("    2. 기존 직원 삭제 및 수정");
		System.out.println("    3. 직원 검색");
		System.out.println("    4. 직원 목록 출력");
		System.out.println("    5. ");
		System.out.println("    6. ");
		System.out.println("    7. ");
		System.out.println("");
		
		System.out.print("      메뉴를 선택하세요.(번호입력) : ");
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
		
		System.out.println("<#1 신규 직원 추가>");
		System.out.println("");
		System.out.print("신규 직원의 이름 : ");
		name = S.next();
		
		
		while(true)
		{
			System.out.println("");
			System.out.println("");
			System.out.println("부서 목록) 1.비서실   2.총무팀   3.인사팀   4.개발1팀   5.개발2팀   6.개발3팀");
			System.out.println("");
			System.out.print("신규 직원이 들어갈 부서를 선택하세요.(번호입력) : ");
			departNum = S.nextInt();
			
		
			if(departNum == 1)
			{
				depart = "비서실";
				position = "Staff";
			
				break;
			}
		
			else if(departNum == 2)
			{
				depart = "총무팀";
				position = "Staff";
			
				break;
			}
		
			else if(departNum == 3)
			{
				depart = "인사팀";
				position = "Staff";
			
				break;
			}
	
		
			else if(departNum == 4)
			{
				depart = "개발1팀";
			
				System.out.println("");
				System.out.println("");
				System.out.println("직책 목록) 1.개발자  2.테스터");
				System.out.println("");
				System.out.print("신규 직원의 직책을 선택하세요.(번호입력) : ");
				positionNum = S.nextInt();
			
				if(positionNum == 1)
					position = "Developer";
			
				else if(positionNum == 2)
					position = "Tester";
			
				break;
			}

			else if(departNum == 5)
			{
				depart = "개발2팀";
			
				System.out.println("");
				System.out.println("");
				System.out.println("직책 목록) 1.개발자  2.테스터");
				System.out.println("");
				System.out.print("신규 직원의 직책을 선택하세요.(번호입력) : ");
				positionNum = S.nextInt();
			
				if(positionNum == 1)
					position = "Developer";
		
				else if(positionNum == 2)
					position = "Tester";
			
				break;
			}
	
			else if(departNum == 6)
			{
				depart = "개발3팀";
			
				System.out.println("");
				System.out.println("");
				System.out.println("직책 목록) 1.개발자  2.테스터");
				System.out.println("");
				System.out.print("신규 직원의 직책을 선택하세요.(번호입력) : ");
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
				System.out.println("      잘못 입력하셨습니다. 다시 입력해주세요.");
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
			System.out.println("검색 방식) 1.ID 검색   2.이름 검색   0. 종료");
			System.out.println("");
			System.out.print("삭제 또는 수정할 직원을 검색할 방식을 선택하세요.(번호입력) : ");
			
			SearchNum = S.nextInt();
			System.out.println("");
			
			
			if(SearchNum == 0)
			{
				System.out.println("검색 기능이 종료되었습니다.");
				break;
			}
			
			else if(SearchNum == 1)  // ID 검색
			{
				System.out.print("ID 입력 : ");
				ID = S.next();
					
				System.out.println("");
				
				System.out.println("기능) 1.삭제  2.수정");
				System.out.print("기능을 선택하세요.(번호입력) : ");
				
				DENum = S.nextInt();
				System.out.println("");
				
				if(DENum == 1)  // ID 검색 - 삭제
				{
					int count=0;
					for(int j=0; j<v.size(); j++)
					{		
						SW_UserManagement ID_D =  (SW_UserManagement) v.get(j);
						
						
						if(ID_D.ID.equals(ID))
						{
							v.remove(j);
							System.out.println("'"+v.toString()+"'가 삭제되었습니다.");
							count++;
							break; //ID는 고유번호이므로 더 이상 반복할 필요 없음
						}
					
					}
					
					if(count==0)
						System.out.println("해당하는 ID를 갖는 직원을 찾을 수 없습니다.");
				}
				
				else if(DENum == 2)  // ID 검색 - 수정
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
							System.out.println("수정할 정보) 1.이름  2.부서(&직책)");
							System.out.print("수정할 정보를 선택하세요.(번호 입력) : ");
							
							NDNum = S.nextInt();
							
							if(NDNum == 1)  // ID 검색 - 수정 - 이름 수정
							{
								System.out.print("새로운 이름을 입력하세요 : ");
								
								newName = S.next();
								((SW_UserManagement) v.elementAt(j)).SetName(newName);
								
								System.out.println("");
								System.out.println("수정되었습니다.");
							}
							
							else if(NDNum == 2)  // ID 검색 - 수정 - 부서 수정
							{
								System.out.println("부서 목록) 비서실 / 총무팀 / 인사팀 / 개발1팀 / 개발2팀 / 개발3팀");
								System.out.print("옮길 부서를 입력하세요. : ");
								
								moveto = S.next();
								
								if(ID_E.depart.equals(moveto))
								{
									System.out.println("기존에 소속된 부서로는 이동할 수 없습니다. 다시 선택해주세요");
									System.out.println("");
									j--;
									continue;
								}
								
								else if(moveto.equals("비서실"))
								{
									((SW_UserManagement) v.elementAt(j)).SetDepart(moveto);
									((SW_UserManagement) v.elementAt(j)).SetPosition("Staff");
									
									System.out.println("");
									System.out.println("수정되었습니다.");
									
								}
								
								else if(moveto.equals("총무팀"))
								{
									((SW_UserManagement) v.elementAt(j)).SetDepart(moveto);
									((SW_UserManagement) v.elementAt(j)).SetPosition("Staff");
									
									System.out.println("");
									System.out.println("수정되었습니다.");
									
								}
								
								else if(moveto.equals("인사팀"))
								{
									((SW_UserManagement) v.elementAt(j)).SetDepart(moveto);
									((SW_UserManagement) v.elementAt(j)).SetPosition("Staff");
									
									System.out.println("");
									System.out.println("수정되었습니다.");
								}
								
								else if(moveto.equals("개발1팀"))
								{
									((SW_UserManagement) v.elementAt(j)).SetDepart(moveto);
									
									System.out.println("");
									System.out.println("개발팀 직책 목록) 1.개발자  2.테스터");
									System.out.println("");
									System.out.print("옮길 직원의 직책을 선택하세요.(번호입력) : ");
									positionNum = S.nextInt();
								
									if(positionNum == 1)
										((SW_UserManagement) v.elementAt(j)).SetPosition("Developer");
							
									else if(positionNum == 2)
										((SW_UserManagement) v.elementAt(j)).SetPosition("Tester");
									
									System.out.println("");
									System.out.println("수정되었습니다.");
								}
								
								else if(moveto.equals("개발2팀"))
								{
									((SW_UserManagement) v.elementAt(j)).SetDepart(moveto);
									
									System.out.println("");
									System.out.println("개발팀 직책 목록) 1.개발자  2.테스터");
									System.out.println("");
									System.out.print("옮길 직원의 직책을 선택하세요.(번호입력) : ");
									positionNum = S.nextInt();
								
									if(positionNum == 1)
										((SW_UserManagement) v.elementAt(j)).SetPosition("Developer");
							
									else if(positionNum == 2)
										((SW_UserManagement) v.elementAt(j)).SetPosition("Tester");
									
									System.out.println("");
									System.out.println("수정되었습니다.");
								}
								
								else if(moveto.equals("개발3팀"))
								{
									((SW_UserManagement) v.elementAt(j)).SetDepart(moveto);
									
									System.out.println("");
									System.out.println("개발팀 직책 목록) 1.개발자  2.테스터");
									System.out.println("");
									System.out.print("옮길 직원의 직책을 선택하세요.(번호입력) : ");
									positionNum = S.nextInt();
								
									if(positionNum == 1)
										((SW_UserManagement) v.elementAt(j)).SetPosition("Developer");
							
									else if(positionNum == 2)
										((SW_UserManagement) v.elementAt(j)).SetPosition("Tester");
									
									System.out.println("");
									System.out.println("수정되었습니다.");
								}
							}
						}	
					}
					if(count==0)
						System.out.println("해당하는 ID를 갖는 직원을 찾을 수 없습니다.");
					
				}
			
			}
			
			
			else if(SearchNum == 2)  //  이름 검색
			{
				int NumOfSamePerson = 0;
				int Choice;
				int Numj[]= new int[10];
				
				System.out.print("이름 입력 : ");
				name = S.next();
					
				System.out.println("");
				
				
				
				System.out.println("");
				
				System.out.println("기능) 1.삭제  2.수정");
				System.out.print("기능을 선택하세요.(번호입력) : ");
				
				DENum = S.nextInt();
				System.out.println("");
				
				
				if(DENum == 1)  //  이름 검색 - 삭제
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
						System.out.println("해당하는 이름을 갖는 직원을 찾을 수 없습니다.");
					
					else if(NumOfSamePerson==1)
					{
						System.out.println("'"+v.elementAt(Numj[0]).toString()+"'가 삭제되었습니다.");
						v.remove(Numj[0]);
					}
					
					else if(NumOfSamePerson>=2)
					{
						System.out.println("");
						System.out.println("총 "+NumOfSamePerson+"명의 ' "+name+" ' 이름을 갖는 직원이 있습니다.");
						
						for(int j=0 ; j<NumOfSamePerson ; j++)
						{
							System.out.println((j+1)+". "+v.elementAt(Numj[j]).toString());
						}
						
						System.out.println("");
						System.out.println("몇 번째 직원의 정보를 삭제하시겠습니까?");
						System.out.print("입력(번호 입력) : ");
						Choice = S.nextInt();
						
						System.out.println("'"+v.elementAt(Numj[Choice-1]).toString()+"'가 삭제되었습니다.");
						
						v.remove(Numj[Choice-1]);
					}
						
				}
				

				else if(DENum == 2)  //  이름 검색 - 수정
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
						System.out.println("해당하는 이름을 갖는 직원을 찾을 수 없습니다.");
					
					else if(NumOfSamePerson==1)
					{
						System.out.println("");
						System.out.println("수정할 정보) 1.이름  2.부서(&직책)");
						System.out.print("수정할 정보를 선택하세요.(번호 입력) : ");
						
						NDNum = S.nextInt();
						
						if(NDNum == 1)  //  이름 검색 - 수정 - 이름 수정
						{
							System.out.print("새로운 이름을 입력하세요 : ");
							
							newName = S.next();
							((SW_UserManagement) v.elementAt(Numj[0])).SetName(newName);
							
							System.out.println("");
							System.out.println("수정되었습니다.");
						}
						
						else if(NDNum == 2)  //  이름 검색 - 수정 - 부서 수정
						{
							for(int j = 0; ; j++)
							{
								System.out.println("부서 목록) 비서실 / 총무팀 / 인사팀 / 개발1팀 / 개발2팀 / 개발3팀");
								System.out.print("옮길 부서를 입력하세요. : ");
								
								moveto = S.next();
								
								if(((SW_UserManagement) v.elementAt(Numj[0])).depart.equals(moveto))
								{
									System.out.println("기존에 소속된 부서로는 이동할 수 없습니다.");
									System.out.println("");
									continue;
								}
								
								else if(moveto.equals("비서실"))
								{
									((SW_UserManagement) v.elementAt(Numj[0])).SetDepart(moveto);
									((SW_UserManagement) v.elementAt(Numj[0])).SetPosition("Staff");
									
									System.out.println("");
									System.out.println("수정되었습니다.");
									break;
								}
								
								else if(moveto.equals("총무팀"))
								{
									((SW_UserManagement) v.elementAt(Numj[0])).SetDepart(moveto);
									((SW_UserManagement) v.elementAt(Numj[0])).SetPosition("Staff");
									
									System.out.println("");
									System.out.println("수정되었습니다.");
									break;
								}
								
								else if(moveto.equals("인사팀"))
								{
									((SW_UserManagement) v.elementAt(Numj[0])).SetDepart(moveto);
									((SW_UserManagement) v.elementAt(Numj[0])).SetPosition("Staff");
									
									System.out.println("");
									System.out.println("수정되었습니다.");
									break;
								}
								
								else if(moveto.equals("개발1팀"))
								{
									((SW_UserManagement) v.elementAt(Numj[0])).SetDepart(moveto);
									
									System.out.println("");
									System.out.println("개발팀 직책 목록) 1.개발자  2.테스터");
									System.out.println("");
									System.out.print("옮길 직원의 직책을 선택하세요.(번호입력) : ");
									positionNum = S.nextInt();
								
									if(positionNum == 1)
										((SW_UserManagement) v.elementAt(Numj[0])).SetPosition("Developer");
							
									else if(positionNum == 2)
										((SW_UserManagement) v.elementAt(Numj[0])).SetPosition("Tester");
									
									System.out.println("");
									System.out.println("수정되었습니다.");
									break;
								}
								
								else if(moveto.equals("개발2팀"))
								{
									((SW_UserManagement) v.elementAt(Numj[0])).SetDepart(moveto);
									
									System.out.println("");
									System.out.println("개발팀 직책 목록) 1.개발자  2.테스터");
									System.out.println("");
									System.out.print("옮길 직원의 직책을 선택하세요.(번호입력) : ");
									positionNum = S.nextInt();
								
									if(positionNum == 1)
										((SW_UserManagement) v.elementAt(Numj[0])).SetPosition("Developer");
							
									else if(positionNum == 2)
										((SW_UserManagement) v.elementAt(Numj[0])).SetPosition("Tester");
									
									System.out.println("");
									System.out.println("수정되었습니다.");
									break;
								}
								
								else if(moveto.equals("개발3팀"))
								{
									((SW_UserManagement) v.elementAt(Numj[0])).SetDepart(moveto);
									
									System.out.println("");
									System.out.println("개발팀 직책 목록) 1.개발자  2.테스터");
									System.out.println("");
									System.out.print("옮길 직원의 직책을 선택하세요.(번호입력) : ");
									positionNum = S.nextInt();
								
									if(positionNum == 1)
										((SW_UserManagement) v.elementAt(Numj[0])).SetPosition("Developer");
							
									else if(positionNum == 2)
										((SW_UserManagement) v.elementAt(Numj[0])).SetPosition("Tester");
									
									System.out.println("");
									System.out.println("수정되었습니다.");
									break;
								}
							}
						}
					}
					
					
					else if(NumOfSamePerson>=2)
					{
						System.out.println("");
						System.out.println("총 "+NumOfSamePerson+"명의'"+name+"'이름을 갖는 직원이 있습니다.");
						
						for(int j=0 ; j<NumOfSamePerson ; j++)
						{
							System.out.println((j+1)+". "+v.elementAt(Numj[j]).toString());
						}
						
						System.out.println("");
						System.out.println("몇 번째 직원의 정보를 수정하시겠습니까?");
						System.out.print("입력(번호 입력) : ");
						Choice = S.nextInt();
						
						System.out.println("' "+v.elementAt(Numj[Choice-1]).toString()+" '를 선택하셨습니다.");
						
						System.out.println("");
						System.out.println("수정할 정보) 1.이름  2.부서(&직책)");
						System.out.print("수정할 정보를 선택하세요.(번호 입력) : ");
						
						NDNum = S.nextInt();
						
						if(NDNum == 1)  //  이름 검색 - 수정 - 이름 수정
						{
							System.out.print("새로운 이름을 입력하세요 : ");
							
							newName = S.next();
							((SW_UserManagement) v.elementAt(Numj[Choice-1])).SetName(newName);
							
							System.out.println("");
							System.out.println("수정되었습니다.");
						}
						
						else if(NDNum == 2)  //  이름 검색 - 수정 - 부서 수정
						{
							for(int j=0 ; ; j++)
							{
								System.out.println("부서 목록) 비서실 / 총무팀 / 인사팀 / 개발1팀 / 개발2팀 / 개발3팀");
								System.out.print("옮길 부서를 입력하세요. : ");
								
								moveto = S.next();
								
								if(((SW_UserManagement) v.elementAt(Numj[Choice-1])).depart.equals(moveto))
								{
									System.out.println("기존에 소속된 부서로는 이동할 수 없습니다. 다시 선택해주세요");
									System.out.println("");
									continue;
									
								}
								
								else if(moveto.equals("비서실"))
								{
									((SW_UserManagement) v.elementAt(Numj[Choice-1])).SetDepart(moveto);
									((SW_UserManagement) v.elementAt(Numj[Choice-1])).SetPosition("Staff");
									
									System.out.println("");
									System.out.println("수정되었습니다.");
									break;
								}
								
								else if(moveto.equals("총무팀"))
								{
									((SW_UserManagement) v.elementAt(Numj[Choice-1])).SetDepart(moveto);
									((SW_UserManagement) v.elementAt(Numj[Choice-1])).SetPosition("Staff");
									
									System.out.println("");
									System.out.println("수정되었습니다.");
									break;
								}
								
								else if(moveto.equals("인사팀"))
								{
									((SW_UserManagement) v.elementAt(Numj[Choice-1])).SetDepart(moveto);
									((SW_UserManagement) v.elementAt(Numj[Choice-1])).SetPosition("Staff");
									
									System.out.println("");
									System.out.println("수정되었습니다.");
									break;
								}
								
								else if(moveto.equals("개발1팀"))
								{
									((SW_UserManagement) v.elementAt(Numj[Choice-1])).SetDepart(moveto);
									
									System.out.println("");
									System.out.println("개발팀 직책 목록) 1.개발자  2.테스터");
									System.out.println("");
									System.out.print("옮길 직원의 직책을 선택하세요.(번호입력) : ");
									positionNum = S.nextInt();
								
									if(positionNum == 1)
										((SW_UserManagement) v.elementAt(Numj[Choice-1])).SetPosition("Developer");
							
									else if(positionNum == 2)
										((SW_UserManagement) v.elementAt(Numj[Choice-1])).SetPosition("Tester");
									
									System.out.println("");
									System.out.println("수정되었습니다.");
									break;
								}
								
								else if(moveto.equals("개발2팀"))
								{
									((SW_UserManagement) v.elementAt(Numj[Choice-1])).SetDepart(moveto);
									
									System.out.println("");
									System.out.println("개발팀 직책 목록) 1.개발자  2.테스터");
									System.out.println("");
									System.out.print("옮길 직원의 직책을 선택하세요.(번호입력) : ");
									positionNum = S.nextInt();
								
									if(positionNum == 1)
										((SW_UserManagement) v.elementAt(Numj[Choice-1])).SetPosition("Developer");
							
									else if(positionNum == 2)
										((SW_UserManagement) v.elementAt(Numj[Choice-1])).SetPosition("Tester");
									
									System.out.println("");
									System.out.println("수정되었습니다.");
									break;
								}
								
								else if(moveto.equals("개발3팀"))
								{
									((SW_UserManagement) v.elementAt(Numj[Choice-1])).SetDepart(moveto);
									
									System.out.println("");
									System.out.println("개발팀 직책 목록) 1.개발자  2.테스터");
									System.out.println("");
									System.out.print("옮길 직원의 직책을 선택하세요.(번호입력) : ");
									positionNum = S.nextInt();
								
									if(positionNum == 1)
										((SW_UserManagement) v.elementAt(Numj[Choice-1])).SetPosition("Developer");
							
									else if(positionNum == 2)
										((SW_UserManagement) v.elementAt(Numj[Choice-1])).SetPosition("Tester");
									
									System.out.println("");
									System.out.println("수정되었습니다.");
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
			System.out.println("검색 방식) 1.이름 검색   2.부서 검색   3.매니저명으로 검색     0. 종료");
			System.out.println("");
			System.out.print("검색 방식을 선택하세요.(번호입력) : ");
			
			SearchNum = S.nextInt();
			System.out.println("");
			
			if(SearchNum == 0)
			{
				System.out.println("종료되었습니다.");
				break;
			}
			
			else if(SearchNum == 1)
			{
				System.out.print("이름을 입력하세요. : ");
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
					System.out.println("해당하는 이름을 갖는 직원을 찾을 수 없습니다.");
				}
				
				else
				{
					System.out.println("");
					System.out.println("총 "+count+"명의 직원이 검색되었습니다.");
				}
	
			}
			
			else if(SearchNum == 2)
			{
				System.out.print("부서명을 입력하세요. : ");
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
					System.out.println("해당하는 이름을 갖는 부서를 찾을 수 없습니다.");
				}
				
				else
				{
					System.out.println("");
					System.out.println("총 "+count+"명의 "+depart+" 직원이 검색되었습니다.");
				}
			}
			
			else if(SearchNum == 3)
			{
				System.out.print("매니저명을 입력하세요. : ");
				
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
					System.out.println("해당하는 이름을 갖는 매니저를 찾을 수 없습니다.");
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
					System.out.println("총 "+(count-1)+"명의 "+depart+" 직원이 검색되었습니다.");
				}
			}
			
			
			
			
			
		}
		
	}
	
	public static void PrintUser(Vector v)
	{
		System.out.println(" No.   ID   이름    부서    직책");
		for(int i=0;i<v.size();i++)
		{ 
			SW_UserManagement P =  (SW_UserManagement) v.get(i);
			System.out.println(" "+(i+1)+".  "+P.toString());
		}
	}
}


