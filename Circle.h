/*
  Circle.h
  SpaceChess

  Created by Tom Sturgeon on 20/11/2018.
  Copyright © 2018 Tom Sturgeon. All rights reserved.
*/

#ifndef Circle_h
#define Circle_h

#include <stdio.h>
#include "Piece.h"

//Circle IS A Piece
class Circle : public Piece {
    
public:
    
    //Constructors
    Circle(void);
    Circle(const float x, const float y, const float radius);
	//virtual again because of hierarchy
    virtual ~Circle();
    
	//Getters - again defensive
    float getRadius() const;
    float getDiameter() const;
    
private:
	//adds extra relevant members for circles, respectively 
    float radius;
    float diameter;
};

#endif
