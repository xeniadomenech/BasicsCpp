

#ifndef SQUARE_H
#define SQUARE_H
#include <iostream>
#include "Quadrilateral.h"

using namespace std;

class Square : public Quadrilateral{
public:
    Square();
    Square(double nombre);
    Square(const Square& orig);
    virtual ~Square(); 
    
    float getArea();
    float getPerimetre();
    void print();
private:
    double num;
};

#endif /* SQUARE_H */

