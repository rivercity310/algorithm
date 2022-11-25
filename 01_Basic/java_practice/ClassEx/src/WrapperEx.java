
public class WrapperEx {
	public static void main(String[] args) {
		// toLowerCase('A'): 'A'�� �ҹ��ڷ� ��ȯ
		System.out.println(Character.toLowerCase('A'));		// a
		
		char c1 = '4', c2 = 'F';
		
		// isDigit: ���� c1�� �����̸� true
		if (Character.isDigit(c1))	
			System.out.println(c1 + "��/�� ����");
		
		// isAlphabetic: ���� c2�� �������̸� true
		if (Character.isAlphabetic(c2))
			System.out.println(c2 + "�� ������");
		
		
		
		System.out.println(Integer.parseInt("-123"));
		System.out.println(Integer.toHexString(28));		// 28�� 16���� ���ڿ��� ��ȯ
		System.out.println(Integer.toBinaryString(28));		// 28�� 2���� ���ڿ��� ��ȯ
		System.out.println(Integer.bitCount(28));			// 28�� ���� 2������ 1�� ����
		
		
		Double d = Double.valueOf(3.14);  					// �Ǵ� Double d = 3.14; (�ڵ� �ڽ�)
		System.out.println(d.toString()); 					// Double�� ���ڿ� "3.14"�� ��ȯ
		System.out.println(Double.parseDouble("3.14"));		// ���ڿ��� �Ǽ� 3.14�� ��ȯ
		
		
		boolean b = (4 > 3);								// b�� true
		System.out.println(Boolean.toString(b));	  		// true�� ���ڿ� "true"�� ��ȯ
		System.out.println(Boolean.parseBoolean("false"));	// ���ڿ��� false�� ��ȯ
	}
}
