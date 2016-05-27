#include <stddef.h>
#include <vector>

//typedef int T;
template<class T> class tree;

template <class T> class node {
    T info;
    std::vector<node<T>*> children;
    node<T>* parent;
    friend class tree<T>;
public:
    typedef typename std::vector<node<T>*>::iterator iterator;
    iterator begin() {
        return children.begin();
    }
    iterator end() {
        return children.end();
    }
    T get() {
        return info;
    }
    
    void remove(node<T>* n){
            for(iterator it = children.begin(), end = children.end(); it!=end; it++ ){
                    if((*it)->info == n->info){
                        children.erase(it);
                        break;
                    }
            }
    }
    ~ node (){ };

};


template <class T> class tree {
    node<T>* r;
    void del(node<T>* v) {
        if (v == NULL) return;
        for (typename node<T>::iterator it = v->begin(); it != v->end(); ++it){
            del(*it);
        }
        delete v;
    }
public:
    tree() : r(NULL) { }
    node<T>* add(T info, node<T>* parent) {
        node<T>* v = new node<T>;
        v->parent = parent;
        v->info = info;
        if (parent != NULL) {
            parent->children.push_back(v);
        } else {
            if (r != NULL) 
                del(r);
            r = v;
        }
        return v;
    }
    node<T>* add(T info) {
        return add(info, NULL);
    }
    
    node<T>* root() { 
        return r; 
    }
    void remove(node<T>* v) {
        if (r == v) r = NULL;
        else { 
            // remove v from the list of children of its parent 
            v->parent->remove(v);
        }
        del(v);
    }
    ~ tree (){
        del( r);
    };
};
