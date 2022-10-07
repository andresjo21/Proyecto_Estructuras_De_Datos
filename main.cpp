#include "Util.h"
#include "Integer.h"

int main() {
    //cout << "Division: " << (ip2 / ip3).toString() << endl;*/

    Integer first("12345");
    Integer second("12345");

    if (first == second) {
        cout << "first and second are equal!\n";
    } else
        cout << "Not equal!\n";

    Integer third("10000");
    Integer fourth("100000");
    if (third < fourth) {
        cout << "third is smaller than fourth!\n";
    }
    Integer fifth("10000000");
    if (fifth > fourth) {
        cout << "fifth is larger than fourth!\n";
    }

    Integer six("2000000000");
    Integer seven("2");


    // Printing all the numbers
    cout << "first = " << first << '\n';
    cout << "second = " << second << '\n';
    cout << "third = " << third << '\n';
    cout << "fourth = " << fourth << '\n';
    cout << "fifth = " << fifth << '\n';

    // Incrementing the value of first
    first++;
    cout << "After incrementing the"
         << " value of first is : ";
    cout << first << '\n';
    Integer sum;
    sum = (fourth + fifth);
    cout << "Sum of fourth and fifth = "
         << sum << '\n';
    Integer rest;
//    rest = (six - seven);
//    cout << "Res of six and seven = "
//         << rest.toString() << '\n';
    Integer product;
    product = second * third;
    cout << "Product of second and third = "
         << product << '\n';

/*// Print the fibonaccii number from 1 to 100
    cout << "-------------------------Fibonacci"
         << "------------------------------\n";
    for (int i = 0; i <= 100; i++) {
        Integer fib;
        fib = fib.fibonacci(i);
        cout << "Fibonacci " << i << " = " << fib << '\n';
    }

    // Calculating factorial of from 1 to 100
    cout << "-------------------------Factorial"
         << "------------------------------\n";
    for (int i = 0; i <= 100; i++) {
        Integer fact;
        fact = fact.factorial(i);
        cout << "Factorial of "
             << i << " = ";
        cout << fact << '\n';
    }*/
    cout<<"Division de "<<six.toString()<<" / "<<seven.toString()<<" =  "<<(six/seven).toString()<<endl;
    return 0;
}
