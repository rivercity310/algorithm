package Server;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;

import http.JspService;

/*
 * setUser: ���ǿ� �Է� �Ķ���� ����
 * getUser: ���ǿ� ����� �Ķ���� ���
 * 
 */

public class JspHandler {
	private String getHtml(String desc) {
		return "<html><meta charset='utf-8'>" + desc + "</html>";
	}
	
	private String getMsg(int code, String html) {
		String msg = "HTTP/1.1" + code + "\n";
		msg += "Content-Type: text/html;charset=utf-8\n";
		msg += "Content-Language: ko\n";
		msg += "Date: " + new java.util.Date().toString() + "\n";
		msg += "\n";
		
		msg += html;
		return msg;
	}
	
	private String getClassName(String file) {
		int idx = file.lastIndexOf(".jsp");
		return idx < 0 ? "" : file.substring(0, idx).replaceAll("/", ".");
	}
	
	private void sendText(OutputStream os, String msg) throws UnsupportedEncodingException {
		PrintWriter pw = new PrintWriter(new OutputStreamWriter(os, "utf-8"));
		pw.println(msg);
		pw.flush();
	}
	
	/*
	 * 1. Class.forName(String path): path�� ��ġ�� Ŭ������ ã�� �޸𸮷� �ε�
	 *   - path�� Ŭ���� ��ΰ� ���� �� ("jsp/SetUser.class" ������ �ε��Ϸ��� "jsp.SetUser")
	 *   
	 * 2. Class.newInstance(): �־��� Ŭ������ ���� ��ü ���� �� ����
	 *   - �� �޼ҵ�� Object ���·� ��ü�� �����ϹǷ�, ��������� Ÿ�� ĳ������ ���־�� �Ѵ�
	 */
	public void send(OutputStream os, String host, String file, String params[]) throws UnsupportedEncodingException {
		file = "jsp" + getClassName(file);
		
		try {
			Class c = Class.forName(file);
			JspService svc = (JspService)c.newInstance();
			sendText(os, getMsg(200, svc.getHtml(Session.getInstance(), host, params)));
		} catch (Exception ex) {
			ex.printStackTrace();
			sendText(os, getMsg(500, getHtml("���� ������ �߻��Ͽ����ϴ�.")));
		}
		
	}

	
}
