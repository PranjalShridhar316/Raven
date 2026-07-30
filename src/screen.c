/*
 * ============================================================================
 * Raven Editor
 * File        : screen.c
 * Description : Screen rendering engine.
 * ============================================================================
 */

#include <stdio.h>      // snprintf()
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "screen.h"
#include "editor.h"
#include "raven.h"

#define ABUF_INIT {NULL, 0}

/*
 * ============================================================================
 * Append data to the append buffer.
 * ============================================================================
 */
void abAppend(AppendBuffer *ab, const char *s, int len)
{
    char *newBuffer = realloc(ab->buffer, ab->length + len);

    if (newBuffer == NULL)
    {
        return;
    }

    memcpy(&newBuffer[ab->length], s, len);

    ab->buffer = newBuffer;
    ab->length += len;
}

/*
 * ============================================================================
 * Free the append buffer.
 * ============================================================================
 */
void abFree(AppendBuffer *ab)
{
    free(ab->buffer);
}

/*
 * ============================================================================
 * Draw every row of the editor.
 * ============================================================================
 */
void editorDrawRows(AppendBuffer *ab)
{
    int y;

    for (y = 0; y < E.screenrows; y++)
    {
        if (y == E.screenrows / 3)
        {
            char welcome[80];

            int len = snprintf(
                welcome,
                sizeof(welcome),
                "Raven Editor -- Version %s",
                RAVEN_VERSION
            );

            if (len > E.screencols)
            {
                len = E.screencols;
            }

            int padding = (E.screencols - len) / 2;

            if (padding)
            {
                abAppend(ab, "~", 1);
                padding--;
            }

            while (padding--)
            {
                abAppend(ab, " ", 1);
            }

            abAppend(ab, welcome, len);
        }
        else
        {
            abAppend(ab, "~", 1);
        }

        /* Clear current line */
        abAppend(ab, "\x1b[K", 3);

        if (y < E.screenrows - 1)
        {
            abAppend(ab, "\r\n", 2);
        }
    }
}

/*
 * ============================================================================
 * Refresh the entire screen.
 * ============================================================================
 */
void editorRefreshScreen(void)
{
    AppendBuffer ab = ABUF_INIT;

    /* Hide cursor */
    abAppend(&ab, "\x1b[?25l", 6);

    /* Move cursor to top-left */
    abAppend(&ab, "\x1b[H", 3);

    /* Draw editor */
    editorDrawRows(&ab);

    /* Move cursor to top-left */
    abAppend(&ab, "\x1b[H", 3);

    /* Show cursor */
    abAppend(&ab, "\x1b[?25h", 6);

    /* Draw everything at once */
    write(STDOUT_FILENO, ab.buffer, ab.length);

    abFree(&ab);
}