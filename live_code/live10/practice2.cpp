//Node<int> * first;
//unsigned int vsize;
// Constructor method
vector::vector(void){
    first = NULL;
    vsize = 0;
}
// Destructor method
~vector(void){
    erase();    
}

// Other useful methods
unsigned int size(void);
void push_back(int);
int at(unsigned int);
int & vector::operator[](unsigned int){

}

// User-defined assignment
vector & vector::operator=(vector & p){

}

// Private members
// used to implement the class, not meant for the user
// the vector is implemented as a linked list

// some hidden methods
void push_backR(int x, Node<int> * & p);
void erase(void){
    eraseR(first);
}
void eraseR(Node<int> * p){
    if(first == NULL) return;

    Node<int> p = first->next;
    delete first;
    push_backR(p);
}