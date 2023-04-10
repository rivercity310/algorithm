import java.util.*;

public class CollectionsEx {
	private static void printList(LinkedList<String> l) {
		Iterator<String> it = l.iterator();
		while (it.hasNext()) {
			String e = it.next();
			String separator = it.hasNext() ? " -> " : "\n";
			
			System.out.print(e + separator);
		}
	}
	
	public static void main(String[] args) {
		var myList = new LinkedList<String>();
		myList.add("Ʈ��������");
		myList.add("��Ÿ����");
		myList.add("��Ʈ����");
		myList.add(0, "�͹̳�����");
		myList.add(2, "�ƹ�Ÿ");
		
		Collections.sort(myList);
		printList(myList);
		
		Collections.reverse(myList);
		printList(myList);
		
		int index = Collections.binarySearch(myList, "�ƹ�Ÿ");
		System.out.printf("�ƹ�Ÿ�� %d��° ����Դϴ�.", index + 1);
	}
}
