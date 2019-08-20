/*
  Bishop.h
  SpaceChess

  Created by Tom Sturgeon on 20/11/2018.
  Copyright © 2018 Tom Sturgeon. All rights reserved.
*/

#ifndef Bishop_h
#define Bishop_h

#include <stdio.h>
#include "Circle.h"

//Bishop IS A Circle which in turn IS A Piece
class Bishop : public Circle {
    
public:

	//Constructors
    Bishop(void);
    
    Bishop(const float x, const float y);
	//virtual
    virtual ~Bishop();

	//Method to be overriden. This is the bottom of the inheritance hierarchy so doesn't need to be virtual anymore.
    bool isAllowedMove(float newX, float newY);
    
};

#endif /* Bishop_h */
