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

/*
 * ============================================================================
 * Clamp Cursor
 *
 * Keeps the cursor within the current line.
 * ============================================================================
 */

static void editorClampCursor(void)
{
    EditorRow *row = NULL;

    if (E.cy < E.numRows)
    {
        row = &E.rows[E.cy];
    }

    int rowlen = row ? row->size : 0;

    if (E.cx > rowlen)
    {
        E.cx = rowlen;
    }
}

/*
 * ============================================================================
 * Scroll
 *
 * Keeps the cursor visible on screen.
 * ============================================================================
 */

void editorScroll(void)
{
    if (E.cy < E.rowoff)
    {
        E.rowoff = E.cy;
    }

    if (E.cy >= E.rowoff + E.screenrows)
    {
        E.rowoff = E.cy - E.screenrows + 1;
    }

    if (E.cx < E.coloff)
    {
        E.coloff = E.cx;
    }

    if (E.cx >= E.coloff + E.screencols)
    {
        E.coloff = E.cx - E.screencols + 1;
    }
}

/*
 * ============================================================================
 * Move Cursor
 * ============================================================================
 */

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

        default:
            break;
    }

    editorClampCursor();
    editorScroll();
}