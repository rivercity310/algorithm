package Generic;

// Scanner Ŭ������ -1�� �Էµ� ������ ���� ������ �Է¹޾� ���Ϳ� �����ϰ�
// ���͸� �˻��Ͽ� ���� ū ���� ����ϴ� ���α׷� �ۼ�

import java.util.Scanner;
import java.util.Vector;

public class TrainingEx1 {
	public static void main(String[] args) {
		var s = new Scanner(System.in);
		var v = new Vector<Integer>();
		
		System.out.print("����: ");
		while (true) {
			int input = s.nextInt();
			v.add(input);
			
			if (v.lastElement() == -1) {
				int max = 0;
				for (int i = 0; i < v.size(); i++)
					if (v.get(i) > max) max = v.get(i);
				
				System.out.printf("���� ū ����: %d", max);
				s.close();
				break;
			}
		} 
	}
}
