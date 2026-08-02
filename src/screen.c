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
    char *newBuffer = realloc(ab->buffer, ab->length + len);

    if (newBuffer == NULL)
        return;

    memcpy(&newBuffer[ab->length], s, len);

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
        if (y < E.numRows)
        {
            int len = E.rows[y].size;

            if (len > E.screencols)
                len = E.screencols;

            abAppend(ab, E.rows[y].chars, len);
        }
        else
        {
            if (E.numRows == 0 && y == E.screenrows / 3)
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

                int padding = (E.screencols - len) / 2;

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

        abAppend(ab, "\x1b[K", 3);

        if (y < E.screenrows - 1)
            abAppend(ab, "\r\n", 2);
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
        E.cy + 1,
        E.cx + 1
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

    abAppend(&ab, "\x1b[?25l", 6);
    abAppend(&ab, "\x1b[H", 3);

    editorDrawRows(&ab);

    editorDrawCursor(&ab);

    abAppend(&ab, "\x1b[?25h", 6);

    write(STDOUT_FILENO, ab.buffer, ab.length);

    abFree(&ab);
}