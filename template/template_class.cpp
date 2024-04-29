#include <stdio.h>

class A {

public:
    int a;

    A operator + (A const &y) {
        A res;
        res.a = this->a + y.a;
        return res;
    }
};


template<typename T>
T add(T x, T y) {
    return x + y;
}


int main() {
    A x, y;
    add<A>(x, y);
}


