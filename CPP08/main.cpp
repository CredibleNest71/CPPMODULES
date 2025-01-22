

#include "easyfind.hpp"

int main(){

    std::cout << "\033[33m" << "VECTOR"<< "\033[0m" << std::endl;
    std::vector<int> vec;
    int search1 = 10;
    int search2 = 123;
    int search3 = 15;

    vec.push_back(10);
    vec.push_back(1);
    vec.push_back(123);
    vec.push_back(-10);

    std::vector<int>::iterator found;
    found = easyfind(vec, search1);
    std::cout << "Found: " << *found << std::endl;
    found = easyfind(vec, search2);
    std::cout << "Found: " << *found << std::endl;
    try {
        found = easyfind(vec, search3);
        std::cout << "Found: " << *found << std::endl;
    } catch(NotFoundException& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\033[33m" << "LIST"<< "\033[0m" << std::endl;
    std::list<int> list;
    list.push_back(10);
    list.push_back(1);
    list.push_back(123);
    list.push_back(-10);
    std::list<int>::iterator foundl;
    foundl = easyfind(list, search1);
    std::cout << "Found: " << *foundl << std::endl;
    foundl = easyfind(list, search2);
    std::cout << "Found: " << *foundl << std::endl;
    try {
        foundl = easyfind(list, search3);
        std::cout << "Found: " << *foundl << std::endl;
    } catch(NotFoundException& e) {
        std::cout << e.what() << std::endl;
    }


    std::cout << "\033[33m" << "DEQUE"<< "\033[0m" << std::endl;
    std::deque<int> dq;
    dq.push_back(10);
    dq.push_back(1);
    dq.push_back(123);
    dq.push_back(-10);
    std::deque<int>::iterator f;
    f = easyfind(dq, search1);
    std::cout << "Found: " << *f << std::endl;
    f = easyfind(dq, search2);
    std::cout << "Found: " << *f << std::endl;
    try {
        f = easyfind(dq, search3);
        std::cout << "Found: " << *f << std::endl;
    } catch(NotFoundException& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}