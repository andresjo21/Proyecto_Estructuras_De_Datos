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
    //separar el string en partes de 9 caracteres de izquierda a drecha y guardarlo en una varible auxiliar
    string aux;
    int i = s.size() - 1;
    int counter = 0;
    while (i >= 0) {
        aux = s[i] + aux;
        counter++;
        if (counter == 9 || i == 0) {
            //convertir la variable auxiliar a un long sin usar librerias y agregarlo a la lista
            //unsigned long *num = new unsigned long;
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

            //*this->list->get(i) += 1;
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
    int i,n;
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
}

Integer Integer::operator--(int temp) {
    Integer temp2 = *this;
    --*this;
    return temp2;
}

/*Integer Integer::operator+(const Integer &a) {
    Integer temp;
    LinkedList<unsigned long> *tempList = new LinkedList<unsigned long>;
    temp = a;
    for (int i = this->list->size() - 1; i >= 0; i--) {
        *temp.list->get(i) += *this->list->get(i);
    }
    return ;
}*/






