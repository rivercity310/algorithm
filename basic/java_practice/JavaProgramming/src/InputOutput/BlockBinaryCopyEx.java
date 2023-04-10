package InputOutput;

import java.io.*;
import java.util.Calendar;

public class BlockBinaryCopyEx {
	public static void main(String[] args) {
		long starts = Calendar.getInstance().get(Calendar.SECOND);
		long startms = Calendar.getInstance().get(Calendar.MILLISECOND);
		System.out.println(starts + " " + startms);
		
		File src = new File("c:/Windows/Web/Wallpaper/ThemeC/img29.jpg");
		File dest = new File("c:/Temp/copyimg4.jpg");
		
		try {
			FileInputStream fi = new FileInputStream(src);
			FileOutputStream fo = new FileOutputStream(dest);
			byte buf[] = new byte[1024*10];   // 10KB ����
			
			while (true) {
				int n = fi.read(buf);   // ���� ũ�⸸ŭ �б�, n�� ���� ���� ����Ʈ
				fo.write(buf, 0, n);    // buf[0]���� n����Ʈ ����
				if (n < buf.length) break;
			}
			fo.flush();
			
			long ends = Calendar.getInstance().get(Calendar.SECOND);
			long endms = Calendar.getInstance().get(Calendar.MILLISECOND);
			System.out.println(ends + " " + endms);
			
			fi.close();
			fo.close();
			int Second = (int)(ends - starts);
			int Milli = (int)(endms - startms);
			System.out.println(src.getPath() + "�� " + dest.getPath() + "�� �����Ͽ����ϴ�.");
			System.out.printf("�ҿ�ð�: %ds %dms", Second, Milli);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
