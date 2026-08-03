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
    /* Cursor */
    int cx;
    int cy;

    /* Screen */
    int screenrows;
    int screencols;

    /* Scroll offsets */
    int rowoff;
    int coloff;

    /* Document */
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