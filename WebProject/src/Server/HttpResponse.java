package Server;
import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Date;

public class HttpResponse {
	private String getMsgNotFound() {
		// Header
		String msg = "HTTP/1.1 404\n";
		msg += "Content-Type: text/html;charset=utf-8\n";
		msg += "Content-Language: ko\n";
		msg += "Date: " + new Date().toString() + "\n";   // toString ���� ����
		msg += "\n";
		
		// Body
		msg += "<html><h1>404 Not Found</h1></html>";
		return msg;
	}
	
	private String getMsgText(String path) throws IOException {
		byte bytes[] = Files.readAllBytes(Paths.get(path));
		
		// Header
		String msg = "HTTP/1.1 200\n";
		msg += "Content-Type: text/html;charset=utf-8\n";
		msg += "Content-Language: ko\n";
		msg += "Content-Length: " + bytes.length + "\n";
		msg += "Date: " + new Date().toString() + "\n";   // toString ���� ���� ��ü�� ���� �� �ڵ����� toString() �޼ҵ尡 �����
		msg += "\n";
		
		// Body
		msg += new String(bytes, "utf-8");
		return msg;
	}
	
	private byte[] getMsgImage(String path) throws IOException {
		byte bytes[] = Files.readAllBytes(Paths.get(path));
		
		String msg = "HTTP/1.1 200\n";
		msg += "Content-Type: image/jpeg\n";
		msg += "Content-length" + bytes.length + "\n";
		msg += "\n";
		
		ByteArrayOutputStream bao = new ByteArrayOutputStream();
		bao.write(msg.getBytes());
		bao.write(bytes);
		
		return bao.toByteArray();
	}
	
	private void sendText(OutputStream os, String msg) throws UnsupportedEncodingException {
		PrintWriter pw = new PrintWriter(new OutputStreamWriter(os, "utf-8"));
		pw.println(msg);
		pw.flush();
	}

	private void sendBytes(OutputStream os, byte bytes[]) throws IOException {
		os.write(bytes);
		os.flush();
	}
	
	// file�κ��� Ȯ���� �и�
	private boolean isImage(String file) {
		String extentions[] = {"jpg", "jpeg", "png", "gif"};
		boolean flag = false;
		
		int idx = file.lastIndexOf(".");
		String ext = idx > 0 ? file.substring(idx + 1) : "";
		
		for (String k : extentions) {
			if (k.equals(ext)) {
				flag = true;
				break;
			}
		}
		
		return flag;
	}
	
	private boolean isJsp(String file) {
		int idx = file.lastIndexOf(".");
		String ext = idx > 0 ? file.substring(idx + 1) : "";
		return ext.equals("jsp");
	}
	
	public void send(OutputStream os, String host, String file, String params[]) throws IOException {
		if (isJsp(file)) new JspHandler().send(os, host, file, params);
		else {
			// HTML ������ ����Ǵ� ��Ʈ ���丮�� web���� ����
			// class ������ ����Ǵ� bin ���丮 �Ʒ��� HTML ������ ������ web ���丮 ���� 
			// web/index.html
			file = "web" + file;    
			System.out.println("send file: " + file);
			
			//Session ses = Session.getInstance();
			//Object obj = ses.get("localhost");
			
			//System.out.println("Obj: " + obj.toString());
			
			String msg = null;
			boolean isExist = new File(file).exists();
			if (isExist) {
				if (isImage(file)) {
					byte bytes[] = getMsgImage(file);
					sendBytes(os, bytes);
				} else {
					msg = getMsgText(file);
					sendText(os, msg);
				}
			} else {
				msg = getMsgNotFound();
				sendText(os, msg);
			}
			
			System.out.println(msg + "\n\n\n");	
		}
		
		
	}
}
