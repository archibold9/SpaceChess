/*
  Queen.h
  Spacechess

  Created by Tom Sturgeon on 20/11/2018.
  Copyright © 2018 Tom Sturgeon. All Rights Reserved.
*/

#ifndef Queen_h
#define Queen_h

#include <stdio.h>
#include "Circle.h"

//Queen IS A Circle which in turn IS A Piece
class Queen : public Circle {
    
public:
	//Constructors
    Queen(void);
    Queen(float x, float y);
    virtual ~Queen();
    
	//Move logic to be overriden. This is the bottom of the inheritance hierarchy so doesn't need to be virtual anymore.
    bool isAllowedMove(float newX, float newY);
};

#endif /* Queen_hpp */
