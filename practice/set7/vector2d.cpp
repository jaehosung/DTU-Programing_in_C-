#include "vector2d.h"
#include <cmath>

v2d::v2d(double a, double b){
// put something here
    this->x = a;
    this->y = b;
}

v2d::v2d(const v2d & v){
// put something here
    this->x = v.x;
    this->y = v.y;
}

v2d::~v2d(){
// put something here
}


v2d & v2d::operator=(const v2d &v){
    this->x=v.x;
    this->y=v.y;
    return *this;
}
v2d & v2d::operator+(const v2d &v){
    this->x+=v.x;
    this->y+=v.y;
    return *this;
}

double v2d::operator*(const v2d &v){
    return this->x*v.x+this->y*v.y;
}

v2d & v2d::operator*(double k){
// put something here
    this->x *=k;
    this->y *=k;
    return *this;
}

double v2d::length(){
// put something here
    return sqrt(this->x*this->x + this->y*this->y);
}
