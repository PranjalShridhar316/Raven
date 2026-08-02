/*
 * ============================================================================
 * Raven Editor
 * File        : input.c
 * Description : Keyboard input processing.
 * ============================================================================
 */

#include <stdlib.h>

#include "input.h"
#include "terminal.h"
#include "screen.h"
#include "cursor.h"

/*
 * ============================================================================
 * Process one key press.
 * ============================================================================
 */

void editorProcessKeypress(void)
{
    int key = readKey();

    switch (key)
    {
        /*
         * Quit
         */

        case CTRL_KEY('q'):

            exit(EXIT_SUCCESS);

            break;

        /*
         * Cursor Keys
         */

        case ARROW_UP:
        case ARROW_DOWN:
        case ARROW_LEFT:
        case ARROW_RIGHT:

            editorMoveCursor(key);

            break;

        default:

            break;
    }

    editorRefreshScreen();
}