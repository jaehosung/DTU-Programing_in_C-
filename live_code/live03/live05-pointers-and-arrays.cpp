#include <iostream>
using namespace std;


int main(){
    
    int * a;
    int n;
    
    cout << "How large do you want the array to be? ";
    cin >> n;
    
    // we allocate a new array of size n
    a = new int[n];
    
    // we write some values in a[0]..a[10]
    // even if the array may be of smaller size!!!
    for(int i=0; i<=10; i++){
        a[i]=i;
    }
    
    cout << "The value   of a    is " << a << endl;
    cout << "The address of a[0] is " << &(a[0]) << endl;
    cout << "The address of a[1] is " << (long)&(a[1]) << endl;
    cout << "The address of a[2] is " << (long)&(a[2]) << endl;
    cout << "The address of a[3] is " << (long)&(a[3]) << endl;
    cout << "The address of a[4] is " << (long)&(a[4]) << endl;
    cout << "The address of a[5] is " << (long)&(a[5]) << endl;

    cout << "a[4] is " << a[4] << endl;
    cout << "a[4] is " << *(a + 4) << endl;
    
    // we shall remember to deallocate the array when we are done with it1
    delete [] a;
    
    return 0;
    
}
