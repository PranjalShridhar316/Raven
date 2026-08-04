#ifndef ROW_H
#define ROW_H

/*
 * ============================================================================
 * Raven Editor
 * File        : row.h
 * Description : Represents one line of text.
 * ============================================================================
 */

/*
 * ============================================================================
 * Editor Row
 * ============================================================================
 */

typedef struct
{
    /*
     * Number of characters.
     */
    int size;

    /*
     * Character buffer.
     */
    char *chars;

} EditorRow;

/*
 * ============================================================================
 * Row Management
 * ============================================================================
 */

/*
 * Initialize a row.
 */
void rowInit(EditorRow *row, const char *s, int len);

/*
 * Free a row.
 */
void rowFree(EditorRow *row);

/*
 * ============================================================================
 * Editing Operations
 * ============================================================================
 */

/*
 * Insert one character.
 */
void rowInsertChar(EditorRow *row, int at, int c);

/*
 * Delete one character.
 */
void rowDeleteChar(EditorRow *row, int at);

/*
 * Append a string to the end of a row.
 */
void rowAppendString(EditorRow *row, const char *s, int len);

#endif /* ROW_H */