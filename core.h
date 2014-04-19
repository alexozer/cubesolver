#ifndef CORE_H
#define CORE_H

void virtualTwist(int face, int turnsClockwise);
int getActualOrientation(int slot);
void showMove(int face, int turnsClockwise);
void twist(int face, int turnsClockwise);
void twist(int face, int turnsClockwise, int perspective);
int findPiece(int pieceType, int pieceNumber);
int findPiece(int pieceType, int pieceNumber, int perspective);
int getOrientation(int pieceType, int pieceNumber);
void printCube();
int getMoveCount();
void inputMoves();
int piecesGet(int a, int b, int c);

const char notation[3][6] =     // Holds the letters that represent face turns
      {
          { 'F', 'R', 'B', 'L', 'D', 'U' },
          { 'f', 'r', 'b', 'l', 'd', 'u' },
          { ' ', ' ', '2', '\'', ' ', ' '}
      };

const int facePieceSlots[6][2][4] = // Holds which faces contain which
      {                              // piece slots so virtual twists are possible
          {    // Face 0
              { 0, 3, 7, 4 },    // Face 0's (F) corner slot #'s
              { 0, 7, 8, 4 }    // Face 0' (F) edge slot #'s
          },{  // Face 1
              { 1, 0, 4, 5 },   // Face 1's (R) corner slot #'s
              { 1, 4, 9, 5 }    // Face 1's (R) edge slot #'s
          },{  // Face 2
              { 2, 1, 5, 6 },    // Face 2's (B) corner slot #'s
              { 2, 5, 10, 6 }    // Face 2's (B) edge slot #'s
          },{  // Face 3
              { 3, 2, 6, 7 },    // Face 3's corner (L) slot #'s
              { 3, 6, 11, 7 }    // Face 3's edge (L) slot #'s
          },{  // Face 4
              { 0, 1, 2, 3 },    // Face 4's (D) corner slot #'s
              { 0, 1, 2, 3 }    // Face 4's (D) edge slot #'s
          },{  // Face 5
              { 7, 6, 5, 4 },   // Face 5's (U) corner slot #'s
              { 11, 10, 9, 8 }    // Face 5's (U) edge slot #'s
          }
      };

#endif

