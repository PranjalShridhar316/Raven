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

/*
 * Convert a key into its Ctrl equivalent.
 *
 * Example:
 * CTRL_KEY('q') -> 17
 * CTRL_KEY('s') -> 19
 */
#define CTRL_KEY(k) ((k) & 0x1f)

/*
 * ============================================================================
 * Editor Keys
 * ============================================================================
 *
 * ASCII values occupy 0–255.
 * Special keys begin at 1000.
 *
 */

enum EditorKey
{
    ARROW_LEFT = 1000,
    ARROW_RIGHT,
    ARROW_UP,
    ARROW_DOWN,

    DEL_KEY,
    HOME_KEY,
    END_KEY,

    PAGE_UP,
    PAGE_DOWN
};

/*
 * ============================================================================
 * Terminal Functions
 * ============================================================================
 */

/* Raw terminal mode */
void enableRawMode(void);
void disableRawMode(void);

/* Keyboard */
int readKey(void);

/* Window size */
int getWindowSize(int *rows, int *cols);

#endif /* TERMINAL_H */