package InputOutput;

import java.io.*;

public class FileInputStreamEx {
	public static void main(String[] args) {
		String filePath = "C:\\Users\\h9701\\Desktop\\FileOutputStream.txt"; 
		byte b[] = new byte[6];
		
		try {
			FileInputStream fin = new FileInputStream(filePath);
			fin.read(b);
			
			System.out.println("���̳ʸ� ������ �о�鸰 �� ����մϴ�.");
			for (byte k : b) System.out.print(k + " ");
			
			fin.close();
		} catch (IOException e) {
			System.out.println(e);
		}
	}
}
