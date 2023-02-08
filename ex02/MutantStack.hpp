#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
template <class T>

class MutantStack: public std::stack<T> {
public:
	typedef std::stack<T> stack;
	typedef typename stack::container_type container;
	typedef typename container::iterator mIterator;

	MutantStack(): stack() {
		std::cout << "MutantStack created with default constructor" << std::endl;
	}

	MutantStack(const stack &src) {
		this->stack = src;
		std::cout << "MutantStack created with copy constructor" << std::endl;
	}

	~MutantStack() {
		std::cout << "MutantStack de-constructed" << std::endl;
	}

	mIterator begin() {
		return stack::c.begin();
	}

	mIterator end() {
		return stack::c.end();
	}
};
#endif