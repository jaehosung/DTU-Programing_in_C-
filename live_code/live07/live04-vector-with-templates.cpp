#include <iostream>
#include <string>

using namespace std;

// This implementation of a vector class is based
// on the one of previous week.
// The difference is that the one in this file
// is generic: it provides support for vectors of any type
// not just integers.

// The class vector is now "templated"
// The template has one parameter: the base type/class T
template <class T>
class vector{

// Below we have replaced every occurrence of "int"
// related to vector elements by "T"
// Moreover, we have replaced all occurrences of "vector"
// by vector<T>
    
public:

    // Constructor method
    vector(void);
    // Destructor method
    ~vector(void);
    
    // Other useful methods
    unsigned int size(void);
    void push_back(T);              // note the use of T
    T at(unsigned int);             // note the use of T
    T & operator[](unsigned int);   // note the use of T

    // User-defined assignment
    vector<T> & operator=(vector<T> &);

private:
    // Private members
    // used to implement the class, not meant for the user
    T * content;                    // note the use of T
    unsigned int vsize;
    unsigned int capacity;
    void resize(void);

};

// Note that all constructors below need to be templated
// with template <class T>

// The constructor
template <class T>
vector<T>::vector(void){
    // We decide here to start with a small capacity
    capacity = 1;
    vsize = 0;
    // We allocate the space we need dynamically
    content = new T[capacity];  // note the use of T
    return;
}

// Destructor method
template <class T>
vector<T>::~vector(void){
    // We need to deallocate the array
    delete [] content;
    return;
}

template <class T>
void vector<T>::resize(){
    // save pointer to current array
    T * old_content = content;  // note the use of T
    
    // allocate new array: we try to double the current capacity
    capacity =  capacity * 2;
    content = new T[capacity];  // note the use of T

    // copy content
    for(unsigned int i=0; i<vsize; i++){
        content[i] = old_content[i];
    }
    
    // delete old array
    delete [] old_content;
}

template <class T>
unsigned int vector<T>::size(void){
    return vsize;
}

template <class T>
void vector<T>::push_back(T x){    // note the use of T
    
    // resize array if full
    if(vsize == capacity){
        resize();
    }
    
    // insert new element
    content[vsize] = x;
    vsize = vsize + 1;

}

template <class T>
T vector<T>::at(unsigned int i){   // note the use of T
    // we check if we are accessing an element of the vector
    // otherwise we raise an error
    if(i >= vsize){
        throw std::out_of_range ("you went out of range of your vector!");
    }
    return content[i];
}

// Here we overload the operator _[_] to access
// vector elements in array-style
template <class T>
T & vector<T>::operator[](unsigned int i)  // note the use of T
{
    if(i>=vsize){
        throw std::out_of_range ("you went out of range of your vector!");
    }
    // note that we do not return an element
    // but a reference to an element (see return type)
    return content[i];
}

// A user defined assignment operator
template <class T>
vector<T> & vector<T>::operator=(vector<T> & v){
    // This is what the default would do
    this->capacity = v.capacity;
    this->vsize = v.vsize;
    //this->content = v.content; // which would just copy the pointer

    delete [] this->content;
    // we need instead to create a new copy of the underlying array
    this->content = new T[this->capacity];  // note the use of T
    for(unsigned int i=0; i<vsize; i++){
        this->content[i] = v.content[i];
    }
    return * this;
}

int main(void){
    
    // when declaring a vector we need to instantiate the template
    // we can have a vector of integers
    vector<int> a;
    // or a vector of doubles
    vector<double> b;
    // or a vector of strings
    vector<string> c;
    // etc.
    
    return 0;

}
