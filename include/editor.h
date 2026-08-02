#ifndef EDITOR_H
#define EDITOR_H

/*
 * ============================================================================
 * Raven Editor
 * File        : editor.h
 * Description : Global editor state.
 * ============================================================================
 */

#include "row.h"

/*
 * ============================================================================
 * Editor Configuration
 * ============================================================================
 */

typedef struct
{
    /*
     * Cursor Position
     */
    int cx;
    int cy;

    /*
     * Screen Size
     */
    int screenrows;
    int screencols;

    /*
     * Document
     */
    int numRows;
    EditorRow *rows;

} EditorConfig;

/*
 * Global editor instance.
 */
extern EditorConfig E;

/*
 * ============================================================================
 * Editor Functions
 * ============================================================================
 */

/* Initialize editor */
void editorInit(void);

#endif /* EDITOR_H */