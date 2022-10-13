package Thread;

import java.lang.Thread;
import java.awt.*;
import javax.swing.*;

class TimerThread extends Thread {
	private JLabel timerLabel;   // Ÿ�̸� ���� ��µ� ���̺�
	private int n = 0;
	
	public TimerThread(JLabel timerLabel) {
		this.timerLabel = timerLabel;
	}
	
	// Thread�� run() �޼ҵ带 �������̵��Ѵ�. run �޼ҵ忡 �ۼ��� �ڵ带 ������ �ڵ��� �θ���.
	@Override
	public void run() {
		while (true) {
			timerLabel.setText(Integer.toString(n++));;
			try {
				sleep(1000);
			} catch(InterruptedException e) {
				return;    // ���ܰ� �߻��ϸ� ������ ����
			}
		}
	}
}

public class ThreadEx extends JFrame {
	public ThreadEx() {
		setTitle("Thread�� ��ӹ��� Ÿ�̸� ������ ����");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		
		// Ÿ�̸� ���� ����� ���̺� ����
		JLabel timerLabel = new JLabel();
		timerLabel.setFont(new Font("Gothic", Font.ITALIC, 80));
		c.add(timerLabel);
		
		// Ÿ�̸� ������ ��ü ����, Ÿ�̸� ���� ����� ���̺� �����ڿ� ����
		TimerThread th = new TimerThread(timerLabel);
		
		setSize(300, 170);
		setVisible(true);
		
		th.start();
	}
	
	public static void main(String[] args) {
		new ThreadEx();
	}
}
