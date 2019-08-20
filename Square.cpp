/*
  Square.cpp
  SpaceChess

  Created by Tom Sturgeon on 20/11/2018.
  Copyright © 2018 Tom Sturgeon. All rights reserved.
*/

#include "Square.h"

/*
	Default Constructor
	@returns Square with default values of parent class (which are 0s)
*/


Square::Square(void) : Piece(){
    this->sideLen = 0;
}

/*
	Parameterised Constructor
	@params float x, float y, float sideLen
*/

Square::Square(const float x, const float y, const float sideLen) : Piece(x,y,sideLen,sideLen){
    this->sideLen = sideLen;
}

Square::~Square(){
    
}

/*Getters for members specific to Square*/

float Square::getSideLen() const{
    return this->sideLen;
}




