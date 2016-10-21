//
//  Proxy.h
//  SegundoParcial
//
//  Created by Alonso Iturbe on 10/21/16.
//  Copyright © 2016 Alonso Iturbe. All rights reserved.
//

#ifndef Proxy_h
#define Proxy_h

#include "Observers.h"
#include <string>

using namespace std;

class Switcher {
public:
    Subject newsStation;
    
public:
    //user-friendly interface para ingresar noticia
    void menu(){
        cout << "¡Bienvenido al switchero de noticias! ¿De quien se trata tu noticia?\n1. Peña Nieto\n2. Hillary\n3. Trump" << endl << endl << "Opción: ";
        int choice;
        cin >> choice;
        newsStation.setType(choice);
        return getNews();
    };
    
    //obtiene la noticia (headline) del usuario
    void getNews(){
        cout << endl << "Ingresa el headline: ";
        string line;
        cin.ignore();
        getline(cin, line);
        newsStation.setHeadline(line);
        cout << endl << "¿Deseas ingresar otra noticia? (y/n): ";
        string choice;
        cin >> choice;
        if (choice != "n"){return menu();}
    };
};

#endif /* Proxy_h */
