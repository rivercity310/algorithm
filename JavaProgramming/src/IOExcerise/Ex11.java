package IOExcerise;

import java.util.Scanner;
import java.io.*;

public class Ex11 {
	private Scanner s;
	private String p;
	private File f;
	
	public Ex11() {
		p = "C:/";
		s = new Scanner(System.in);
		f = new File(p);
	}
	
	private void pathHub(String query) {
		String[] queryAry = query.split("\\s+");
		
		switch (queryAry[0]) {
		case "mkdir":
			if (queryAry.length == 2) {
				makeDir(queryAry[1]);
				printLists();
			}
			else System.out.println("�߸��� ����Դϴ�.");
			break;
		case "rename":
			if (queryAry.length == 3) {
				rename(queryAry[1], queryAry[2]);
				printLists();
			}
			else System.out.println("�߸��� ����Դϴ�.");
			break;
		case "remove":
			if (queryAry.length == 2) {
				remove(queryAry[1]);
				printLists();
			}
			else System.out.println("�߸��� ����Դϴ�.");
			break;
		default:
			if (queryAry.length == 1) {
				defaultAction(new File(p + query), queryAry);
			}
			else System.out.println("�߸��� ����Դϴ�.");
			break;
		}
	}
	
	private void defaultAction(File asd, String[] queryAry) {
		if (asd.isDirectory()) {
			boolean check = false;
			for (File k : f.listFiles()) {
				if (k.getName().equals(queryAry[0])) {
					check = true;
					p = getNewPath(queryAry[0]);
					printLists();
				}
			}
			
			if (queryAry[0].equals("..")) {
				if (!p.equals("C:/")) {
					p = getNewPath("..");
					printLists();
				} else {
					System.out.println("���̻� �̵��� �� �����ϴ�.");
				}
				
				check = true;
			}
			
			if (!check) System.out.println("�������� �ʴ� �����̰ų� �߸��� ����Դϴ�.");
		}
		
		// �����ΰ�� �� ������ ������ ����Ѵ�.
		else {
			try {
				Scanner sf = new Scanner(new FileInputStream(asd));
				System.out.println("----------------------------");
				System.out.println("������ ����մϴ�....");
				while (sf.hasNext()) {
					String line = sf.nextLine();
					System.out.println(line);
				}
				System.out.println("----------------------------");
				sf.close();
			} catch (Exception e) {
				System.out.println(e);
				return;
			}
		}
	}
	
	private File findFile(String name) {
		for (File k : f.listFiles())
			if (k.getName().equals(name))
				return k;
		
		return null;
	}
	
	private void remove(String forderName) {
		File k = findFile(forderName);
		if (k != null) {
			k.delete();
			System.out.println(forderName + "�� �����Ͽ����ϴ�.");
		}
		else System.out.println("�������� �ʴ� ���� Ȥ�� �����Դϴ�.");
	}
	
	private void rename(String orgName, String rename) {
		File k = findFile(orgName);
		if (k != null) {
			k.renameTo(new File(p + rename));
			System.out.println(orgName + "�� " + rename + "���� �����Ͽ����ϴ�.");
		}
		else System.out.println("�������� �ʴ� ���� Ȥ�� �����Դϴ�.");
	}
	
	private void makeDir(String dirName) {
		File newF = new File(p + dirName);
		if (!newF.exists()) newF.mkdir();
		System.out.println(dirName + " ���͸��� �����Ͽ����ϴ�.");
	}
	
	private String getNewPath(String move) {		
		if (move.equals("..")) {
			if (!p.equals("C:/")) {
				String[] strAry = p.split("/");
				int begin = p.lastIndexOf(strAry[strAry.length - 1]);
				String res = p.substring(0, begin);
				f = new File(res);
				return res;
			}
			
			// move(����� �Է°�)�� ..�̰� p(���)�� C:/�̸� �״�� p�� �����Ѵ�. (���̻� �̵��� �� ����) 
			return p;
		}

		String res = p.concat(move + "/");
		f = new File(res);
		return res;
	}
	
	private void printLists() {
		System.out.println("-------------------------------------------------");
		System.out.printf("[%s]\n", p);
			
		for (File k : f.listFiles()) {
			String h = k.isDirectory() ? "dir" : "file";
			System.out.printf("%s\t%d����Ʈ\t%s\n", h, k.length(), k.getName());
		}
		System.out.println("-------------------------------------------------");
	}
	
	private void run() {
		System.out.println("*** ���� Ž�����Դϴ�. ***");
		
		printLists();
		while (true) {
			System.out.print("�̵�: ");
			String query = s.nextLine();
			
			try {
				// C:\\Temp�� �����
				if (query.equals("!maketxt")) {
					var makeTxt = new Ex1();
					makeTxt.run();
					
					s.next();
				}
				else if (query.equals("!break")) {
					System.out.print("���α׷��� �����մϴ�....");
					return;
				} else {
					pathHub(query);
				}
			} catch (Exception e) {
				System.out.println(e);
				continue;
			}
		} 
	}
	
	public static void main(String[] args) {
		var app = new Ex11();
		app.run();
	}
}
