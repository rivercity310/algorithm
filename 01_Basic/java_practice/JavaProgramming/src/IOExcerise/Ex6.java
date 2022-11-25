package IOExcerise;

import java.io.*;

public class Ex6 {
	private void run() {
		String path = "C:\\Program Files";
		File f = new File(path);
		
		long max = 0;
		String filePath = null;
		for (File k : f.listFiles()) {			
			if (k.isFile() && (k.length() > max)) {
				max = k.length();
				filePath = k.getPath();
			}
		}
		
		System.out.printf("���� ū ������ %s %d����Ʈ", filePath, max);
	}
	
	public static void main(String[] args) {
		var app = new Ex6();
		app.run();
	}
}
