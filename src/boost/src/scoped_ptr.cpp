#include "boost/scoped_ptr.hpp"
#include <iostream> 

class foo {
public:
    ~foo() {
        std::cout << "oh noes" << std::endl;
    }
};

int main(int argc, char** argv)
{
    boost::scoped_ptr<int> p(new int);
    boost::scoped_ptr<foo> f(new foo());

    *p = 10;
    for (int i = 0; i < 10; i++) {
        (*p)++;
        std::cout << *p << std::endl;
    }

    return 0;
}
