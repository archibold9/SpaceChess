/*
  Queen.cpp
  SpaceChess

  Created by Tom Sturgeon on 20/11/2018.
  Copyright © 2018 Tom Sturgeon. All rights reserved.
*/

#include "Queen.h"
//Useful to include as they're very similar
#include "Rook.h"
#include "Bishop.h"

/*
Default Constructor


@return Queen with defaults from Circle and Piece, respectively
*/

Queen::Queen() : Circle(){
    
}


/*
	Param Constructor

	@params float x, float y

	@details Size of Queen will be assigned by calling the constructor of Circle with a radius of 1 as per the specification, allows the
	user to just call for a Queen without worrying about technicalities. Size was only an attrib of circle in the first place so other concrete
	pieces can be added to the class by users extending it.

*/

Queen::Queen(float x, float y) : Circle(x,y,1){
    
}

//Intentionally blank
Queen::~Queen(){}

/*

	isAllowedMove

	@params float newX, float newY
	@return bool
	@details An overriden boolean function specified in Piece that defines move logic for the piece. This may seem pointless 
	since queen can move anywhere but it forces queen to actually move within the same predicates as bishop and rook, 
	therefore it can't stay on its current coords

*/

bool Queen::isAllowedMove(float newX, float newY){
    //create a faux rook and a faux bishop with the current x and y
    Rook r(this->getX(),this->getY());
    Bishop b(this->getX(),this->getY());
    //Check if queen is moving in the fashion of the rook or of the bishop - a legal queen move
    //Could make a static call using Rook::isAllowedMove(x,y) and Bishop::isAllowedMove(x,y) here but it was more detrimental to the overall system to do it that way
    return r.isAllowedMove(newX, newY) || b.isAllowedMove(newX, newY);
}
