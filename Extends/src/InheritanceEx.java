
class Person {
	private int weight;		// private ���� ����
	int age;				// ����Ʈ ���� ����
	protected int height;	// protected ���� ����
	public String name;		// public ���� ����
	
	// private ����� weight�� �����ϱ� ���� get/set �޼���
	public void setWeight(int weight) {
		this.weight = weight;
	}
	
	public int getWeight() {
		return this.weight;
	}
}

class Student extends Person {
	public void set() {
		age = 30;
		name = "ȫ�浿";
		height = 175;
		// weight = 99;	  ���� �Ұ� ����
		setWeight(99);
	}
}


public class InheritanceEx {
	public static void main(String[] args) {
		Student s = new Student();
		s.set();
	}
}
