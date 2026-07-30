#include <stdio.h>

#include "../include/raven.h"
#include "../include/terminal.h"


int main()
{

    printf("Raven Editor v%s\n", RAVEN_VERSION);


    enableRawMode();


    while(1)
    {

        int key = readKey();


        if(key == 17)
        {
            break;
        }

    }


    disableRawMode();


    return 0;
}