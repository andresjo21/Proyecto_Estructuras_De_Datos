//
// Created by Grone on 30/09/2022.
//

#include "LinkedList.h"

#ifndef PRUEBAS_INTEGER_H
#define PRUEBAS_INTEGER_H

class Integer {
public:
    Integer(Integer &l);
    Integer(unsigned int i);
    Integer(string s);
    Integer();

    ~Integer();

    LinkedList<unsigned long> *getList() const;
    void setList(LinkedList<unsigned long> *list);
    bool Null(const Integer& a);

//Funciones que auxiliares
    //friend void divide_by_2(Integer &a);
    //friend bool Null(const Integer &);
    //friend int Length(const Integer &);
    unsigned long operator[](const int) const;

/* * * * Operator Overloading * * * */
//Direct assigment
    Integer& operator=(const Integer &a);

    //Incremention
    Integer& operator++();
    Integer operator++(int temp);

    //Decremention
    Integer& operator--();
    Integer operator--(int temp);

    //Addition
    Integer operator+(const Integer &a);
    Integer& operator+=(const Integer &a);

private:
    LinkedList<unsigned long > *list;
};



#endif //PRUEBAS_INTEGER_H
