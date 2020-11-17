//Include guard.
#ifndef DEFINITIONS_H
#define DEFINITIONS_H

//Defining a 64 bit integer. (TODO: This needs to be changed as on 32-bit systems, the performance takes a huge hit declaring 64 bit integers)
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

//The maximum number of moves we can expect from a game of chess. (No chess game has gone over 2048 half moves)
#define MAX_NUMBER_OF_MOVES 2048

//Defining square contents. https://www.chess.com/terms/chess-pieces
enum Pieces
{
    EMPTY,
    WHITE_PAWN, WHITE_KNIGHT, WHITE_BISHOP, WHITE_ROOK, WHITE_QUEEN, WHITE_KING,
    BLACK_PAWN, BLACK_KNIGHT, BLACK_BISHOP, BLACK_ROOK, BLACK_QUEEN, BLACK_KING
};

//Defining file names. (A file is the technical term for a column on the chess board) https://www.chess.com/terms/chessboard#files
enum Files
{
    FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H,
    FILE_NONE
};

//Defining rank names. (A rank is the technical term for a row on the chess board) https://www.chess.com/terms/chessboard#ranks
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
// **Keep in mind here that A1 won't start on index 0, because then we need negatives to calculate border squares.** https://www.chess.com/terms/chessboard#algebraic
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

//defining the rules for castling. https://en.wikipedia.org/wiki/Castling
//This is representing by 4 bits. 0 0 0 0; eg. 1 0 0 1 (in this position of the board, white can castle queen-side and black can castle king-side)
enum CastlingPermissions
{
    WHITE_KING_CASTLING = 1, WHITE_QUEEN_CASTLING = 2,
    BLACK_KING_CASTLING = 4, BLACK_QUEEN_CASTLING = 8
};

//Contains what information we need to undo a move.
typedef struct Undo
{
    //We need the move we wish to undo.
    int move;

    //If castling was allowed on this turn.
    int castlePermission;

    //If an en passant was possible.
    int enPassant;

    //We also need to know how far in to the 50 move rule we are.
    int fiftyMoveRule;

    //We also need to position of the board.
    uint64 positionKey;
};

//Defining the board structure.
typedef struct BoardStructure
{
    //This is basically what's on the board.
    int pieces[BOARD_SQUARE_NUMBER];

    //There are three of them because they are represented them by color, not quantity.
    //This is because it will be represented, with 1 bit for each square on the 64 squares on the board.
    //The bit will be set to one if there is a pawn of the corressponding color on that square.
    uint64 pawns[3];    // 01000000 --> rank 1 (A1 -> H1). In this example, B1 has a pawn on it.

    //Keeping track of which square the kings are on.
    int kingSquare[2];

    //The current side to move.
    int side;

    //The "En Passant" square. If there is one active, if not it will be set to NO_SQUARE.
    //En Passant is where a pawn can capture another pawn immediately after a pawn makes a move of two squares from its starting position. https://en.wikipedia.org/wiki/En_passant
    int enPassant;

    //The fifty move rule. (The game can be claimed as a draw if no capture has been made and no pawn has moved in the past 50 moves) https://en.wikipedia.org/wiki/Fifty-move_rule
    //This will be measured in "half-turns" because 1 turn is both players moving a piece.
    int fiftyMoveRule;

    //The ply of current search.
    int ply;

    //In the game so far, how many half moves have been made.
    //This will be used to evaluating "move repitition".
    int historyPly;

    //Tracking who can castle.
    int castlePermission;

    //A unique key generated for each board position. 
    uint64 positionKey;

    //Store the number of pieces on the board.
    int numberOfPieces[13];

    //Store by color, the number of pieces that are not pawns.
    int bigPieces[3];

    /*
    Store the number of major pieces (Queens, Rooks, *TECHNICALLY KINGS*)
    Store the number of minor pieces (Bishops, Knights)

    These have 3 elements because it is used once for each color. A tracker for both colors are included.
    */
    int minorPieces[3];
    int majorPieces[3];
    
    //Create an instance of the game history.
    //So everytime a move is made, we store [at whatever move number we are at] all of the properties of the position. 
    Undo history[MAX_NUMBER_OF_MOVES]; 
};

//Macros
//This finds the index number from the array of squares by inputting a file and rank.
#define FindSquareViaFileAndRank(file, rank) ((21 + (f)) + ((r) * 10))

//Declaring some global variables here.
extern int square120ToSquare64[BOARD_SQUARE_NUMBER];
extern int square64ToSquare120[64];

//Place the initialise function here so the main function can see it.
extern void InitialiseAll();

#endif
//End include guard.