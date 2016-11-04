//
//  Request.h
//  Chain of Responsibility
//
//  Created by Alonso Iturbe on 11/4/16.
//  Copyright © 2016 Alonso Iturbe. All rights reserved.
//

#ifndef Request_h
#define Request_h

#include <string>

using namespace std;

class Request {
    string domain;
    
public:
    Request(string input) : domain(input){}
    
    string getDomain(){return domain;}
};

#endif /* Request_h */
