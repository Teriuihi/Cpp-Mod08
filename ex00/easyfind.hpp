#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <algorithm>
#include <iostream>

class NotFoundException: public std::exception {
private:
public:
	virtual const char *what() const throw() {
		return ("Unable to find what you're looking for.");
	}
};

template <typename T>
typename T::iterator easyfind(T &t, int find) {
	typename T::iterator a;
	a = std::find(t.begin(), t.end(), find);
	if (a == t.end() && find != *t.end())
		throw NotFoundException();
	return a;
}


#endif