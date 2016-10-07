//
//  Clases.h
//  Observer (7 oct)
//
//  Created by Alonso Iturbe on 10/7/16.
//  Copyright © 2016 Alonso Iturbe. All rights reserved.
//

#ifndef Clases_h
#define Clases_h

#include <iostream>

using namespace std;

class SumObserver
{
    int numero;

public:
    //constructor
    SumObserver(int num) : numero(num){}
    
    //update function es llamada por observer cuando haya algún cambio en valores
    void printUpdate(int val)
    {
        cout << val << " + " << numero << " = " << val + numero << '\n';
    }
};

class ResObserver
{
    int numero;
public:
    //constructor
    ResObserver(int num) : numero(num){}
    
    //update function es llamada por observer cuando haya algún cambio en valores
    void printUpdate(int val)
    {
        cout << val << " - " << numero << " = " << val - numero << '\n';
    }
};

class Subject
{
    int value;
    //objetos de tipo observers son parte de Subject. para extender funcionalidad sería un arreglo dinámico de objetos observadores
    SumObserver suma;
    ResObserver resta;

public:
    //constructor con lista de inicialización
    Subject() : suma(4), resta(3){}
    
    //asignar valor guarda el valor deseado y manda llamar notify
    void setValue(int input)
    {
        value = input;
        notify();
    }
    
    //notify manda llamar los comandos de printUpdate de los objetos
    void notify()
    {
        suma.printUpdate(value);
        resta.printUpdate(value);
    }
};


#endif /* Clases_h */
