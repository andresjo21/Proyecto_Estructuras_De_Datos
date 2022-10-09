#include "Integer.h"

Integer::Integer(Integer &l) {
    this->list = l.getList();
}

Integer::Integer(string s) {
    this->list = new LinkedList<long>;
    string aux;
    int i = s.size() - 1;
    int counter = 0;
    while (i >= 0) {
        aux = s[i] + aux;
        counter++;
        if (counter == 9 || i == 0) {
            long num2 = 0;
            for (int j = 0; j < aux.size(); ++j) {
                num2 += (aux[j] - '0') * pow(10, aux.size() - j - 1);
            }
            long *num = new long(num2);
            this->list->add(num);
            aux = "";
            counter = 0;
        }
        i--;
    }
}
Integer::Integer(){
    list = new LinkedList<long>;
}

Integer::Integer(int n){
    Integer(to_string(n));
}

Integer::~Integer() {
}

LinkedList<long> *Integer::getList() const {
    return list;
}

bool Null(const Integer& a) {
    if (a.getList()->size() == 1 && a.getList()->get(0) == 0)
        return true;
    return false;
}

//------- Overloading Operators --------

//Direct assigment
Integer &Integer::operator=(const Integer &a) {;
    this->list = a.getList();
    return *this;
}

//Incremention
Integer &Integer::operator++() {
    int i, n;
    for (i = this->list->size() - 1; i >= 0; i--) {
        if (i == this->list->size() - 1) {
            if (*this->list->get(i) == 999999999) {
                *this->list->get(i) = 0;
                *this->list->get(i - 1) += 1;
            } else {
                *this->list->get(i) += 1;
            }
        }
    }
    return *this;
}

Integer Integer::operator++(int temp) {
    Integer temp2 = *this;
    ++*this;
    return temp2;
}

Integer &Integer::operator--() {
    int i;
    for (i = this->list->size() - 1; i >= 0; i--) {
        if (i == this->list->size() - 1) {
            if (*this->list->get(i) == 0) {
                *this->list->get(i) = 999999999;
                *this->list->get(i - 1) -= 1;
            } else {
                *this->list->get(i) -= 1;
            }
        }
    }
    return *this;
}

Integer Integer::operator--(int temp) {
    Integer temp2 = *this;
    --*this;
    return temp2;
}

//Addition and Substraction

Integer Integer::operator+(const Integer &a){
    Integer temp = *this;
    temp += a;
    return temp;
}

Integer &Integer::operator+=(const Integer &a) {
    int i, j ,n = this->list->size(), m = a.getList()->size();
    long *aux = new long;
    if( m > n) {
        for (int k = 0; k < m - n; k++) {
            this->list->add(new long (0));
        }
        n = this->list->size();
    }
    for (i = n - 1, j = m -1; i >= 0; i-- , j--) {
        if(j >= 0)
            *this->getList()->get(i) += *a.getList()->get(j);
        if (*this->list->get(i) > 999999999) {
            *aux = *this->list->get(i) / 1000000000;
            *this->list->get(i) = *this->list->get(i) % 1000000000;
            if(i == 0)
                this->list->add(aux);
            else
                *this->list->get(i - 1) += 1;
        }
    }
    return *this;
}

Integer Integer::operator-(const Integer &a){
    Integer temp = *this;
    temp -= a;
    return temp;
}

Integer &Integer::operator-=(const Integer &a) {
    int n = this->list->size(), m = a.getList()->size();
    bool negative = false;
    if( m > n) {
        LinkedList<long> temp = *this->list;
        this->list = new LinkedList<long>(*a.getList());
        *a.getList() = temp;
        negative = true;
    }

    if(m == n) {
        for (int i = 0; i < this->list->size(); ++i) {
            if (*this->list->get(i) < *a.getList()->get(i)) {
                LinkedList<long> temp = *this->list;
                this->list = new LinkedList<long>(*a.getList());
                *a.getList() = temp;
                negative = true;
            }
        }
    }

    Integer temp1;

    for (int i = this->list->size() - 1, j = a.getList()->size() - 1; i >= 0 && j >= 0; i--, j--) {
            if (*a.getList()->get(j) <= *this->list->get(i)) {
                *this->list->get(i) -= *a.getList()->get(j);
            } else {
                *this->list->get(i) -= *a.getList()->get(j);
                if(*this->list->get(i) < 0) {
                    *this->list->get(i) += 1000000000;
                    *this->list->get(i - 1) -= 1;
                }
            }
        }
    if(negative)
        *this->list->get(0) *= -1;
    return *this;
}

Integer Integer::operator*(const Integer &a){
    Integer temp = *this;
    temp *= a;
    return temp;
}

//Multiplication and Division

Integer Integer::operator*=(const Integer &a){
    int n = this->list->size(), m = a.getList()->size();
    if( m > n ) {
        LinkedList<long> temp = *this->list;
        this->list = new LinkedList<long>(*a.getList());
        *a.getList() = temp;
    }

    Integer* tempInteger = new Integer("0");
    Integer tempInteger2 = *this;

    long tempLongFromLink;

    if(*(this->getList()->get(0))== 1 && (this->getList()->size() ==1)) {
        *this = a;
        return *this;
    }
    if(*(a.getList()->get(0))==1 && (a.getList()->size() ==1)){
        return *this;
    }

    if((*(this->getList()->get(0))==0) && (this->getList()->size() ==1)
                    ||
            *(a.getList()->get(0))==0&& (a.getList()->size() ==1)){
        tempInteger->getList()->add(0,new long(0));
        *this = *tempInteger;
        return *this;
    }

    for(unsigned long i =0;i<a.getList()->size();i++){
        tempLongFromLink = *(a.getList()->get(i));
        while(tempLongFromLink != 0){
            *tempInteger += tempInteger2;
            tempLongFromLink--;
        }
    }
    *this = *tempInteger;
    return *this;
}

Integer Integer::operator/(const Integer &a){
    Integer temp = *this;
    temp /= a;
    return temp;
}

Integer &Integer::operator/=(const Integer &a) {
    Integer* contador = new Integer("0");
    Integer* baseZero = new Integer(to_string(ZER0));
    Integer* resultado = new Integer();
    Integer* temp = new Integer(this->toString());
    Integer* baseMasUno = new Integer("1");
    Integer* base2 = new Integer("17");

    if(*(a.getList()->get(0))==1&&a.getList()->size()==1){
        return *this;
    }

    if(*this<a){
        *this = *baseZero;
        return *this;
    }

    do {
        if(!(*this<a)) {
            *this -= a;
            *contador += *baseMasUno;
        }
        else
            break;

    } while (!(this->getList()->isEmpty()));

    *this = *contador;
    return *this;
}


bool Integer::operator==(const Integer &a) {
    if(this->list->size() != a.getList()->size())
        return false;
    for (int i = 0; i < this->list->size(); ++i) {
        if(*this->list->get(i) != *a.getList()->get(i))
            return false;
    }
    return true;
}

bool Integer::operator!=(const Integer &a) {
    return !(*this == a);
}

bool Integer::operator<(const Integer &a) {
    if(this->list->size() < a.getList()->size())
        return true;
    if(this->list->size() > a.getList()->size())
        return false;
    for (int i = 0; i < this->list->size(); ++i) {
        if(*this->list->get(i) < *a.getList()->get(i))
            return true;
        if(*this->list->get(i) > *a.getList()->get(i))
            return false;
    }
    return false;
}

bool Integer::operator>(const Integer &a) {
    if(this->list->size() > a.getList()->size())
        return true;
    if(this->list->size() < a.getList()->size())
        return false;
    for (int i = 0; i < this->list->size(); ++i) {
        if(*this->list->get(i) > *a.getList()->get(i))
            return true;
        if(*this->list->get(i) < *a.getList()->get(i))
            return false;
    }
    return false;
}

bool Integer::operator<=(const Integer &a) {
    return !(*this > a);
}

bool Integer::operator>=(const Integer &a) {
    return !(*this < a);
}

string Integer::toString() {
    stringstream temp;

    for (int i = 0; i < this->list->size(); ++i) {

        string temp2 = to_string(*this->list->get(i));
        while(temp2.length() < 9 && i != 0){
            temp2 = "0" + temp2;
        }

        temp << temp2;
    }
    return temp.str();
}

Integer Integer::operator^(const Integer &a) {
    Integer temp = *this;
    temp ^= a;
    return temp;
}

Integer &Integer::operator^=(const Integer &a) {
Integer temp = *this;
    for (int i = a.getList()->size()-1; i >= 0; --i) {
        for (int j = 0; j < *a.getList()->get(i)-1; ++j) {
            *this *= temp;
        }
    }
    return *this;
}

Integer Integer::factorial(int n) {
    Integer temp("1");
    for (int i = 2; i <= n; ++i) {
        Integer temp2(to_string(i));
        temp *= temp2;
    }

    return temp;
}

Integer Integer::fibonacci(int n) {
    Integer temp("1"), temp2("1"), temp3("0");
    if(!n)
        return temp3;
    if(n == 1)
        return temp;
    n--;
    while(n--){
        Integer *temp4 = new Integer(temp.toString());
        temp3 = *temp4 + temp2;
        temp2 = temp;
        temp = temp3;
    }
    return temp2;
}

Integer Integer::combinations(int n,int k){
    Integer result;
    result = factorial(n)/(factorial(k)*(factorial(n-k)));
    return result;
}

ostream &operator<<(ostream &os, Integer &a) {
    //for (int i = 0; i < a.getList()->size(); i++) {
        cout << a.toString();
    //}
    return cout;
}

istream &operator>>(istream &is, Integer &a) {
       string temp;
        is >> temp;
        a = Integer(temp);
        return is;
}

Integer Integer::operator%(const Integer &a) {
    Integer temp = *this;
    temp %= a;
    return temp;
}

Integer &Integer::operator%=(const Integer &a) {
Integer *temp(new Integer(*this));
    *temp /= a;
    return *this;
}






