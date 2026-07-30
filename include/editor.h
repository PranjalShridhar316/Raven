#ifndef EDITOR_H
#define EDITOR_H

/*
 * ============================================================================
 * Raven Editor
 * File        : editor.h
 * Description : Defines the global editor state and editor functions.
 * ============================================================================
 */

/*
 * Stores the complete state of the editor.
 */
typedef struct
{
    /* Cursor Position */
    int cx;                 /* Cursor X position */
    int cy;                 /* Cursor Y position */

    /* Screen Size */
    int screenrows;         /* Number of terminal rows */
    int screencols;         /* Number of terminal columns */

} EditorConfig;

/*
 * Global editor instance.
 * Defined in editor.c
 */
extern EditorConfig E;

/*
 * Initialize the editor.
 *
 * Responsibilities:
 *   - Initialize cursor position.
 *   - Get terminal dimensions.
 *   - Prepare the editor state.
 */
void editorInit(void);

#endif /* EDITOR_H */