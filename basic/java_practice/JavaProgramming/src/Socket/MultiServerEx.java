package Socket;

import java.io.*;
import java.net.*;

public class MultiServerEx {
	public static void main(String[] args) {
		try {
			ServerSocket srvsock = new ServerSocket(9999);
			System.out.println("Server Started");
			
			// �ִ� 5���� Ŭ���̾�Ʈ���� "����������" ���� ��� => Thread�� �̿��ϸ� �ټ� Ŭ���̾�Ʈ�� ���� ó�� ����
			for (int i = 0; i < 5; i++) {
				Socket sock = srvsock.accept();
				System.out.printf("IP: %s, Port: %s\n", sock.getInetAddress(), sock.getPort());
				
				BufferedReader in = new BufferedReader(new InputStreamReader(sock.getInputStream()));
				PrintWriter out = new PrintWriter(sock.getOutputStream());
				
				while (true) {
					String msg = in.readLine();
					System.out.println(msg);
					
					out.println("Server: Ack");
					out.flush();
					
					if (msg.equals("bye")) break;
				}
				
				in.close();
				out.close();
				sock.close();
			}
			
			srvsock.close();
			
		} catch (IOException ex) {
			ex.printStackTrace();
		}
	}
}
