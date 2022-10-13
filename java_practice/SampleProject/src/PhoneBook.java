import java.util.Scanner;

class Phone {
	private String name;
	private String tel;
	
	public Phone(String name, String tel) {
		this.name = name;
		this.tel = tel;
	}
	
	public String getName() {
		return this.name;
	}
	
	public String getTel() {
		return this.tel;
	}
}

public class PhoneBook {
	private static Phone[] phone;
	private static Scanner scanner = new Scanner(System.in);
	
	public static void init() {
		System.out.print("�ο� ��: ");
		int num = scanner.nextInt();
		phone = new Phone[num];
		for (int i = 0; i < phone.length; i++) {
			System.out.print("�̸��� ��ȭ��ȣ�� �Է��ϼ��� (�������� ����): ");
			String name = scanner.next();
			String tel = scanner.next();
			phone[i] = new Phone(name, tel);
		}
		
		System.out.println("���������� ����Ǿ����ϴ�....\n");
	}
	
	public static String search(String name) {
		for (int i = 0; i < phone.length; i++) 
			if (phone[i].getName().equals(name)) {
				return phone[i].getTel();
			}
		return null;
	}
	
	public static void main(String[] args) {
		init();
		
		while (true) {
			System.out.print("�˻��� �̸�: ");
			String name = scanner.next();
			if (name.equals("�׸�"))
				break;
			 
			System.out.printf("%s�� ��ȭ��ȣ�� %s�Դϴ�.\n", name, search(name));
		}
	}
}
