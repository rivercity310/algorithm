import java.util.Scanner;

public class JSP {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("�̸�: ");
		String name = scanner.next();
		System.out.println("�̸���: " + name);
		
		scanner.close();
	}
}
