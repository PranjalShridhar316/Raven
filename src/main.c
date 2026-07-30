/*
 * ============================================================================
 * Raven Editor
 * File        : main.c
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

    while (1)
    {
        editorRefreshScreen();

        editorProcessKeypress();
    }

    return 0;
}