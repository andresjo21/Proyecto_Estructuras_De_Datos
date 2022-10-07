#include "Util.h"
#include "Integer.h"

int main() {
    Integer i1("123454345328385940099849302");
    Integer i2("25");

    Integer ip;
    Integer ip2("2432902008176640000");

    cout << "-------------------------Factorial"
         << "------------------------------\n";
    for (int i = 0; i <= 22; i++) {
        Integer fact;
        fact = fact.factorial(i);
        cout << "Factorial of "
             << i << " = ";
        cout << fact.toString() << '\n';
    }

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
    //cout<<(i1*i2).toString()<<endl;


    return 0;
}
