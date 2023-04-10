class Rect {
	private int width, height;
	public Rect(int w, int h) {
		this.width = w;
		this.height = h;
	}
	
	// ����(w x h)�� ������ �� Rect ��ü�� ���� ������ �Ǵ��ϴ� equals() �޼ҵ� �������̵� �ϱ� 
	public boolean equals(Object obj) {
		Rect r = (Rect)obj;
		if (width * height == r.width * r.height) return true;
		else return false;
	}
}

public class ObjectPropertyEx {
	public static void main(String[] args) {
		Rect a = new Rect(2, 5);
		Rect b = new Rect(1, 10);
		
		System.out.println(a.equals(b)); 	// true
	}	
}
