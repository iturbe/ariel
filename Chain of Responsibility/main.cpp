//
//  main.cpp
//  Chain of Responsibility
//
//  Created by Alonso Iturbe on 11/1/16.
//  Copyright © 2016 Alonso Iturbe. All rights reserved.
//

#include <iostream>
#include "Server.h"

int main(int argc, const char * argv[]) {
    //declaración de servidores
    Server * s1 = new Server("Server1");
    Server * s2 = new Server("Server2");
    Server * s3 = new Server("Server3");
    
    //asignar sucesores
    s1->setNext(s2);
    s2->setNext(s3);
    
    //insertar datos de resolución para S1
    s1->insertRelation("facebook.com", "192.175.2.4");
    s1->insertRelation("cisco.com", "192.175.5.8");
    
    //insertar datos de resolución para S2
    s2->insertRelation("hello.com", "192.165.2.4");
    s2->insertRelation("asf.edu.mx", "22.175.5.8");
    
    //pedir cosas a S1
    s1->processRequest(Request("facebook.com"));
    s1->processRequest(Request("hello.com"));
    s1->processRequest(Request("itesm.com.mx"));
    return 0;
}
