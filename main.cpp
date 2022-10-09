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

    Integer six("30");
    Integer seven("31");


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
    rest = (six - seven);
       cout << "Res of six and seven = "
         << rest.toString() << '\n';
    Integer product;
    product = second * third;
    cout << "Product of second and third = "
         << product << '\n';
    Integer modulus;
    modulus = second % third;
    cout << "modulus of second and third = "
         << modulus << '\n';

// Print the fibonaccii number from 1 to 100

        Integer fib;
        fib = fib.fibonacci(1000);
        cout << "Fibonacci " << 1000 << " = " << fib.toString() << '\n';


    /*// Calculating factorial of 1000
        Integer fact;
        cout << "Factorial of 1000: ";
        cout << fact.factorial(1000).toString() << '\n';*/


    /*Integer con;
    cout << "-------------------------Combinations"
         << "------------------------------\n";
    cout << "Combinations of 1000 and 350 = " <<
    con.combinations(1000, 350).toString() << '\n';*/

    //cout << "Modulus of 1000 and 350 = " << (fifth % fourth).toString() << '\n';


    return 0;
}
