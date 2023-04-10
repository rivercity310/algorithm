class PersonD {
	String name;
	String id;
	
	public PersonD(String name) {
		this.name = name;
	}
}

class StudentD extends PersonD {
	String grade;
	String department;
	
	public StudentD(String name) {
		super(name);
	}
}


public class DowncastingEx {
	public static void main(String[] args) {
		// StudentD ��ü�� PersonD Ÿ������ ��ĳ����
		PersonD p = new StudentD("Ȳ�¼�");
		
		// PersonD Ÿ���� p�� StudentD Ÿ������ ��ȯ: �ٿ�ĳ����
		StudentD s = (StudentD)p;	
		
		System.out.println(s.name);
		s.grade = "A";
		s.department = "Com";
	}
}
