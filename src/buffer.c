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
 * Insert Row
 * ============================================================================
 */

void editorInsertRow(int at, const char *s, int len)
{
    if (at < 0 || at > E.numRows)
    {
        return;
    }

    EditorRow *newRows = realloc(
        E.rows,
        sizeof(EditorRow) * (E.numRows + 1)
    );

    if (newRows == NULL)
    {
        return;
    }

    E.rows = newRows;

    memmove(
        &E.rows[at + 1],
        &E.rows[at],
        sizeof(EditorRow) * (E.numRows - at)
    );

    rowInit(&E.rows[at], s, len);

    E.numRows++;

    E.dirty++;
}

/*
 * ============================================================================
 * Delete Row
 * ============================================================================
 */

void editorDeleteRow(int at)
{
    if (at < 0 || at >= E.numRows)
    {
        return;
    }

    rowFree(&E.rows[at]);

    memmove(
        &E.rows[at],
        &E.rows[at + 1],
        sizeof(EditorRow) * (E.numRows - at - 1)
    );

    E.numRows--;

    if (E.numRows == 0)
    {
        free(E.rows);
        E.rows = NULL;
    }
    else
    {
        EditorRow *newRows = realloc(
            E.rows,
            sizeof(EditorRow) * E.numRows
        );

        if (newRows != NULL)
        {
            E.rows = newRows;
        }
    }

    E.dirty++;
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

    rowInsertChar(
        &E.rows[E.cy],
        E.cx,
        c
    );

    E.cx++;

    E.dirty++;
}

/*
 * ============================================================================
 * Delete Character
 * ============================================================================
 */

void editorDeleteChar(void)
{
    if (E.cy >= E.numRows)
    {
        return;
    }

    if (E.cx == 0 && E.cy == 0)
    {
        return;
    }

    EditorRow *row = &E.rows[E.cy];

    /*
     * Delete inside current row
     */

    if (E.cx > 0)
    {
        rowDeleteChar(row, E.cx - 1);

        E.cx--;

        E.dirty++;

        return;
    }

    /*
     * Merge with previous row
     */

    int previousLength = E.rows[E.cy - 1].size;

    rowAppendString(
        &E.rows[E.cy - 1],
        row->chars,
        row->size
    );

    editorDeleteRow(E.cy);

    E.cy--;

    E.cx = previousLength;

    E.dirty++;
}

/*
 * ============================================================================
 * Insert Newline
 * ============================================================================
 */

void editorInsertNewline(void)
{
    if (E.cx == 0)
    {
        editorInsertRow(E.cy, "", 0);
    }
    else
    {
        EditorRow *row = &E.rows[E.cy];

        editorInsertRow(
            E.cy + 1,
            &row->chars[E.cx],
            row->size - E.cx
        );

        row->size = E.cx;

        row->chars[row->size] = '\0';
    }

    E.cy++;

    E.cx = 0;

    E.dirty++;
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