#ifndef BUFFER_H
#define BUFFER_H

/*
 * ============================================================================
 * Raven Editor
 * File        : buffer.h
 * Description : Document buffer management.
 * ============================================================================
 */

#include "row.h"

/*
 * ============================================================================
 * Row Operations
 * ============================================================================
 */

/*
 * Insert a new row into the document.
 */
void editorInsertRow(int at, const char *s, int len);

/*
 * Delete a row from the document.
 */
void editorDeleteRow(int at);

/*
 * ============================================================================
 * Character Operations
 * ============================================================================
 */

/*
 * Insert one character at the cursor.
 */
void editorInsertChar(int c);

/*
 * Delete one character.
 */
void editorDeleteChar(void);

/*
 * Insert a newline.
 */
void editorInsertNewline(void);

/*
 * ============================================================================
 * Buffer Management
 * ============================================================================
 */

/*
 * Free the entire document buffer.
 */
void editorFreeBuffer(void);

#endif /* BUFFER_H */