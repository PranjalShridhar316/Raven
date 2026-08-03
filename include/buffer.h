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
 * Buffer Functions
 * ============================================================================
 */

/*
 * Insert a new row into the document.
 */
void editorInsertRow(int at, const char *s, int len);

/*
 * Insert a character at the cursor.
 */
void editorInsertChar(int c);

/*
 * Free the entire document.
 */
void editorFreeBuffer(void);

#endif /* BUFFER_H */