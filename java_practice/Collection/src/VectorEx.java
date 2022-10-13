import java.util.Vector;

public class VectorEx {
	public static void main(String[] args) {
		Vector<Integer> v = new Vector<Integer>();
		v.add(Integer.valueOf(5));
		v.add(Integer.valueOf(4));
		v.add(-1);	// �ڵ� �ڽ̿� ���� int Ÿ�� -> Integer ��ü�� ��ȯ�Ǿ� ����
		v.add(2, 100);	// index 2�� 100 ����
		
		
		
		
		// ���� ���� ��� ��������
		Integer obj = v.get(1);
		int i = obj.intValue();
		int j = v.get(2);	// �ڵ� ��ڽ�
		System.out.printf("i: %d\n", i);
		System.out.printf("j: %d\n", j);
		for (int k = 0; k < v.size(); k++)
			System.out.printf("v[%d]: %d\n", k, v.get(k));
		
		// ���� �� ��� ���� ���ϱ�
		int sum = 0;
		for (int l = 0; l < v.size(); l++) {
			sum += v.elementAt(l);
		}
		System.out.println("��� ������ ��: " + sum);
		
		
		
		
		// ������ ũ��� �뷮
		int len = v.size(); // ���� �� ��� ��ü�� ��
		int cap = v.capacity();	// ������ �뷮: �⺻ ũ�� 10
		System.out.printf("len: %d\n", len);	
		System.out.printf("cap: %d\n", cap);	
		
		
		
		
		// ���Ϳ��� ��� ����: ������ �� �ڿ� �ִ� ��� ��Ұ� ������ ���ڸ��� �̵��Ѵ�.
		// ������ ��� ����
		System.out.println(v.lastElement());
		
		// pop
		while (v.size() > 0) {
			System.out.println(v.remove(v.size() - 1));
			
		}
		
		// ��� ��� ����
		v.removeAllElements();
		
	}
}
