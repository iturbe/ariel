//
//  Observers.h
//  SegundoParcial
//
//  Created by Alonso Iturbe on 10/21/16.
//  Copyright © 2016 Alonso Iturbe. All rights reserved.
//

#ifndef Observers_h
#define Observers_h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class NewsObserver {
    string headline;
    string name;
    
public:
    //constructor con lista de inicialización
    NewsObserver(string h, string n) : headline(h), name(n){}
    
    //simplemente imprime el update de la noticia
    void printUpdate(string update){
        cout << name << " Breaking News: " << update << endl;
    }
};

class Subject {
    //headline y tipo de noticia (para el switch)
    string headline;
    int newsType;
    
    //estaciones de noticias
    NewsObserver mvs;
    NewsObserver televisa;
    NewsObserver azteca;
    NewsObserver radio;
    NewsObserver cnn;
    
    //listas de a quienes les va a llegar cada noticia
    vector <NewsObserver> nieto;
    vector <NewsObserver> hillary;
    vector <NewsObserver> trump;
    
    
public:
    //constructor con lista de inicialización
    Subject() : newsType(2), headline("Inicializamos Programa"), mvs("","MVS"), televisa("", "Televisa"), azteca("", "TV Azteca"), radio("", "Radio Fórmula"), cnn(" ", "CNN"){
        
        //news stations a quienes les va a llegar la noticia de peña
        nieto.push_back(mvs);
        nieto.push_back(televisa);
        nieto.push_back(azteca);
        nieto.push_back(radio);
        
        //news stations a quienes les va a llegar la noticia de hillary
        hillary.push_back(mvs);
        hillary.push_back(televisa);
        hillary.push_back(azteca);
        hillary.push_back(radio);
        hillary.push_back(cnn);
        
        //news stations a quienes les va a llegar la noticia de trump
        trump.push_back(mvs);
        trump.push_back(televisa);
        trump.push_back(azteca);
        trump.push_back(radio);
        trump.push_back(cnn);
    }
    
    //asignar valor guarda el valor deseado y manda llamar notify
    void setHeadline(string input){
        headline = input;
        newsNotify();
    }
    
    //set el tipo de noticia
    void setType(int input){
        newsType = input;
    }

    //notify manda llamar los comandos de printUpdate de los objetos
    void newsNotify(){
        switch (newsType) {
            case 1: //noticia es sobre peña
                for (int a = 0; a < nieto.size(); a++) {
                    nieto.at(a).printUpdate(headline);
                }
                break;
                
            case 2: //noticia es sobre hillary
                for (int a = 0; a < hillary.size(); a++) {
                    hillary.at(a).printUpdate(headline);
                }
                break;
                
            case 3: //noticia es sobre trump
                for (int a = 0; a < trump.size(); a++) {
                    trump.at(a).printUpdate(headline);
                }
                break;
                
            default:
                cout << "Error al procesar la noticia" << endl;
                break;
        }
        
    }
    
};

#endif /* Observers_h */
