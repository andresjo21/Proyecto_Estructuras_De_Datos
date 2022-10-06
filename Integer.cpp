//
// Created by Grone on 30/09/2022.
//

#include "Integer.h"

Integer::Integer(Integer &l) {
    this->list = l.getList();
}

Integer::Integer(unsigned int i) {
    //convertir el int a long
    long *ul = new long();
    ul = reinterpret_cast<long *>(i);
    this->list = new LinkedList<long>;
    this->list->add(ul);
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

Integer::~Integer() {
//    delete this->list;
}

void Integer::setList(LinkedList<long> *list) {
    Integer::list = list;
}

LinkedList<long> *Integer::getList() const {
    return list;
}

bool Null(const Integer& a) {
    if (a.getList()->size() == 1 && a.getList()->get(0) == 0)
        return true;
    return false;
}

long Integer::operator[](const int index) const {
    if(list->size() <= index || index < 0)
        throw ("ERROR");
    return *this->list->get(index);
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
    //recorrer la lista de derecha a izquierda
    for (i = this->list->size() - 1; i >= 0; i--) {
        //sumarle 1 al ultimo elemento
        if (i == this->list->size() - 1) {
            //si el elemento es mayor o igual a 999999999, sumarle 1 al elemento anterior y poner el elemento en 0
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
    //recorrer la lista de derecha a izquierda
    for (i = this->list->size() - 1; i >= 0; i--) {
        //restarle 1 al ultimo elemento
        if (i == this->list->size() - 1) {
            //si el elemento es menor o igual a 0, restarle 1 al elemento anterior y poner el elemento en 999999999
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

//Addition

Integer Integer::operator+(const Integer &a){
    Integer temp = *this;
    temp += a;
    return temp;
}

Integer &Integer::operator+=(const Integer &a) {
    int i, j ,n = this->list->size(), m = a.getList()->size();
    long *aux = new long;
    if( m > n) {
        //añadir la cantidad de ceros necesarios a la lista
        for (int k = 0; k < m - n; k++) {
            this->list->add(new long (0));
            n = this->list->size();
        }
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

//Subtraction

Integer Integer::operator-(const Integer &a){
    Integer temp = *this;
    temp -= a;
    return temp;
}

Integer &Integer::operator-=(const Integer &a) {
    int i, j ,n = this->list->size(), m = a.getList()->size();
    long *aux = new long;
    if( m > n) {
        LinkedList<long> temp = *this->list;
        this->list = new LinkedList<long>(*a.getList());
        *a.getList() = temp;
        n = this->list->size();
        m = a.getList()->size();
    }
    for (i = n - 1, j = m -1; i >= 0; i-- , j--) {
        if(j >= 0)
            *this->getList()->get(i) -= *a.getList()->get(j);
        if (*this->list->get(i) < 0) {
            *aux = *this->list->get(i) / 1000000000;
            *this->list->get(i) = *this->list->get(i) % 1000000000;
            if(i!=0)
                *this->list->get(i ) *= -1;
            if(i == 0)
                this->list->add(aux);
            else
                *this->list->get(i - 1) -= 1;
        }
    }
    //si el primer elemento de la lista es 0, eliminarlo
    if(*this->list->get(0) == 0)
        this->list->remove(0);
    return *this;
}
        //TEST POR RESOLVER
        Integer Integer::operator*(const Integer &a){
        Integer temp = *this;
        temp *= a;
        return temp;
}

//multiplication
Integer Integer::operator*=(const Integer &a){
    int n = this->list->size(), m = a.getList()->size();
    if( m > n) {
        LinkedList<long> temp = *this->list;
        this->list = new LinkedList<long>(*a.getList());
        *a.getList() = temp;
    }
    //auxiliares
    //Integer temporal que va a ir sumandose
    Integer* tempInteger = new Integer("0");
    Integer tempInteger2 = *this;

    //long que captura el valor de cada nodo
    long tempLongFromLink;
    //comprobacion caso 1
    if(*(this->getList()->get(0))==1 && (this->getList()->size() ==1)
                                    ||
    *(a.getList()->get(0))==1&& (a.getList()->size() ==1))
        return *this;
    //comprobacion caso 0
    if((*(this->getList()->get(0))==0) && (this->getList()->size() ==1)
                    ||
            *(a.getList()->get(0))==0&& (a.getList()->size() ==1)){
        tempInteger->getList()->add(0,new long(0));
        *this = *tempInteger;
        return *this;
    }
    //caso diferente
    //recorrer todos los nodos de la lista que entra por parametro
    for(unsigned long i =0;i<a.getList()->size();i++){
        //asignar el valor del nodo al long temporal
        tempLongFromLink = *(a.getList()->get(i));
        //sumar la misma lista la cantidad de veces necesaria
        while(tempLongFromLink != 0){
            *tempInteger += tempInteger2;
            tempLongFromLink--;
        }
    }
    *this = *tempInteger;
    return *this;
}

//Division
Integer Integer::operator/(const Integer &a){
    //auxiliares
    //contador
    Integer* contador = new Integer("0");
    Integer* resultado = new Integer();
    Integer* base = new Integer("0");
    Integer* baseMasUno = new Integer("1");

    while (this->list != base->list) {
        *resultado = (*this -= a);
        if (*resultado > *base) {
                *contador += *baseMasUno;
        }
        else{
            break;
        }
    }
return *contador;
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
    string temp = "";
    for (int i = 0; i < this->list->size(); ++i) {
        //pasar el long a string
        string temp2 = to_string(*this->list->get(i));
        //si el long es menor a 9 digitos, agregarle ceros a la izquierda mientras no sea el primer elemento
        while(temp2.length() < 9 && i != 0){
            temp2 += "0";
        }
        //agregar el string al string final
        temp += temp2;
    }
    return temp;
}
