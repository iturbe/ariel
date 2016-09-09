//
//  main.cpp
//  PrimerParcial
//
//  Created by Alonso Iturbe on 9/9/16.
//  Copyright © 2016 Alonso Iturbe. All rights reserved.
//

#include <iostream>
#include "Pasteles.hpp"
#include "Fabrica.hpp"
#include "Iterator.cpp"

int main(int argc, const char * argv[]) {
    FabricaFisica * aguascalientes;
    FabricaFisica * cdmx;
    
    Pastel * leches = aguascalientes->crearPastel("tresleches");
    leches->setNombre("pastelito");
    
    Pastel * sach = cdmx->crearPastel("sacher");
    leches->setNombre("pastelote");
    
    Pastel * impo = cdmx->crearPastel("imposible");
    leches->setNombre("impozzible");
    
    Pastel * choco = cdmx->crearPastel("chocolate");
    
    //Clonado
    Pastel * nueva;
    nueva = leches->clonar();
    nueva->empaquetado();
    
    //Aggregate e iterador
    Aggregate <Pastel*> pastelesAguascalientes;
    pastelesAguascalientes.add(leches);
    
    Aggregate <Pastel*> pastelesCDMX;
    pastelesCDMX.add(leches);
    pastelesCDMX.add(impo);
    
    Iterator<Pastel *> * iterador;
    /*
    for(iterador = pastelesCDMX.getIterator(); iterador->hasNext(); )
    {
        iterador->next()->amasado();
    }
     */
    iterador->imprimirPasteles(pastelesCDMX);
    iterador->buscarPastel("impozzible", pastelesCDMX);
    
    return 0;
}
