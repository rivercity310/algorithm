class Parents {
	public Parents(String name) {
		System.out.println(name);
	}
	
	public void say() {
		System.out.println("�ȳ��ϼ��� Parents�Դϴ�.");
	}
}

class Son extends Parents {
	public Son(String name) {
		super(name);
	}
	
	public void say() {
		System.out.println("�ȳ��ϼ��� Son�Դϴ�.");
	}
	
	public void hello() {
		System.out.println("hello");
	}
}

class Daughter extends Parents {
	public Daughter(String name) {
		super(name);
	}
	
	public void say() {
		System.out.println("�ȳ��ϼ��� Daughter�Դϴ�.");
	}
	
	public void good() {
		System.out.println("good");
	}
}

public class Application {
	static void print(Parents p) {
		if (p instanceof Parents)
			System.out.println("Parents ");
		if (p instanceof Son)
			System.out.println("Son");
		if (p instanceof Daughter)
			System.out.println("Daughter");
	}
	
	public static void main(String[] args) {
		// ��üȭ
		Parents p = new Parents("�ƺ�");
		Son s = new Son("�Ƶ�");
		Daughter d = new Daughter("��");
		System.out.println();
		
		
		
		// ��ĳ����
		Parents p1 = (Parents)s;
		p1.say();
		print(p1);	// Parents Son
		System.out.println();
		
		Parents p2 = (Parents)d;
		p2.say();
		print(p2);	// Parents Daughter
		System.out.println();
		
		
		
		// �ٿ�ĳ����
		Son s1 = (Son)p1;
		s1.hello();
		print(s1);	// Parents Son
		System.out.println();
		
		Daughter d1 = (Daughter)p2;
		d1.good();
		print(d1);	// Parents Daughter
	}
}