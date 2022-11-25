package Server;
import java.util.HashMap;

// Session: ���������� �ӽ������� �����͸� �����ϱ� ���� (default: 30��), HashMap���� ����
// getInstance() �޼ҵ带 static���� �����Ͽ� ���� ��ü�� �����ϵ��� ����
// ���� �Ķ���͸� �������� �ʰ� ��𼭵� getInstance �޼ҵ带 ���� ��ü�� �� �� ����
// -> Singleton ����: ��ü�� ���� �ϳ��� ������ �� �ֵ��� static���� �ν��Ͻ� ����
public class Session {
	private HashMap<String, Object> table;
	private static Session instance;
	
	// new Session() ���·� �����ڸ� ȣ���� ���, ���� ���ó�� ��ü�� ������ ����
	public Session() {
		table = new HashMap<String, Object>();
	}
	
	// Session.getInstance()�� ȣ���� ���, ���� ��ü�� ���� 
	public static Session getInstance() {
		if (instance == null) instance = new Session();
		return instance;
	}
	
	public void set(String key, Object val) {
		table.put(key, val);
	}
	
	public Object get(String key) {
		return table.get(key);
	}
	
	public Object remove(String key) {
		return table.remove(key);
	}
}