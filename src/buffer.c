/*
 * ============================================================================
 * Raven Editor
 * File        : buffer.c
 * Description : Document buffer management.
 * ============================================================================
 */

#include <stdlib.h>
#include <string.h>

#include "buffer.h"
#include "editor.h"

/*
 * ============================================================================
 * Insert a row.
 * ============================================================================
 */
void editorInsertRow(int at, const char *s, size_t len)
{
    if (at < 0 || at > E.numRows)
        return;

    E.rows = realloc(E.rows, sizeof(EditorRow) * (E.numRows + 1));

    memmove(
        &E.rows[at + 1],
        &E.rows[at],
        sizeof(EditorRow) * (E.numRows - at)
    );

    rowInit(&E.rows[at]);

    E.rows[at].chars = malloc(len + 1);

    memcpy(E.rows[at].chars, s, len);

    E.rows[at].chars[len] = '\0';

    E.rows[at].size = len;

    E.numRows++;
}

/*
 * ============================================================================
 * Free every row.
 * ============================================================================
 */
void editorFreeBuffer(void)
{
    int i;

    for (i = 0; i < E.numRows; i++)
    {
        rowFree(&E.rows[i]);
    }

    free(E.rows);

    E.rows = NULL;
    E.numRows = 0;
}