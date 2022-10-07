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
    Integer(LinkedList<long >);
    Integer();

    ~Integer();

    LinkedList<long> *getList() const;
    void setList(LinkedList<long> *list);
    bool Null(const Integer& a);

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

    //Substraction
    Integer operator-(const Integer &a);
    Integer& operator-=(const Integer &a);

    //multiplication
    Integer operator*(const Integer &a);
    Integer operator*=(const Integer &a);

    //Division
    Integer operator/(const Integer &a);
    Integer &operator/=(const Integer &a);


    //Comparison operators
    bool operator==(const Integer &a);
    bool operator!=(const Integer &a);
    bool operator<(const Integer &a);
    bool operator>(const Integer &a);
    bool operator<=(const Integer &a);
    bool operator>=(const Integer &a);

    //Power
    Integer operator^(const Integer &a);
    Integer &operator^=(const Integer &a);

    //Factorial
    Integer factorial(int n);

    //Fibonacci
    Integer fibonacci(int n);

    //combinations
    Integer combinations(int n,int k);

    //Sobre carga de operador <<
    friend ostream& operator<<(ostream& os, const Integer& a);

    //Sobre carga de operador >>
    friend istream& operator>>(istream& is, Integer& a);

    //toString
    string toString();
private:
    LinkedList<long > *list;

    Integer *paddZeros(Integer *pInteger, int abs);

    Integer &subtractLinkedListHelper(Integer *pInteger, Integer *pInteger1, bool borrow);
};



#endif //PRUEBAS_INTEGER_H
