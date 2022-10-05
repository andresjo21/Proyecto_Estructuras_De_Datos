#include "Util.h"
#include "Integer.h"

int main() {
    Integer i1("1111111111");
    Integer i2("3555555555");
    //i1++;
    //i1--;
    //cout << "i1: " << i1.getList()->toString() << endl;
    //cout << "Suma: " << (i1 + i2).getList()->toString() << endl;
    cout << "Resta: " << (i1 - i2).getList()->toString() << endl;

    return 0;
}
