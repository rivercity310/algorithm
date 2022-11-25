import java.math.BigInteger;
import java.util.Scanner;
import java.util.Vector;

public class Fibonacci {
	private static BigInteger fibo(int n) {
		if (n == 0) return BigInteger.valueOf(0);
		if (n == 1) return BigInteger.valueOf(1);
		
		BigInteger a = BigInteger.valueOf(0);
		BigInteger b = BigInteger.valueOf(1);
		BigInteger c = BigInteger.valueOf(1);
		
		for (int i = 0; i < n - 2; i++) {
			a = b;
			b = c;
			c = a.add(b);
		}
		
		return c;
	}
	
	public static void main(String[] args) {
		var s = new Scanner(System.in);
		System.out.print("���Ϸ��� Fibonacci ���� �Է��ϼ���: ");
		int n = s.nextInt();
		
		// BigInteger�� ������ ���Ѵ��̴�.
		BigInteger result = fibo(n);
		
		System.out.printf("fib(%d) = %d", n, result);
		s.close();
	}
}
