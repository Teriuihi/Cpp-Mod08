#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>

class Span {
private:
	unsigned int len, contains;
	std::vector<int> data;
	int span(int (*calcSpan)(int shortest, int curr));
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
