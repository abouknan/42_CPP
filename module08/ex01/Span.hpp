#pragma once

#include <vector>
#include <iostream>  
#include <algorithm>
#include <stdexcept> 

using std::cerr;
using std::cout;
using std::endl;
using std::exception;
using std::logic_error;
using std::overflow_error;
using std::vector;

class Span
{
private:
    unsigned int _maxSize; 
    vector<int> _numbers;  

public:
    Span(unsigned int N);               
    Span(const Span &other);            
    Span &operator=(const Span &other); 
    ~Span();                           

    void addNumber(int number);                                              
    void addNumbers(vector<int>::iterator begin, vector<int>::iterator end); 
    int shortestSpan();                                                     
    int longestSpan();           
};
