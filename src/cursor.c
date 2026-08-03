/*
 * ============================================================================
 * Raven Editor
 * File        : cursor.c
 * Description : Cursor movement engine.
 * ============================================================================
 */

#include <stdlib.h>

#include "cursor.h"
#include "editor.h"
void editorMoveCursor(int key)
{
    EditorRow *row = NULL;

    if (E.cy < E.numRows)
    {
        row = &E.rows[E.cy];
    }

    switch (key)
    {
        case ARROW_LEFT:

            if (E.cx > 0)
            {
                E.cx--;
            }
            else if (E.cy > 0)
            {
                E.cy--;
                E.cx = E.rows[E.cy].size;
            }

            break;

        case ARROW_RIGHT:

            if (row && E.cx < row->size)
            {
                E.cx++;
            }
            else if (row &&
                     E.cx == row->size &&
                     E.cy < E.numRows - 1)
            {
                E.cy++;
                E.cx = 0;
            }

            break;

        case ARROW_UP:

            if (E.cy > 0)
            {
                E.cy--;
            }

            break;

        case ARROW_DOWN:

            if (E.cy < E.numRows - 1)
            {
                E.cy++;
            }

            break;
    }

    row = (E.cy < E.numRows)
            ? &E.rows[E.cy]
            : NULL;

    int rowlen = row ? row->size : 0;

    if (E.cx > rowlen)
    {
        E.cx = rowlen;
    }
}