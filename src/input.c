/*
 * ============================================================================
 * Raven Editor
 * File        : input.c
 * Description : Keyboard input.
 * ============================================================================
 */

#include <ctype.h>
#include <stdlib.h>

#include "input.h"
#include "terminal.h"
#include "cursor.h"
#include "buffer.h"
#include "screen.h"

/*
 * ============================================================================
 * Process Keyboard Input
 * ============================================================================
 */

void editorProcessKeypress(void)
{
    int c = readKey();

    switch (c)
    {
        /*
         * Quit
         */

        case CTRL_KEY('q'):

            exit(EXIT_SUCCESS);

            break;

        /*
         * Cursor
         */

        case ARROW_UP:
        case ARROW_DOWN:
        case ARROW_LEFT:
        case ARROW_RIGHT:

            editorMoveCursor(c);

            break;

        /*
         * Printable characters
         */

        default:

            if (!iscntrl(c))
            {
                editorInsertChar(c);
            }

            break;
    }

    editorRefreshScreen();
}