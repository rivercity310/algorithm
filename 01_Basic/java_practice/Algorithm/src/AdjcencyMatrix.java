// ������� ������� �׷��� �����ϱ�

class ArrGraph {
	private int[][] arrGraph;
	
	// �׷��� �ʱ�ȭ
	public ArrGraph(int initSize) {
		this.arrGraph = new int[initSize + 1][initSize + 1];
	}
	
	// �׷��� return
	public int[][] getGraph() {
		return this.arrGraph;
	}
	
	// �׷��� ����� �߰�
	public void put(int x, int y) {
		this.put(x, y, 1);
	}
	
	public void put(int x, int y, int w) {
		arrGraph[x][y] = arrGraph[y][x] = w;
	}
	
	// �׷��� �ܹ��� �߰�
	public void putSingle(int x, int y) {
		this.putSingle(x, y, 1);
	}
	
	public void putSingle(int x, int y, int w) {
		arrGraph[x][y] = w;
	}
	
	// �׷��� ��� 
	public void printGraphToAdjArr() {
		for (int i = 1; i < arrGraph.length; i++) {
			for (int j = 1; j < arrGraph[i].length; j++)
				System.out.printf("%d ", arrGraph[i][j]);
			System.out.println();
		}
	}
}

public class AdjcencyMatrix {
	public static void main(String[] args) {
		int initSize = 6;
		ArrGraph adjArr = new ArrGraph(initSize);
		
		adjArr.put(1, 2, 5);
		adjArr.put(1, 3);
		adjArr.put(2, 3);
		adjArr.put(2, 4);
		adjArr.put(3, 4);
		adjArr.put(3, 5);
		adjArr.put(4, 5);
		adjArr.put(4, 6);
		
		adjArr.printGraphToAdjArr();
	}
}











