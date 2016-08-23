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
    
    virtual void seleccionarComponentes() = 0;
    virtual void ensamblar() = 0;
    virtual void instalarSoftware() = 0;
    virtual void empacar() = 0;
};

template <class Base, class SubClase>
class Clonado : public Base
{
public:
    using Base::Base;
    virtual Base * clonar()
    {
        return new SubClase(dynamic_cast<SubClase&>(*this));
    }
};

class Laptop : public Clonado <Computadora, Laptop> {
    friend class FabricaFisica;
private:
    Laptop(){};
    
public:
    void seleccionarComponentes(){cout << "Componentes de la laptop seleccionados" << endl;}
    void ensamblar(){cout << "Laptop ensamblada correctamente" << endl;}
    void instalarSoftware(){cout << "MacOS instalado correctamente" << endl;}
    void empacar(){cout << "Laptop empacada correctamente con su cargador" << endl;}
};

class Desktop : public Clonado <Computadora, Desktop> {
    friend class FabricaFisica;
private:
    Desktop(){};
    
public:
    void seleccionarComponentes(){cout << "Componentes de la desktop seleccionados" << endl;}
    void ensamblar(){cout << "Desktop ensamblada correctamente" << endl;}
    void instalarSoftware(){cout << "MacOS instalado correctamente" << endl;}
    void empacar(){cout << "Desktop empacada correctamente con su cable de corriente, Magic Mouse y Bluetooth Keyboard" << endl;}
};

class Netbook : public Clonado <Computadora, Netbook> {
    friend class FabricaFisica;
private:
    Netbook(){};
    
public:
    void seleccionarComponentes(){cout << "Componentes de la netbook seleccionados" << endl;}
    void ensamblar(){cout << "Netbook ensamblada correctamente" << endl;}
    void instalarSoftware(){cout << "MacOS instalado correctamente" << endl;}
    void empacar(){cout << "Netbook empacada correctamente con su cargador" << endl;}
};

class Tablet : public Clonado <Computadora, Tablet> {
    friend class FabricaFisica;
private:
    Tablet(){};
    
public:
    void seleccionarComponentes(){cout << "Componentes de la tablet seleccionados" << endl;}
    void ensamblar(){cout << "Tablet ensamblada correctamente" << endl;}
    void instalarSoftware(){cout << "iOS 10 instalado correctamente" << endl;}
    void empacar(){cout << "Tablet empacada correctamente con su cargador" << endl;}
};

#endif /* Computadora_hpp */
