#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <sstream>
#include <cstdlib>
#include <cmath>

static bool isPseudo(const std::string& s)
{
    return (s == "nan" || s == "nanf" || s == "+inf" || s == "-inf" || s == "+inff" || s == "-inff");
}

static bool isCharLiteral(const std::string& s)
{
    return (s.size() == 3 && s[0] == '\'' && s[2] == '\'');
}

void ScalarConverter::convert(std::string literal)
{
    // detect char literal 'c'
    if (isCharLiteral(literal))
    {
        char c = literal[1];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
        return;
    }

    // handle pseudo-literals
    if (isPseudo(literal))
    {
        bool isFloat = (!literal.empty() && literal[literal.size() - 1] == 'f');
        std::string base = literal;
        if (isFloat) base = literal.substr(0, literal.size() - 1);
        // char impossible
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << (isFloat ? literal : base + "f") << std::endl;
        std::cout << "double: " << base << std::endl;
        return;
    }

    // try parse as int
    char *endptr = NULL;
    long lv = std::strtol(literal.c_str(), &endptr, 10);
    if (*endptr == '\0')
    {
        // it's an int
        if (lv < std::numeric_limits<int>::min() || lv > std::numeric_limits<int>::max())
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
        }
        else
        {
            int iv = static_cast<int>(lv);
            if (iv >= 32 && iv <= 126)
                std::cout << "char: '" << static_cast<char>(iv) << "'" << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
            std::cout << "int: " << iv << std::endl;
            {
                std::ostringstream oss;
                oss << static_cast<float>(iv);
                std::string fs = oss.str();
                if (fs.find('.') == std::string::npos)
                    fs += ".0";
                std::cout << "float: " << fs << "f" << std::endl;
            }
            {
                std::ostringstream oss;
                oss << static_cast<double>(iv);
                std::string ds = oss.str();
                if (ds.find('.') == std::string::npos)
                    ds += ".0";
                std::cout << "double: " << ds << std::endl;
            }
        }
        return;
    }

    // try parse as float (with optional trailing f)
    bool hasF = false;
    std::string s = literal;
    if (!literal.empty() && literal[literal.size() - 1] == 'f') { hasF = true; s = literal.substr(0, literal.size() - 1); }

    // parse double
    char *endptrd = NULL;
    double dv = std::strtod(s.c_str(), &endptrd);
    if (*endptrd == '\0')
    {
        // it's a float/double literal
        // char
        if (std::isnan(dv) || std::isinf(dv) || dv < std::numeric_limits<char>::min() || dv > std::numeric_limits<char>::max())
            std::cout << "char: impossible" << std::endl;
        else if (dv >= 32 && dv <= 126)
            std::cout << "char: '" << static_cast<char>(dv) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;

        // int
        if (std::isnan(dv) || std::isinf(dv) || dv < std::numeric_limits<int>::min() || dv > std::numeric_limits<int>::max())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(dv) << std::endl;

        // float
        {
            float fv = static_cast<float>(dv);
            std::ostringstream oss;
            oss << fv;
            std::string fs = oss.str();
            if (fs.find('.') == std::string::npos)
                fs += ".0";
            std::cout << "float: " << fs << "f" << std::endl;
        }

        // double
        {
            std::ostringstream oss;
            oss << dv;
            std::string ds = oss.str();
            if (ds.find('.') == std::string::npos)
                ds += ".0";
            std::cout << "double: " << ds << std::endl;
        }
        return;
    }

    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}
