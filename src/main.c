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
    enableRawMode();

    editorInit();

    editorRefreshScreen();

    while (1)
    {
        editorProcessKeypress();
    }

    return 0;
}