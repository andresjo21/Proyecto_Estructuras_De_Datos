#include "Util.h"
#include "Collection.h"
#include "Link.h"

#ifndef PRUEBAS_LINKEDLIST_H
#define PRUEBAS_LINKEDLIST_H

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

    bool isEmpty(){
        if(this->get(0)==0&&this->size()==0){
            return true;
        }
        for(long i = 0; i<this->size();i++){
            long zero = 0;
            if(*(this->get(i)) != zero)
                return false;
        }
        return true;
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
            r = current->info;
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
