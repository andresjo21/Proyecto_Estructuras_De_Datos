#include "Util.h"
#include "Integer.h"

int main() {
    Integer i1("123454345328385940099849302");
    Integer i2("25");

    Integer ip2("2432902008176640000");
    Integer ip3("2432902008176640000");

    // Fibonnacci de 1 a 100
    cout << "-------------------------Fibonacci"
         << "------------------------------\n";
    for (int i = 0; i <= 100; i++) {
        Integer fib;
        fib = fib.fibonacci(i);
        cout << "Fibonacci " << i << " = " << fib.toString() << '\n';
    }


    //Calculo del factorial de 1 a 100
    /*cout << "-------------------------Factorial"
         << "------------------------------\n";

    for (int i = 0; i <= 100; i++) {
        Integer fact;
        fact = fact.factorial(i);
        cout << "Factorial of "
             << i << " = ";
        cout << fact.toString() << '\n';
    }*/

    //cout<<*i2.getList()->get(0)<<endl;
    //i1++;
    //i1--;
    //cout << "i1: " << i1.getList()->toString() << endl;
    //cout << "Suma: " << (i1 + i2).toString() << endl;
    //cout << "Resta: " << (i1 - i2).getList()->toString() << endl;
    //cout << "Igualdad: " << (i1 == i2) << endl;
    //cout << "Igualdad: " << (i1 < i2) << endl;
    //cout << "Igualdad: " << (i1 > i2) << endl;
    //cout << "Igualdad: " << (i1 >= i2) << endl;
    //cout << "Igualdad: " << (i1 <= i2) << endl;


    return 0;
}
