#include "QuadrilateralContainer.h"

QuadrilateralContainer::QuadrilateralContainer() {
    v = std::vector<Quadrilateral*>();
    cout << "Constructor de QuadrilateralContainer" << endl;
}

QuadrilateralContainer::QuadrilateralContainer(const QuadrilateralContainer& orig) {
}

QuadrilateralContainer::~QuadrilateralContainer() {
    cout << "Destructor de QuadrilateralContainer" << endl;
    cout << endl;
}


void QuadrilateralContainer::addQuadrilateral(Quadrilateral *figura) {
    if(v.size()<10){
        v.push_back(figura);
    }else{
        cout << endl;
        cout << "Ja tenim 10 figures guardades." << endl;
    }
    
}

float QuadrilateralContainer::getAreas() {
    suma = 0;
    int compt=1;
    float tmp;
    cout << "********************" << endl;
    for (std::vector<Quadrilateral*>::iterator it = v.begin(); it != v.end(); ++it) {
        if (Square* s = dynamic_cast<Square*> (*it)) {
            tmp = s->getArea();
            cout << "* Area figura " << compt << ": " << tmp  << " *" << endl;
        }else if (Rectangle* r = dynamic_cast<Rectangle*> (*it)){
            tmp = r->getArea();
            cout << "* Area figura " << compt << ": " << tmp << " *" << endl;
        }else{
            throw invalid_argument("S’ha produït una excepció");
        }
        compt++;
        suma += tmp;
    }
    return suma;
}

void QuadrilateralContainer::print() {
    cout << endl;
    for (std::vector<Quadrilateral*>::iterator it = v.begin(); it != v.end(); ++it) {
        if (Square *s = dynamic_cast<Square*> (*it)) {
            s->print();
            cout << endl;
        }else if (Rectangle *r = dynamic_cast<Rectangle*> (*it)){
            r->print();
            cout << endl;
        }else{
            throw invalid_argument("S’ha produït una excepció");
        }
    }    
}

int QuadrilateralContainer::count() {
    return v.size();
}