#include <stdio.h>

#include "raven.h"
#include "terminal.h"

int main(void)
{
    /* Display editor version */
    printf("Raven Editor v%s\n", RAVEN_VERSION);

    /* Enable raw terminal mode */
    enableRawMode();

    /* Main input loop */
    while (1)
    {
        int key = readKey();

        /* Display the ASCII value of the key pressed */
        printf("\rKey Pressed: %3d", key);
        fflush(stdout);

        /*
         * Ctrl + Q
         * ASCII value = 17
         */
        if (key == 17)
        {
            break;
        }
    }

    /* Restore terminal settings */
    disableRawMode();

    printf("\nGoodbye!\n");

    return 0;
}