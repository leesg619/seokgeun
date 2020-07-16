package Boarding;
import Unit.*;

//Position �� Ŭ����.  board Ŭ�������� ����� ����
class Position {
	int x, y;
	UnitShape unit = new UnitShape(); //���� �������� �����ؾ� �ϹǷ� �ʵ弱��
	public Position(int x, int y) { //��ġ ���� ������
		this.x = x;
		this.y = y;
		unit = null;
	}
}


public class Board {   
	public Position Positions[][]  = new Position[11][11]; //Position �� ����ʵ�.
	
	public Board() {//������
		for(int i=0; i<11; i++) //��� �ε��� ��ġ���� ���� 
			for(int j=0; j<11; j++)
				this.Positions[i][j] = new Position(i, j); 
    }

 //���⼭���� �޼ҵ�
	public boolean IsEmpty(int x, int y) { //�������Ȯ�ο� �޼ҵ�
		if(Positions[x][y].unit == null) {	return true; }//��� true
		else return false; //�̹� ������ ������ false
	}

	public UnitShape getUnit(int x, int y) { //���� �ҷ����� 
		return Positions[x][y].unit;
	}
	
	public void setPosition(int x, int y ,UnitShape u) { //��ġ ����
			Positions[x][y].unit = u;
    }
	public void clear(int x, int y) { //�̵��߰ų� �׾����� ���־ߵ�.
		Positions[x][y].unit = null;
	}
	
	
	public void print_Board() { //���ϸ��� ���� ���� ��ġ��Ȳ ���
		UnitShape unit;
		int i , j;
		System.out.println("     1     2     3     4     5     6     7     8     9     10    11");
		System.out.println("--------------------------------------------------------------------");
		for(i=0;i<11;i++) {
			if(i<9) System.out.print((i+1)+"  ");//����� ����ϰ�
			else System.out.print((i+1)+" ");//ó���ϱ� ���� ���ǹ�
			
			for(j=0;j<11;j++) {
				System.out.print("[");
				if(!IsEmpty(i, j))	{ //i,j�� ���� �����ϸ�
					unit = getUnit(i, j);//�ҷ��� �Ŀ� ���� ���
					System.out.print(unit.unitCtr + unit.getName() + unit.Playernum +"] ");						
				}
				else System.out.print("   ] "); //���� ������� ����
			}
			System.out.println("\n--------------------------------------------------------------------");
		}
	}
}
