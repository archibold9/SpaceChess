/*
  Game.cpp
  SpaceChess

  Created by Tom Sturgeon on 20/11/2018.
  Copyright © 2018 Tom Sturgeon. All rights reserved.
*/

#include "Main.h"
#include "Piece.h"
#include "Circle.h"
#include "Square.h"
#include "Bishop.h"
#include "Queen.h"
#include "Rook.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>    // std::max
#include <cstdlib>
#include <ctime>

using namespace std;


//Vectors storing the current state of the game, pointers to the abstract type piece
vector<Piece*> gameVEC;
vector<Piece*> capturedVEC;

//Constant for board size
const float BOARD_BOUNDARIES = 10;

/*
 Statically defined collision detectors. Take a reference to circle or square since obviously cannot instantiate and main grid is represented with vector of abstracts.
    These functions implicitly know what you're passing into them since they are just overloads of the same function. Therefore avoids doing a big if statement in the games loop to detect which pieces are currently being dealt with
 */
static bool detectCOL(const Circle* c1, const Circle* c2);
static bool detectCOL(const Square* s1, const Square* s2);
static bool detectCOL(const Circle* c1, const Square* s1);
void removeCaptured();
void checkCaptured(Piece* p);


/*
	detectCOL
	@params Circle* c1, Circle* c2
	@returns bool
	@details Overloaded method returning a bool predicate that shows if a collision happened between the two shapes specified in the parameters
*/
static bool detectCOL(const Circle* c1, const Circle* c2) 
{
	//fairly simple geometry, check if (radius + radius^2) is <= the difference in the origin points squared  
    return pow((c1->getX() - c2->getX()),2) + pow((c1->getY() - c2->getY()),2) <= pow((c1->getRadius() + c2->getRadius()),2);
    return false;
}

/*
	detectCOL
	@params Square* c1, Square* c2
	@returns bool
	@details Overloaded method returning a bool predicate that shows if a collision happened between the two shapes specified in the parameters
*/

static bool detectCOL(const Square* s1, const Square* s2) 
{
    //Need to check that no spaces exist between the boundaries of the two squares
	return s1->getX() < s2->getX() + s2->getWidth() &&
		s1->getX() + s1->getWidth() > s2->getX() &&
		s1->getY() < s2->getY() + s2->getHeight() &&
		s1->getHeight() + s1->getY() > s2->getY();
	
    return false;
}

/*
	detectCOL
	@params Circle* c1, Square* c2
	@returns bool
	@details Overloaded method returning a bool predicate that shows if a collision happened between the two shapes specified in the parameters

	This code took heavy inspiration from https://yal.cc/rectangle-circle-intersection-test/ since we have never
	discussed trigonometric functions I was at a loss as how to achieve bounding box collision with circle.

*/

static bool detectCOL(const Circle* c1, const Square* s1) 
{
	float Dx = c1->getX() - std::max(s1->getX(), std::min(c1->getX(), s1->getX() + s1->getWidth()));
	float Dy = c1->getY() - std::max(s1->getY(), std::min(c1->getY(), s1->getY() + s1->getHeight()));

	return (Dx * Dx + Dy * Dy) < (c1->getRadius() * c1->getRadius());
}

/*
	checkCaptured
	@params Piece* movedP
	@returns void
	@details uses the overloaded methods at the top of the class to detect any kind of collision and add the collided piece to the captured vector
*/

void checkCaptured(Piece* movedP) {

	for (int x = 0; x < gameVEC.size(); x++)
	{
		Piece* currentP = gameVEC.at(x);

		//if theyre the same, skip this element
		if (movedP == currentP)
			continue;

		//Square on Square
		if (dynamic_cast <Square*> (movedP) && dynamic_cast <Square*> (currentP)) {
			if (detectCOL(dynamic_cast <Square*> (movedP), dynamic_cast <Square*> (currentP))) {
				capturedVEC.push_back(currentP);
				cout << "Captured Square on Square" << endl;
			}
		}

		//Circle on Square
		else if (dynamic_cast <Circle*> (movedP) && dynamic_cast <Square*> (currentP)) {
			if (detectCOL(dynamic_cast <Circle*> (movedP), dynamic_cast <Square*> (currentP))) {
				capturedVEC.push_back(currentP);
				cout << "Captured Circle on Square" << endl;
			}
		}

		//Circle on Circle
		else if (dynamic_cast <Circle*> (movedP) && dynamic_cast <Circle*> (currentP)) {
			if (detectCOL(dynamic_cast <Circle*> (movedP), dynamic_cast <Circle*> (currentP))) {
				capturedVEC.push_back(currentP);
				cout << "Captured Circle on Circle" << endl;
			}
		}
	}
}

/*
	removeCaptured
	@returns void
	@details erases anything in captured vec from the game state vector and then empties the captured vector for reuse
*/

void removeCaptured() {
	for (int x = 0; x < gameVEC.size(); x++) {
		for (int y = 0; y < capturedVEC.size(); x++) {
			cout << "Removing..." << endl;
			gameVEC.erase(remove(gameVEC.begin(), gameVEC.end(), capturedVEC[y]), gameVEC.end());
			capturedVEC.erase(remove(capturedVEC.begin(), capturedVEC.end(), capturedVEC[y]), capturedVEC.end());
		}
	}
}

//game simulation takes place here

int main()
{

	float xPos = 0.0;
	float yPos = 0.0;
	srand((unsigned)time(0));

	Rook p1(0, 0);
	gameVEC.push_back(&p1);
    Rook p2(4, 1);
	gameVEC.push_back(&p2);
	Rook p3(6, 2);
	gameVEC.push_back(&p3);
	Rook p4(7, 8);
	gameVEC.push_back(&p4);
	Rook p5(2, 3);
	gameVEC.push_back(&p5);
	Rook p6(7, 0);
	gameVEC.push_back(&p6);

	Bishop b1(0, 0);
	gameVEC.push_back(&b1);
	Bishop b2(0, 0);
	gameVEC.push_back(&b2);
	Bishop b3(0, 0);
	gameVEC.push_back(&b3);
	Bishop b4(0, 0);
	gameVEC.push_back(&b4);
	Bishop b5(0, 0);
	gameVEC.push_back(&b5);
	Bishop b6(0, 0);
	gameVEC.push_back(&b6);

	Queen q1(20, 1);
	gameVEC.push_back(&q1);
	Queen q2(1, 1);
	gameVEC.push_back(&q2);
	Queen q3(1, 1);
	gameVEC.push_back(&q3);
	Queen q4(1, 1);
	gameVEC.push_back(&q4);
	Queen q5(1, 1);
	gameVEC.push_back(&q5);
	Queen q6(1, 1);
	gameVEC.push_back(&q6);
    
	while (gameVEC.size() > 1)
	{
		//for each piece on the board
		for (int x = 0; x < gameVEC.size(); x++) {

			xPos = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / BOARD_BOUNDARIES));
			yPos = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / BOARD_BOUNDARIES));

			//if rook then only move either x or y (decided randomly)
			if (dynamic_cast <Rook*> (gameVEC.at(x)))
			{
				int picker = rand() % 2;

				switch (picker) {
				case 0:
					cout << "Moving.." << endl;
					gameVEC.at(x)->move(gameVEC.at(x)->getX(), yPos);
					checkCaptured(gameVEC.at(x));
					removeCaptured();
					break;
				case 1:
					cout << "Moving......" << endl;
					gameVEC.at(x)->move(xPos, gameVEC.at(x)->getY());
					checkCaptured(gameVEC.at(x));
					removeCaptured();
					break;
				}
			}
			//else if any other piece, move it randomly
			else {
				cout << "Moving..............." << endl;
				gameVEC.at(x)->move(xPos, yPos);
				checkCaptured(gameVEC.at(x));
				removeCaptured();
			}

			cout << "PIECES LEFT IN GAME: " << gameVEC.size() << endl;
		}
	}

	//stop console closing
	getchar();

    return 0;

}


