#include "Util.h"
#include "Integer.h"

int main() {
    Integer i1("1111111111");
    Integer i2("11111111111");
    Integer ip("1000000000");
    Integer ip3("2000000000");
    Integer ip2("3");

   cout<<(ip2*ip).toString()<<endl;

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


    //TESTS

    LinkedList<long> l1 ;
    for(long i=0;i<15;i++){
        long* f = new long (i);
        l1.add(f);
    }
    cout<<l1.toString()<<endl;

    return 0;
}
