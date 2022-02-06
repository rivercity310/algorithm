package IOExcerise;

import java.util.Scanner;
import java.io.*;

public class Ex10 {
	private StringBuffer sb;
	private Scanner s;
	
	public Ex10() {
		sb = new StringBuffer();
		s = new Scanner(System.in);
	}
	
	private String getPath(String path) {
		String[] pref = {"C:\\", "c:\\", "c:/", "C:/"};
		String defaultPath = "C:\\Users\\h9701\\eclipse-workspace\\JavaProgramming\\src\\IOExcerise\\";

		boolean StartedWithPref = false;
		for (String k : pref) 
			if (path.startsWith(k))
				StartedWithPref = true;
		
		return StartedWithPref ? path : defaultPath.concat(path);
	}
	
	private boolean readFile() {
		System.out.print("��� ���ϸ� �Է�: ");
		String path = getPath(s.next());
		System.out.printf("%s�� �˻��մϴ�...\n", path);
		
		try {
			Scanner sf = new Scanner(new FileInputStream(path));
			while (sf.hasNext())
				sb.append(sf.nextLine() + "\n");
			
			// �����ִ� ���� ����
			s.nextLine();
			sf.close();
		} catch (Exception e) {
			System.out.println(e);
			return false;
		}
		
		return true;
	}
	
	private void run() {
		while (true) {
			System.out.print("�˻��� �ܾ ����: ");
			String input = s.nextLine();
			if (input.equals("�׸�")) {
				s.close();
				System.out.println("���α׷��� �����մϴ�.");
				return;
			}
			
			String[] strAry = sb.toString().split("\n");
			for (String k : strAry) 
				if (k.contains(input))
					System.out.println(k);
			
		}
	}
	
	public static void main(String[] args) {
		var app = new Ex10();
		if (app.readFile()) app.run();
	}
}
