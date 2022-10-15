#pragma once
// ������ ���κ��� �Ÿ� ������ �����ϱ� ���� ����ü
template <typename T>
struct Label {
	unsigned ID;
	T distance;

	// Label ��ü �񱳴� �Ÿ� ���� �̿�
	inline bool operator>(const Label<T>& l) const {
		return this->distance > l.distance;
	}
};
