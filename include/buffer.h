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
 * Insert a new row.
 */
void editorInsertRow(int at, const char *s, size_t len);

/*
 * Free the entire document.
 */
void editorFreeBuffer(void);

#endif