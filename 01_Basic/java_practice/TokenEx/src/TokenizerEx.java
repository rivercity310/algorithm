import java.util.StringTokenizer;


public class TokenizerEx {
	public static void main(String[] args) {
		// ���ڿ� �и��� StringTokenizer ��ü �Ǵ� String ��ü�� split �޼���� �� �� �ִ�.
		
		// 1. StringTokenizer ��ü�� �̿��� ���ڿ��� �и��ϰ�, ���ڿ� Ÿ���� ���ڸ� ������ ��ȯ�� ���� ���ϱ�
		String s = "a=3,b=5,c=6, d = 56, e = 10, f = 12";
		StringTokenizer st = new StringTokenizer(s, ",=");
		
		int sum = 0;
		while (st.hasMoreTokens()) {
			String nextToken = st.nextToken().trim();
			if (isStringInt(nextToken)) 
				sum += Integer.parseInt(nextToken);
		}
		
		System.out.println("���� " + sum);		
		
		int sum2 = 0;
		String[] sp = s.split(",");
		for (int i = 0; i < sp.length; i++) {
			sp[i] = sp[i].trim();
			String[] spAry = sp[i].split("=");
			for (int j = 0; j < spAry.length; j++) {
				spAry[j] = spAry[j].trim();
				if (isStringInt(spAry[j])) {
					sum2 += Integer.parseInt(spAry[j]);
				}
			}
		}
		
		System.out.println("���� " + sum2);
	}
	
	private static boolean isStringInt(String s) {
		try {
			Integer.parseInt(s);
			return true;
		} catch (NumberFormatException e) {
			return false;
		}
	}
}
