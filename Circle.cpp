/*
  Circle.cpp
  SpaceChess2

  Created by Tom Sturgeon on 20/11/2018.
  Copyright © 2018 Tom Sturgeon. All rights reserved.
*/

#include "Circle.h"


/*
	Default Constructor
	@returns Cirlce with default values of parent class (which are 0s)
*/

Circle::Circle(void): Piece(){
    this->radius = 0;
    this->diameter = 0;
}

/*
	Parameterised Constructor
	@params float x, float y, float radius
*/

Circle::Circle(const float x, const float y, const float radius) : radius(radius), Piece(x,y,radius*2,radius*2){
    this->diameter = radius*2;
}

//Destructor
Circle::~Circle(){}

/*
	General getters for specific circle members
*/

float Circle::getRadius() const{
    return this->radius;
}

float Circle::getDiameter() const{
    return this->diameter;
}
