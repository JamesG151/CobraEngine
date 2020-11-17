//We need access to the definitions file.
#include "../Headers/Definitions.h"

//These values are used to count the squares on the 'legal' game board.
int square120ToSquare64[BOARD_SQUARE_NUMBER];
int square64ToSquare120[64];

void InitialiseSquare120To64()
{
    //Early declarations.
    int index = 0;
    int file = FILE_A;
    int rank = RANK_1;
    int square = A1;
    int square64 = 0;

    //Iterating through the squares in each array and setting their value to be one that is never reached.
    for (index = 0; index < BOARD_SQUARE_NUMBER; ++index)
        square120ToSquare64[index] = 65;
    
    //Do the same but for the rest. Used for failsafe checking.
    for (index = 0; index < 64; ++index)
        square64ToSquare120[index] = 120;

    //Going through each file on each rank...
    for (rank = RANK_1; rank <= RANK_8; ++rank)
        for (file = FILE_A; file <= FILE_H; ++file)
        {
            //Using the macro, send in the file and rank to retrieve a square.
            square = FindSquareViaFileAndRank(file, rank);

            //Assign the values and increment the square number.
            square64ToSquare120[square64] = square;
            square120ToSquare64[square] = square64;
            square64++;
        }
}

//This function is used to initialise everything in the engine.
void InitialiseAll()
{
    InitialiseSquare120To64();
}