#ifndef CURSOR_H
#define CURSOR_H

/*
 * ============================================================================
 * Raven Editor
 * File        : cursor.h
 * Description : Cursor movement and scrolling.
 * ============================================================================
 */

#include "terminal.h"

/*
 * Move the cursor.
 */
void editorMoveCursor(int key);

/*
 * Scroll the viewport.
 */
void editorScroll(void);

#endif /* CURSOR_H */