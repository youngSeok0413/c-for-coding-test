#include <array>
#include <iostream>
#include <type_traits>

//모두 수의 형태로 전환될 수 있으므로, 하나의 형으로 통일한다. 아래의 경우에는 float

template<typename ... Args>
auto build_array(Args&&... args) -> std::array<typename std::common_type<Args...>::type, sizeof...(args)> {
	using commonType = typename std::common_type<Args...>::type;
	return { std::forward<commonType>((Args&&)args)... };
}


int main() {
	auto data = build_array(1, 0u, 'a', 3.2f, false);

	for (auto i : data)
		std::cout << i << " ";

	std::cout << std::endl;

	//auto data2 = build_array(1, "Packt", 2.0);

	return 0;
}