#ifndef ROW_H
#define ROW_H

/*
 * ============================================================================
 * Raven Editor
 * File        : row.h
 * Description : Represents a single line of text.
 * ============================================================================
 */

/*
 * ============================================================================
 * Editor Row
 * ============================================================================
 *
 * One EditorRow represents one line in the document.
 *
 */

typedef struct
{
    /* Number of characters in the row */
    int size;

    /* Character buffer */
    char *chars;

} EditorRow;

/*
 * ============================================================================
 * Row Functions
 * ============================================================================
 */

/* Initialize a row */
void rowInit(EditorRow *row, const char *s, int len);

/* Free row memory */
void rowFree(EditorRow *row);

/* Insert one character */
void rowInsertChar(EditorRow *row, int at, int c);

#endif /* ROW_H */