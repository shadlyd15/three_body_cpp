#ifndef __BASE3D_H__
#define __BASE3D_H__

#include <iostream>

using namespace std;

// np-array type data structure that does math operations elementwise

class Base3D {
    public:
        Base3D():x(0), y(0), z(0){};
        Base3D(double x, double y, double z):x(x), y(y), z(z){};
        Base3D(const Base3D& b):x(b.x), y(b.y), z(b.z){};

        Base3D operator+(const Base3D &base);
        Base3D operator-(const Base3D &base);
        Base3D operator*(const Base3D &base);
        Base3D operator/(const Base3D &base);

        Base3D operator+(double scaler);
        Base3D operator-(double scaler);
        Base3D operator*(double scaler);
        Base3D operator/(double scaler);


        // double norm();
        void randomize();

        friend std::ostream &operator<<(std::ostream &output, const Base3D& b);
        
    // private:
        double x, y, z;
};

#endif