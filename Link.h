//
// Created by Grone on 30/09/2022.
//

#ifndef PRUEBAS_LINK_H
#define PRUEBAS_LINK_H


template <class T>
class Link {
public:
    Link(Link* next, T* info)
    {
        this->next = next;
        this->info = info;
    }

    Link(T* info){
        this->next = nullptr;
        this->info = info;
    }

    Link* next;
    T* info;
};

#endif //PRUEBAS_LINK_H
