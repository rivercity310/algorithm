package jsp;

import Server.Session;
import http.JspService;

public class SetUser extends JspService {
	@Override
	public String getHtml(Session ses, String host, String params[]) {
		ses.set(host, params);
		return "<html><meta charset='utf-8'>���� ������ �߰��Ǿ����ϴ�.</html>";
	}
}
