#include <iostream>

using namespace std;

// This is a templated function
// the template has a parameter T
// which is a type
template<typename T>
// it takes two values of type T as input
// and returns a value of type T
T average(T x, T y){
    return (x + y) / 2 ;
}

// This is another example of templated function
template<typename T>
T safe_average(T x, T y){
    return (x + y) / 2 ;
}

// Templated functions can be specialized for some cases
template<>
int safe_average<int>(int x, int y){
    if((x + y) % 2 != 0) cout << " *** Warning! Truncating values in average *** ";
    return (x + y) / 2 ;
}

template<>
string safe_average<string>(string x, string y){
    return to_string(safe_average<double>(stod(x),stod(y))) ;
}

int main(void){
    
    double d1 = 1.0;
    double d2 = 2.0;
    double i1 = 1;
    double i2 = 2;
    string s1 = "1.0";
    string s2 = "2.0";
    
    // These are examples of using the templated function average
 
    // with doubles 
    cout << "average between " << d1 << " and " << d2 << " is... ";
    cout << average<double>(d1,d2) << endl;
    
    // and with integers
    cout << "average between " << i1 << " and " << i2 << " is... ";
    cout << average<int>(i1,i2)<< endl;
    
    // In this case we use a specialized variant of the templated function
    cout << "safe_average between " << i1 << " and " << i2 << " is... ";
    cout << safe_average<int>(i1,i2)<< endl;
    
    // And here we try to do the average of strings
    cout << "safe_average between " << s1 << " and " << s2 << " is... ";
    // uncommenting the below line leads to a compilation error
    // since division is not defined for strings
    // cout << average<string>(s1,s2)<< endl;
    // the below line is ok because the function has a specialization
    // for strings that does not use division
    cout << safe_average<string>(s1,s2)<< endl;
    
    return 0;
    
}
