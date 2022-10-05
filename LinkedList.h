//
// Created by Grone on 29/09/2022.
//

#include "Util.h"
#include "Collection.h"
#include "Link.h"

#ifndef PRUEBAS_LINKEDLIST_H
#define PRUEBAS_LINKEDLIST_H

/*
 * public class LinkedList<T> extends Collection<T> {

    public LinkedList() {
        this.k = 0;
        this.first = null;
    }

    @Override
    public int size() { // O(1)
        return k;
    }

    @Override
    public T get(int i) { // O(n)
        T r = null;
        if ((0 <= i) && (i < size())) {
            Link<T> current = first;
            int p = 0;
            while ((current != null) && (p < i)) {
                current = current.next;
                p++;
            }
            assert (current != null);
            r = (T) current.info;
        } else {
            throw new IndexOutOfBoundsException();
        }
        return r;
    }

    @Override
    public Collection<T> set(int i, T v) {
        // Modifica el elemento en la posición i-ésima de la lista.
        // El método lanza una excepción si la posición indicada
        // es incorrecta o si el valor del parámetro v es nulo.
        if ((0 <= i) && (i < size())) {
            if (v != null) {
                Link<T> current = first;
                int p = 0;
                while ((current != null) && (p < i)) {
                    current = current.next;
                    p++;
                }
                assert (current != null);
                current.info = v;
            } else {
                throw new NullPointerException();
            }
        } else {
            throw new IndexOutOfBoundsException();
        }
        return this;
    }


    @Override
    public Collection<T> swap(int i, int j) {
        // Intercambia los elementos en las posiciones i-ésima y j-ésima.
        // El método lanza una excepción si alguna de las posiciones
        // indicadas no existe en la lista.
        if ((0 <= i) && (i < size()) && (0 <= j) && (j < size())) {
            T aux = get(i);
            set(i, get(j));
            set(j, aux);
        } else {
            throw new IndexOutOfBoundsException();
        }
        return this;
    }


    @Override
    public Collection<T> add(T v) { // O(1)
        return add(0, v);
    }

    @Override
    public Collection<T> add(int i, T v) { // O(n)
        if (v != null) {
            int m = ((0 <= i) && (i < size())) ? i : size();
            if (m == 0) {
                first = new Link(first, v);
            } else {
                Link<T> current = first;
                int p = 0;
                while ((current != null) && (p < (m - 1))) {
                    current = current.next;
                    p++;
                }
                assert (current != null);
                current.next = new Link(current.next, v);
            }
            k++;
        } else {
            throw new IllegalArgumentException();
        }
        return this;
    }

    @Override
    public T remove() {
        return remove(0);
    }

    @Override
    public T remove(int i) {
        T r = null;
        if (!isEmpty()) {
            if (i == 0) {
                r = first.info;
                first = first.next;
                k--;
            } else if ((0 <= i) && (i < size())) {
                Link<T> current = first;
                int p = 0;
                while ((current.next != null) && (p < (i - 1))) {
                    current = current.next;
                    p++;
                }
                assert (current != null);
                current.next = current.next.next;
                k--;
            }
        }
        return r;
    }

    @Override
    public String toString() { // O(n)
        StringBuilder r = new StringBuilder("{");
        Link current = first;
        while (current != null) {
            r.append(current.info);
            current = current.next;
            if (current != null) {
                r.append(", ");
            }
        }
        r.append("}");
        return r.toString();
    }

    private int k;
    private Link<T> first;
}

class Link<T> {

    public Link(Link next, T info) {
        this.next = next;
        this.info = info;
    }

    public Link(T info) {
        this(null, info);
    }

    Link next;
    T info;
}
  */

template <class T>
class LinkedList : public Collection<T> {
private:
    int k;
    Link<T> *first;

public:
    int getK() const {
        return k;
    }

    void setK(int k) {
        LinkedList::k = k;
    }

    Link<T> *getFirst() const {
        return first;
    }

    void setFirst(Link<T> *first) {
        LinkedList::first = first;
    }

    LinkedList(){
        this->k = 0;
        this->first = nullptr;
    }
    LinkedList(LinkedList const &l){
        this->setK(l.k);
        this->setFirst(l.first);
    }

    int size(){
        return this->k;
    }

    T * get(int i){
        T *r = nullptr;
        if ((0 <= i) && (i < size())) {
            Link <T> *current = this->first;
            int p = 0;
            while ((current != nullptr) && (p < i)) {
                current = current->next;
                p++;
            }
            //assert(current != nullptr);
            r = current->info;
        } else {
            //throw new IndexOutOfBoundsException();
        }
        return r;
    }

    Collection<T>* set(int i, T* v) {
        if ((0 <= i) && (i < size())) {
            if (v != nullptr) {
                Link<T>* current = this->first;
                int p = 0;
                while ((current != nullptr) && (p < i)) {
                    current = current->next;
                    p++;
                }
                //assert (current != nullptr);
                current->info = (T*) v;
            } else {
                //throw new NullPointerException();
            }
        } else {
            //throw new IndexOutOfBoundsException();
        }
        return this;
    }

    Collection<T>* swap(int i, int j) override{
        if ((0 <= i) && (i < size()) && (0 <= j) && (j < size())) {
            T* aux = get(i);
            set(i, get(j));
            set(j, aux);
        } else {
            //throw new IndexOutOfBoundsException();
        }
        return this;
    }

    Collection<T>* add(T* v){
        return add(0, v);
    }

    Collection<T>* add(int i, T* v){
        if (v != nullptr) {
            int m = ((0 <= i) && (i < size())) ? i : size();
            if (m == 0) {
                this->first = new Link<T>(this->first, v);
            } else {
                Link<T>* current = this->first;
                int p = 0;
                while ((current != nullptr) && (p < (m - 1))) {
                    current = current->next;
                    p++;
                }
                //assert (current != nullptr);
                current->next = new Link<T>(current->next, v);
            }
            this->k++;
        } else {
            //throw new IllegalArgumentException();
        }
        return this;
    }

    T* remove() {
        return remove(0);
    }

    T* remove(int i) {
        T* r = nullptr;
        if (!this->isEmpty()) {
            if (i == 0) {
                r = this->first->info;
                this->first = this->first->next;
                this->k--;
            } else if ((0 <= i) && (i < size())) {
                Link<T>* current = this->first;
                int p = 0;
                while ((current->next != nullptr) && (p < (i - 1))) {
                    current = current->next;
                    p++;
                }
                //assert (current != nullptr);
                current->next = current->next->next;
                this->k--;
            }
        }
        return r;
    }

    string toString(){ // O(n)
        stringstream r;
        r << "{";
        Link<T>* current = this->first;
        while (current != nullptr) {
            r << *current->info;
            current = current->next;
            if (current != nullptr) {
                r << ", ";
            }
        }
        r << "}";
        return r.str();
    }
};

#endif //PRUEBAS_LINKEDLIST_H
