/*
  Piece.cpp
  SpaceChess

  Created by Tom Sturgeon on 20/11/2018.
  Copyright © 2018 Tom Sturgeon. All rights reserved.
*/

#include "Piece.h"

using namespace std;


/**
	Default Piece Constructor

	@return Piece with default values of 0.
*/
Piece::Piece(void) : x(0), y(0), width(0), height(0){
    this->top = 0;
    this->left = 0;
    this->bottom = 0;
    this->right = 0;
}

/**
	Parameterised Piece Constructor

	@param float x, float y, float width, float height
	@return Piece with specified values
*/

Piece::Piece(const float x, const float y, const float width, const float height): x(x), y(y), width(width), height(height){
    this->top = x+(height/2);
    this->left = y-(width/2);
    this->bottom = x-(height/2);
    this->right = y+(width/2);
}

/**
	Piece Deconstructor

	@details No need to implement this here
*/

Piece::~Piece(){};

float Piece::getX() const {return this->x;}
float Piece::getY() const {return this->y;}
float Piece::getWidth() const {return this->width;}
float Piece::getHeight() const {return this->height;}
float Piece::getTop() const {return this->top;}
float Piece::getLeft() const {return this->left;}
float Piece::getBottom() const {return this->bottom;}
float Piece::getRight() const {return this->right;}



/**
	Move function

	@param float newX, float newY
	@return void
	@details this calls a virtual function isAllowedMove(newX, newY) using dynamic binding to get allowed moves for the type of piece passed in. Carries out the move by assigning new values
*/
void Piece::move(float newX, float newY){
    if(isAllowedMove(newX, newY)){
        this->x = newX;
        this->y = newY;
        this->top = x+(height/2);
        this->left = y-(width/2);
        this->bottom = x-(height/2);
        this->right = y+(width/2);
    }
}

/**
	operator<<() overload

	@details Handles and prints out all types of piece through dynamic binding
*/

std::ostream& operator<<(std::ostream& os, const Piece& p){
    os << "x: " << p.getX() << "|" << "y: " << p.getY() << "\n" <<
    "width: " <<p.getWidth() << "|height: " << p.getHeight() << "\n" <<
    "top,left,bottom,right: " << p.getTop() << ", " << p.getLeft() <<", "<<p.getBottom() << ", "<< p.getRight();
    return os;
}


