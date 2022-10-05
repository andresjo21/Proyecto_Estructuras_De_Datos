//
// Created by Grone on 30/09/2022.
//

#include "Integer.h"

Integer::Integer(Integer &l) {
    this->list = l.getList();
}

Integer::Integer(unsigned int i) {
    //convertir el int a unsigned long
    unsigned long *ul = new unsigned long();
    ul = reinterpret_cast<unsigned long *>(i);
    this->list = new LinkedList<unsigned long>;
    this->list->add(ul);
}

Integer::Integer(string s) {
    this->list = new LinkedList<unsigned long>;
    string aux;
    int i = s.size() - 1;
    int counter = 0;
    while (i >= 0) {
        aux = s[i] + aux;
        counter++;
        if (counter == 9 || i == 0) {
            unsigned long num2 = 0;
            for (int j = 0; j < aux.size(); ++j) {
                num2 += (aux[j] - '0') * pow(10, aux.size() - j - 1);
            }
            unsigned long *num = new unsigned long(num2);
            this->list->add(num);
            aux = "";
            counter = 0;
        }
        i--;
    }
}

Integer::~Integer() {
}

void Integer::setList(LinkedList<unsigned long> *list) {
    Integer::list = list;
}

LinkedList<unsigned long> *Integer::getList() const {
    return list;
}

bool Null(const Integer& a) {
    if (a.getList()->size() == 1 && a.getList()->get(0) == 0)
        return true;
    return false;
}

unsigned long Integer::operator[](const int index) const {
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

Integer Integer::operator+(const Integer &a){
    Integer temp = *this;
    temp += a;
    return temp;
}

Integer &Integer::operator+=(const Integer &a) {
    int i, j ,n = this->list->size(), m = a.getList()->size();
    unsigned long *aux = new unsigned long;
    if( m > n) {
        //añadir la cantidad de ceros necesarios a la lista
        for (int k = 0; k < m - n; k++) {
            this->list->add(new unsigned long (0));
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








