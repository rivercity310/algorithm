package Generic;

import java.util.Stack;

class GenericStack<T> {
	int size;
	int tos;
	Object[] stack;	// ���ÿ� ��Ҹ� ������ ���� �迭
	
	public GenericStack(int size) {
		this.size = size;
		this.tos = 0;
		stack = new Object[size];  // ���׸� �Ű������� ��ü�� ������ �� �����Ƿ� Object �迭 �̿�
	}
	
	public void push(T item) {
		if (tos == 10) return;	// ������ ���� ��
		stack[tos] = item;
		tos++;
	}
	
	@SuppressWarnings("unchecked")
	public T pop() {
		if (tos == 0) return null;	// ������ ��� ����
		
		tos--;
		return (T)stack[tos]; 		// Ÿ�� �Ű����� Ÿ������ �ٿ�ĳ����
	}
	
	public int getLength() {
		return this.size;
	}
}

class GenericMethodEx {
	// Ÿ�� �Ű������� �޼ҵ��� ���� Ÿ�� �տ� �����Ѵ�.
	static <T> void toStack(T[] a, GenericStack<T> gs) {
		for (int i = 0; i < a.length; i++)
			gs.push(a[i]);
	}
	
	static <V> GenericStack<V> reverse(GenericStack<V> a) {
		GenericStack<V> s = new GenericStack<V>(a.getLength());
		
		while (true) {
			V temp = a.pop();
			if (temp == null) break;
			else s.push(temp);
		}
		
		return s;
	}
}

public class GenericClassEx {
	public static void main(String[] args) {
		var gs = new GenericStack<Double>(5);
		
		for (int i = 0; i < gs.getLength(); i++)
			gs.push(Double.valueOf(i));
		
		gs = GenericMethodEx.reverse(gs);
		for (int i = 0; i < gs.getLength(); i++)
			System.out.println(gs.pop());
		
		
		var st = new Stack<Integer>();
		st.push(1);
		System.out.println(st.pop());
	}
}