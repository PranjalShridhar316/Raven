/*
 * ============================================================================
 * Raven Editor
 * File        : editor.c
 * Description : Editor initialization.
 * ============================================================================
 */

#include <stdlib.h>

#include "editor.h"
#include "terminal.h"
#include "buffer.h"

/*
 * ============================================================================
 * Global Editor State
 * ============================================================================
 */

EditorConfig E;

/*
 * ============================================================================
 * editorInit()
 * ============================================================================
 */

void editorInit(void)
{
    /* Cursor starts at top-left */

    E.cx = 0;
    E.cy = 0;

    /* Empty document */

    E.numRows = 0;
    E.rows = NULL;

    /* Determine terminal size */

    if (getWindowSize(&E.screenrows, &E.screencols) == -1)
    {
        exit(EXIT_FAILURE);
    }

    /*
     * Temporary rows for testing.
     */

    editorInsertRow(0, "Welcome to Raven", 16);
    editorInsertRow(1, "Milestone 1.7", 13);
    editorInsertRow(2, "Buffer Engine", 13);
}