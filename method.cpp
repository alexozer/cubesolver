/* method.cpp
 * A beginner's 3x3x3 method to use
 * Note: Each function needs to be called in order to work (should be fixed...)
 * */

#include <iostream>
#include "core.h"
#include "algs.h"

using namespace std;

void bottomEdges() {// Solves bottom 4 edges on face 4
  cout << "BOTTOM EDGES:" << endl;
  for(int a = 0; a < 4; a++) {    // Repeat for each edge
    while(true) {    // Keep looping until loop broken
      switch(findPiece(1,a,a)) {

        case 0: {    // If edge in solved position...
          if(getOrientation(1,a) == 0) { // See if it is oriented correctly
            break;    // If it oriented correctly, break out of the switch statement
          } else {
            twist(0,2,a);    // Else, twist face 0 twice and repeat the switch statement
            continue;
          }
        }
        case 1: {	
          twist(1,2,a);
          continue;
        }

        case 2: {
          twist(2,2,a);
          continue;
        }

        case 3: {
          twist(3,2,a);
          continue;
        }

        case 4: {
          twist(0,3,a);
          continue;
        }

        case 5: {
          twist(1,3,a);
          twist(5,1,a);
          twist(1,1,a);
          continue;
        }

        case 6: {
          twist(3,1,a);
          twist(5,3,a);
          twist(3,3,a);
          continue;
        }

        case 7: {
          twist(0,1,a);
          continue;
        }

        case 8: {
          if(getOrientation(1,a) == 0) {
            twist(0,2,a);
            break;
          } else {
            twist(0,1,a);
            twist(4,1,a);
            twist(1,3,a);
            twist(4,3,a);
            break;
          }
        }

        case 9: {
          twist(5,1,a);
          continue;
        }

        case 10: {
          twist(5,2,a);
          continue;
        }

        case 11: {
          twist(5,3,a);
          continue;
        }
      }
      break;  // If the switch is broken, then the edge is solved, so break while loop
    }
  }
  showMove(11,0);    // Special call to reset move counter
  cout << "\n\n";
}

void bottomCorners() {      // Solve the bottom corners thus completing the first layer
  cout << "BOTTOM CORNERS:" << endl;
  for(int a = 0; a < 4; a++) {
    while(true) {    // Keep looping until switch broken
      switch(findPiece(0,a,a)) {
        case 0: {
          if(getOrientation(0,a) == 0) {
            break;
          } else {
            twist(1,1,a);
            twist(5,1,a);
            twist(1,3,a);
            twist(5,3,a);
            twist(1,1,a);
            twist(5,1,a);
            twist(1,3,a);
            continue;
          }
        }

        case 1: {
          twist(0,3,a);
          twist(2,1,a);
          twist(5,1,a);
          twist(0,1,a);
          twist(2,3,a);
          continue;
        }

        case 2: {
          twist(0,3,a);
          twist(2,3,a);
          twist(5,2,a);
          twist(0,1,a);
          twist(2,1,a);
          continue;
        }

        case 3: {
          twist(1,1,a);
          twist(3,3,a);
          twist(5,3,a);
          twist(1,3,a);
          twist(3,1,a);
          continue;
        }

        case 4: {
          twist(1,1,a);
          twist(5,1,a);
          twist(1,3,a);
          continue;
        }

        case 5: {
          twist(5,1,a);
          continue;
        }

        case 6: {
          twist(5,2,a);
          continue;
        }

        case 7: {
          twist(5,3,a);
          continue;
        }
      }
      break;    // If switch is broken then break while loop
    }
  }
  showMove(11,0);
  cout << "\n\n";
}


void middleEdges() {
  cout << "MIDDLE EDGES:" << endl;
  for(int a = 0; a < 4; a++) {
    while(true) {    // Keep looping until switch broken
      if(findPiece(1,a+4,a) < 8) {    // If edge in middle layer
        if(findPiece(1,a+4,a) == 4 && getOrientation(1,a+4) == 0) break;    // Solved
        else {    // Not solved / in wrong slot
          int b = (a + findPiece(1,a+4,a) ) % 4;  // Change perspective on piece loc
          twist(1,1,b);
          twist(5,3,b);
          twist(1,3,b);
          twist(5,3,b);
          twist(0,3,b);
          twist(5,1,b);
          twist(0,1,b);
          continue;
        }
      } else {    // If edge in top layer
        if(findPiece(1,a+4,a) == 8) {    // If edge in buffer position (slot 8)
          if(getOrientation(1,a+4) == 1) {  // F turn would solve edge
            twist(5,1,a);
            twist(1,1,a);
            twist(5,3,a);
            twist(1,3,a);
            twist(5,3,a);
            twist(0,3,a);
            twist(5,1,a);
            twist(0,1,a);
            break;    // Edge solved
          } else {    // U' R' would solve edge
            twist(5,2,a);
            twist(0,3,a);
            twist(5,1,a);
            twist(0,1,a);
            twist(5,1,a);
            twist(1,1,a);
            twist(5,3,a);
            twist(1,3,a);
            break;    // Edge solved
          }
        } else {    // Edge not in buffer position (slot 8)
          twist(5,findPiece(1,a+4,a) - 8,a);    // Position in slot 8
          continue;
        }

      }

    }
  }
  cout << "\n\n";
  showMove(11,0);
}


void topEdges() {
  int firstEdge = 0;    // Stores location of first found correctly flipped edge
  int secondEdge = 0;   // Stores location of second found correctly flipped edge
  bool allCorrect = false;  // Changes to true if more than 2 edges are correct
                             // If no edges are correct, then firstEdge will stay 0
  cout << "TOP EDGES:" << endl;
  while(true) {    // Edge Orientation
    for(int a = 8; a < 12; a++) {
      if(getActualOrientation(a) == 0) {
        if(firstEdge == 0) firstEdge = a;
        else
        if(secondEdge == 0) secondEdge = a;
        else {
          allCorrect = true;
          break;    // Escape FOR loop
        }
      }
    }
    if(allCorrect) break;    // Move on to edge permutation
    if(firstEdge == 0) {    // No edges flipped correctly
      twist(0,1);
      twist(5,1);
      twist(1,1);
      twist(5,3);
      twist(1,3);
      twist(0,3);
      continue;
    }
    if( (secondEdge - firstEdge) % 2 == 0) {    // Bar shape
      if(firstEdge == 8) twist(5,1);    // Correct top face placement
      twist(0,1);
      twist(1,1);
      twist(5,1);
      twist(1,3);
      twist(5,3);
      twist(0,3);
      break;    // Move on to edge permutation
    } else { // L shape
      switch(firstEdge + secondEdge) {    // Correctly position top layer
        case 17: {
          twist(5,2);
          break;
        }
        case 19: {
          if(firstEdge == 9) twist(5,3);
          else twist(5,1);
          break;
        }
        case 21: {
          break;    // In correct position
        }
      }
      twist(0,1);
      twist(5,1);
      twist(1,1);
      twist(5,3);
      twist(1,3);
      twist(0,3);
    }
    break;    // If it has made it this far, edge orientation is done
  }
  // Edge permutation time
  if(findPiece(1,8) != 8) twist(5,findPiece(1,8) - 8);  // Solve edge 8

  int edgeParody = 0;    // Do we need to use a T-perm?
    for(int a = 9; a < 12; a++) {      // How many other solved edges are there?
      if(piecesGet(1, a, 0) == a) edgeParody++;    // Is another edge solved?
    }
    if(edgeParody == 1) {
      tPerm();
    }
    if(piecesGet(1, 9, 0) == 10) sune();
    else if(piecesGet(1, 9, 0) == 11) antiSune();


  cout << "\n\n";
  showMove(11,0);
}


void topCorners() {
  cout << "TOP CORNERS:" << endl;
    if(piecesGet(0, 4, 0) != 4) {  // If corner 4 isn't in its solved position
      if(findPiece(0,4) == 5) clockwiseCornerCycle();
      if(findPiece(0,4) == 6) {
        twist(5,1);  // U
        clockwiseCornerCycle();
        twist(5,3);  // U'
      } else if(findPiece(0,4) == 7) {
        twist(5,1);  // U
        counterClockwiseCornerCycle();
        twist(5,3);  // U'
      }
    }
    if(piecesGet(0, 7, 0) == 6) clockwiseCornerCycle();
    else if(piecesGet(0, 7, 0) == 5) counterClockwiseCornerCycle();

  // And now, lastly, to orient the corners
    for(int a = 0; a < 4; a++) {
      if(piecesGet(0, 4, 1) == 1) orientCorner();
      else if(piecesGet(0, 4, 1) == 2) inverseOrientCorner();
      twist(5,1);
    }

  showMove(11,0);
  cout << "\n\n";
}

void solve()
{
	bottomEdges();
	bottomCorners();
	middleEdges();
	topEdges();
	topCorners();
}

