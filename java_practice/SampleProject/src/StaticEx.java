class ArrayUtil {
	// �迭 a�� b�� ������ ���ο� �迭�� ����
	public static int[] concat(int a[], int b[]) {
		int length = a.length + b.length;
		int c[] = new int[length];
		
		for (int i = 0; i < a.length; i++) 
			c[i] = a[i];
		
		for (int j = 0; j < b.length; j++)
			c[j + a.length] = b[j];
		
		return c;
	}
	
	// �迭 a�� ���
	public static void print(int a[]) {
		for (int i = 0; i < a.length; i++)
			System.out.print(a[i] + " ");
	}
}

public class StaticEx {
	public static void main(String[] args) {
		int array1[] = {1, 5, 7, 9};
		int array2[] = {3, 6, -1, 100, 77};
		int array3[] = ArrayUtil.concat(array1, array2);
		ArrayUtil.print(array3);
	}
}
