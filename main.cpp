#include "Util.h"
#include "Integer.h"

int main() {
    Integer i1("999999999");
    Integer i2("999999999");
    //i1++;
    //i1--;
    //cout << "i1: " << i1.getList()->toString() << endl;
    cout << "suma: " << (i1 + i2).getList()->toString() << endl;

    return 0;
}
