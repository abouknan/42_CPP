#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &other) { (void)other; }

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
    (void)other;
    return *this;
}

void printImpossible()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

void toChar(double value)
{
    if (std::isnan(value) || std::isinf(value) || 
        value < std::numeric_limits<char>::min() || 
        value > std::numeric_limits<char>::max())
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    char c = static_cast<char>(value);
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl; 
    else
    std::cout << "char: Non displayable" << std::endl;
}

void toInt(double value)
{
    if (std::isnan(value) || std::isinf(value) || 
        value < std::numeric_limits<int>::min() || 
        value > std::numeric_limits<int>::max())
    {
        std::cout << "int: impossible\n";
        return;
    }
    std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void toFloat(double value)
{
    std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
}

void toDouble(double value)
{
    std::cout << "double: " << value << std::endl;
}

void printConvertedResult(double value) 
{
    std::cout << std::fixed << std::setprecision(1);
    toChar(value);
    toInt(value);
    toFloat(value);
    toDouble(value);
}

void ScalarConverter::convert(const std::string& literal)
{
    if (literal.c_str() == '\0')
    {
        printImpossible();
        return;
    }
    if (literal.size() == 1 && !std::isdigit(literal[0]))
    {
        printConvertedResult(static_cast<double>(literal[0]));
        return;
    }
    errno = 0;
    char *end;
    double value = strtod(literal.c_str(), &end);
    if ((*end != '\0' && (*end != 'f' || *(end + 1) != '\0')) ||
      end == literal.c_str() || errno != 0)
    {
        printImpossible();
        return;
    }
    printConvertedResult(value);
}
