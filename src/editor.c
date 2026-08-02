/*
 * ============================================================================
 * Raven Editor
 * File        : editor.c
 * Description : Editor initialization and cursor management.
 * ============================================================================
 */

#include <stdlib.h>

#include "editor.h"
#include "terminal.h"

/*
 * ============================================================================
 * Global Editor State
 * ============================================================================
 */

EditorConfig E;

/*
 * ============================================================================
 * editorInit()
 * ----------------------------------------------------------------------------
 * Initializes the editor state.
 * ============================================================================
 */
void editorInit(void)
{
    /* Initial cursor position */
    E.cx = 0;
    E.cy = 0;

    /*
     * Determine the current terminal size.
     */
    if (getWindowSize(&E.screenrows, &E.screencols) == -1)
    {
        exit(EXIT_FAILURE);
    }
}

/*
 * ============================================================================
 * editorMoveCursor()
 * ----------------------------------------------------------------------------
 * Moves the cursor while keeping it inside the visible terminal.
 * ============================================================================
 */
void editorMoveCursor(int key)
{
    switch (key)
    {
        case ARROW_LEFT:
        {
            if (E.cx > 0)
            {
                E.cx--;
            }
            break;
        }

        case ARROW_RIGHT:
        {
            if (E.cx < E.screencols - 1)
            {
                E.cx++;
            }
            break;
        }

        case ARROW_UP:
        {
            if (E.cy > 0)
            {
                E.cy--;
            }
            break;
        }

        case ARROW_DOWN:
        {
            if (E.cy < E.screenrows - 1)
            {
                E.cy++;
            }
            break;
        }

        default:
            break;
    }
}