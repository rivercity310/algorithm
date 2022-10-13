import java.util.Scanner;

class Dictionary {
	private static String kor[] = {"���", "�Ʊ�", "��", "�̷�", "���"};
	private static String eng[] = {"love", "baby", "money", "future", "hope"};
	public static String kor2eng(String word) {
		for (int i = 0; i < kor.length; i++) 
			if (kor[i].equals(word))
				return eng[i];
		
		return null;
	}
}

public class DictApp {
	private static Scanner scanner = new Scanner(System.in);
	
	public static void run() {
		while (true) {
			System.out.print("�ѱ� �ܾ�?: ");
			String word = scanner.next();
			String answer = Dictionary.kor2eng(word);
			if (word.equals("�׸�")) {
				System.out.print("���α׷��� �����մϴ�...");
				scanner.close();
				return;
			}
				
			System.out.printf("%s�� %s\n", word, answer);
		}
	}
	
	public static void main(String[] args) {
		System.out.println("�ѿ� �ܾ� ���α׷��Դϴ�.");
		run();
	}
}
