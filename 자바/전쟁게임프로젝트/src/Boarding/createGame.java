package Boarding;
import java.util.Random;
import Unit.*;

public class createGame {//Board Ŭ������ ���̽��� �ѱ� or �Ϻ� ���� �����
	Random random = new Random();
	Board myBoard;

	public createGame(Board board) {myBoard = board;} //������
	
	public void makingK(int Playernum,K kK, A kA[], I kI[],C kC[]) { //�ѱ� ���� ���� �ǿ� ������ġ�ϴ� �޼ҵ�
		Civilization civil = new Korea();
		int toAdd=0; // Player1 �Ǵ� 2 �� ���� �ٸ� ������ �ʱ�ȭ �� ���� Ŭ���� ���.
		if (Playernum == 1) {
			toAdd = 0;
			myBoard.setPosition(5, 0, kK); //king ����
		}
	
		if (Playernum == 2) {
			toAdd= 6;
			myBoard.setPosition(5, 10, kK); //king ����
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
	public void makingJ(int Playernum, K jK, A jA[] , I jI[], C jC[]) { //�Ϻ� ���� ���� ������ġ�ϴ� �޼ҵ�
		Civilization civil=new Japan();
		int toAdd=0;
		if (Playernum == 1) {
			toAdd = 0;
			myBoard.setPosition(5, 0, jK); //king �ڸ�����
		}
	
		if (Playernum == 2) {
			toAdd= 6;
			myBoard.setPosition(5, 10, jK); //king �ڸ�����
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
