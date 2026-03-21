#include "Span.hpp"
#include <algorithm>
#include <limits>

Span::Span() : _n(0) {}
Span::Span(unsigned int n) : _n(n) {}
Span::Span(const Span& src) : _n(src._n), _vec(src._vec){}
Span& Span::operator=(const Span& src)
{
    if (this != &src)
    {
        this->_n = src._n;
        this->_vec = src._vec;
    }
    return *this;
}
Span::~Span() {}

void Span::addNumber(int number)
{
    if (_vec.size() >= _n)
        throw Span::FullException();
    _vec.push_back(number);
}

int Span::longestSpan() const
{
    if (_vec.size() <= 1)
        throw Span::NotEnoughElementsException();
    int min = *std::min_element(_vec.begin(), _vec.end());
    int max = *std::max_element(_vec.begin(), _vec.end());
    return (max - min);
}

int Span::shortestSpan() const
{
    if (_vec.size() <= 1)
        throw Span::NotEnoughElementsException();
    std::vector<int> copy = _vec;
    std::sort(copy.begin(), copy.end());

    int shortest = std::numeric_limits<int>::max();

    for (size_t i = 0; i < copy.size() - 1; i++)
    {
        int diff = copy[i + 1] - copy[i];
        if (diff < shortest)
            shortest = diff;
    }
    return shortest;
}

const char* Span::FullException::what() const throw()
{
    return "Span is already full!";
}

const char* Span::NotEnoughElementsException::what() const throw()
{
    return "Not enough elements to calculate span!";
}