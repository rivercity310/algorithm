package Generic;

import java.util.*;

class Word {
	private String kor;
	private String eng;
	
	public Word(String k, String e) {
		this.kor = k;
		this.eng = e;
	}
	
	public String getKor() {
		return this.kor;
	}
	
	public String getEng() {
		return this.eng;
	}
}


public class EngWordGameEx {
	private Vector<Word> v;
	private Scanner s;
	private Random r;
	private int count;
	
	public EngWordGameEx() {
		s = new Scanner(System.in);
		r = new Random();
		v = new Vector<>();
		count = 0;
		
		initVector();
	}
	
	private void initVector() {
		v.add(new Word("���", "love"));
		v.add(new Word("�ູ", "happy"));
		v.add(new Word("ģ��", "friend"));
		v.add(new Word("�Ʊ�", "baby"));
		v.add(new Word("����", "pencil"));
		v.add(new Word("�Ұ��", "beef"));
		v.add(new Word("�Ϻ�", "japan"));
		v.add(new Word("�ѱ�", "korea"));
		v.add(new Word("ť��", "cube"));
		v.add(new Word("���", "nostalgia"));
	}
	
	private void run() {
		System.out.println("��ǰ���� �ܾ� �׽�Ʈ�� �����մϴ�. -1�� �Է��ϸ� �����մϴ�.");
		System.out.printf("���� %d���� �ܾ ����ֽ��ϴ�.\n", v.size());
		
		for (int i = 0; i < v.size(); i++) {
			int first, second, third;
			while (true) {
				first = r.nextInt(v.size());
				second = r.nextInt(v.size());
				third = r.nextInt(v.size());
				
				if (i == first || i == second || i == third) continue;
				if (first != second && second != third && first != third) break;
			}

			int[] idxAry = {i, first, second, third};
			idxAry = shuffleAry(idxAry);
			
			System.out.printf("%s?\n", v.get(i).getEng());
			System.out.printf("(1)%s (2)%s (3)%s (4)%s : ", v.get(idxAry[0]).getKor(), v.get(idxAry[1]).getKor(), v.get(idxAry[2]).getKor(), v.get(idxAry[3]).getKor());
			int answer = s.nextInt();
			
			if (answer == -1) {
				System.out.print("��ǰ��� �����մϴ�.\n");
				s.close();
				break;
			}
			
			if (v.get(i).equals(v.get(idxAry[answer - 1]))) {
				System.out.println("Excellent!!\n");
				count++;
			}
			else System.out.println("No!!\n");
		}
		
		System.out.printf("����: %d/%d\n", count, v.size());
	}
	
	private int[] shuffleAry(int[] a) {
		// System.out.print("�ʱ� �迭: ");
		// for (int i = 0; i < a.length; i++)
		//  	System.out.print(a[i] + " ");
		
		for (int x = 0; x < a.length; x++) {
			int i = r.nextInt(a.length);
			int j = r.nextInt(a.length);
			
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
		
		// System.out.print("���� �� �迭: ");
		// for (int i = 0; i < a.length; i++) 
		//  	System.out.print(a[i] + " ");
		// System.out.println();
		
		return a;
	}
	
	public static void main(String[] args) {
		var app = new EngWordGameEx();
		app.run();
	}
}