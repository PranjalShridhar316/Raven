/*
 * ============================================================================
 * Raven Editor
 * File        : input.c
 * Description : Keyboard processing.
 * ============================================================================
 */

#include <stdlib.h>

#include "input.h"
#include "terminal.h"

/*
 * Process one keypress.
 */
void editorProcessKeypress(void)
{
    int key = readKey();

    switch (key)
    {
        /*
         * Ctrl + Q
         */
        case 17:
            exit(EXIT_SUCCESS);
            break;

        default:
            break;
    }
}