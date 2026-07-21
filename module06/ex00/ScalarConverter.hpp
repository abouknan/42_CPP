#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cerrno>
#include <cstdlib>
#include <cctype>

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter&);
    ScalarConverter& operator=(const ScalarConverter&);
    ~ScalarConverter();

    static void printImpossible();
    static void printConvertedResult(double value);
    static void toChar(double value);
    static void toInt(double value);
    static void toFloat(double value);
    static void toDouble(double value);

public:
    static void convert(const std::string& literal);
};

#endif