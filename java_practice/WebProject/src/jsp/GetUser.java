package jsp;

import Server.Session;

public class GetUser extends http.JspService {
	@Override
	public String getHtml(Session ses, String host, String params[]) {
		String prms[] = (String[])ses.get(host);
		if (prms == null)
			return "<html><meta charset='utf-8'>ȸ�������� �����ϴ�.</html>";
		
		String str = "<h1>[ȸ������]</h1>";
		str += "ID: " + getParamValue(prms, "id") + "<br/>";
		str += "TEL: " + getParamValue(prms, "tel") + "<br/>";
		
		return "<html><meta charset='utf-8'>" + str + "</html>";	
	}
}
