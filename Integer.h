#include "LinkedList.h"

#ifndef PRUEBAS_INTEGER_H
#define PRUEBAS_INTEGER_H

//MACROS
#define ZER0 0
#define ONE 1

class Integer {
public:
    Integer(Integer &l);
    Integer(string s);
    Integer(int);
    Integer();
    ~Integer();

    LinkedList<long> *getList() const;

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

    //Modulus
    Integer operator%(const Integer &a);
    Integer &operator%=(const Integer &a);

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
    static Integer factorial(int n);

    //Fibonacci
    static Integer fibonacci(int n);

    //combinations
    static Integer combinations(int n,int k);

    //Sobre carga de operador <<
    friend ostream& operator<<(ostream& os,Integer& a);

    //Sobre carga de operador >>
    friend istream& operator>>(istream& is, Integer& a);

    //toString
    string toString();
private:
    LinkedList<long > *list;
};



#endif //PRUEBAS_INTEGER_H
