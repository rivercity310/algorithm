class PersonA {
	String name;
	String id;
	
	public PersonA(String name) {
		this.name = name;
	}
}

class StudentA extends PersonA {
	String grade;
	String department;
	
	public StudentA(String name) {
		super(name);
	}
}

public class UpcastingEx {
	public static void main(String[] args) {
		PersonA p;
		StudentA s = new StudentA("Ȳ�¼�");
		p = s;	// ��ĳ����
		
		System.out.println(p.name);
		// p.grade = "A";		// ����
		// p.department = "Com"; // ����
	}
}
