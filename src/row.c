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
    if (at < 0 || at > row->size)
    {
        at = row->size;
    }

    row->chars = realloc(row->chars, row->size + 2);

    memmove(&row->chars[at + 1],
            &row->chars[at],
            row->size - at + 1);

    row->size++;

    row->chars[at] = c;
}