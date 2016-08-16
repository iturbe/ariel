//
//  Computadora.hpp
//  Tarea_1
//
//  Created by Alonso Iturbe on 8/14/16.
//  Copyright © 2016 Alonso Iturbe. All rights reserved.
//

#ifndef Computadora_hpp
#define Computadora_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Computadora {
public:
    string componentes = "Sin componentes";
    string ensamblado = "Sin ensamblar";
    string software = "Sin software";
    string empaquetado = " Sin empaquetar";
    
    //Retorna un párrafo con las especificaciones de la computadora
    void resumen();
};

#endif /* Computadora_hpp */
