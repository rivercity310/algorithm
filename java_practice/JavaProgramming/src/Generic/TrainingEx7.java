package Generic;

import java.util.Scanner;
import java.util.HashMap;

public class TrainingEx7 {
	private void run() {
		var s = new Scanner(System.in);
		var h = new HashMap<String, Double>();
		
		System.out.println("���б� ���� �ý����Դϴ�.");
		
		for (int i = 0; i < 5; i++) {
			System.out.print("�̸��� ����: ");
			String name = s.next();
			double grade = s.nextDouble();
			h.put(name, grade);
		}
		
		System.out.print("���л� ���� ���� ����: ");
		double limit = s.nextDouble();
		
		var keys = h.keySet();
		var it = keys.iterator();
		while (it.hasNext()) {
			String n = it.next();
			if (h.get(n) >= limit) {
				System.out.printf("%s ", n);
			}
		}
		
		s.close();
	}
	
	public static void main(String[] args) {
		var app = new TrainingEx7();
		app.run();
	}
}
