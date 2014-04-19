#include "core.h"
#include <iostream>
#include <string>

using namespace std;

static int moves = 0;

int pieces[2][12][2] =          // Holds the permutation and orientation of every piece
      {                      // All pieces start out solved
          {           // Corners are defined first
              { 0, 0 },      // Corner 0 in slot 0 with orientation 0
              { 1, 0 },      // Corner 1 in slot 1 with orientation 0
              { 2, 0 },      // Corner 2 in slot 2 with orientation 0
              { 3, 0 },      // Corner 3 in slot 3 with orientation 0
              { 4, 0 },      // Corner 4 in slot 4 with orientation 0
              { 5, 0 },      // Corner 5 in slot 5 with orientation 0
              { 6, 0 },      // Corner 6 in slot 6 with orientation 0
              { 7, 0 }       // Corner 7 in slot 7 with orientation 0
              // The left-over 4 slots (8 bytes) are not used
          },
          {           // Edges are defined second
              { 0, 0 },      // Edge 0 in slot 0 and is "good"
              { 1, 0 },      // Edge 1 in slot 1 and is "good"
              { 2, 0 },      // Edge 2 in slot 2 and is "good"
              { 3, 0 },      // Edge 3 in slot 3 and is "good"
              { 4, 0 },      // Edge 4 in slot 4 and is "good"
              { 5, 0 },      // Edge 5 in slot 5 and is "good"
              { 6, 0 },      // Edge 6 in slot 6 and is "good"
              { 7, 0 },      // Edge 7 in slot 7 and is "good"
              { 8, 0 },      // Edge 8 in slot 8 and is "good"
              { 9, 0 },      // Edge 9 in slot 9 and is "good"
              { 10, 0 },      // Edge 10 in slot 10 and is "good"
              { 11, 0 }      // Edge 11 in slot 11 and is "good"
          }
      };

void virtualTwist(int face, int turnsClockwise) {
  int temp;      // Temporary storage used when virtually cycling pieces
  for(int a = 0; a < turnsClockwise; a++) {  // Repeat for however many twists
    // ***** Permute corners and edges, cycle current orientations *****
    for(int b = 0; b < 4; b++) {    // Loop 4 times through permutation and orientation
      temp =       // Store the 4th piece of data to be cycled here temporarily
      pieces        // Where all of the pieces and their orientations are stored
        [b < 2 ? 0 : 1]  // On the first 2 runs of the loop, we are accessing corner
                         // data, and on the next 2 runs, we are accessing edge data
        [facePieceSlots  // We are looking for the 4th piece on the specified face
          [face]            // Which face to look on (0-5)
          [b < 2 ? 0 : 1]  // Access corners first 2 runs, then edges next 2 runs
          [3]              // Access the 4th piece / orientation (0-based)
        ]
        [b % 2];          // On even numbered loops, access pieces, and on odd numbered
                          // loops, access part orientation
      for(int c = 3; c > 0; c--) {  // Cycle 3 pieces / orientation, last stored in temp
        pieces
        [b < 2 ? 0 : 1]
        [facePieceSlots
          [face]            // Which face to look on (0-5)
          [b < 2 ? 0 : 1]  // Access corners first 2 runs, then edges next 2 runs
          [c]              // Access the cth piece
        ]
        [b % 2]          // Access pieces on even cycles, orientations on odd cycles
        =
        pieces
        [b < 2 ? 0 : 1]
        [facePieceSlots
          [face]            // Which face to look on (0-5)
          [b < 2 ? 0 : 1]  // Access corners first 2 runs, then edges next 2 runs
          [c - 1]              // Access the cth piece - 1
        ]
        [b % 2];          // Access pieces on even cycles, orientations on odd cycles
      };
      pieces        // Restore the temporarily stored piece / orientation
        [b < 2 ? 0 : 1]  // On the first 2 runs of the loop, we are accessing corner
                         // data, and on the next 2 runs, we are accessing edge data
        [facePieceSlots  // We are looking for the 0th piece on the specified face
          [face]            // Which face to look on (0-5)
          [b < 2 ? 0 : 1]  // Access corners first 2 runs, then edges next 2 runs
          [0]              // Access the 0th piece / orientation (0-based)
        ]
        [b % 2]          // On even numbered loops, access pieces, and on odd numbered
                          // loops, access part orientation
        = temp;        // Restore
    };
    // ****** Next, modify part orientation ******
    for(int d = 3; d > 1; d--) {    // Loop 2 times, for corners and edges
      if( (face > 3) && (d == 3) ) continue;      // Corner orientation doesn't change
                                                  // when top or bottom side is twisted
      for(int e = 0; e < 4; e++) {      // Orient 4 corners / edges
        pieces
        [d == 3 ? 0 : 1]    // Whether to modify corner or edge orientation
        [facePieceSlots      // Find which slot the piece is in
          [face]
          [d == 3 ? 0 : 1]    // Whether to find location of corner or edge
          [e]                // Which piece of the face it is on
        ]
        [1]          // Looking for orientation
        =
        (pieces
        [d == 3 ? 0 : 1]    // Whether to modify corner or edge orientation
        [facePieceSlots      // Find which slot the piece is in
          [face]
          [d == 3 ? 0 : 1]    // Whether to find location of corner or edge
          [e]                // Which piece of the face it is on
        ]
        [1]          // Orientation
        + d + (e % 2 == 0 ? - 1 : + 1)) % d;
      };
    };
  };

};

// Gets the physical orientation of the edge in the specified slot on the top layer
// 0 = correct, 1 = incorrect
int getActualOrientation(int slot) {
  return ( ( (slot + 4) - (pieces[1][slot][0]) ) + (pieces[1][slot][1]) ) % 2;
}

// Print move
void showMove(int face, int turnsClockwise) {
  static int counter = 0;
  if(face == 11) {    // If showMove was called directly to reset count
    counter = 0;
		return;
  }
  cout << notation[0][face] << notation[2][turnsClockwise];
  if(turnsClockwise > 1)
	  cout << ' ';
  counter++;
  if(counter == 20) {
    cout << '\n';
	counter = 0;
  }
}

/* twist
 *    Preforms a physical turn on the cube.
 * int face
 *    The number of the face to twist (0-5) as described in the Part / Slot Names diagram
 * int turnsClockwise
 *    The number of times to turn the face clockwise (1-3) a quarter turn.  If the
 *    number is 3, the physical move will be a single anti-clockwise turn
 *    (but the virtual twisting will still consist of 3 clockwise quarter turns.)
 */
void twist(int face, int turnsClockwise) {    // Turn a side on a Rubik's cube
  moves++;    // Update the total moves count to be displayed at the end
  showMove(face, turnsClockwise);
  virtualTwist(face,turnsClockwise);
  };

//Interprit twist from a perspective (0-3)
void twist(int face, int turnsClockwise, int perspective) {
  twist(face < 4 ? ((face + perspective) % 4) : face, turnsClockwise);

}

// getPiece()     Returns the location of the specified corner / edge piece
// int pieceType        0 for corners, 1 for edges
// int pieceNumber      What piece to look for (0-7 corners, 0-11 edges)
int findPiece(int pieceType, int pieceNumber) {
  for(int a = 0; a < 12; a++) {
    if(pieces[pieceType][a][0] == pieceNumber) return a;
  }
    return 0;		// Gets rid of compiler warning; it doesn't make sense for this line to ever execute, a bug exists if it
}

// Returns location of piece from perspective (0-3)
int findPiece(int pieceType, int pieceNumber, int perspective) {
  int temp = findPiece(pieceType, pieceNumber);
  return ((((temp % 4) + 4) - perspective) % 4) + (temp - (temp % 4));
}

// Get the orientation of the specified piece
int getOrientation(int pieceType, int pieceNumber) {
  return pieces[pieceType][findPiece(pieceType, pieceNumber)][1];
}


void printCube() {    // Prints all of the virtual cube's data
for(int a = 0;a < 2; a++) {
  if (a == 0)
		cout << "CORNERS:";
	else
		cout << "EDGES:";
	cout << "\n";
  for(int b = 0; b < 12; b++) {
    if(a == 0 && b > 7) break;
    cout << b << "| ";
    for(int c = 0; c < 2; c++) {
      cout << pieces[a][b][c] << " ";
    }
    cout << "\n";
  }
}
}

int getMoveCount()
{
    return moves;
}

void inputMoves()
{
    string strMoves;
    getline(cin, strMoves);
	int nFace = -1;
    for(unsigned int i = 0; i <= strMoves.length(); i++)
    {
    	if(i == strMoves.length() && nFace != -1)
		{
			virtualTwist(nFace, 1);
			break;
		}
		switch(strMoves[i])
		{
			case 'F':
			case 'f':
				if(nFace != -1)
				{
					virtualTwist(nFace, 1);
				}
				nFace = 0;
				break;
				
			case 'R':
			case 'r':
				if(nFace != -1)
				{
					virtualTwist(nFace, 1);
				}
				nFace = 1;
				break;
				
			case 'B':
			case 'b':
				if(nFace != -1)
				{
					virtualTwist(nFace, 1);
				}
				nFace = 2;
				break;
				
			case 'L':
			case 'l':
				if(nFace != -1)
				{
					virtualTwist(nFace, 1);
				}
				nFace = 3;
				break;
			
			case 'D':
			case 'd':
				if(nFace != -1)
				{
					virtualTwist(nFace, 1);
				}
				nFace = 4;
				break;
			
			case 'U':
			case 'u':
				if(nFace != -1)
				{
					virtualTwist(nFace, 1);
				}
				nFace = 5;
				break;
			
			case '2':
				if(nFace != -1)
				{
					virtualTwist(nFace, 2);
					nFace = -1;
				}
				break;
			case '\'':
				if(nFace != -1)
				{
					virtualTwist(nFace, 3);
					nFace = -1;
				}
				break;
			default:
				if(nFace != -1)
				{
					virtualTwist(nFace, 1);
					nFace = -1;
				}
				break;
		}
    }
}

int piecesGet(int a, int b, int c)
{
	return pieces[a][b][c];
}
