#ifndef __Shape__
#define __Shape__
#ifndef __Rectangle__
#define __Rectangle__
#ifndef __Square__
#define __Square__
#ifndef __Circle__
#define __Circle__
const double pi = 3.14159265358979323;
class Shape{
    public :
       Shape(double a, double b){
           w = b;
           h = a;
           _area = w*h;
           _perimeter =  2*(w+h);

       };
       
       double area(){
           return _area;
       };

       double perimeter(){
           return _perimeter;
       };

       double width(){
           return w;
       }
       double height(){
           return h;
       }
       void rotate(){
           double temp;
           temp = w;
           w = h;
           h = temp;
       }

       double w;
       double h;
       double _area;
       double _perimeter;
};

class Rectangle : public Shape{
    public :
        Rectangle(double a, double b) : Shape(a,b){};

};

class Square : public Shape{
    public :
        Square(double a) : Shape(a,a){};
};
class Circle : public Shape{
    public :
        Circle(double a) : Shape(a,a){
            w = 2*a;
            h = 2*a;
            _area =  w*w*pi/4;
            _perimeter = w*pi;
        };
};
#endif
#endif
#endif
#endif
