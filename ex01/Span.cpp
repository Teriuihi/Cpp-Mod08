#include "Span.hpp"

static int shortestSpanFunc(int shortest, int curr) {
	return curr < shortest ? curr : shortest;
}

static int longestSpanFunc(int longest, int curr) {
	return curr > longest ? curr : longest;
}

Span::Span(int n): len(n), contains(0) {
	this->data = std::vector<int>();
}

int Span::shortestSpan() {
	return span(shortestSpanFunc);
}

int Span::longestSpan() {
	return span(longestSpanFunc);
}

int Span::span(int (*calcSpan)(int, int)) {
	if (contains <= 1)
		throw NotEnoughEntriesException();
	std::vector<int>::iterator it = data.begin();
	int span = std::abs(*it - *(++it));
	for (; it != --data.end();) {
		int tmp = std::abs(*it - *(++it));
		span = calcSpan(tmp, span);
	}
	return span;
}

void Span::addNumber(int x) {
	if (len == contains)
		throw SpanFullException();
	data.insert(data.end(), x);
	contains++;
}

/**
 * Includes x, not y
 * @param x first int to add
 * @param y first int not to add since x
 */
void Span::addRange(int x, int y) {
	if (x > y)
		return;
	for (; x < y; x++) {
		addNumber(x);
	}
}

const char *Span::SpanFullException::what() const throw() {
	return "This span is full.";
}

const char *Span::NotEnoughEntriesException::what() const throw() {
	return "This span does not have enough entries to get shortest/longest span.";
}
