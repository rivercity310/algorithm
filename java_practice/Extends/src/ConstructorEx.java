class A {
	private int x;
	public A() {
		System.out.println("������A");
	}
	
	public A(int x) {
		this.x = x;
	}
}

class B extends A {
	public B() {
		super(5);
		System.out.println("������B");
	}
}

class C extends B {
	public C() {
		System.out.println("������C");
	}
}

public class ConstructorEx {
	public static void main(String[] args) {
		C c = new C();
	}
}
