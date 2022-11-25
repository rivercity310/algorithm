// List�� �����ϴ� Node Ŭ����
class ListNode {
	private String data;   // ������ ���� ����
	public ListNode link;  // �ٸ� ��带 ������ ��ũ ���
	
	public ListNode() {
		this(null, null);
	}
	
	public ListNode(String data) {
		this(data, null);
	}
	
	public ListNode(String data, ListNode link) {
		this.data = data;
		this.link = link;
	}
	
	public String getData() {
		return this.data;
	}
}

public class LinkedList {
	private ListNode head;    // head ���
	
	public LinkedList() {
		head = null;         // head ��� �ʱ�ȭ
	}
	
	// Node ���� (�߰��� ����)
	public void insertNode(ListNode preNode, String data) {
		ListNode newNode = new ListNode(data);
		
		// preNode -> newNode -> ���� preNode�� ���� ���� �����ǰ� ��
		newNode.link = preNode.link;
		preNode.link = newNode;
	}
	
	// Node ���� (�������� ����)
	public void insertNode(String data) {
		ListNode newNode = new ListNode(data);
		if (head == null) this.head = newNode;
		else {
			ListNode tempNode = head;
			
			while (tempNode.link != null) 
				tempNode = tempNode.link;
			
			tempNode.link = newNode;
		}
	}
	
	// Node ���� (�߰� ��� ����)
	public void deleteNode(String data) {
		ListNode preNode = head;
		ListNode tempNode = head.link;
		
		if (data.equals(preNode.getData())) {
			head = preNode.link;
			preNode.link = null;
		} else {
			while (tempNode != null) {
				if (data.equals(tempNode.getData())) {
					if (tempNode.link == null) {
						preNode.link = null;
					} else {
						preNode.link = tempNode.link;
						tempNode.link = null;
					}
					break;
				} else {
					preNode = tempNode;
					tempNode = tempNode.link;
				} 
			}
		}
	}
	
	// Node ���� (������ ��� ����)
	public void deleteNode() {
		ListNode preNode;
		ListNode tempNode;
		
		if (head == null) return;
		
		// head ����� link�� null�� ��� -> ��尡 1�� ������ ���
		if (head.link == null) head = null;
		else {
			preNode = head;
			tempNode = head.link;
			
			while (tempNode.link != null) {
				preNode = tempNode;
				tempNode = tempNode.link;
			}
			
			preNode.link = null;
		}
	}
	
	// Node Ž��
	public ListNode searchNode(String data) {
		ListNode tempNode = this.head;
		
		while (tempNode != null) {
			if (data.equals(tempNode.getData())) return tempNode;
			else tempNode = tempNode.link;
		}
		
		return tempNode;
	}
	
	// ����Ʈ�� ��带 �������� ����
	public void reverseList() {
		ListNode nextNode = head;
		ListNode currentNode = null;
		ListNode preNode = null;
		
		while (nextNode != null) {
			preNode = currentNode;
			currentNode = nextNode;
			nextNode = nextNode.link;
			currentNode.link = preNode;
		}
		
		head = currentNode;
	}
	
	// ���� ����Ʈ�� ����� ��� ������ ���
	public void printList() {
		ListNode tempNode = this.head;
		
		while (tempNode != null) {
			System.out.print(tempNode.getData() + " ");
			tempNode = tempNode.link;
		}
		System.out.println();
	}
	
	public static void main(String[] args) {
		LinkedList linkedList = new LinkedList();
		String str = "wed";
		
		linkedList.insertNode("sun");
		linkedList.insertNode("mon");
		linkedList.insertNode("tue");
		linkedList.insertNode("wed");
		linkedList.insertNode("thu");
		linkedList.insertNode("fri");
		linkedList.insertNode("sat");
		
		System.out.println(linkedList.searchNode(str).getData());
		
		linkedList.deleteNode(linkedList.searchNode(str).getData());
		linkedList.printList();
		
		linkedList.reverseList();
		linkedList.printList();
	}
}










