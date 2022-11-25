
public class MyPoint {
	private int x, y;
	
	public MyPoint(int x, int y) {
		this.x = x;
		this.y = y;
	}
	
	public boolean equals(Object obj) {
		MyPoint p = (MyPoint)obj;	// �ٿ�ĳ����
		return this.x == p.x && this.y == p.y;
	}
	
	public String toString() {
		return "(" + this.x + ", " + this.y + ")�� �ִ� ���Դϴ�."; 
	}
	
	public static void main(String[] args) {
		MyPoint p = new MyPoint(3, 50);
		MyPoint q = new MyPoint(4, 50);
		
		if (p.equals(q))
			System.out.println("���� ��");
		else 
			System.out.println("�ٸ� ��");
		
		System.out.println(p);
		System.out.println(q);
	}
}
