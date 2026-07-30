/*
 * ============================================================================
 * Raven Editor
 * File        : editor.c
 * Description : Editor initialization and global state.
 * ============================================================================
 */

#include <stdlib.h>

#include "editor.h"
#include "terminal.h"

/*
 * Global editor instance.
 */
EditorConfig E;

/*
 * ============================================================================
 * Initialize the editor.
 *
 * Responsibilities:
 *   - Initialize cursor position.
 *   - Obtain terminal dimensions.
 * ============================================================================
 */
void editorInit(void)
{
    /* Initial cursor position */
    E.cx = 0;
    E.cy = 0;

    /* Get terminal dimensions */
    if (getWindowSize(&E.screenrows, &E.screencols) == -1)
    {
        exit(EXIT_FAILURE);
    }
}