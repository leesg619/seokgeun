package Boarding;
import java.util.Random;
import Unit.*;

public class createGame {//Board 클래스를 베이스로 한국 or 일본 진영 만들기
	Random random = new Random();
	Board myBoard;

	public createGame(Board board) {myBoard = board;} //생성자
	
	public void makingK(int Playernum,K kK, A kA[], I kI[],C kC[]) { //한국 문명 유닛 판에 랜덤배치하는 메소드
		Civilization civil = new Korea();
		int toAdd=0; // Player1 또는 2 에 따라 다른 값으로 초기화 후 랜덤 클래스 사용.
		if (Playernum == 1) {
			toAdd = 0;
			myBoard.setPosition(5, 0, kK); //king 생성
		}
	
		if (Playernum == 2) {
			toAdd= 6;
			myBoard.setPosition(5, 10, kK); //king 생성
		}
		
		int x, y;
		
		for(int i=0;i<civil.getA() ;i++) {
			kA[i] = new A(Playernum,'k');
			while(true) {
				x = random.nextInt(11);
				y = random.nextInt(4)+toAdd;
				if(myBoard.IsEmpty(x, y)) {
					myBoard.setPosition(x, y, kA[i]);
					break;
				}
			}
		}
		for(int i=0;i<civil.getI();i++) {
			kI[i] = new I(Playernum,'k');
			while(true) {
				x = random.nextInt(11);
				y = random.nextInt(4)+toAdd;
				if(myBoard.IsEmpty(x, y)) {
					myBoard.setPosition(x, y, kI[i]);
					break;
				}
			}
		}
		for(int i=0;i<civil.getC();i++) {
			kC[i] = new C(Playernum,'k');
			while(true) {
				x = random.nextInt(11);
				y = random.nextInt(4)+toAdd;
				if(myBoard.IsEmpty(x, y)) {
					myBoard.setPosition(x, y, kC[i]);
					break;
				}
			}
		}
		
	}
	public void makingJ(int Playernum, K jK, A jA[] , I jI[], C jC[]) { //일본 문명 유닛 랜덤배치하는 메소드
		Civilization civil=new Japan();
		int toAdd=0;
		if (Playernum == 1) {
			toAdd = 0;
			myBoard.setPosition(5, 0, jK); //king 자리고정
		}
	
		if (Playernum == 2) {
			toAdd= 6;
			myBoard.setPosition(5, 10, jK); //king 자리고정
		}
		int x,y;
		
		for(int i=0;i<civil.getA() ;i++) {
			jA[i] = new A(Playernum,'j');
			while(true) {
				x = random.nextInt(11);
				y = random.nextInt(4)+toAdd;
				if(myBoard.IsEmpty(x, y)) {
					myBoard.setPosition(x, y, jA[i]);
					break;
				}
			}
		}
		for(int i=0;i<civil.getC() ;i++) {
			jC[i] = new C(Playernum,'j');
			while(true) {
				x = random.nextInt(11);
				y = random.nextInt(4)+toAdd;
				if(myBoard.IsEmpty(x, y)) {
					myBoard.setPosition(x, y, jC[i]);
					break;
				}
			}
		}
		for(int i=0;i<civil.getI() ;i++) {
			jI[i] = new I(Playernum,'j');
			while(true) {
				x = random.nextInt(11);
				y = random.nextInt(4)+toAdd;
				if(myBoard.IsEmpty(x, y)) {
					myBoard.setPosition(x, y, jI[i]);
					break;
				}
			}
		}
		
	}
}
