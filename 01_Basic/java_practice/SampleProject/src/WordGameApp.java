import java.util.Scanner;

class Player {
	private String name;
	
	public void setName(String name) {
		this.name = name;
	}
	
	public String getName() {
		return this.name;
	}
}


public class WordGameApp {
	private static Scanner scanner = new Scanner(System.in);
	private static Player[] players;
	
	private static void run() {
		System.out.println("�����ձ� ������ �����մϴ�.");
		System.out.print("���ӿ� �����ϴ� �ο��� ����ΰ���? ");
		int playerNumber = scanner.nextInt();
		
		players = new Player[playerNumber];
		for (int i = 0; i < playerNumber; i++) {
			players[i] = new Player();
			System.out.printf("%d��° �������� �̸��� �Է��ϼ���: ", i + 1);
			String name = scanner.next();
			players[i].setName(name);
		}
		
		int i = 0;
		String word1 = "�ƹ���";
		System.out.printf("���� �ܾ�� \"%s\"�Դϴ�.\n", word1);
		while (true) {
			if (i >= playerNumber) i = 0;
			System.out.printf("%s >> ", players[i].getName());
			int word1LastIndex = word1.length() - 1;
			char word1LastChar = word1.charAt(word1LastIndex);
			
			String word2 = scanner.next();
			char word2FirstChar = word2.charAt(0);
			
			if (word1LastChar != word2FirstChar) {
				System.out.printf("%s��/�� �����ϴ�.\n", players[i].getName());
				scanner.close();
				return;
			}
			
			word1 = word2;
			i++;
		}
		
		
	}
	
	public static void main(String[] args) {
		run();
	}
}
