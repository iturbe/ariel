//
//  main.cpp
//  Tarea_1
//
//  Created by Alonso Iturbe on 8/14/16.
//  Copyright © 2016 Alonso Iturbe. All rights reserved.
//

#include <iostream>
#include "Computadora.hpp"
#include "Fabrica.hpp"

int main() {
    
    // NOTA: Para su compilación en la terminal, se debe de compilar con el comando:
    // g++ *.cpp
    // esto debido a un error en el cual no encuentra todos los archivos .cpp, por alguna razón
    
    //Objeto auxiliar que nos crea los demás apuntadores a objetos tipo Computadora
    Fabrica apple;
    
    Computadora * macbook = apple.crear("laptop");
    macbook->resumen();
    
    Computadora * macbookair = apple.crear("netbook");
    macbookair->resumen();
    
    Computadora * imac = apple.crear("desktop");
    imac->resumen();
    
    Computadora * ipad = apple.crear("tablet");
    ipad->resumen();
    
    //Este último no es posible de crear, asi que se retornan valores nulos
    Computadora * ipod = apple.crear("reproductormp3");
    ipod->resumen();
    
    delete macbook;
    delete macbookair;
    delete imac;
    delete ipad;
    delete ipod;
    
    return 0;
}
