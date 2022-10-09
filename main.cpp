#include "Util.h"
#include "Integer.h"

int main() {
    cout<<"100! = " << Integer::factorial(100).toString() << endl;
    cout<<"Fibonacci(1000) = " << Integer::fibonacci(1000).toString() << endl;
    cout<<"C(10, 5) = " << Integer::combinations(10, 5 ).toString() << "  C(10, 3) = " << Integer::combinations(10, 3 ).toString() << endl;
    cout<<"C(10, 2) = " << Integer::combinations(10, 2 ).toString() << endl;

    return 0;
}
