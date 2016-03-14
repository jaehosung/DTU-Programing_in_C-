#include "vector2d.h"
#include <cmath>

v2d::v2d(double a, double b){
// put something here
    x = a;
    y = b;
}

v2d::v2d(const v2d & v){
// put something here
    x = v.x;
    y = v.y;
}

v2d::~v2d(){
// put something here
}


v2d & v2d::operator=(const v2d &v){
    x=v.x;
    y=v.y;
    return *this;
}
v2d & v2d::operator+(const v2d &v){
    x+=v.x;
    y+=v.y;
    return *this;
}

double v2d::operator*(const v2d &v){
    return x*v.x+y*v.y;
}

v2d & v2d::operator*(double k){
// put something here
    x *=k;
    y *=k;
    return *this;
}

double v2d::length(){
// put something here
    return sqrt(x*x + y*y);
}
