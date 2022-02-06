import java.util.*;

class Student {
	private int id;
	private String tel;
	
	public Student(int id, String tel) {
		this.id = id;
		this.tel = tel;
	}
	public int getId() {
		return this.id;
	}
	public String getTel() {
		return this.tel;
	}
}

public class HashMapStudentEx {
	public static void main(String[] args) {
		var s = new Scanner(System.in);
		var map = new HashMap<String, Student>();
		map.put("Ȳ�¼�", new Student(1, "010-0000-0000"));
		map.put("�����", new Student(2, "010-1050-0601"));
		map.put("���ֿ�", new Student(3, "010-2030-0902"));
		
		while (true) {
			System.out.print("�˻��� �̸�: ");
			String name = s.nextLine();
			if (name.equals("exit")) {
				System.out.println("���α׷� ����....");
				s.close();
				return;
			}
			
			if (name.equals("showAllStudents")) {
				var keys = map.keySet(); 	    // Set<String> keys�� ����
				var it = keys.iterator(); 		// Iterator<String> it�� ����
				
				while (it.hasNext()) {
					String studentName = it.next();
					Student st = map.get(studentName);
					System.out.printf("�̸�: %s, ID: %d, TEL: %s\n", studentName, st.getId(), st.getTel());
				}
				
				continue;
			}
			
			var student = map.get(name);		// Student student�� ����
			if (student == null)
				System.out.println(name + "��/�� ���� ����Դϴ�.");
			else 
				System.out.printf("ID: %d, TEL: %s\n", student.getId(), student.getTel());
		}
	}
}
