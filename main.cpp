#include <iostream>
#include "method.h"
#include "core.h"

using namespace std;

int main() {
	for(int i = 0; i < 1500000 * 15; i++)
	{
		virtualTwist(3,1);
		virtualTwist(4,1);
		virtualTwist(5,1);
		virtualTwist(0,1);
		virtualTwist(1,1);
		virtualTwist(2,2);
		virtualTwist(0,1);
		virtualTwist(4,2);
		virtualTwist(5,1);
		
	}
	
	printCube();
/*
  cout << "Enter the scramble and press enter:" << endl;
  inputMoves();
  solve();
  cout << "SOLVED!  In " << getMoveCount() << " moves" << endl;
  */
}

