import java.util.Scanner;
import java.util.Random;

public class RSP {
	public static void printWinner(String ps, String cps, String msg) {
		System.out.printf("ö��[%s] : ��ǻ��[%s]\n", ps, cps);
		System.out.println(msg);
	}
	
	public static void run(int p, int cp) {
		String ps = p == 0 ? "����" : p == 1 ? "����" : "��"; 
		String cps = cp == 0 ? "����" : cp == 1 ? "����" : "��";
		String msg = null;
		
		if (p == cp) 
			msg = "�����ϴ�.";
		else if ((p == 0 && cp == 1) || (p == 1 && cp == 2) || (p == 2 && cp == 0)) 
			msg = "��ǻ�Ͱ� �̰���ϴ�.";
		else if ((p == 0 && cp == 2) || (p == 1 && cp == 0) || (p == 2 && cp == 1)) 
			msg = "ö���� �̰���ϴ�.";
		
		printWinner(ps, cps, msg);
	}
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		Random r = new Random();
		
		while (true) {
			System.out.print("ö�� [����(0), ����(1), ��(2), ������(3)] >> ");
			int picked = s.nextInt();
			int comPicked = r.nextInt(3);
			
			if (picked == 3) {
				System.out.println("���α׷� ����");
				s.close();
				return;
			}
			
			run(picked, comPicked);
		}
	}
}
