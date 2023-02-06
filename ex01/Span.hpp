#ifndef SPAN_HPP
#define SPAN_HPP
#include <set>

class Span {
private:
	unsigned int len, contains;
	std::multiset<int> data;
public:
	Span(int n);
	int shortestSpan();
	int longestSpan();
	void addNumber(int x);
	void addRange(int x, int y);
	class SpanFullException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class NotEnoughEntriesException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
};


#endif
