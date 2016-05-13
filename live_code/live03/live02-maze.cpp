#include <iostream>
#include <stdlib.h>     /* Library containing funciton such as
                           rand (a generator of random numbers) */
using namespace std;


// We declare here an enumeration type called "material"
typedef enum {wood,stone} material;
// In C++ we can also write the "equivalent" declaration
//enum material {wood,stone};

// We declare here a record type called "field"
typedef struct {
    int x;
    int y;
    bool isWall;
    material type;
} field;
// As above, we can write
// struct field {...};

// this function translates materials into characters
// in order to display them
char character(material m){
    // Switching is a sort of if_then_else
    // Useful when there many cases
    switch(m){
        case wood:
            return ' ';
        case stone:
            return '#';ty
        default:
            return '?';
    }
}

int main(){
    
    int n = 0;
    int m = 0;
    
    cout << "Enter the height of the field: ";
    cin >> n;
    cout << "Enter the width of the field: ";
    cin >> m;
    
    // declaration of a playground
    // as an n x m array of field elements
    field playground[n][m];
    // the above declaration may not work in all compilers
    // one should use instead dynamic allocation as follows
    // field ** playground = new field*[n];
    // for (int i=0; i<n; i++){
    //     playground[i] = new field[m];
    // }
    // when playground is not more needed we should deallocate it with
    // delete [] playground;
    
    // building the playground (stone perimeter, wood inside)
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            // Note here how we access an element of an array
            // with playground[i][j]
            // and how we access the fields of a (field) record
            // with .x, .y, etc.
            playground[i][j].x=i;
            playground[i][j].y=j;
            playground[i][j].isWall=(i==0||i==(n-1)||j==0||j==(m-1)||(rand()%4)==0);
            if (playground[i][j].isWall)
                playground[i][j].type=stone;
            else
                playground[i][j].type=wood;
        }
    }
    
    // printing the playground
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << character(playground[i][j].type);
        }
        cout << endl;
    }

    return 0;
    
}
