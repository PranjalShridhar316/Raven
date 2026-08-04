/*
 * ============================================================================
 * Raven Editor
 * File        : editor.c
 * Description : Editor initialization and global state management.
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
 *
 * Initialize the global editor configuration.
 * ============================================================================
 */

void editorInit(void)
{
    /*
     * Cursor Position
     */
    E.cx = 0;
    E.cy = 0;

    /*
     * Render Position
     *
     * (Future syntax highlighting and tab expansion.)
     */
    E.rx = 0;

    /*
     * Scroll Offsets
     */
    E.rowOffset = 0;
    E.colOffset = 0;

    /*
     * Empty Document
     */
    E.numRows = 0;
    E.rows = NULL;

    /*
     * File Information
     */
    E.filename = NULL;

    /*
     * Dirty Flag
     *
     * 0 = clean
     * 1 = modified
     */
    E.dirty = 0;

    /*
     * Determine Terminal Size
     */
    if (getWindowSize(&E.screenrows, &E.screencols) == -1)
    {
        exit(EXIT_FAILURE);
    }

    /*
     * Leave room for the future status bar
     * and message bar.
     */
    E.screenrows -= 2;

    /*
     * ------------------------------------------------------------------------
     * Temporary Test Document
     *
     * Remove after file loading is implemented.
     * ------------------------------------------------------------------------
     */

    editorInsertRow(0, "Welcome to Raven", 16);
    editorInsertRow(1, "Milestone 1.8", 13);
    editorInsertRow(2, "Text Buffer Ready", 17);
}

/*
 * ============================================================================
 * editorFree()
 *
 * Free all allocated editor resources.
 * ============================================================================
 */

void editorFree(void)
{
    editorFreeBuffer();

    free(E.filename);
    E.filename = NULL;
}