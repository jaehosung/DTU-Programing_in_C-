#include <iostream>

// Example based on pairs
// see http://www.cplusplus.com/reference/utility/pair/

using namespace std;

template <typename A, typename B>
class paar {

public:
    paar(A a, B b);
    A first(void);
    B second(void);
    paar<B,A> flip(void);
    paar<A,B> & operator=(paar<A,B> & p);
    void display(void);
    
private:
    A a;
    B b;
    
};

template <typename A, typename B>
paar<A,B>::paar(A a, B b){
    this->a = a;
    this->b = b;
}

template <typename A, typename B>
A paar<A,B>::first(void){
    return a;
}

template <typename A, typename B>
B paar<A,B>::second(void){
    return b;
}

template <typename A, typename B>
paar<B,A> paar<A,B>::flip(void){
    paar<B,A> p(b,a);
    return p;
}

template <typename A, typename B>
paar<A,B> & paar<A,B>::operator=(paar<A,B> & p){
    a = p.first();
    b = p.second();
}

template <typename A, typename B>
void paar<A,B>::display(void){
    cout << "<" << a << "," << b << ">" << endl;
}

// some templated free funcitons for pairs

// test if two pairs can be matched/plugged
template <typename A, typename B, typename C>
bool match(paar<A,B> p, paar<B,C> q){
    return (p.second() == q.first());
}

// join a pair by taking the first component of the first pair
// and the second component of the second pair
template <typename A, typename B, typename C>
paar<A,C> join(paar<A,B> p, paar<B,C> q){
    paar<A,C> r(p.first(),q.second());
    return r;
}

int main(void){
    
    paar<string,int> a("Alice",1);
    paar<string,int> b("Bob",2);
    paar<int,int> likes(1,2);
    
    a.display();
    b.display();
    likes.display();
    
    if( match<string,int,int>(a,likes)
     && match<int,int,string>(likes,b.flip()) ){
        paar<string,string> gossip = join<string,int,string>(a,b.flip());
        cout << "gossip alert: ";
        gossip.display();
        cout << endl;
    }
    cout << endl;
    
    return 0;
}



