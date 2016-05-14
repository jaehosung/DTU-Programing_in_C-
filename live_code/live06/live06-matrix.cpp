#include <iostream>
#include <utility>

using namespace std;

class matrix{
    
public:
    
    // Constructor method
    matrix(unsigned int rows, unsigned int columns);
    // Destructor method
    ~matrix(void);
    
    // Other useful members
    unsigned int numRows(void);
    unsigned int numColumns(void);
    double & operator[](pair<unsigned int, unsigned int>);
    void scalar_mult(double u);
    void transpose(void);
    void display(void);
    matrix & operator=(matrix & v);
    
private:
    // Private members
    unsigned int rows;
    unsigned int columns;
    double * m;
    
};

// constructor method
matrix::matrix(unsigned int rows, unsigned int columns){
    this->rows = rows;
    this->columns = columns;
    // we implement a matrix with an array
    m = new double[rows*columns];
    return;
}

// destructor method
matrix::~matrix(void){
    delete [] m;
    return;
}

unsigned int matrix::numRows(void){
    return rows;
}


unsigned int matrix::numColumns(void){
    return columns;
}


// method to access elements in the matrix
double & matrix::operator[](pair<unsigned int, unsigned int> p) {
    if(p.first > rows || p.second > columns ){
        throw std::out_of_range ("you went out of range of your matrix!");
    }
    // note thow we access the right element
    // this is completely transparent to the user
    return m[(p.first*columns)+p.second];
}

// scalar multiplication method
void matrix::scalar_mult(double u){
    for(unsigned int i=0; i<rows; i++){
        for(unsigned int j=0; j<columns; j++){
            m[(i*columns)+j] = m[(i*columns)+j] * u;
        }
    }
}

// matrix trasposition method
void matrix::transpose(void){

    // we first traspose the values
    double aux;
    for(unsigned int i=0; i<rows; i++){
        for(unsigned int j=i; j<columns; j++){
            aux = m[(i*columns)+j];
            m[(i*columns)+j] = m[(j*rows)+i];
            m[(j*rows)+i] = aux;
        }
    }
    
    // and now we change the matrix properties
    unsigned int x;
    x = columns;
    columns = rows;
    rows = x;
    
}

void matrix::display(){
    //
    //cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    for(unsigned int i=0; i<rows; i++){
        for(unsigned int j=0; j<columns; j++){
            cout <<(*this)[make_pair(i,j)] << " ";
        }
        cout << endl;
    }
}

// A user defined assignment operator
matrix & matrix::operator=(matrix & v){
    // This is what the default would do
    this->rows = v.rows;
    this->columns = v.columns;
    //this->m = v.m; // which would just copy the pointer
    
    // we need instead to create a new copy of the underlying array
    this->m = new double[v.rows*v.columns];
    for(unsigned int i=0; i<v.rows*v.columns; i++){
        this->m[i] = v.m[i];
    }
    return * this;
}

int main(void){
    
    matrix m(3,2);
    
    cout << "Initial matrix" << endl;
    cout << "==============" << endl;
    m.display();
    cout << endl;
    
    for(unsigned int i=0; i<m.numRows(); i++){
        for(unsigned int j=0; j<m.numColumns(); j++){
            m[make_pair(i,j)] = 1.0 / ( (i+1.0) * (j+2.0) );
        }
    }
    
    cout << "Setting values..." << endl;
    cout << "=================" << endl;
    m.display();
    cout << endl;

    m.scalar_mult(0.5);
    cout << "Multiplying..." << endl;
    cout << "==============" << endl;
    m.display();
    cout << endl;
    
    m.transpose();
    cout << "Trasposing..." << endl;
    cout << "=============" << endl;
    m.display();
    cout << endl;
    
}
