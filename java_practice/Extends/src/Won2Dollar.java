import java.util.Scanner;

abstract class Converter {
	// �߻� �޼ҵ� 
	abstract double convert(double src);
	abstract String getSrcString();
	abstract String getDestString();
	double ratio;
	
	void run() {
		Scanner scanner = new Scanner(System.in);
		System.out.printf("%s�� %s�� �ٲߴϴ�.\n", getSrcString(), getDestString());
		System.out.printf("%s�� �Է��ϼ���: ", getSrcString());
		double val = scanner.nextDouble();
		double res = convert(val);
		System.out.printf("��ȯ ���: %.2f%s�Դϴ�.\n", res, getDestString());
		scanner.close();
	}
}

class Km2Mile extends Converter {
	Km2Mile(double km) {
		super.ratio = km;
	}
	
	protected double convert(double src) {
		// 1������ 1.6km
		return src / super.ratio;
	}
	
	String getSrcString() {
		return "km";
	}
	
	String getDestString() {
		return "mile";
	}
}


public class Won2Dollar extends Converter {
	Won2Dollar(double dollar) {
		super.ratio = dollar;
	}
	
	double convert(double src) {
		return src / super.ratio;
	}
	
	String getSrcString() {
		return "Won";
	}
	
	String getDestString() {
		return "$";
	}
	
	public static void main(String[] args) {
		Km2Mile toMile = new Km2Mile(1.6);
		toMile.run();
	}
}
