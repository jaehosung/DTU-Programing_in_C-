#include <iostream>

using namespace std;

class vector{
    
public:

    // Constructor method
    vector(void);
    // Destructor method
    ~vector(void);
    
    // Other useful methods
    unsigned int size(void);
    void push_back(int);
    int at(unsigned int);
    int & operator[](unsigned int);

    // User-defined assignment
    vector & operator=(vector &);

private:
    // Private members
    // used to implement the class, not meant for the user
    int * content;
    unsigned int vsize;
    unsigned int capacity;
    void resize(void);

};

// The constructor
vector::vector(void){
    // We decide here to start with a small capacity
    capacity = 1;
    // We allocate the space we need dynamically
    content = new int[capacity];
    vsize = 0;
    return;
}

// Destructor method
vector::~vector(void){
    // We need to deallocat the array
    delete [] content;
    return;
}

void vector::resize(){
    // save pointer to current array
    int * old_content = content;
    
    // allocate new array: we try to double the current capacity
    capacity =  capacity * 2;
    content = new int[capacity];

    // copy content
    for(unsigned int i=0; i<vsize; i++){
        content[i] = old_content[i];
    }
    
    // delete old array
    delete [] old_content;
}

unsigned int vector::size(void){
    return vsize;
}
    
void vector::push_back(int x){
    
    // resize array if full
    if(vsize == capacity){
        resize();
    }
    
    // insert new element
    content[vsize] = x;
    vsize = vsize + 1;

}

int vector::at(unsigned int i){
    // we check if we are accessing an element of the vector
    // otherwise we raise an error
    if(i >= vsize){
        throw std::out_of_range ("you went out of range of your vector!");
    }
    return content[i];
}

// Here we overload the operator _[_] to access
// vector elements in array-style
int & vector::operator[](unsigned int i)
{
    if(i>=vsize){
        throw std::out_of_range ("you went out of range of your vector!");
    }
    // note that we do not return an element
    // but a reference to an element (see return type)
    return content[i];
}

// A user defined assignment operator
vector & vector::operator=(vector & v){
    // This is what the default would do
    this->capacity = v.capacity;
    this->vsize = v.vsize;
    //this->content = v.content; // which would just copy the pointer

    // we need instead to create a new copy of the underlying array
    this->content = new int[this->capacity];
    for(unsigned int i=0; i<vsize; i++){
        this->content[i] = v.content[i];
    }
    return * this;
}

int main(void){
    
    // we declare a vector a
    vector a;
    
    // we insert some numbers with push_back
    for(unsigned int i=0; i<10; i++){
        a.push_back(i);
    }
    
    // we access and manipulate some elements in array-style
    for(unsigned int i=2; i<a.size(); i++){
        a[i] = a[i-1] + a[i-2];
    }
    
    // we access some elements usint at()
    for(unsigned int i=0; i<a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl;
    
    // we open a new scope
    {
        vector b;
        // we set b to be equal to a
        b = a;
        for(unsigned int i=0; i<10; i++){
            b.push_back(i);
        }
        for(unsigned int i=0; i<b.size(); i++){
            cout << b.at(i) << " ";
        }
        cout << endl;
    }
    // here b is de-allocated since it scope has finished
    
    for(unsigned int i=0; i<a.size(); i++){
        cout << a.at(i) << " ";
    }
    cout << endl;

}
