interface PhoneInterface {
	// ��� �ʵ�, public static final ���� ����
	public static final int TIMEOUT = 10000;
	
	// �߻� �޼ҵ�, public abstract ���� ����
	public abstract void sendCall();
	public abstract void receiveCall();
	
	// default �޼ҵ�, public ���� ����
	public default void printLogo() {
		System.out.println("My Phone");
	}
}

interface MobilePhoneInterface extends PhoneInterface {
	// �߻� �޼ҵ�, public abstract ���� ����
	void sendSMS();
	void receiveSMS();
}

interface MP3Interface {
	void play();
	void stop();
}

// ���� ��� ����
interface MusicPhoneInterface extends MobilePhoneInterface, MP3Interface {
	void playMP3RingTone();
}

class PDA {
	public int calculate(int x, int y)  {
		return x + y;
	}
}


// SamsungPhone Ŭ������ PDA�� ��ӹް�,
// MobilePhoneInterface�� MP3Interface�� ����� �߻� �޼ҵ���� ��� �����Ѵ�.
class SamsungPhone extends PDA implements MP3Interface, MobilePhoneInterface {
	// MobilePhoneInterface�� ��� �߻� �޼ҵ� ����
	@Override
	public void sendCall() {
		System.out.println("�츮������");
	}
	
	@Override
	public void receiveCall() {
		System.out.println("��ȭ �Ծ��~");
	}
	
	@Override
	public void sendSMS() {
		System.out.println("���ڰ��ϴ�.");
	}
	
	@Override
	public void receiveSMS() {
		System.out.println("���� �Ծ��~");
	}
	
	// MP3Interface�� ��� �߻� �޼ҵ� ����
	@Override
	public void play() {
		System.out.println("������ ����մϴ�.");
	}
	
	@Override
	public void stop() {
		System.out.println("������ �ߴ��մϴ�.");
	}
	
	// �޼ҵ� �߰� �ۼ�
	public void printTimeout() {
		System.out.println(TIMEOUT);
	}
}


public class InterfaceEx {
	public static void main(String[] args) {
		SamsungPhone phone = new SamsungPhone();
		phone.printLogo();
		phone.sendCall();
		phone.receiveCall();
		phone.sendSMS();
		phone.receiveSMS();
		phone.play();
		phone.stop();
		System.out.printf("3�� 5�� ���ϸ� %d\n", phone.calculate(3, 5));
		phone.printTimeout();
	}
}
