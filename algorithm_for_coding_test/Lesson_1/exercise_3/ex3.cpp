#include <string>
#include <iostream>
#include <forward_list>





typedef struct 
{
	std::string name;
	int age;
} citizen;

std::ostream& operator<<(std::ostream& os, const citizen& s) 
{
	return (os << "[" << s.name << ", " << s.age << "]");
}





int main() 
{

	std::forward_list<citizen> citizens = {
		{"Kim", 22},
		{"Lee", 25},
		{"Park", 18},
		{"Jin", 16},
	};

	auto citizens_copy = citizens;

	std::cout << "전체 시민들 : ";
	for (const auto& c : citizens) 
	{
		std::cout << c << " ";
	}

	std::cout << std::endl;

	citizens.remove_if([](const citizen& c) {
		return (c.age < 18);
	});

	std::cout << "투표권이 있는 시민: ";
	for (const auto& c : citizens)
		std::cout << c << " ";
	std::cout << std::endl;

	citizens_copy.remove_if([](const citizen& c) {
		return (c.age != 18);
		});

	std::cout << "내년에 투표권이 생기는 시민: ";
	for (const auto& c : citizens_copy)
		std::cout << c << " ";
	std::cout << std::endl;

	return 0;
}