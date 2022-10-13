#include <array>
#include <iostream>
#include <type_traits>

/*
[ Ex2. ������ �������� ������ ���� �����̳� ����� ]
�پ��� Ÿ���� ������ ���� ���� ���ڷ� �޾� ���� Ÿ������ ��ȯ�ϴ� �Լ�
*/

// �Լ� ��ȯ���� ���� ���� Ÿ������ ����
template <typename ...Args> 
auto build_array(Args&&... args)->std::array<typename std::common_type<Args...>::type, sizeof...(args)> {
	using commonType = typename std::common_type<Args...>::type;
	return { std::forward<commonType>((Args&&)args)... };
}

void std_array_ex2() {
	auto data = build_array(1, 0u, 'a', 3.2f, false);

	for (auto i : data) std::cout << i << " ";
	std::cout << std::endl;
}