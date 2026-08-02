#ifndef EDITOR_H
#define EDITOR_H

/*
 * ============================================================================
 * Raven Editor
 * File        : editor.h
 * Description : Global editor state and editor function declarations.
 * ============================================================================
 */

/*
 * ---------------------------------------------------------------------------
 * Editor Configuration
 * ---------------------------------------------------------------------------
 *
 * This structure stores the complete runtime state of Raven.
 * As the project grows, additional members (rows, files, syntax highlighting,
 * Git state, keymaps, etc.) will be added here.
 *
 */

typedef struct
{
    /*
     * Cursor Position
     * ----------------
     * cx -> Cursor X (column)
     * cy -> Cursor Y (row)
     */
    int cx;
    int cy;

    /*
     * Terminal Size
     * ----------------
     * Number of visible rows and columns.
     */
    int screenrows;
    int screencols;

} EditorConfig;


/*
 * Global editor instance.
 * Defined in editor.c
 */
extern EditorConfig E;


/*
 * ---------------------------------------------------------------------------
 * Initialization
 * ---------------------------------------------------------------------------
 */

/*
 * Initialize the editor.
 */
void editorInit(void);


/*
 * ---------------------------------------------------------------------------
 * Cursor
 * ---------------------------------------------------------------------------
 */

/*
 * Move the cursor according to the pressed key.
 */
void editorMoveCursor(int key);

#endif /* EDITOR_H */