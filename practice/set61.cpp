#include<iostream>
#include<string>
using namespace std;
class fraction {
    private:
        // Internal representation of a fraction as two integers
        int numerator;
        int denominator;
    public:
        // Class constructor
        fraction(int n, int d);
        // Methods to update the fraction
        void add(fraction f);
        void mult(fraction f);
        void div(fraction f);
        // Display method
        void display(void);
};

int GCD( int u, int v) {
    while ( v != 0) {
        int r = u % v;
        u = v;
        v = r;
    }
    return u;
}
fraction::fraction(int n, int d){
    numerator = n;
    denominator = d;
}

void fraction::add(fraction f){
    this->numerator = this->denominator*f.numerator +this->numerator*f.denominator;
    this->denominator = f.denominator*this->denominator;
}

void fraction::mult(fraction f){
    this->numerator = this->numerator * f.numerator;
    this->denominator = this->denominator*f.denominator;
}

void fraction::div(fraction f){
    this->numerator = this->numerator * f.denominator;
    this->denominator = this->denominator*f.numerator;
}
void fraction::display(){
    int gcd = GCD(this->numerator,this->denominator);
    this->numerator /= gcd;
    this->denominator /=gcd;
    cout<<this->numerator<<" / "<<this->denominator<<endl;
}

int main(){
    int num11,den11,num12,den12;
    int num21,den21,num22,den22;
    int num31,den31,num32,den32;
    string trash;
    string op;

    cin>>num11>>trash>>den11>>op>>num12>>trash>>den12;
    cin>>num21>>trash>>den21>>op>>num22>>trash>>den22;
    cin>>num31>>trash>>den31>>op>>num32>>trash>>den32;

    fraction test11(num11,den11);
    fraction test12(num12,den12);
    test11.add(test12);

    fraction test21(num21,den21);
    fraction test22(num22,den22);
    test21.mult(test22);

    fraction test31(num31,den31);
    fraction test32(num32,den32);
    test31.div(test32);

    test11.display();
    test21.display();
    test31.display();

    return 0;
}
