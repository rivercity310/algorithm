import java.util.Scanner;
import java.util.InputMismatchException;

public class CircleManager {
	private static Circle[] setCircleInfo() {
		Scanner scanner = new Scanner(System.in);
		System.out.print("�迭 ��� �����ұ��? ");
		int length = scanner.nextInt();
		Circle c[] = new Circle[length];
		
		for (int i = 0; i < c.length; i++) {
			System.out.print("x, y, radius�� ������� �Է��Ͻÿ�: ");
			try {
				int x = scanner.nextInt();
				int y = scanner.nextInt();
				int radius = scanner.nextInt();
				c[i] = new Circle(x, y, radius);
			} catch (InputMismatchException e) {
				System.out.println("�߸��� �Է��Դϴ�! ������ �Է��ϼ���.");
				scanner.nextLine();
				i--;
				continue;
			} 
		}
		
		scanner.close();
		
		return c;
	}
	
	private static void printCircleInfo(Circle c[]) {
		System.out.println("\n\n��ü �迭 �ȿ� �ִ� ��ü ������ ����մϴ�.");
		for (int i = 0; i < c.length; i++) {
			System.out.printf("c[%d] >> ", i);
			c[i].show();
		}
		
		System.out.print("���� ū ���� ���̴�: ");
		double maxCircle = c[0].getArea();
		for (int i = 0; i < c.length; i++) {
			if (maxCircle < c[i].getArea()) 
				maxCircle = c[i].getArea();
		}
		System.out.printf("%.2f", maxCircle);
	}
	
	public static void main(String[] args) {
		Circle c[] = setCircleInfo();
		printCircleInfo(c);
		
	}
}


class Circle {
	private int x, y, radius;
	
	public Circle(int x, int y, int radius) {
		this.x = x;
		this.y = y;
		this.radius = radius;
	}
	
	public void show() {
		System.out.printf("��ǥ: (%d, %d), ������: %d\n", x, y, radius);
	}
	
	public double getArea() {
		return Math.pow(this.radius, 2) * Math.PI; 
	}
}