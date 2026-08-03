/*
 * ============================================================================
 * Raven Editor
 * File        : buffer.c
 * Description : Document buffer.
 * ============================================================================
 */

#include <stdlib.h>
#include <string.h>

#include "buffer.h"
#include "editor.h"

/*
 * ============================================================================
 * Insert Row
 * ============================================================================
 */

void editorInsertRow(int at, const char *s, int len)
{
    if (at < 0 || at > E.numRows)
        return;

    EditorRow *newRows =
        realloc(E.rows, sizeof(EditorRow) * (E.numRows + 1));

    if (newRows == NULL)
        return;

    E.rows = newRows;

    memmove(
        &E.rows[at + 1],
        &E.rows[at],
        sizeof(EditorRow) * (E.numRows - at)
    );

    rowInit(&E.rows[at], s, len);

    E.numRows++;
}

/*
 * ============================================================================
 * Insert Character
 * ============================================================================
 */

void editorInsertChar(int c)
{
    if (E.cy == E.numRows)
    {
        editorInsertRow(E.numRows, "", 0);
    }

    rowInsertChar(&E.rows[E.cy], E.cx, c);

    E.cx++;
}

/*
 * ============================================================================
 * Free Buffer
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