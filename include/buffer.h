#ifndef BUFFER_H
#define BUFFER_H

#include "row.h"

/*
 * Insert a row.
 */
void editorInsertRow(int at, const char *s, int len);

/*
 * Insert one character.
 */
void editorInsertChar(int c);

/*
 * Free the document.
 */
void editorFreeBuffer(void);

#endif