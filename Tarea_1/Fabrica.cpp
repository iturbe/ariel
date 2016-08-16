//
//  Fabrica.cpp
//  Tarea_1
//
//  Created by Alonso Iturbe on 8/14/16.
//  Copyright © 2016 Alonso Iturbe. All rights reserved.
//

#include "Fabrica.hpp"
#include <iostream>
#include <string>
#include "Computadora.hpp"

using namespace std;

//función principal, manda llmamar a las demás
Computadora * Fabrica::crear(string tipo){
    Computadora * base = new Computadora();
    if (tipo == "laptop" || tipo == "netbook" || tipo == "desktop" || tipo == "tablet")
    {
        cout << endl << "*** Estamos armando tu " + tipo + " ***" << endl;
        base->componentes = seleccionarComponentes(tipo);
        base->ensamblado = ensamblar(tipo);
        base->software = instalarSoftware(tipo);
        base->empaquetado = empacar(tipo);
        return base;
    }
    else
    cout << endl << "Lo sentimos, por el momento no contamos con la creación de computadoras tipo '" + tipo + "'.";
    return base;
    
}

//retorna e imprime el estatus de seleccion de componentes
string Fabrica::seleccionarComponentes(string tipo){
    cout << "Se han seleccionado los componentes para la " + tipo + " correctamente." << endl;
    return "Completos";
}

//retorna e imprime el estatus de ensamblaje
string Fabrica::ensamblar(string tipo){
    cout << "Se ha ensamblado la " + tipo + " correctamente." << endl;
    return "100%";
}

//retorna e imprime el nombre del sistema operativo instalado
string Fabrica::instalarSoftware(string tipo){
    cout << "Se ha instalado el software en la " + tipo + " correctamente." << endl;
    if (tipo == "tablet")
    {
        return "iOS 10";
    }
    else
        return "Mac OS X Sierra";
}

//retorna e imprime el estatus de empaque
string Fabrica::empacar(string tipo){
    cout << "Se ha empacado la " + tipo + " correctamente." << endl;
    if (tipo == "desktop")
    {
        return "Empacada con cable de corriente, Magic Mouse y Wireless Keyboard";
    }
    else
        return "Empacada con cargador";
}