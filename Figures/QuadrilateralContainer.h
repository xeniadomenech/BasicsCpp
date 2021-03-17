#ifndef QUADRILATERALCONTAINER_H
#define QUADRILATERALCONTAINER_H
#include <iostream>
#include <vector>
#include "Quadrilateral.h"
#include "Rectangle.h"
#include "Square.h"
 
class QuadrilateralContainer {
public:
    QuadrilateralContainer();
    QuadrilateralContainer(const QuadrilateralContainer& orig);
    virtual ~QuadrilateralContainer();
    
    void addQuadrilateral(Quadrilateral *figura);
    float getAreas();
    void print();
    int count();
    
    
private:
    std::vector<Quadrilateral*> v;
    float suma;
};

#endif /* QUADRILATERALCONTAINER_H */

