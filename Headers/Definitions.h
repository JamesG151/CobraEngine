//Include guard.
#ifndef DEFINITIONS_H
#define DEFINITIONS_H

//Defining a 64 bit integer.
typedef unsigned long long uint64;

//Defining the engine name.
#define ENGINE_NAME "CobraEngine 1.0"

//Defining the number of squares on the board.
/*
We define the board as having 120 squares,
because some pieces can move backwards from the starting point in irregular shapes.
i.e the knight, so we add a two additional rows and columns to each side of the board.

This acts as clamping the array to not go out of bounds during checks.
*/
#define BOARD_SQUARE_NUMBER 120

//Defining square contents.
enum Pieces
{
    EMPTY,
    WHITE_PAWN, WHITE_KNIGHT, WHITE_BISHOP, WHITE_ROOK, WHITE_QUEEN, WHITE_KING,
    BLACK_PAWN, BLACK_KNIGHT, BLACK_BISHOP, BLACK_ROOK, BLACK_QUEEN, BLACK_KING
};

//Defining file names. (A file is the technical term for a column on the chess board)
enum Files
{
    FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H,
    FILE_NONE
};

//Defining rank names. (A rank is the technical term for a row on the chess board)
enum Ranks
{
    RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8,
    RANK_NONE
};

//Defining the players of the game.
enum Players
{
    WHITE, BLACK,
    BOTH
};

//Defining the board squares.
// **Keep in mind here that A1 won't start on index 0, because then we need negatives to calculate border squares.**
enum Squares
{
    A1 = 21, B1, C1, D1, E1, F1, G1, H1,
    A2 = 31, B2, C2, D2, E2, F2, G2, H2,
    A3 = 41, B3, C3, D3, E3, F3, G3, H3,
    A4 = 51, B4, C4, D4, E4, F4, G4, H4,
    A5 = 61, B5, C5, D5, E5, F5, G5, H5,
    A6 = 71, B6, C6, D6, E6, F6, G6, H6,
    A7 = 81, B7, C7, D7, E7, F7, G7, H7,
    A8 = 91, B8, C8, D8, E8, F8, G8, H8,
    NO_SQUARE 
};

//Defining a bool constant.
enum BoolConst
{
    FALSE, TRUE
};

#endif
//End include guard.