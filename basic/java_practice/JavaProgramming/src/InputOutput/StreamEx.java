package InputOutput;

import java.io.InputStreamReader;
import java.io.IOException;

public class StreamEx {
	public static void main(String[] args) {
		InputStreamReader rd = new InputStreamReader(System.in);
		// rd.read()�� �� ���� ���� ó���� ���־�� ��
		// 1. try-catch�� IOException ó��
		try {
			int c = rd.read();  	// �ƽ�Ű �ڵ�� �о����
			System.out.println(c);
		} catch (IOException e) {
			System.out.println(e);
		}
	}
}
