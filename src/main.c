#include <stdio.h>

#include "raven.h"
#include "terminal.h"
#include "editor.h"

int main(void)
{
    printf("1. Starting Raven\n");

    enableRawMode();
    printf("2. Raw mode enabled\n");

    editorInit();
    printf("3. Editor initialized\n");

    while (1)
    {
        int key = readKey();

        printf("Key = %d\n", key);

        if (key == 17)
            break;
    }

    disableRawMode();

    printf("4. Exiting\n");

    return 0;
}