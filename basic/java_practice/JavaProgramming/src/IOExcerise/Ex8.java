package IOExcerise;

import java.io.*;
import java.util.Scanner;
import java.util.Vector;

// Ex1���� ������ Person ��ü ���
public class Ex8 {
	private Vector<Person> v;
	private Scanner s;

	public Ex8() {
		s = new Scanner(System.in);
		v = new Vector<Person>();
	}
	
	private void run() {
		String path = "C:\\Temp\\phone8079.txt";
		File f = new File(path);
		
		try {
			Scanner sf = new Scanner(new FileReader(f));
			while (sf.hasNext()) {
				String[] info = sf.nextLine().split(" ");
				v.add(new Person(info[0], info[1]));
			}
			sf.close();
		} catch (Exception e) {
			System.out.println(e);
		}
		
		System.out.printf("�� %d���� ��ȭ��ȣ�� �о����ϴ�.\n", v.size());
		while (true) {
			String res = null;

			System.out.print("�̸�: ");
			String name = s.next();
			if (name.equals("stop")) {
				System.out.println("���α׷��� �����մϴ�.");
				s.close();
				break;
			}
			
			for (int i = 0; i < v.size(); i++) {
				Person obj = v.get(i);
				if (name.equals(obj.getName())) 
					res = obj.getNumber();
			}
			
			if (res == null) System.out.println("ã�� �̸��� �����ϴ�.");
			else System.out.println(res);
		}
	}
	
	public static void main(String[] args) {
		var app = new Ex8();
		app.run();
	}
}
