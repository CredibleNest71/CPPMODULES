#ifndef EASYFIND_H
# define EASYFIND_H
# include <iostream>
# include <vector>
# include <list>
# include <algorithm>
# include <exception>
# include <deque>

class NotFoundException : public std::exception{
public:
    const char *what() throw(){
        return "Could not find element";
    }
};

template <typename T>
typename T::iterator easyfind(T &vec, int n){
    typename T::iterator it = std::find(vec.begin(), vec.end(), n);
    if (it == vec.end())
        throw NotFoundException();
    return it;
}
#endif