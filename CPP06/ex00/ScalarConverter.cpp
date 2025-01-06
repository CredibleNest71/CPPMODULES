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
        return (CHAR)
    if (!str.compare("nan"))
        return (NAN);
    if (!str.compare("+inf"))
        return (INF_MAX);
    if (!str.compare("-inf"))
        return (INF_MIN);
    if (str.find_first_not_of("0123456789+-") == std::string::npos)
        return (INT);
    if (str.back() == 'f')
        return (FLOAT);
    if (str.at(str.find_first_not_of("0123456789+-")) == '.')
        return (DOUBLE);
    return -1;
}

static bool nonDisplayable(std::string &str){
    for (int i = 0; i < str.size(); i++){
        if (str.at(i) < 32 || str.at(i) > 126){
            std::cout << "not displayable" << std::endl;
            return false;
        }
    }
    return true;
}

static void printInt(std::string str)

void ScalarConverter::convert(std::string &str) {
    int type = getType(str);
    // PRINT CHAR 
    std::cout << "char: ";
    if (str.at(0) == '\'' && str.at(2) == '\''){
        std::cout << str.at(1) << std::endl;
    } else
        std::cout << "not possible" << std::endl;

    //PRINT INT
    

}