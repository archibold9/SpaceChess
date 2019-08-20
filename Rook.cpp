/*
  Rook.cpp
  SpaceChess

  Created by Tom Sturgeon on 20/11/2018.
  Copyright © 2018 Tom Sturgeon. All rights reserved.
*/

#include "Rook.h"

/*
Default Constructor


@return Rook with defaults from Square and Piece, respectively
*/


Rook::Rook(void) : Square(){
    
}

/*
	Param Constructor

	@params float x, float y

	@details Size of Rook will be assigned by calling the constructor of Square with sideLen = 2 as per the specification, allows the
	user to just call for a Rook without worrying about technicalities. SideLen was only an attrib of circle in the first place so other concrete
	square pieces can be added to the class by users extending it.

*/

Rook::Rook(const float x, const float y):Square(x, y, 2){
    
}

Rook::~Rook(){}


/*

	isAllowedMove

	@params float newX, float newY
	@return bool
	@details An overriden boolean function specified in Piece that defines move logic for the piece

*/

bool Rook::isAllowedMove(float newX, float newY){
    //need to use xor (!=) here to prevent diagonals
    float curX = this->getX();
    float curY = this->getY();
    
    return (newX > curX || newX < curX) != (newY > curY || newY < curY);
}
