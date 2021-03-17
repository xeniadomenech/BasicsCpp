#include "Square.h"

Square::Square():Quadrilateral(){
    cout << "Constructor de Quadrat sense parametres" << endl;
}
Square::Square(double nombre):Quadrilateral(){
    if (nombre <= 0)
        throw invalid_argument("S’ha produït una excepció");
    cout << "Constructor de Quadrat amb parametres" << endl;
    num=nombre;
}

Square::Square(const Square& orig):Quadrilateral(){
}

Square::~Square(){
    cout << "Destructor de Quadrat" << endl;
}

float Square::getArea(){
    return num*num;
}

float Square::getPerimetre(){
    return 4*num;
}

void Square::print(){
    cout << "Quadrat (base = " << num  << ")" << endl;
    cout << "AREA: " << getArea() << endl;
    cout << "PERIMETRE: " << getPerimetre() << endl;
}