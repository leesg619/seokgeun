package Playgame;
import java.util.Scanner;
import Unit.*;
import Boarding.*;

public class KingGame {
	Scanner input = new Scanner(System.in);
	
	
	public static void main(String[] args) {
		Korea korea = new Korea();
		Japan japan= new Japan();
		Board myBoard = new Board();
		createGame creategame = new createGame(myBoard);
		KingGame game = new KingGame();
		
		int firstplayer ; //1 : 한국 2: 일본
		int secondplayer ;  //1: 한국 2: 일본
		int turn=1; //플레이어 1, 2 차례로 돌아가면서 하는변수
		
		K K1=null,K2=null;
		A A1[],A2[];
		I I1[],I2[];
		C C1[],C2[];
		//뒤에 1 이 붙은건 player1이 쓸 변수, 2이 붙은 건 player2이 쓸 변수
		firstplayer=game.SelectCivil(1); //사용자에게 문명 1 또는 2를 받는다.
			
		if (firstplayer==1){
			K1 = new K(1,'k'); 
			A1= new A[korea.getA()];
			I1= new I[korea.getI()];
			C1= new C[korea.getC()];
			creategame.makingK(1,K1, A1, I1, C1);
		}
		if (firstplayer==2){
			K1 = new K(1,'j'); 
			A1= new A[japan.getA()];
			I1= new I[japan.getI()];
			C1= new C[japan.getC()];
			creategame.makingJ(1,K1, A1, I1, C1);
		}
		//player1 생성완료
		secondplayer = game.SelectCivil(2);

		if (secondplayer==1){
			K2 = new K(2,'k'); 
			A2= new A[korea.getA()];
			I2= new I[korea.getI()];
			C2= new C[korea.getC()];
			creategame.makingK(2,K2, A2, I2, C2); /////오류
		}
		if (secondplayer==2){
			K2 = new K(2,'j'); 
			A2= new A[japan.getA()];
			I2= new I[japan.getI()];
			C2= new C[japan.getC()];
			creategame.makingJ(2,K2, A2, I2, C2);
		}
		//player2 생성완료
		
			while(true) {
				myBoard.print_Board();
				if(turn==1) {
					game.DoTurn(turn,myBoard);
					if(K2.isDead()) {
						System.out.println("Player["+turn+"] Win!");
						break;}
					turn = 2;
				}
				else {
					game.DoTurn(turn, myBoard);
					if(K1.isDead()) {
						System.out.println("Player["+turn+"] Win!");
						break;}
					turn = 1;
				}
			}
			
		System.out.println("The game is over");
		//while 루프문 탈출하면 main method는 종료
	}

	
	
	void DoTurn(int turn, Board myBoard) { //턴을 주고받는 메소드
			int option;
			System.out.println("Player"+turn+"'s turn");
			System.out.println("1. Move my unit");
			System.out.println("2. Attack enemy");
			System.out.println("3. Change Turn");
			System.out.print(">>>");
			option = input.nextInt();
			
			switch(option) {
			case 1:
				MoveUnit(myBoard);
				break;
			case 2:
				AttackUnit(myBoard);
				break;
			case 3:
				System.out.println("You Choose [3. Change Turn] .");
				break;
			}
		
	}
	public void MoveUnit(Board myBoard) { //1번 메뉴 이동
		int x,y,toX,toY;
		UnitShape myunit=null;
		
		System.out.println("You Choose [1. Move my unit]");
		System.out.println("Input the Location Of your Unit.");
		System.out.print("x >>>");
			x = input.nextInt();
			x=x-1;
		System.out.print("y >>>");
			y = input.nextInt();
			y=y-1;
		myunit = myBoard.getUnit(x, y); //판에서 내 유닛을 불러옴
		System.out.println("you choose "+ myunit.getName()+ myunit.Playernum);
		myunit.showInform(); //내 유닛 정보출력

		System.out.println("Input the Location you want to go."); //이동하고 싶은 곳 입력
		System.out.print("x >>>");
		toX = input.nextInt();
		toX = toX-1;
		System.out.print("y >>>");
		toY = input.nextInt();
		toY = toY-1;
		System.out.println(myunit.unitCtr+myunit.getName()+myunit.Playernum+ "is located ("+ (x+1)+","+(y+1)+ ") --> "+(toX+1)+","+(toY+1)+")");
		myBoard.setPosition(toX, toY, myunit);//새로 이동할 곳에 배치
		myBoard.clear(x, y); //전에 있던 자리는 없애줌
		
	}
	
	public void AttackUnit(Board myBoard) {
		int x,y,toX,toY;
		UnitShape myunit=null , enemy=null;
		System.out.println("You Choose [2. Attack Enemy]");
		System.out.println("Input the Location Of your Unit."); //내유닛 지정
		System.out.print("x >>>");
		x = input.nextInt();
		x=x-1;
		System.out.print("y >>>");
		y = input.nextInt();
		y=y-1;
		myunit = myBoard.getUnit(x, y); 
		System.out.println("you choose "+ myunit.getName()+ myunit.Playernum);
		myunit.showInform();
		//내유닛 선택완료
		System.out.println("Input the Location Of Enemy's Unit."); //상대 유닛을 선택하게 함
		System.out.print("x >>>");
		toX = input.nextInt();
		toX = toX-1;
		System.out.print("y >>>");
		toY = input.nextInt();
		toY = toY-1;
		enemy = myBoard.getUnit(toX, toY);
		System.out.println("you choose "+ enemy.getName()+ enemy.Playernum);
		System.out.println(myunit.unitCtr+myunit.getName()+myunit.Playernum+" 's power : ["+myunit.getPower()+"] ");
		System.out.println("The Unit on ( "+(toX+1)+","+(toY+1)+") is attacked.");
		enemy.hp-=myunit.getPower();
		System.out.println("remain hp : "+enemy.hp); //적 유닛의 남은 h.p출력
		
		if(enemy.isDead()) { //상대 유닛 죽었으면
			System.out.println(" Attacked Unit is dead.");
			myBoard.clear(toX, toY);
		}
	}
	int SelectCivil(int player) { //문명 1 or 2를 고르는 메소드
		int option;
		System.out.println("Select Player"+(player)+"'s Civilization");
		System.out.println("1. Korean\t2. Japanese");
		System.out.print(">>>>");
		option = input.nextInt();
		if(option == 1) {
			System.out.println("You choose Korean");
			return 1;
		}
		else {
			System.out.println("You choose Japan");
			return 2;
		}
	}


}