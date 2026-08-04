/*
 * ============================================================================
 * Raven Editor
 * File        : main.c
 * Description : Entry point of Raven.
 * ============================================================================
 */

#include "terminal.h"
#include "editor.h"
#include "screen.h"
#include "input.h"

int main(void)
{
    /* Enable raw terminal mode */
    enableRawMode();

    /* Initialize editor state */
    editorInit();

    /* Draw the initial screen */
    editorRefreshScreen();

    /* Main editor event loop */
    while (1)
    {
        editorProcessKeypress();
    }

    return 0;
}