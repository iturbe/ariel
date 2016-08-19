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
    virtual Computadora * crear(string) = 0;
    
    Computadora * crearComputadora(string tipo)
    {
        Computadora * nueva = crear(tipo);
        cout << "Creando una " + tipo << endl;
        nueva->seleccionarComponentes();
        nueva->ensamblar();
        nueva->instalarSoftware();
        nueva->empacar();
        cout << endl;
        return nueva;
    }
};

//----------------------------------------

class FabricaFisica : public Fabrica {
private:
    FabricaFisica(){};
    
public:
    static FabricaFisica * instancia;
    Computadora * crear(string tipo)
    {
        if (tipo == "laptop"){
            return new Laptop;}
        else if (tipo == "netbook")
            return new Netbook;
        else if (tipo == "desktop")
            return new Desktop;
        else if (tipo == "tablet")
            return new Tablet;
        else
            {
                cout << "Error: No se puede crear una Computadora de tipo " + tipo << endl;
                return nullptr;
            }
    }
    
    static FabricaFisica * getInstance()
    {
        if (!instancia) {instancia = new FabricaFisica;}
        return instancia;
    }
};

//Se necesita inicializar la variable fuera de la clase para asegurar su unicidad
FabricaFisica * FabricaFisica::instancia = 0;

#endif /* Fabrica_hpp */
