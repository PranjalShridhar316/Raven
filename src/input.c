/*
 * ============================================================================
 * Raven Editor
 * File        : input.c
 * Description : Keyboard input processing.
 * ============================================================================
 */

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "input.h"
#include "terminal.h"
#include "cursor.h"
#include "buffer.h"
#include "screen.h"
#include "editor.h"

/*
 * ============================================================================
 * Process Keyboard Input
 * ============================================================================
 */

void editorProcessKeypress(void)
{
    int c = readKey();

    /*
     * ------------------------------------------------------------------------
     * DEBUG
     * Displays the numeric key code on the last line of the screen.
     * Remove this after debugging.
     * ------------------------------------------------------------------------
     */

    {
        char dbg[64];

        snprintf(
            dbg,
            sizeof(dbg),
            "\x1b[%d;1HKey = %d\x1b[K",
            E.screenrows,
            c
        );

        write(
            STDOUT_FILENO,
            dbg,
            strlen(dbg)
        );
    }

    switch (c)
    {
        /*
         * --------------------------------------------------------------------
         * Quit
         * --------------------------------------------------------------------
         */

        case CTRL_KEY('q'):

            editorFree();

            exit(EXIT_SUCCESS);

            break;

        /*
         * --------------------------------------------------------------------
         * Cursor Movement
         * --------------------------------------------------------------------
         */

        case ARROW_UP:
        case ARROW_DOWN:
        case ARROW_LEFT:
        case ARROW_RIGHT:

            editorMoveCursor(c);

            break;

        /*
         * --------------------------------------------------------------------
         * Home / End
         * --------------------------------------------------------------------
         */

        case HOME_KEY:

            E.cx = 0;

            break;

        case END_KEY:

            if (E.cy < E.numRows)
            {
                E.cx = E.rows[E.cy].size;
            }

            break;

        /*
         * --------------------------------------------------------------------
         * Page Navigation
         * --------------------------------------------------------------------
         */

        case PAGE_UP:

            E.cy = E.rowoff;

            break;

        case PAGE_DOWN:

            E.cy = E.rowoff + E.screenrows - 1;

            if (E.cy > E.numRows)
            {
                E.cy = E.numRows;
            }

            break;

        /*
         * --------------------------------------------------------------------
         * Enter
         * --------------------------------------------------------------------
         */

        case '\r':

            editorInsertNewline();

            break;

        /*
         * --------------------------------------------------------------------
         * Backspace
         * --------------------------------------------------------------------
         */

        case BACKSPACE_KEY:

            editorDeleteChar();

            break;

        /*
         * --------------------------------------------------------------------
         * Delete
         * --------------------------------------------------------------------
         */

        case DEL_KEY:

            editorMoveCursor(ARROW_RIGHT);
            editorDeleteChar();

            break;

        /*
         * --------------------------------------------------------------------
         * Printable Characters
         * --------------------------------------------------------------------
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