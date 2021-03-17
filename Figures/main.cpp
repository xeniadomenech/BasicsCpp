/*EXERCICI 7*/

#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Square.h"
#include "Rectangle.h"
#include "Quadrilateral.h"
#include "QuadrilateralContainer.h"

using namespace std;

void introduirQuadrat (int &comptS, float base, QuadrilateralContainer *quadril){
    try{
        cout << endl;
        Square *quadrat = new Square(base);
        quadrat->print();
        quadril->addQuadrilateral(quadrat);
        comptS++;
        cout << endl;
    }
    catch(const invalid_argument& e){
        cout << e.what() << endl;
    }    
}

void introduirRectangle (int &comptR, float base, float altura, QuadrilateralContainer *quadril){
    try{
        cout << endl;
        Rectangle *rect = new Rectangle(base,altura);
        quadril->addQuadrilateral(rect);
        rect->print();
        comptR++;
        cout << endl;
    }
    catch(const invalid_argument& e){
        cout << e.what() << endl;
    }    
}

void afegirFigura (int &comptS, int &comptR, QuadrilateralContainer *quadril) {
    float a,b;
    char sr;
    cout << "(S)quare/(R)ectangle?" << endl;
    cin >> sr;
    switch(sr){
        case 'R':
            cout << "Base?" << endl;
            cout << "Altura?" << endl;
            cin >> b >> a;
            introduirRectangle(comptR, b, a, quadril);break;
        case 'S':
            cout << "Base?" << endl;
            cin >> b;
            introduirQuadrat(comptS, b, quadril);break;
        default: 
            cout << endl;
            cout << "Error en la opció." << endl;
            cout << endl;break;
    }
}

void llegirFitxer (int &comptS, int &comptR, QuadrilateralContainer *quadril){
    float a,b;
    char sr;
    ifstream fitxer;
    fitxer.open("Figures.txt",ios::in);
    cout << endl;
    cout << "Reading file Figures.txt" << endl;
    if(!fitxer){
        cout << "Fitxer buit." << endl;
    }else{
        while (quadril->count()<10 && !fitxer.eof()){
            fitxer >> sr >> b;
            if(sr=='R')
                fitxer >> a;
            switch(sr){
                case 'R':
                    introduirRectangle(comptR, b, a, quadril);break;
                case 'S':
                    introduirQuadrat(comptS, b, quadril);break;
                default: 
                    cout << endl;
                    cout << "Error en la opció." << endl;
                    cout << endl;break;
            }
        }
    }
    if(quadril->count()==10)
                cout << "Error: ja hem guardat el maxim de figures." << endl;
    fitxer.close();
}


int main(int argc, char** argv) {
    int i, opcio, comptR=0, comptS=0, suma=0, max=0;
    QuadrilateralContainer *quadril = new QuadrilateralContainer();
    string nom;
    string arr_options[] = {"Sortir", "Afegir figura", "Llegir fitxer",
    "Glossari de figures", "Calcular la suma de les arees"};
    do{
        cout << endl;
        max=quadril->count();
        cout << " ---------------------------------------" << endl;
        cout << "  Hola, tenim " << max << " figures emmagatzemades." << endl;
        cout << " ---------------------------------------" << endl;
        cout << "  Que vols fer ara?" <<endl;
        for (i=0; i<5; i++)
            cout << "  " << i+1 << ". " << arr_options[i] << endl;
        cout << " ---------------------------------------" << endl;
        cin >> opcio;
        switch(opcio){
            case 1: cout << "Fins la propera " << nom << endl;break;
            case 2:
                if(max<10){
                    afegirFigura(comptS, comptR, quadril);
                }else{
                    cout << "No podem afegir mes figures" << endl;
                }break;
            case 3:
                if(max<10){
                    llegirFitxer(comptS, comptR, quadril);
                }else{
                    cout << "No podem afegir mes figures" << endl;
                }break; 
            case 4: 
                cout << endl;
                try{
                    cout << " INFORMACIO DE LES FIGURES" << endl;
                    cout << " =========================" << endl;
                    cout << endl;
                    cout << "Tens " << comptS << " quadrats i " << comptR <<
                    " rectangles." << endl;
                    quadril->print();
                    cout << endl;
                }catch(const invalid_argument& e){
                    cout << e.what() << endl;
                }break;
            case 5: 
                cout << endl;
                try{
                    suma=quadril->getAreas();
                    cout << "********************" << endl;
                    cout << endl;
                    cout << "La suma de les arees es " << suma << endl;
                    cout << endl;
                }catch(const invalid_argument& e){
                        cout << e.what() << endl;
                }break;
            default: 
                cout << endl;
                cout << "Error en la opció." << endl;
                cout << endl;break;
        }
    }while(opcio != 1);
    delete quadril;
    return 0;
}

/*A partir del què has observat respon:
 
 * a) Què ens permet fer l'herència que no podríem fer altrament?
 
 L'herència permet la reusabilitat de variables i funcionalitats que s'han definit
 en diverses classes. En aquest cas, les classe filles (Square i Rectangle) 
 hereten només les funcionalitats de la classe mare (Quadrilariteral), és a dir,
 els mètodes. Per tant, quan creem un objecte de la classe Square o un de la 
 classe Rectangle, alhora estem creant un objecte de la classe Quadrilateral, i
 el mateix passa quan destruim aquests objectes.

 * b) Que passa si getArea() de la classe Quadrilateral no és virtual? Per què?
 
 Si la funció getArea() de Quadrilateral no és virtual, però fem herència de classes
 i creem classes filles que també tinguin la funció getArea(), quan cridem aquesta
 funció, ens saltarà un error. Això és degut a que malgrat comparteixen nom, les dues 
 funcions getArea() definides no estan relacionades. Això passa perquè les 
 classes filles sobreescriuen el comportament de la classe mare, i el que fa
 el mètode "virtual" és crear un enllaç dinàmic entre el getArea() de la classe
 Quadrilàter i el de les seves classes filles.
 
 * c)Per què els constructors i desctructors els hem de cridar a les classes derivades i no a la classe base?
 
 Els cridem a les classes derivades i no a la classe base degut a què si 
 construim o destruim un objecte de la classe derivada, automàticament estem
 creant l'objecte també en la classe base. En canvi, si cridem al constructor 
 o al destructor de la classe base, només creem o destruim l'objecte d'aquesta
 classe i no de les derivades.


 * d) Es podria fer que getArea() i getPerimetre() fos només un mètode de la classe "Quadrilateral"?
 
 Obviament, les classes filles deriven de la mare, per tant, podem concloure 
 que les classes filles són especificacions de la classe mare. En aquest cas,
 el quadrat i el rectangle són tipus de quadrilaters, per tant, podríem tenir
 només la classe Quadrilateral amb les respectives funcions getArea() i getPerimetre()
 per calcular les propietats de les figures concretes. 
 Això si, el que no podríem fer és definir aquestes funcions a la classe mare 
 i no a les classes filles, i després usarles amb objectes creat de les classes
 filles. 

 * e) Anomena els membres de dades definits en els teus programes i digues a quina classe pertanyen. Explica
les decisions de visibilitat de cadascun.
 
 En la classe Square tinc declarat l'atribut num (que fa referència a la base del
 quadrat), en la classe Rectangle tinc definits els atributs a i b (fan referència
 a la base i a l'altura del rectangle). En canvi, en la classe Quadrilateral
 no tinc definit cap atribut, i en la classe QuadrilateralContainer tinc declarat
 el vector de figures i un enter suma que calcula la suma de les arees.
 Tots els atributs definits en les classes són privades, i això és equivalent a 
 tenir nivell d'encapsulament tancat, és a dir, només es pot accedir als respectius
 atributs de cada classe des de la pròpia classe.

 * L’iterador que recorre les figures, quant s’incrementa cada cop? Per què?

 L'iterador s'incrementa una posició de memoria en cada cas, això és degut a què
 s'està iternant sobre un vector de punters, i això és un vector de poscions de
 memòria.

 */
