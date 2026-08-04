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

    row->chars = malloc((size_t)len + 1);

    if (row->chars == NULL)
    {
        row->size = 0;
        return;
    }

    memcpy(row->chars, s, (size_t)len);

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
    char *newChars;

    if (at < 0)
    {
        at = 0;
    }

    if (at > row->size)
    {
        at = row->size;
    }

    newChars = realloc(row->chars, (size_t)row->size + 2);

    if (newChars == NULL)
    {
        return;
    }

    row->chars = newChars;

    memmove(
        &row->chars[at + 1],
        &row->chars[at],
        (size_t)(row->size - at + 1) * sizeof(char)
    );

    row->chars[at] = (char)c;

    row->size++;

    row->chars[row->size] = '\0';
}

/*
 * ============================================================================
 * Append String
 *
 * Appends text to the end of a row.
 * ============================================================================
 */

void rowAppendString(EditorRow *row, const char *s, int len)
{
    char *newChars;

    newChars = realloc(
        row->chars,
        (size_t)(row->size + len + 1)
    );

    if (newChars == NULL)
    {
        return;
    }

    row->chars = newChars;

    memcpy(
        &row->chars[row->size],
        s,
        (size_t)len
    );

    row->size += len;

    row->chars[row->size] = '\0';
}

/*
 * ============================================================================
 * Delete Character
 *
 * Deletes one character from a row.
 * ============================================================================
 */

void rowDeleteChar(EditorRow *row, int at)
{
    if (at < 0 || at >= row->size)
    {
        return;
    }

    memmove(
        &row->chars[at],
        &row->chars[at + 1],
        (size_t)(row->size - at)
    );

    row->size--;

    row->chars[row->size] = '\0';
}

