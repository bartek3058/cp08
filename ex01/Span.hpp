#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>

class Span
{
    private:
            unsigned int        _n;
            std::vector<int>    _vec;

    public:
            Span();
            Span(unsigned int n);
            Span(const Span& src);
            Span& operator=(const Span& src);
            ~Span();

            void addNumber(int number);

            int shortestSpan() const;
            int longestSpan() const;

            template <typename Iterator>
            void addNumber(Iterator begin, Iterator end)
            {
                if (std::distance(begin, end) > _n - _vec.size())
                    throw Span::FullException();
                _vec.insert(_vec.end(), begin, end);
            }

             class FullException : public std::exception
            {
                public:
                        virtual const char* what() const throw();
            };

            class NotEnoughElementsException : public std::exception
            {
                public:
                        virtual const char* what() const throw();
            };
};
#endif