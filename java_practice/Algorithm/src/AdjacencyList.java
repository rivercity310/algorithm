import java.util.ArrayList;

// ArrayList�� ����Ͽ� ����� ��������Ʈ �����ϱ�

class ListGraph {
	private ArrayList<ArrayList<Integer>> listGraph;
	
	// �׷��� �ʱ�ȭ
	public ListGraph(int initSize) {
		this.listGraph = new ArrayList<ArrayList<Integer>>();
		
		for (int i = 0; i < initSize + 1; i++) 
			listGraph.add(new ArrayList<Integer>());
	}
	
	// �׷��� return
	public ArrayList<ArrayList<Integer>> getGraph() {
		return this.listGraph;
	}
	
	// �׷����� Ư�� ��� return
	public ArrayList<Integer> getNode(int i) {
		return this.listGraph.get(i);
	}
	
	// �׷��� ����� �߰�
	public void put(int x, int y) {
		listGraph.get(x).add(y);
		listGraph.get(y).add(x);
	}
	
	// �׷��� �ܹ��� �߰�
	public void putSingle(int x, int y) {
		listGraph.get(x).add(y);
	}
	
	// �׷��� ��� (��������Ʈ)
	public void printGraphToAdjList() {
		for (int i = 1; i < listGraph.size(); i++) {
			System.out.printf("���� %d�� ��������Ʈ", i);
			
			for (int j = 0; j < listGraph.get(i).size(); j++)
				System.out.printf(" -> %d", listGraph.get(i).get(j));
			
			System.out.println();
		}
	}
}

public class AdjacencyList {
	public static void main(String[] args) {
		int initSize = 6;
		ListGraph adjList = new ListGraph(initSize);
		
		adjList.put(1, 2);
		adjList.put(1, 3);
		adjList.put(2, 3);
		adjList.put(2, 4);
		adjList.put(3, 4);
		adjList.put(3, 5);
		adjList.put(4, 5);
		adjList.put(4, 6);

		adjList.printGraphToAdjList();
	}
}





