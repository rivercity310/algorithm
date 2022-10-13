import java.util.Vector;
import java.util.Scanner;

class Person {
	private String name;
	private String number;
	
	public Person(String name, String num) {
		this.name = name;
		this.number = num;
	}
	
	public String getNumber() {
		return this.number;
	}
	
	public String getName() {
		return this.name;
	}
}


interface Phone {
	public abstract void sendSMS(String msg);
	public abstract void call(Person p);
	public abstract void playMusic();
	public abstract void stopMusic();
	
	public default void printLogo() {
		System.out.println("Phone");
	}
}

class SamsungPhone implements Phone {
	private Person[] p;
	private Vector<Person> v;
	private Scanner s;
	
	public SamsungPhone() {
		p = new Person[5];
		s = new Scanner(System.in);
		v = new Vector<Person>();
	}
	
	public Vector<Person> getPersonVector() {
		return this.v;
	}
	
	public void initPerson() {
		for (int i = 0; i < 5; i++) {
			System.out.print("�̸�: ");
			String name = s.next();
			System.out.print("��ȣ: ");
			String number = s.next();
			
			p[i] = new Person(name, number);
			v.add(p[i]);
		}
	}
	
	@Override
	public void sendSMS(String msg) {
		System.out.println(msg);
		System.out.println("������ �Ϸ�Ǿ����ϴ�.");
	}
	
	@Override
	public void call(Person p) {
		System.out.println("�߽�: " + p.getName());
		System.out.println(p.getNumber() + "�� ��ȭ�մϴ�.");
	}
	
	@Override
	public void playMusic() {
		System.out.println("������ ����մϴ�.");
	}
	
	@Override
	public void stopMusic() {
		System.out.println("����� ����ϴ�.");
	}
}

public class Example {
	private void run() {
		var myPhone = new SamsungPhone();
		myPhone.initPerson();
		var v = myPhone.getPersonVector();
		for (int i = 0; i < 5; i++) {
			System.out.println("\n-----------------------------");
			myPhone.printLogo();
			System.out.println(v.get(i).getName());
			System.out.println(v.get(i).getNumber());
			myPhone.sendSMS("hi");
			myPhone.call(v.get(i));
			myPhone.playMusic();
			myPhone.stopMusic();
			System.out.println("-------------------------------\n");
		}
	}
	
	public static void main(String[] args) {
		Example app = new Example();
		app.run();
	}
}
