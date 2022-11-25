package Socket;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class ServerEx {
	public static void main(String[] args) {
		try {
			ServerSocket srvk = new ServerSocket(9999);
			System.out.println("Server on...");
			
			Socket socket = srvk.accept();
			// Ŭ���̾�Ʈ�κ��� ���� �� �Ʒ� �ڵ尡 ����˴ϴ�.
			
			// readLine() �Լ� �̿��� ����, BufferedReader Ŭ���� �̿�
			BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			PrintWriter out = new PrintWriter(socket.getOutputStream());
			
			while (true) {
				String msg = in.readLine();
				System.out.println(msg);
				
				out.println("Server: Ack");
				out.flush();
				
				if (msg.equals("bye")) break;
			}

			in.close();
			out.close();
			socket.close();
			srvk.close();
			
			System.out.println("Server Stopped");
			
		} catch(IOException err) {
			err.printStackTrace();
		}
	}
}
