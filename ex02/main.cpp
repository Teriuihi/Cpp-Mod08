#include <stack>
#include <iostream>
#include <list>
#include "MutantStack.hpp"

void mutantStack() {
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
//[...]
	mstack.push(0);
	MutantStack<int>::mIterator it = mstack.begin();
	MutantStack<int>::mIterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void normalList() {
	std::list<int> nList;
	nList.push_back(5);
	nList.push_back(17);
	std::cout << nList.back() << std::endl;
	nList.pop_back();
	std::cout << nList.size() << std::endl;
	nList.push_back(3);
	nList.push_back(5);
	nList.push_back(737);
//[...]
	nList.push_back(0);
	std::list<int>::iterator it = nList.begin();
	std::list<int>::iterator ite = nList.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> s(nList);
}

int main() {
	std::cout << "\t---My stack---\n" << std::endl;
	mutantStack();
	std::cout << "\t---Normal list---\n" << std::endl;
	normalList();
	return 0;
}