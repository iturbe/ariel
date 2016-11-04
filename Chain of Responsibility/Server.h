//
//  Server.h
//  Chain of Responsibility
//
//  Created by Alonso Iturbe on 11/1/16.
//  Copyright © 2016 Alonso Iturbe. All rights reserved.
//

#ifndef Server_h
#define Server_h

#include <vector>
#include <iostream>
#include <string>
#include <string.h>

#include "Request.h"

using namespace std;

class Server {
    vector <string> domains;
    Server *sucessor;
    string name;
    
    
public:
    
    //constructor
    Server(string _name) : name(_name), sucessor(NULL){}
    
    //return name
    string getName(){return name;}
    Server * getNext(){return sucessor;}
    void setNext(Server * _sucessor){sucessor = _sucessor;}
    
    //buscar el dominio dentro de la lista de dominios
    void processRequest(Request query){
        for (int a = 0; a < domains.size(); a+=2) { //iterar lista de direcciones
            string current = domains.at(a);
            if (current.compare(query.getDomain()) == 0) { //checar si encontramos el dominio
                cout << "El servidor " << getName() << " ha resuelto la dirección." << endl << domains.at(a) << " <-> " << domains.at(a+1) << endl << endl;
                return;
            }
        }
        if (getNext() == NULL) {
            cout << "Ningún servidor pudo resolver " << query.getDomain() << endl;
            return;
        }
        else
        cout << "El servidor " << getName() << " no pudo resolver " << query.getDomain() << ", mandando a " << getNext()->getName() << "..." << endl;
        return getNext()->processRequest(query);
    }
    
    //imprime todos los dominios en el servidor
    void printRelations(){
        cout << getName() << "'s relations:" << endl;
        for (int a = 0; a < domains.size(); a+=2) {
            cout << domains.at(a) << " -> " << domains.at(a+1) << endl;
        }
        cout << endl;
    }
    
    //insertar dos relaciones a la lista del servidor
    void insertRelation(string domain, string ipaddress){
        domains.push_back(domain);
        domains.push_back(ipaddress);
    }
};

#endif /* Server_h */
