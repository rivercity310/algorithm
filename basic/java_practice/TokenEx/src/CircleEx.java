
public class CircleEx {
	private int x, y, r;
	
	public CircleEx(int x, int y, int r) {
		this.x = x;
		this.y = y;
		this.r = r;
	}
	
	public boolean equals(Object obj) {
		CircleEx c = (CircleEx)obj;
		return this.x == c.x && this.y == c.y;
	}
	
	public static void main(String[] args) {
		CircleEx a = new CircleEx(1, 2, 3);
		CircleEx b = new CircleEx(1, 2, 5);
		
		System.out.println(a == b);			// false: == �����ڴ� ���۷����� ��
		System.out.println(a.equals(b));	// true: equals() �޼ҵ带 �������̵��Ͽ� ����� ���� ��
	}
}
