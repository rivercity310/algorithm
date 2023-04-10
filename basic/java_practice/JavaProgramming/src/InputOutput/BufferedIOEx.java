package InputOutput;

import java.util.Scanner;
import java.io.*;

public class BufferedIOEx {
	public static void main(String[] args) {
		try {
			var s = new Scanner(System.in);
			var fin = new FileReader("C:\\Users\\h9701\\Desktop\\test.txt");
			//BufferedOutputStream out = new BufferedOutputStream(System.out, 5);
			
			// �ѱ��� ����Ϸ��� out�� ������ ���� �����ؾ� �Ѵ�.
			BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out), 5);
			
			int c;
			while ((c = fin.read()) != -1)
				out.write(c);
			
			out.flush();	// ���ۿ� ���� �ִ� ���� ��� ���
			
			s.close();
			fin.close();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
