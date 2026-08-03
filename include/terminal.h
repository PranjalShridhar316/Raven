#ifndef TERMINAL_H
#define TERMINAL_H

/*
 * ============================================================================
 * Raven Editor
 * File        : terminal.h
 * Description : Terminal control and keyboard input.
 * ============================================================================
 */

#include <termios.h>

/*
 * ============================================================================
 * Helper Macros
 * ============================================================================
 */

/* Convert a key into its Ctrl equivalent. */
#define CTRL_KEY(k) ((k) & 0x1f)

/*
 * ============================================================================
 * Editor Keys
 * ============================================================================
 *
 * ASCII values occupy 0-255.
 * Special keys begin at 1000.
 *
 */

typedef enum
{
    ARROW_LEFT = 1000,
    ARROW_RIGHT,
    ARROW_UP,
    ARROW_DOWN,

    DEL_KEY,

    HOME_KEY,
    END_KEY,

    PAGE_UP,
    PAGE_DOWN,

    INSERT_KEY,
    BACKSPACE_KEY

} EditorKey;

/*
 * ============================================================================
 * Terminal Functions
 * ============================================================================
 */

void enableRawMode(void);
void disableRawMode(void);

int readKey(void);

int getWindowSize(int *rows, int *cols);

#endif /* TERMINAL_H */