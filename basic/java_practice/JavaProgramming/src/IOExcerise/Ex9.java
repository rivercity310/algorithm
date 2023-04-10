package IOExcerise;

import java.util.Scanner;
import java.util.Vector;
import java.io.*;

public class Ex9 {
	private void run() {
		Scanner s = new Scanner(System.in);
		Vector<String> v = new Vector<>();
		
		String path = "C:\\Users\\h9701\\Desktop\\Java\\words.txt";
		File f = new File(path);
		
		try {
			Scanner sf = new Scanner(new FileReader(f));
			while (sf.hasNext()) v.add(sf.nextLine());
			
			sf.close();
		} catch (Exception e) {
			System.out.println(e);
		}
		
		while (true) {
			System.out.print("�ܾ�: ");
			String word = s.next();
			if (word.equals("�׸�")) {
				System.out.println("���α׷��� �����մϴ�");
				s.close();
				break;
			}
			
			int count = 0;
			for (int i = 0; i < v.size(); i++) {
				if (v.get(i).startsWith(word)) {
					System.out.println(v.get(i));
					count++;
				}
			}
			
			System.out.printf("��� %d�� �߰�!\n", count);
		}
	}
	
	public static void main(String[] args) {
		var app = new Ex9();
		app.run();
	}
}
