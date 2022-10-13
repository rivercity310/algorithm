#include <iostream>
#include <sstream>
#include <algorithm>

/*
[ Ex1 : ���� ũ�� �迭 �����ϱ� ]
�б����� �л� ������ �����ϴ� ������ ���� ���α׷�
*/

template <typename T> class dynamic_array {
	T* data;
	size_t n;

public:
	// �����ڿ� ���� ������
	dynamic_array(int n) {
		this->n = n;
		data = new T[n];
	}

	dynamic_array(const dynamic_array<T>& other) {
		n = other.n;
		data = new T[n];

		for (int i = 0; i < n; i++) data[i] = other[i];
	}

	// ����� ���� �����ϱ� ���� [] �����ڿ� at �Լ� �ۼ�
	T& operator[](int idx) {
		return data[idx];
	}

	const T& operator[](int idx) const {
		return data[idx];
	}

	T& at(int idx) {
		if (idx < n) return data[idx];
		throw "Index out of range";
	}


	// �迭�� ũ�⸦ ��ȯ�ϴ� size�� �Ҹ��� ����
	size_t size() const {
		return n;
	}

	~dynamic_array() {
		delete[] data;
	}


	// �� �迭�� ���Ҹ� ��ȸ�� �� ����� �ݺ��� ���� �Լ� ����
	T* begin() { return data; }
	const T* begin() const { return data; }
	T* end() { return data + n; }
	const T* end() const { return data + n; }


	// �� �迭�� �ϳ��� ��ġ�� ������ �����ϴ� + ������ �Լ� ����
	friend dynamic_array<T> operator+(const dynamic_array<T>& arr1, dynamic_array<T>& arr2) {
		dynamic_array<T> result(arr1.size() + arr2.size());
		std::copy(arr1.begin(), arr1.end(), result.begin());
		std::copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());

		return result;
	}


	// �迭�� ����� ��� �����͸� ���ڿ��� ��ȯ�ϴ� �Լ�
	std::string to_string(const std::string& sep = ", ") {
		if (n == 0) return "";

		std::ostringstream os;
		os << data[0];
		for (int i = 1; i < n; i++) os << sep << data[i];

		return os.str();
	}
};

// �л� ������ ������ ����ü ����
struct student {
	// �л��� �̸��� �б� ����
	std::string name;
	int standard;
};

std::ostream& operator<<(std::ostream& os, const student& s) {
	return (os << "[" << s.name << ", " << s.standard << "]");
}

void std_array_ex1() {
	int n;
	std::cout << "1�� �л� ��? ";
	std::cin >> n;

	dynamic_array<student> class1(n);
	for (int i = 0; i < n; i++) {
		std::string name;
		int standard;

		std::cout << i + 1 << "��° �л��� �̸��� ���̸� �Է�: ";
		std::cin >> name >> standard;

		class1[i] = student{ name, standard };
	}

	// ���� ����
	auto class2 = class1;
	std::cout << "1���� �����Ͽ� 2�� ����: " << class2.to_string() << std::endl;

	// �� �б��� ���ļ� ���ο� ū �б� ����
	auto class3 = class1 + class2;
	std::cout << "1�ݰ� 2���� ���� 3�� ����: " << class3.to_string() << std::endl;
}