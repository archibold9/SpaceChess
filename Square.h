/*
  Square.h
  SpaceChess

  Created by Tom Sturgeon on 20/11/2018.
  Copyright © 2018 Tom Sturgeon. All rights reserved.
*/

#ifndef Square_h
#define Square_h

#include <stdio.h>
#include "Piece.h"

//Square IS A Piece
class Square : public Piece {
    
public:
    //Constructors
    Square(void);
    Square(const float x, const float y, const float sideLen);
    virtual ~Square();

	//getters - defensive
    
    float getSideLen() const;
private:
    float sideLen;
    
};

#endif /* Square_hpp */
