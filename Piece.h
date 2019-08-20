/*
  Piece.h
  SpaceChess

  Created by Tom Sturgeon on 20/11/2018.
  Copyright © 2018 Tom Sturgeon. All rights reserved.
*/

#ifndef Piece_h
#define Piece_h

#include <stdio.h>
#include <iostream>

class Piece {
    
public:
    //Constructor
    Piece(void);
    Piece(const float x, const float y, const float width, const float height);
	//Defined as virtual since this is top of a class hierarchy
    virtual ~Piece();
    
    //Getters. I know this is abstract and therefore members could be accessed through protected but I wanted to make it defensive to control access for my outstream and other general methods
    float getX() const;
    float getY() const;
    float getWidth() const;
    float getHeight() const;
    float getTop() const;
    float getLeft() const;
    float getBottom() const;
    float getRight() const;
    
    //Methods
    void move(float newX, float newY);
    virtual bool isAllowedMove(float newX, float newY)=0;
    
private:
	//Member variables that will be used to control pieces and get helpful data about them on the fly from the geometry methods in the game logic
    float x;
    float y;
    float width;
    float height;
    float top,left,bottom,right;
};


//operator<< overload
std::ostream& operator<<(std::ostream& os, const Piece& p);


#endif /* Piece_h */
