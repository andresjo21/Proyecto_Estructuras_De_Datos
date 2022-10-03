#include "Util.h"
#include "Integer.h"

int main() {
    Integer i1("123456789159999999");
    Integer i2("123456789987654321");
    //i1++;
    //i1--;
    cout << "i1: " << i1.getList()->toString() << endl;

    return 0;
}
