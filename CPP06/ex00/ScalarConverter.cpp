#include "ScalarConverter.h"
# define INF_MAX 0
# define INF_MIN 1
# define INT 2
# define FLOAT 3
# define DOUBLE 4
# define NAN 5
# define CHAR 6

static int getType(std::string str) {
    if (str.at(0) == '\'' && str.at(2) == '\'')
        return (CHAR);
    if (!str.compare("nan") || !str.compare("nanf"))
        return (NAN);
    if (!str.compare("+inf") || !str.compare("inf") || !str.compare("inff"))
        return (INF_MAX);
    if (!str.compare("-inf")|| !str.compare("-inff"))
        return (INF_MIN);
    if (str.find_first_not_of("0123456789+-") == std::string::npos)
        return (INT);
    if (str.at(str.size() - 1) == 'f')
        return (FLOAT);
    if (str.at(str.find_first_not_of("0123456789+-")) == '.')
        return (DOUBLE);
    return -1;
}

static void fromInt(std::string str){
    double val = strtod(str.c_str(), NULL);

    if (val >= 32 && val <= 126)
        std::cout << "char: " << static_cast<char>(val) << std::endl;
    else
        std::cout << "char: " << "not displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(val) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(val) << std::endl;
}

static void fromChar(std::string str){
    char val = str[1];

    if (val >= 32 && val <= 126)
        std::cout << "char: " << static_cast<char>(val) << std::endl;
    else
        std::cout << "char: " << "not displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(val) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(val) << "f"  << std::endl;
    std::cout << "double: " << static_cast<double>(val) << std::endl;
}

static void fromFloat(std::string str){
    double val = strtod(str.c_str(), NULL);

    if (val >= 32 && val <= 126)
        std::cout << "char: " << static_cast<char>(val) << std::endl;
    else
        std::cout << "char: " << "not displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(val) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(val) << "f"  << std::endl;
    std::cout << "double: " << static_cast<double>(val) << std::endl;
}

static void fromDouble(std::string str){
    double val = strtod(str.c_str(), NULL);

    if (val >= 32 && val <= 126)
        std::cout << "char: " << static_cast<char>(val) << std::endl;
    else
        std::cout << "char: " << "not displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(val) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(val) << "f"  << std::endl;
    std::cout << "double: " << static_cast<double>(val) << std::endl;
}

static void fromInfMin(){
    std::cout << "char: " << "impossible" << std::endl;
    std::cout << "int: " << "-inf" << std::endl;
    std::cout << "float: " << "-inff" << std::endl;
    std::cout << "double: " << "-inf" << std::endl;
}

static void fromInfMax(){
    std::cout << "char: " << "impossible" << std::endl;
    std::cout << "int: " << "+inf" << std::endl;
    std::cout << "float: " << "+inff" << std::endl;
    std::cout << "double: " << "+inf" << std::endl;
}

static void fromNan(){
    std::cout << "char: " << "impossible" << std::endl;
    std::cout << "int: " << "impossible" << std::endl;
    std::cout << "float: " << "nanf" << std::endl;
    std::cout << "double: " << "nan" << std::endl;
}

static void impossible(){
    std::cout << "char: " << "impossible" << std::endl;
    std::cout << "int: " << "impossible" << std::endl;
    std::cout << "float: " << "impossible" << std::endl;
    std::cout << "double: " << "impossible" << std::endl;
}

void ScalarConverter::convert(std::string &str) {
    if (str.empty())
        return impossible();
    int type = getType(str);
    if (type == -1)
        return impossible();
    switch (type) {
        case INT:
            fromInt(str);
            break;
        case CHAR:
            fromChar(str);
            break;
        case FLOAT:
            fromFloat(str);
            break;
        case DOUBLE:
            fromDouble(str);
            break;
        case INF_MIN:
            fromInfMin();
            break;
        case INF_MAX:
            fromInfMax();
            break;
        case NAN:
            fromNan();
            break;
    }
}