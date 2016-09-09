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

class Pastel {
public:
    string nombre;
    void setNombre(string name){nombre = name;};
    virtual void batido() = 0;
    virtual void amasado() = 0;
    virtual void horneado() = 0;
    virtual void decorado() = 0;
    virtual void empaquetado() = 0;
    virtual Pastel * clonar() = 0;
};

template <class Base, class SubClase>
class Clonado : public Base
{
public:
    using Base::Base;
    /*
    virtual Base * clonar()
    {
        return new SubClase(dynamic_cast<SubClase&>(*this));
        //cout << "esto se está usando";
    }
     */
};


class TresLeches : public Clonado <Pastel, TresLeches> {
    friend class FabricaFisica;

public:
    TresLeches(){};
    void batido(){cout << "Batiendo el pastel de Tres Leches" << endl;}
    void amasado(){cout << "Amasando el pastel de Tres Leches" << endl;}
    void horneado(){cout << "Horneando el pastel de Tres Leches" << endl;}
    void decorado(){cout << "Decorando el pastel de Tres Leches" << endl;}
    void empaquetado(){cout << "Empaquetando el pastel de Tres Leches" << endl;}
    TresLeches * clonar(){
        cout << "Clonando un pastel de Tres Leches..." << endl;
        return new TresLeches(*this);};
};

class Sacher : public Clonado <Pastel, Sacher> {
    friend class FabricaFisica;
    
public:
    Sacher(){};
    void batido(){cout << "Batiendo el pastel Sacher" << endl;}
    void amasado(){cout << "Amasando el pastel Sacher" << endl;}
    void horneado(){cout << "Horneando el pastel Sacher" << endl;}
    void decorado(){cout << "Decorando el pastel Sacher" << endl;}
    void empaquetado(){cout << "Empaquetando el pastel Sacher" << endl;}
    Sacher * clonar(){
        cout << "Clonando un pastel Sacher..." << endl;
        return new Sacher(*this);};
};

class Imposible : public Clonado <Pastel, Imposible> {
    friend class FabricaFisica;
    
public:
    Imposible(){};
    void batido(){cout << "Batiendo el pastel Imposible" << endl;}
    void amasado(){cout << "Amasando el pastel Imposible" << endl;}
    void horneado(){cout << "Horneando el pastel Imposible" << endl;}
    void decorado(){cout << "Decorando el pastel Imposible" << endl;}
    void empaquetado(){cout << "Empaquetando el pastel Imposible" << endl;}
    Imposible * clonar(){
        cout << "Clonando un pastel Imposible..." << endl;
        return new Imposible(*this);};
};

#endif /* Computadora_hpp */
