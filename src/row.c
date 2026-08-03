/*
 * ============================================================================
 * Raven Editor
 * File        : row.c
 * Description : Row manipulation.
 * ============================================================================
 */

#include <stdlib.h>
#include <string.h>

#include "row.h"

/*
 * ============================================================================
 * Initialize Row
 * ============================================================================
 */

void rowInit(EditorRow *row, const char *s, int len)
{
    row->size = len;

    row->chars = malloc(len + 1);

    memcpy(row->chars, s, len);

    row->chars[len] = '\0';
}

/*
 * ============================================================================
 * Free Row
 * ============================================================================
 */

void rowFree(EditorRow *row)
{
    free(row->chars);

    row->chars = NULL;
    row->size = 0;
}

/*
 * ============================================================================
 * Insert Character
 * ============================================================================
 */

void rowInsertChar(EditorRow *row, int at, int c)
{
    if (at < 0)
        at = 0;

    if (at > row->size)
        at = row->size;

    char *newChars = realloc(row->chars, row->size + 2);

    if (newChars == NULL)
        return;

    row->chars = newChars;

    memmove(
        &row->chars[at + 1],
        &row->chars[at],
        row->size - at + 1
    );

    row->chars[at] = c;

    row->size++;

    row->chars[row->size] = '\0';
}