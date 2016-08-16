//
//  Computadora.cpp
//  Tarea_1
//
//  Created by Alonso Iturbe on 8/14/16.
//  Copyright © 2016 Alonso Iturbe. All rights reserved.
//

#include "Computadora.hpp"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

void Computadora::resumen(){
    cout << endl << "Resumen de producto:" << endl;
    cout << "Seleccion de componentes: " + componentes + "." << endl;
    cout << "Estatus de ensamblado: " + ensamblado + "." << endl;
    cout << "Software instalado: " + software + "." << endl;
    cout << "Estatus del empaquetado: " + empaquetado + "." << endl;
}