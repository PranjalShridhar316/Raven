#ifndef ROW_H
#define ROW_H

/*
 * ============================================================================
 * Raven Editor
 * File        : row.h
 * Description : Represents a single line of text.
 * ============================================================================
 */

typedef struct
{
    int size;
    char *chars;
} EditorRow;

/*
 * Initialize a row.
 */
void rowInit(EditorRow *row, const char *s, int len);

/*
 * Free a row.
 */
void rowFree(EditorRow *row);

/*
 * Insert a character into a row.
 */
void rowInsertChar(EditorRow *row, int at, int c);

#endif /* ROW_H */