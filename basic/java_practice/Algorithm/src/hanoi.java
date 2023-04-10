import java.util.Scanner;

public class hanoi {
	private static void hanoi_tower(int n, char from, char tmp, char to) {
		if (n == 1) System.out.printf("���� 1: %c => %c �̵�\n", from, to);
		else {
			hanoi_tower(n - 1, from, to, tmp);
			System.out.printf("���� %d: %c => %c �̵�\n", n, from, to);
			hanoi_tower(n - 1, tmp, from, to);
		}
	}
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		System.out.print("���Ϸ��� ������ ����: ");
		int n = s.nextInt();
		
		System.out.printf("������ %d�� ���� �� �ϳ��� ž�� ���\n\n", n);
		hanoi_tower(n, 'A', 'B', 'C');
		
		s.close();
	}
}
