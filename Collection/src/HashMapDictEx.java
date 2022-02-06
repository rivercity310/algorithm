import java.util.*;

public class HashMapDictEx {
	public static void main(String[] args) {
		var s = new Scanner(System.in);
		var dict = new HashMap<String, String>();
		
		dict.put("baby", "�Ʊ�");
		dict.put("apple", "���");
		dict.put("love", "���");
		
		while(true) {
			System.out.print("ã�� ���� �ܾ�? ");
			String eng = s.next();
			if (eng.equals("exit")) {
				System.out.println("���α׷��� �����մϴ�...");
				s.close();
				break;
			}
			
			// �ؽø��� ��ü �˻�
			if (eng.equals("showAllWords")) {
				var keys = dict.keySet();		// Set<String> keys�� ����
				var it = keys.iterator();		// Iterator<String> it�� ����
				
				while (it.hasNext()) {
					String key = it.next();
					String value = dict.get(key);
					System.out.printf("(%s, %s)\n", key, value);
				}
				
				continue;
			}
			
			String kor = dict.get(eng);
			if (kor == null)
				System.out.println(eng + "�� ���� �ܾ��Դϴ�.");
			else 
				System.out.println(kor);
		}
	}
}
