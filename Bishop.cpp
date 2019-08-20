/*
  Bishop.cpp
  SpaceChess

  Created by Tom Sturgeon on 20/11/2018.
  Copyright © 2018 Tom Sturgeon. All rights reserved.
*/

#include "Bishop.h"

/*
	Default Constructor


	@return Bishop with defaults from Circle and Piece, respectively
*/

Bishop::Bishop(void) : Circle(){
    
}

/*
	Param Constructor

	@params float x, float y

	@details Size of Bishop will be assigned by calling the constructor of Circle with a radius of 1 as per the specification, allows the 
	user to just call for a bishop without worrying about technicalities. Size was only an attrib of circle in the first place so other concrete 
	pieces can be added to the class by users extending it (if needs be).
*/

Bishop::Bishop(const float x, const float y) : Circle(x,y,1){
    
}

// Destructor blank again
Bishop::~Bishop(){}

/*
	
	isAllowedMove

	@params float newX, float newY
	@return bool
	@details An overriden boolean function specified in Piece that defines move logic for the piece

*/

bool Bishop::isAllowedMove(float newX, float newY){
    //need to use and (&&) here to allow diagonal and deny horizontal
    float curX = this->getX();
    float curY = this->getY();

	//Useful for only allowing a 45 degree angle
	float deltaX = abs(newX - curY);
	float deltaY = abs(newY - curY);
    

	//Bishop has to move diagonally 
    return (newX > curX || newX < curY) && 
					(newY > curY || newY < curY && deltaX == deltaY);
}


