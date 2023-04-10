package Generic;

import java.util.Scanner;
import java.util.Vector;
import java.util.Random;
import java.util.ArrayList;

class Nation {
	private String country;
	private String capital;
	
	public Nation(String cou, String cap) {
		this.country = cou;
		this.capital = cap;
	}
	
	public String getCountry() {
		return this.country;
	}
	
	public String getCapital() {
		return this.capital;
	}
}

public class TrainingEx11 {
	private Vector<Nation> v;
	private ArrayList<Integer> a;
	private Scanner s;
	private Random r;
	
	public TrainingEx11() {
		v = new Vector<>();
		a = new ArrayList<>();
		s = new Scanner(System.in);
		r = new Random();
	}
	
	private void printError(Exception e) {
		System.out.println("\n" + e + "\n");
	}
	
	private void input() {
		System.out.printf("���� %d�� ����� ������ �ԷµǾ��ֽ��ϴ�.\n", v.size());
		while (true) {
			System.out.print("����� ���� �Է�: ");
			String country = s.next();
			if (country.equals("stop")) return;
			String capital = s.next();
			boolean duplicationCheck = false;
			for (int i = 0; i < v.size(); i++) {
				if (v.get(i).getCountry().equals(country)) {
					System.out.printf("%s�� �̹� �ֽ��ϴ�!\n", v.get(i).getCountry());
					duplicationCheck = true;
				}
			}
			
			if (duplicationCheck) continue;
			else v.add(new Nation(country, capital));
			
		}
	}
	
	private void quiz() {
		while (true) {
			a.clear();
			
			for (int i = 0; i < 4; i++) {
				int randomIndex = r.nextInt(v.size());
				if (a.contains(randomIndex)) i--;
				else a.add(randomIndex);
			}
			
			for (int k = 0; k < a.size(); k++) 
				System.out.print(a.get(k));
			
			System.out.println();
			
			for (int j = 0; j < a.size(); j++) {
				String country = v.get(a.get(j)).getCountry();
				String capital = v.get(a.get(j)).getCapital();
				System.out.printf("%s�� ������? ", country);
				String answer = s.next();
				
				if (answer.equals("stop")) return;
				if (capital.equals(answer)) System.out.println("����!!");
				else System.out.println("�ƴմϴ�!!");
			}
		}
	}
	
	private void run() {
		while (true) {
			try {
				System.out.println("*** ���� ���߱� ������ �����մϴ� ***");
				System.out.print("�Է�:1, ����:2, ����:3 >> ");
				int select = s.nextInt();
				switch(select) {
				case 1:
					input();
					break;
				case 2:
					quiz();
					break;
				case 3:
					System.out.println("������ �����մϴ�.");
					s.close();
					return;
				default:
					throw new Exception("������ ���� ������ �Է��ϼ���.");
				}
			} catch(Exception e) {
				printError(e);
				s.nextLine();
			}
		}
	}
	
	public static void main(String[] args) {
		var app = new TrainingEx11();
		app.run();
	}
}
