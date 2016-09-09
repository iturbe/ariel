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
#include "Pasteles.hpp"

using namespace std;

class Fabrica {
    
public:
    Fabrica(){}
    virtual Pastel * crear(string) = 0;
    //virtual Computadora * clonar(Computadora) = 0;
    
    Pastel * crearPastel(string tipo)
    {
        Pastel * nuevo;
        //Pastel * nueva = crear(tipo);
        if (tipo == "tresleches"){
            cout << "El pastel de Tres Leches será creado en Aguascalientes, donde se utilizan los ingredientes: leche, huevo y mantequilla" << endl;
            nuevo = new TresLeches;}
        else if (tipo == "sacher"){
            cout << "El pastel Sacher será creado en la CDMX, donde se utilizan los ingredientes: chocolate, frutas, merengue" << endl;
            nuevo = new Sacher;}
        else if (tipo == "imposible"){
            cout << "El pastel Imposible será creado en la CDMX, donde se utilizan los ingredientes: chocolate, frutas, merengue" << endl;
            nuevo = new Imposible;}
        else
        {
            cout << "Error: Todavía no se cuenta con la creación de pasteles de tipo " + tipo << endl << endl;
            return nullptr;
        }
        cout << "Creando un " + tipo << endl;
        nuevo->batido();
        nuevo->amasado();
        nuevo->horneado();
        nuevo->decorado();
        nuevo->empaquetado();
        cout << endl;
        return nuevo;
    }
};

//----------------------------------------

class FabricaFisica : public Fabrica {

private:
    FabricaFisica(){};
    
public:
    //FabricaFisica(){};
    //static FabricaFisica * instancia;
    Pastel * crear(string tipo)
    {
        if (tipo == "tresleches"){
            return new TresLeches;}
        else if (tipo == "sacher")
            return new Sacher;
        else if (tipo == "imposible")
            return new Imposible;
        else
            {
                cout << "Error: No se puede crear un pastel de tipo " + tipo << endl;
                return nullptr;
            }
    }
    /*
    static FabricaFisica * getInstance()
    {
        if (!instancia) {instancia = new FabricaFisica;}
        return instancia;
    }
     */
    
};

//Se necesita inicializar la variable fuera de la clase para asegurar su unicidad
//FabricaFisica * FabricaFisica::instancia = 0;

#endif /* Fabrica_hpp */
