package Generic;

// Vector �÷����� �̿��Ͽ� �������� ����� ���� �����ϴ� ���α׷� �ۼ�
// �������� �Է��ϸ� ���Ϳ� �߰��ϰ� ���� �Էµ� ��� �������� ����� ����Ѵ�.

import java.util.Scanner;
import java.util.Vector;

public class TrainingEx4 {
	public static void main(String[] args) {
		var s = new Scanner(System.in);
		var v = new Vector<Integer>();
		
		while (true) {
			System.out.print("������ �Է�: ");
			int rain = s.nextInt();
			if (rain == 0) {
				s.close();
				return;
			}
			v.add(rain);
			
			double aver = 0;
			for (int i = 0; i < v.size(); i++) {
				aver += v.get(i);
				System.out.print(v.get(i) + " ");
			}
			System.out.println();
			System.out.printf("���� ���: %.2f\n\n", aver/v.size());
		}
	}
}
