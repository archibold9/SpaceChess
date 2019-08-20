//
//  Rook.hpp
//  SpaceChess
//
//  Created by Tom Sturgeon on 20/11/2018.
//  Copyright © 2018 Tom Sturgeon. All rights reserved.
//

#ifndef Rook_h
#define Rook_h

#include <stdio.h>
#include "Square.h"

//Rook IS A square which in turn IS A piece
class Rook : public Square {
    
public:
    
    //Constructors
    Rook(void);
    Rook(const float x, const float y);
	//Virtual again
    virtual ~Rook();
    
    //fun
	//Move logic to be overriden. This is the bottom of the inheritance hierarchy so doesn't need to be virtual anymore.
    bool  isAllowedMove(float newX, float newY);
    
    
};

#endif /* Rook_hpp */
