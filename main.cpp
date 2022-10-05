#include "Util.h"
#include "Integer.h"

int main() {
    Integer i1("1111111111");
    Integer i2("11111111111");
    Integer ip("4");
    Integer ip2("3");
    Integer i3;
//    i3=ip*ip2;

i3 =ip*ip2;
    cout<<i3.getList()->toString()<<endl;

    //cout<<*i2.getList()->get(0)<<endl;
    //i1++;
    //i1--;
    //cout << "i1: " << i1.getList()->toString() << endl;
    //cout << "Suma: " << (i1 + i2).getList()->toString() << endl;
    //cout << "Resta: " << (i1 - i2).getList()->toString() << endl;
    //cout << "Igualdad: " << (i1 == i2) << endl;
    //cout << "Igualdad: " << (i1 < i2) << endl;
    //cout << "Igualdad: " << (i1 > i2) << endl;
    //cout << "Igualdad: " << (i1 >= i2) << endl;
    //cout << "Igualdad: " << (i1 <= i2) << endl;


    return 0;
}
