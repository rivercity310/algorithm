package InputOutput;

import java.io.File;

public class FileEx {
	public static void listDirectory(File dir) {
		System.out.println("-----" + dir.getPath() + "�� ���� ����Ʈ�Դϴ�. -----");
		File[] subFiles = dir.listFiles();
		
		for (File f : subFiles) {
			long t = f.lastModified();  // ���������� ������ �ð�
			System.out.print(f.getName());
			System.out.print("\t���� ũ��: " + f.length());
			System.out.printf("\t������ �ð�: %tb %tb %ta %tT", t, t, t, t);
			System.out.print("\t" + t + "\n");
		}
	}
	
	public static void main(String[] args) {
		File f1 = new File("c:\\windows\\system.ini");
		System.out.println(f1.getPath() + ", " + f1.getParent() + ", " + f1.getName());
		
		String res = f1.isFile() ? "����" : f1.isDirectory() ? "���丮" : "?";
		System.out.println(f1.getPath() + "�� " + res + "�Դϴ�.");
		
		File f2 = new File("C:\\Temp\\java_sample");
		if (!f2.exists()) f2.mkdir(); // f2 ���͸��� �������� ������ ���丮 ����
		
		listDirectory(new File("c:\\Temp"));  // c:\\Temp�� �ִ� ���� ����Ʈ ���
		f2.renameTo(new File("c:\\Temp\\javasample"));
		listDirectory(new File("c:\\Temp"));
		
	}
}
