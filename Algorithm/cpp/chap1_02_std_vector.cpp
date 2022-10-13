#include <iostream>
#include <vector>

void chap1_vector() {
	// ũ�Ⱑ 0�� ���� ����
	std::vector<int> vec;

	// ������ �ʱ갪���� �̷���� ũ�Ⱑ 5�� ���� ����
	std::vector<int> vec2 = { 1, 2, 3, 4, 5 };

	// ũ�Ⱑ 10�� ���� ����
	std::vector<int> vec3(10);

	// ũ�Ⱑ 10�̰�, ��� ���Ұ� 5�� �ʱ�ȭ�� ���� ����
	std::vector<int> vec4(10, 5);

	vec4.push_back(1);
	vec4.push_back(2);
	vec4.insert(vec4.begin(), 0);    // �� �տ� 0 �߰�
	vec4.insert(find(vec4.begin(), vec4.end(), 1), 4);  // 1 �տ� 4 �߰�

	// emplace: �� ���� ��ġ�� ��ٷ� ��ü ���� -> insert�� push_back�� ���� ���� ����
	vec4.emplace(vec4.begin(), 11);   // �� �տ� 11 �߰�
	vec4.emplace_back(12);			  // �� �ڿ� 12 �߰�
	
	vec4.pop_back();				// �� �� ���� �ϳ� ����
	vec4.erase(vec4.begin());		// �� ó�� ���� ����
	vec4.erase(vec4.begin(), vec4.begin() + 4);  // 1��° ���Һ��� 4���� �� ���ұ��� ����
	
	for (auto element : vec4) std::cout << element << " ";
	std::cout << std::endl;

	vec4.clear();          // ��� ���� ����
	vec4.reserve(100);     // ���Ϳ��� ����� �뷮 ����
	vec4.shrink_to_fit();  // ������ �޸� ������ ���� (�뷮 = ũ��)
}