#include "easyfind.hpp"
#include <array>

int main() {
	std::array<int, 6> ar = {1, 2, 3, 4, 5, 6};
	try {
		std::cout << *easyfind(ar, 3) << std::endl;
		std::cout << *easyfind(ar, 0) << std::endl;
	} catch (NotFoundException &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}