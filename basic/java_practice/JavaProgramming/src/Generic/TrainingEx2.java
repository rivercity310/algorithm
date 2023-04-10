package Generic;

// Scanner Ŭ������ ����Ͽ� 6���� ������ ���ڷ� �Է¹޾� ArrayList�� �����ϰ�
// ArrayList�� �˻��Ͽ� ������ ������ ��ȯ�Ͽ� ����� ����ϱ�

import java.util.Scanner;
import java.util.ArrayList;

public class TrainingEx2 {
	public static void main(String[] args) {
		var s = new Scanner(System.in);
		var a = new ArrayList<String>();
		
		System.out.print("6���� ���� �Է�: ");
		for (int i = 0; i < 6; i++) {
			String grade = s.next();
			a.add(i, grade.toUpperCase());
		}
		
		double sum = 0;
		for (String k : a) {
			switch (k) {
			case "A": sum += 4.0; break;
			case "B": sum += 3.0; break;
			case "C": sum += 2.0; break;
			case "D": sum += 1.0; break;
			case "F": break;
			}
		}
		
		System.out.printf("��� ����: %.2f", sum / a.size());
		s.close();	
	}
}