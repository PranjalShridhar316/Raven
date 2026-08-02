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
 * A single line inside the editor.
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
 * Row Management
 */

void rowInit(EditorRow *row);

void rowFree(EditorRow *row);

#endif /* ROW_H */