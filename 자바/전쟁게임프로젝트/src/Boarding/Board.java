package Boarding;
import Unit.*;

//Position 형 클래스.  board 클래스에서 사용할 예정
class Position {
	int x, y;
	UnitShape unit = new UnitShape(); //유닛 정보까지 저장해야 하므로 필드선언
	public Position(int x, int y) { //위치 정보 생성자
		this.x = x;
		this.y = y;
		unit = null;
	}
}


public class Board {   
	public Position Positions[][]  = new Position[11][11]; //Position 형 멤버필드.
	
	public Board() {//생성자
		for(int i=0; i<11; i++) //모든 인덱스 위치정보 생성 
			for(int j=0; j<11; j++)
				this.Positions[i][j] = new Position(i, j); 
    }

 //여기서부터 메소드
	public boolean IsEmpty(int x, int y) { //비었는지확인용 메소드
		if(Positions[x][y].unit == null) {	return true; }//비면 true
		else return false; //이미 유닛이 있으면 false
	}

	public UnitShape getUnit(int x, int y) { //유닛 불러오기 
		return Positions[x][y].unit;
	}
	
	public void setPosition(int x, int y ,UnitShape u) { //위치 지정
			Positions[x][y].unit = u;
    }
	public void clear(int x, int y) { //이동했거나 죽었을시 없애야됨.
		Positions[x][y].unit = null;
	}
	
	
	public void print_Board() { //매턴마다 현재 판의 위치상황 출력
		UnitShape unit;
		int i , j;
		System.out.println("     1     2     3     4     5     6     7     8     9     10    11");
		System.out.println("--------------------------------------------------------------------");
		for(i=0;i<11;i++) {
			if(i<9) System.out.print((i+1)+"  ");//출력을 깔끔하게
			else System.out.print((i+1)+" ");//처리하기 위한 조건문
			
			for(j=0;j<11;j++) {
				System.out.print("[");
				if(!IsEmpty(i, j))	{ //i,j에 유닛 존재하면
					unit = getUnit(i, j);//불러온 후에 정보 출력
					System.out.print(unit.unitCtr + unit.getName() + unit.Playernum +"] ");						
				}
				else System.out.print("   ] "); //유닛 비었으면 공백
			}
			System.out.println("\n--------------------------------------------------------------------");
		}
	}
}
