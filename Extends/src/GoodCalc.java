
abstract class Calculator {
	// �� ������ ���� ���Ͽ� ����
	public abstract int add(int a, int b);
	
	// �� ������ ���� ���Ͽ� ����
	public abstract int sub(int a, int b);
	
	// �迭�� ����� ������ ��� ����
	public abstract double average(int a[]);
}

public class GoodCalc extends Calculator {
	@Override
	public int add(int a, int b) {
		return a + b;
	}
	
	@Override
	public int sub(int a, int b) {
		return a - b;
	}
	
	@Override
	public double average(int a[]) {
		int sum = 0;
		for (int i = 0; i < a.length; i++) 
			sum += a[i];
		
		return sum / a.length;
	}
	
	public static void main(String[] args) {
		GoodCalc c = new GoodCalc();
		System.out.println(c.add(5, 6));
		System.out.println(c.sub(5, 3));
		System.out.println(c.average(new int[] {2, 3, 4}));
	}
}
