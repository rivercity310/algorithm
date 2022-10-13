import java.util.*;

public class IteratorEx {
	public static void main(String[] args) {
		var v = new Vector<Integer>();
		v.add(5);
		v.add(4);
		v.add(Integer.valueOf(-1));
		v.add(Integer.valueOf(-5));
		
		// Iterator�� �̿��� ��� ���� ����ϱ�
		// v.iterator()�� ���� v�� ��Ҹ� ���� �˻��ϰ� ���ִ� Iterator ��ü�� �����Ѵ�.
		var it = v.iterator();		// Iterator<Integer> �Ǵ� var
		while (it.hasNext()) {
			int n = it.next();
			System.out.println(n);
			it.remove();
		}
		
		
		// it.remove()�� ���� ���ŵǾ� ���Ϳ��� �ƹ��͵� ���� ����
		for (int i = 0; i < v.size(); i++) 
			System.out.printf("v[%d]: %d", i, v.get(i));
	}
}
