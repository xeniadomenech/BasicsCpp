
#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H
#include <iostream>

using namespace std;

class Quadrilateral {
public:
    Quadrilateral();
    Quadrilateral(const Quadrilateral& orig);
    virtual ~Quadrilateral();
    
    virtual float getArea() = 0;
    virtual float getPerimetre() = 0;
    virtual void print();
};

#endif /* QUADRILATERAL_H */