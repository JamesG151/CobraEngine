//We need access to standard input and output.
#include <stdio.h>

//We also need access to the definitions.
#include "../Headers/Definitions.h"

//Program begins here.
int main()
{
    //Initialise our engine.
    InitialiseAll();

    //TESTING AND DEBUGGING CODE AHEAD, SUBJECT TO BE REMOVED.
    //The following code will print out our arrays to see if they are properly being assigned to.
    int index = 0;

    for (index = 0; index < BOARD_SQUARE_NUMBER; ++index)
    {
        if (index % 10 == 0)
            printf("\n");
        
        printf("%5d", square120ToSquare64[index]);
    }

    printf("\n");
    printf("\n");

    for (index = 0; index < 64; ++index)
    {
        if (index % 8 == 0)
            printf("\n");
        
        printf("%5d", square64ToSquare120[index]);
    }

    //Terminate the program.
    return 0;
}