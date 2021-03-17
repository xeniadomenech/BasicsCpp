
#include "Rectangle.h"

Rectangle::Rectangle():Quadrilateral(){
    cout << "Constructor de Rectangle sense paràmetres" << endl;
}

Rectangle::Rectangle(double base, double altura):Quadrilateral(){
    if(altura<=0 || base<=0)
        throw invalid_argument("S’ha produït una excepció");
    cout << "Constructor de Rectangle amb parametres" << endl;
    a=altura;
    b=base;
}

Rectangle::Rectangle(const Rectangle& orig):Quadrilateral(){
}

Rectangle::~Rectangle(){
    cout << "Destructor de Rectangle" << endl;
}

float Rectangle::getArea(){
    return a*b;
}

float Rectangle::getPerimetre(){
    return 2*a + 2*b;
}

void Rectangle::print(){
    cout << "Rectangle (base = " << b << ", altura = " << a << ")" << endl;
    cout << "AREA: " << getArea() << endl;
    cout << "PERIMETRE: " << getPerimetre() << endl;
}

