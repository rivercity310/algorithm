package Generic;

// "�׸�"�� �Էµ� ������ ���� �̸��� �α��� �Է¹޾� �����ϰ�
// �ٽ� ���� �̸��� �Է��ϸ� �ش� ������ �α��� ����϶�

import java.util.Scanner;
import java.util.HashMap;

public class TrainingEx3 {
	public static void main(String[] args) {
		var h = new HashMap<String, Integer>();
		var s = new Scanner(System.in);
		
		System.out.println("���� �̸��� �α��� �Է��ϼ���");
		while (true) {
			System.out.print("���� �̸�, �α�: ");
			String country = s.next();
			if (country.equals("�׸�")) break;
			int population = s.nextInt();
			h.put(country.toUpperCase(), population);
		}
		
		while (true) {
			try {
				System.out.print("�α� �˻�: ");
				String country = s.next();
				if (country.equals("�׸�")) {
					s.close();
					return;
				}
				
				int pop = h.get(country.toUpperCase());
				System.out.printf("%s�� �α��� %d\n", country, pop);
			} catch(NullPointerException e) {
				System.out.println("�ش� ������ ��ϵǾ� ���� �ʽ��ϴ�.");
			}
		}
	}
}
