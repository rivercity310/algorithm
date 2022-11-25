import java.util.Scanner;
import java.util.Calendar;

class Player {
	private String name;
	private int t;
	private Calendar now; 
	
	public Player(String n) {
		this.name = n;
	}
	public String getName() {
		return this.name;
	}
	public void setTime(int t) {
		this.t = t;
	}
	public int getTime() {
		return this.t;
	}
	public Calendar getCalendar() {
		now = Calendar.getInstance();
		return this.now;
	}
}

public class CalendarGame {
	private static Player[] players;
	private static Scanner s;
	final private static int TEN = 10;
	
	private static void initGame() {
		s = new Scanner(System.in);
		System.out.println("10�ʿ� ����� ����� �̱�� �����Դϴ�.");
		System.out.print("���� �ο��� �Է��ϼ���: ");
		int n = s.nextInt();
		players = new Player[n];
		
		for (int i = 0; i < n; i++) {
			System.out.printf("%d��° �̸�: ", i + 1);
			String name = s.next();
			players[i] = new Player(name);
		}
		
		// �����ִ� ���๮�� ����
		s.nextLine();	
	}
	
	private static void run() {
		
		for (int i = 0; i < players.length; i++) {
			System.out.printf("%s ���� <Enter>Ű", players[i].getName());
			s.nextLine();
			int prev = players[i].getCalendar().get(Calendar.SECOND);
			System.out.printf("���� �� �ð�: %d\n", prev);
			
			System.out.print("10�� ���� �� <Enter>Ű");
			s.nextLine();
			int next = players[i].getCalendar().get(Calendar.SECOND);
			System.out.printf("���� �� �ð�: %d\n", next);
			
			players[i].setTime(next - prev);
		}
	}
	
	private static void printWinner() {
		String name = null;
		int pTime = 10;
	
		for (int i = 0; i < players.length; i++) {
			System.out.printf("%s�� ���: %d\n", players[i].getName(), players[i].getTime());
			if (Math.abs(TEN - players[i].getTime()) < pTime) {
				name = players[i].getName();
			}
		}
		
		System.out.printf("���ڴ� %s", name);
		s.close();
		
	}
	
	public static void main(String[] args) {
		initGame();
		run();
		printWinner();
	}
}
