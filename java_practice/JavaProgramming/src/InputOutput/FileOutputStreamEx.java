package InputOutput;

import java.io.*;

public class FileOutputStreamEx {
	public static void main(String[] args) {
		byte b[] = {7, 51, 3, 4, -1, 24};
		String filePath = "C:\\Users\\h9701\\Desktop\\FileOutputStream.txt"; 
		
		try {
			FileOutputStream fout = new FileOutputStream(filePath);
			fout.write(b);
			fout.close();
		} catch (IOException e) {
			System.out.println(e);
			System.out.println(filePath + "�� ������ �� �����ϴ�.");
			return;
		}
		
		System.out.println(filePath + "�� �����Ͽ����ϴ�.");
	}
}
