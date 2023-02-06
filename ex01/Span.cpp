#include "Span.hpp"

Span::Span(int n): len(n), contains(0) {
	this->data = std::multiset<int>();
}

int Span::shortestSpan() {
	if (contains <= 1)
		throw NotEnoughEntriesException();
	//TODO implement
	return 0;
}

int Span::longestSpan() {
	if (contains <= 1)
		throw NotEnoughEntriesException();
	//TODO implement
	return 0;
}

void Span::addNumber(int x) {
	if (len == contains)
		throw SpanFullException();
	data.insert(x);
	contains++;
}

void Span::addRange(int x, int y) {
	if (x > y)
		return;
	std::multiset<int>::iterator a = data.insert(x);
	x++;
	for (; x < y; x++) {
		a = data.insert(a, x);
	}
}

const char *Span::SpanFullException::what() const throw() {
	return "This span is full.";
}

const char *Span::NotEnoughEntriesException::what() const throw() {
	return "This span does not have enough entries to get shortest/longest span.";
}
