#include <iostream>
#include <vector>
#include "shapes.h"

using namespace std;

int main(void){
    
    vector<Shape *> shapes;
    
    Rectangle u(2,5);
    shapes.push_back(&u);
    Square v(3);
    shapes.push_back(&v);
    Circle w(2);
    shapes.push_back(&w);
    
    
    // Enumerating all areas
    cout << "Areas..." << endl;
    double area = 0;
    for(Shape * p : shapes){
        cout << p->area() << " ";
        area += p->area();
    }
    cout << endl << "Total area is " << area << endl;
    
    // Enumerating all areas
    cout << "Perimeters..." << endl;
    double perimeter = 0;
    for(Shape * p : shapes){
        cout << p->perimeter() << " ";
        perimeter += p->perimeter();
    }
    cout << endl << "Total area is " << perimeter << endl;
    
    // I want to put them side-by-side
    // And see how much space they use (width and height)
    cout << "Placing side-by-side..." << endl;
    double width = 0;
    double height = 0;
    for(Shape * p : shapes){
        width += p->width();
        if(height < p->height()){
            height = p->height();
        }
    }
    cout << "Total width is " << width << endl;
    cout << "Total height is " << height << endl;
    
    // I now try to do the same, but minimizing width
    // First, I rotate those shapes that need it
    for(Shape * p : shapes){
        if(p->width() > p->height()) {
            p->rotate();
        }
    }
    // Then I proceed as before
    cout << "Placing side-by-side..." << endl;
    width = 0;
    height = 0;
    for(Shape * p : shapes){
        width += p->width();
        if(height < p->height()){
            height = p->height();
        }
    }
    cout << "Total width is " << width << endl;
    cout << "Total height is " << height << endl;

    return 0;
    
}
