#include "Util.h"
#include "Integer.h"

int main() {
    Integer i1("123454345328385940099849302");
    Integer i2("2");

//    Integer ip2("2432902008176640000");
//    Integer ip3("2432902008176640000");
    Integer ip2("-40");
    Integer ip3("80");

    // Fibonnacci de 1 a 100
//    cout << "-------------------------Fibonacci"
//         << "------------------------------\n";
//    for (int i = 0; i <= 100; i++) {
//        Integer fib;
//        fib = fib.fibonacci(i);
//        cout << "Fibonacci " << i << " = " << fib.toString() << '\n';
//    }


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
    cout << "Suma: " << (ip2 + ip3).toString() << endl;
    //cout << "Resta: " << (ip2 - ip3).toString() << endl;
    //cout << "Division: " << (ip2 / ip3).toString() << endl;
    //cout << "Igualdad: " << (i1 == i2) << endl;
    //cout << "Igualdad: " << (i1 < i2) << endl;
   // cout << "Igualdad: " << (ip2 > ip3) << endl;
    //cout << "Igualdad: " << (i1 >= i2) << endl;
    //cout << "Igualdad: " << (i1 <= i2) << endl;
    if(ip2>ip3){
        cout<<"mayor"<<endl;
    }else
        cout<<"diferente"<<endl;


    return 0;
}
