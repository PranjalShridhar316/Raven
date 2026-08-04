/*
 * ============================================================================
 * Raven Editor
 * File        : screen.c
 * Description : Screen rendering engine.
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "screen.h"
#include "editor.h"
#include "raven.h"

/*
 * ============================================================================
 * Append Buffer
 * ============================================================================
 */

void abAppend(AppendBuffer *ab, const char *s, int len)
{
    char *newBuffer;

    if (len <= 0)
        return;

    newBuffer = realloc(ab->buffer, ab->length + len);

    if (newBuffer == NULL)
        return;

    memcpy(newBuffer + ab->length, s, len);

    ab->buffer = newBuffer;
    ab->length += len;
}

void abFree(AppendBuffer *ab)
{
    free(ab->buffer);

    ab->buffer = NULL;
    ab->length = 0;
}

/*
 * ============================================================================
 * Draw Editor Rows
 * ============================================================================
 */

void editorDrawRows(AppendBuffer *ab)
{
    int y;

    for (y = 0; y < E.screenrows; y++)
    {
        int filerow = y + E.rowoff;

        if (filerow >= E.numRows)
        {
            if (E.numRows == 0 &&
                y == E.screenrows / 3)
            {
                char welcome[80];

                int len = snprintf(
                    welcome,
                    sizeof(welcome),
                    "Raven Editor -- Version %s",
                    RAVEN_VERSION
                );

                if (len > E.screencols)
                    len = E.screencols;

                int padding =
                    (E.screencols - len) / 2;

                if (padding)
                {
                    abAppend(ab, "~", 1);
                    padding--;
                }

                while (padding--)
                    abAppend(ab, " ", 1);

                abAppend(ab, welcome, len);
            }
            else
            {
                abAppend(ab, "~", 1);
            }
        }
        else
        {
            int len =
                E.rows[filerow].size - E.coloff;

            if (len < 0)
                len = 0;

            if (len > E.screencols)
                len = E.screencols;

            if (len > 0)
            {
                abAppend(
                    ab,
                    &E.rows[filerow].chars[E.coloff],
                    len
                );
            }
        }

        /*
         * Clear remainder of line.
         */
        abAppend(ab, "\x1b[K", 3);

        if (y < E.screenrows - 1)
        {
            abAppend(ab, "\r\n", 2);
        }
    }
}

/*
 * ============================================================================
 * Draw Cursor
 * ============================================================================
 */

void editorDrawCursor(AppendBuffer *ab)
{
    char buf[32];

    snprintf(
        buf,
        sizeof(buf),
        "\x1b[%d;%dH",
        (E.cy - E.rowoff) + 1,
        (E.cx - E.coloff) + 1
    );

    abAppend(ab, buf, strlen(buf));
}

/*
 * ============================================================================
 * Refresh Screen
 * ============================================================================
 */

void editorRefreshScreen(void)
{
    AppendBuffer ab = APPEND_BUFFER_INIT;

    /*
     * Hide Cursor
     */
    abAppend(&ab, "\x1b[?25l", 6);

    /*
     * Cursor Home
     */
    abAppend(&ab, "\x1b[H", 3);

    /*
     * Draw File
     */
    editorDrawRows(&ab);

    /*
     * Position Cursor
     */
    editorDrawCursor(&ab);

    /*
     * Show Cursor
     */
    abAppend(&ab, "\x1b[?25h", 6);

    write(
        STDOUT_FILENO,
        ab.buffer,
        ab.length
    );

    abFree(&ab);
}