package IOExcerise;

import java.io.*;

public class Ex7 {
	private void run() {
		String path = "C:/Temp";
		File f = new File(path);
		int deleteCount = 0;
		
		for (File k : f.listFiles()) {
			if (k.getName().contains(".txt")) {
				System.out.println(k.getName() + " ����");
				k.delete();
				deleteCount++;
			}
		}
		
		System.out.printf("�� %d���� .txt ������ �����Ͽ����ϴ�.", deleteCount);
	}
	
	public static void main(String[] args) {
		var app = new Ex7();
		app.run();
	}
}
