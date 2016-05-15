#include<iostream>
using namespace std;

template <typename T>
class vector{
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

template <typename T>
vector<T>::vector(void){
    capacity = 1;
    vsize = 0;
    content = new T[capacity];
    return;
}

template <typename T>
vector<T>::~vector(void){
    delete[] content;
    return;
}
template <typename T>
void vector<T>::resize(void){
    T * oldcontent;
    capacity = 2*capacity;
    content = new T[capacity];
    for(int i=0; i<vsize; i++){
        content[i] = oldcontent[i];
    }
    delete[] oldcontent;

}
template <typename T>
unsigned int vector<T>::size(void){
    return vsize;
}
template <typename T>
T vector<T>::at(unsigned int i ){
    return content[i];
}
template <typename T>
void vector<T>::push_back(T pushVal){
    if(vsize==capacity)
        resize();
    content[vsize]=pushVal;
    vsize++;
}

template <typename T>
T& vector<T>::operator[](unsigned int a){
    return content[a];
}
template <typename T>
vector<T>& vector<T>::operator=(vector<T> &v){
    this->capacity = v.capacity;
    this->vsize = v.vsize;
    delete [] this->content;
    this-> content = new T[this->capacity];
    for(int i=0; i<vsize; i++){
        this->content[i] = v.content[i];
    }
    return *this;
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
