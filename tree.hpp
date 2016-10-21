#include <stddef.h>
#include <vector>

typedef int T;
class tree; 

class node {
    T info;
    std::vector<node*> children;
    node* parent;
    friend class tree;
public:
    typedef std::vector<node*>::iterator iterator;
    iterator begin() {
        return children.begin();
    }
    iterator end() {
        // print chilndren.info;        ** NOT TESTED **
        return children.end();
    }
    T get() {
        return info;
    }
    void remove(node* n){
            for(iterator it = children.begin(), end = children.end(); it!=end; it++ ){
                    if((*it)->info == n->info){
                        children.erase(it);
                        break;
                    }
            }
    }
    ~ node (){ };
};

class tree {
    node* r;
    void del(node* v) {
        if (v == NULL) return;
        for (node::iterator it = v->begin(); it != v->end(); ++it)    
            del(*it);
        delete v;
    }
public:
    tree() : r(NULL) { }
    node* add(T info, node* parent) {
        node* v = new node;
        v->parent = parent;
        v->info = info;
        if (parent != NULL) 
            parent->children.push_back(v);
        else {
            if (r != NULL) 
                del(r);
            r = v;
        }
        return v;
    }
    node* add(T info) {
        return add(info, NULL);
    }
    node* root() { return r; }
    void remove(node* v) {
        if (r == v) r = NULL;
        else { 
            /* remove v from the list of children of its parent */ 
            v->parent->remove(v);
        }
        del(v);
    }
    
    ~ tree (){
        del( r);
    };

};
