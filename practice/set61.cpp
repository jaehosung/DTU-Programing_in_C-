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
    string trash;
    string op;

    while(1){
        cin>>num11>>trash>>den11>>op>>num12>>trash>>den12;
        if(cin.fail()){
            break;
        }
        fraction test11(num11,den11);
        fraction test12(num12,den12);

        if(op == "+"){
            test11.add(test12);
        }else if(op == "*"){
            test11.mult(test12);
        }else if(op == "div"){
            test11.div(test12);
        }
        test11.display();
    }

    return 0;
}
