//
//  Fabrica.hpp
//  Tarea_1
//
//  Created by Alonso Iturbe on 8/14/16.
//  Copyright © 2016 Alonso Iturbe. All rights reserved.
//

#ifndef Fabrica_hpp
#define Fabrica_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "Computadora.hpp"

using namespace std;

class Fabrica {
    
public:
    
    string seleccionarComponentes(string input);
    string ensamblar(string input);
    string instalarSoftware(string input);
    string empacar(string input);
    
    Computadora * crear(string tipo);
};

#endif /* Fabrica_hpp */
