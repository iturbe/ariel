//
//  Avion.h
//  Builder (26 aug)
//
//  Created by Alonso Iturbe on 8/26/16.
//  Copyright © 2016 Alonso Iturbe. All rights reserved.
//

#ifndef Avion_h
#define Avion_h

#include <string>

using namespace std;

class Motor {
private:
    int potencia;
    int numserie;
    string marca;
    
public:
    int getPotencia(){return potencia;};
    int getNumserie(){return numserie;};
    string getMarca(){return marca;};
    void setPotencia(int _potencia){potencia = _potencia;}
    void setNumserie(int _numserie){numserie = _numserie;}
    void setMarca(string _marca){marca = _marca;}
};

class Alas {
private:
    int hipersustentador;
    int numserie;
    string marca;
    
public:
    int getHipersustentador(){return hipersustentador;};
    int getNumserie(){return numserie;};
    string getMarca(){return marca;};
    void setHipersustentador(int _hipersustentador){hipersustentador = _hipersustentador;}
    void setNumserie(int _numserie){numserie = _numserie;}
    void setMarca(string _marca){marca = _marca;}
};

class Piloto {
private:
    string nombre;
    
public:
    string getNombre(){return nombre;};
    void setNombre(string _nombre){nombre = _nombre;};
};

class Avion {
private:
    int numserie;
    string marca;
    Motor * motor;
    Alas * alas;
    Piloto piloto;
    
public:
    int getNumserie(){return numserie;}
    string getMarca(){return marca;}
    void setNumserie(int _numserie){numserie = _numserie;}
    void setMarca(string _marca){marca = _marca;}
    void setAlas(Alas * _alas){alas = _alas;};
    void setMotor(Motor * _motor){motor = _motor;};
};

class Builder {
protected:
    Avion * avion;
public:
    Avion * getAvion(){return avion;};
    virtual void buildAlas() = 0;
    virtual void buildMotor() = 0;
    virtual void buildNumSerie() = 0;
    virtual void buildMarca() = 0;
    void createAvion(){avion = new Avion();};
};

class BoeingBuilder : public Builder {
public:
    void buildAlas(){
        Alas * lasAlas = new Alas();
        lasAlas->setMarca("Boeing");
        avion->setAlas(lasAlas);
    };
    void buildMotor(){
        Motor * elMotor = new Motor();
        elMotor->setMarca("Boeing");
        avion->setMotor(elMotor);
    };
    void buildNumSerie(){avion->setNumserie(12345);};
    void buildMarca(){avion->setMarca("Boeing");};
};

class Director {
private:
    Builder * builder;
    
public:
    void setBuilder(Builder * bd){
        builder = bd;
    };
    Avion * getAvion(){
        return builder->getAvion();
    };
    void construct(){
        builder->createAvion();
        builder->buildNumSerie();
        builder->buildMarca();
        builder->buildAlas();
        builder->buildMotor();
    }
};


#endif /* Avion_h */
