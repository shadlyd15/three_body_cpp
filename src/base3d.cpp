#include <iostream>
#include "base3d.h"
using namespace std;

std::ostream& operator<<(std::ostream &output, const Base3D& b){
    output << b.x << "," << b.y << "," << b.z;
    return output;
}

Base3D Base3D::operator+(const Base3D &b){
	Base3D result;
    result.x = this->x + b.x;
    result.y = this->y + b.y;
    result.z = this->z + b.z;
    return result;
}

Base3D Base3D::operator-(const Base3D &b){
	Base3D result;
    result.x = this->x - b.x;
    result.y = this->y - b.y;
    result.z = this->z - b.z;
    return result;
}

Base3D Base3D::operator*(const Base3D &b){
	Base3D result;
    result.x = this->x * b.x;
    result.y = this->y * b.y;
    result.z = this->z * b.z;
    return result;
}

Base3D Base3D::operator/(const Base3D &b){
	Base3D result;
    result.x = this->x / b.x;
    result.y = this->y / b.y;
    result.z = this->z / b.z;
    return result;
}

Base3D Base3D::operator+(double scaler){
	Base3D result;
    result.x = this->x + scaler;
    result.y = this->y + scaler;
    result.z = this->z + scaler;
    return result;
}

Base3D Base3D::operator-(double scaler){
	Base3D result;
    result.x = this->x - scaler;
    result.y = this->y - scaler;
    result.z = this->z - scaler;
    return result;
}

Base3D Base3D::operator*(double scaler){
	Base3D result;
    result.x = this->x * scaler;
    result.y = this->y * scaler;
    result.z = this->z * scaler;
    return result;
}

Base3D Base3D::operator/(double scaler){
	Base3D result;
    result.x = this->x / scaler;
    result.y = this->y / scaler;
    result.z = this->z / scaler;
    return result;
}

void Base3D::randomize(){
    this->x = rand() % 10;
    this->y = rand() % 10;
    this->z = rand() % 10;
}

// double Base3D::norm(Base3D &b){
//     return sqrt(pow(b->x,2) + pow(b->y2) + pow(b->z,2));
// }