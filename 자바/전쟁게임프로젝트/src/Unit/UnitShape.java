package Unit;

public class UnitShape{
	public int hp;//ü�� ������ ��� �ٲ� public����
	public int Playernum; //ù��°�÷��̾�����, �ι�°����
	public char unitCtr; //������ ����
	
	String unitname;//�����̸�
	int power;//���ݷ�
	int MoveRange;//�̵�����
	int MoveDirection;//�̵����� 
	int AttackRange;//���ݹ���
	int AttackDirection;//���ݹ���

	/*������ 0 , 4, 8 �������� �������ִµ�, 0�� 0����,
	 4�� ��������4����, 8�� �밢������ 8����*/
	
	public String getName(){
		return unitname;
	}
	
	public int getPower() {
		return power;
	}
	
	public void showInform() {//�� �� �ִ� ���� , ���ݹ��� ǥ������
		System.out.println("MoveRange: ["+MoveRange+"] MoveDirection: ["+MoveDirection+"]");
		System.out.println("AttackRange: ["+AttackRange+"] AttackDirection: ["+AttackDirection+"]");
	}
	
	public boolean isDead() { //�׾�����
		if(hp<=0) return true;
		else return false;
	}
	
}
