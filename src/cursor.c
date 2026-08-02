/*
 * ============================================================================
 * Raven Editor
 * File        : cursor.c
 * Description : Cursor movement engine.
 * ============================================================================
 */

#include "cursor.h"
#include "editor.h"

/*
 * ============================================================================
 * editorMoveCursor()
 * ============================================================================
 */

void editorMoveCursor(int key)
{
    switch (key)
    {
        case ARROW_LEFT:

            if (E.cx > 0)
            {
                E.cx--;
            }

            break;

        case ARROW_RIGHT:

            if (E.cx < E.screencols - 1)
            {
                E.cx++;
            }

            break;

        case ARROW_UP:

            if (E.cy > 0)
            {
                E.cy--;
            }

            break;

        case ARROW_DOWN:

            if (E.cy < E.screenrows - 1)
            {
                E.cy++;
            }

            break;

        default:
            break;
    }
}