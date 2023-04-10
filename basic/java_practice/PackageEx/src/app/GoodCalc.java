package app;

// �ٸ� ��Ű��(lib)�� �ִ� Ŭ������ ����ϱ� ����, �����Ϸ����� ��θ� �˷���
import lib.Calculator;

public class GoodCalc extends Calculator {
	public int add(int a, int b) {
		return a + b;
	}
	public int subtract(int a, int b) {
		return a - b;
	}
	public double average(int[] a) {
		int sum = 0;
		for (int k : a) sum += k;
		return sum / a.length;
	}
	
	public static void main(String[] args) {
		Calculator c = new GoodCalc();
		System.out.println(c.add(2, 3));
		System.out.println(c.subtract(3, 2));
		System.out.println(c.average(new int[] {1, 2, 3, 4, 5, 6}));
	}
}
