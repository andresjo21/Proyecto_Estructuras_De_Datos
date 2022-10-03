//
// Created by Grone on 29/09/2022.
//

#include "Util.h"

#ifndef PRUEBAS_COLLECTION_H
#define PRUEBAS_COLLECTION_H

/*
 public abstract class Collection<T> {

    public boolean isEmpty() {
        return size() == 0;
    }

    public abstract int size();

    public abstract T get(int i);

    public abstract Collection<T> set(int i, T v);

    public abstract Collection<T> swap(int i, int j);

    public abstract Collection<T> add(T v);

    public abstract Collection<T> add(int i, T v);

    public abstract T remove();

    public abstract T remove(int i);

    public Collection<T> clear() {
        while (!isEmpty()) {
            remove();
        }
        return this;
    }

}
  */

template <class T>
class Collection {
public:
    virtual bool isEmpty() {
        return size() == 0;
    }

    virtual int size() = 0;

    virtual T *get(int i) = 0;

    virtual Collection<T>* set(int i, T *v) = 0;

    virtual Collection<T>* swap(int i, int j) = 0;

    virtual Collection<T>* add(T *v) = 0;

    virtual Collection<T>* add(int i, T *v) = 0;

    virtual T *remove() = 0;

    virtual T *remove(int i) = 0;

    virtual Collection<T> *clear() {
        while (!isEmpty()) {
            remove();
        }
        return this;
    }

};

#endif //PRUEBAS_COLLECTION_H
