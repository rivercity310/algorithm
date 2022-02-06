package Thread;

import java.lang.Runnable;

class TimerRunnable implements Runnable {
	private int n = 0;
	
	@Override
	public void run() {
		while (true) {
			System.out.println(n++);
			try {
				// Runnable �������̽����� sleep�� ������, Thread Ŭ������ static�̹Ƿ� ������ ���� ��밡��
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				System.out.println(e);
				return;
			}
		}
	}
}

public class RunnableEx {
	public static void main(String[] args) {
		var th = new Thread(new TimerRunnable());
		th.start();
	}
}
