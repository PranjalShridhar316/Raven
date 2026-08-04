#ifndef TERMINAL_H
#define TERMINAL_H

/*
 * ============================================================================
 * Raven Editor
 * File        : terminal.h
 * Description : Terminal control, keyboard input and window management.
 * ============================================================================
 */

#include <termios.h>

/*
 * ============================================================================
 * Helper Macros
 * ============================================================================
 */

/*
 * Convert an alphabetic key into its Ctrl-key equivalent.
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
 * Printable ASCII characters are returned directly.
 * Special keys begin at 1000.
 *
 * These values are returned by readKey().
 */

typedef enum
{
    /*
     * Cursor Movement
     */
    ARROW_LEFT = 1000,
    ARROW_RIGHT,
    ARROW_UP,
    ARROW_DOWN,

    /*
     * Navigation
     */
    HOME_KEY,
    END_KEY,
    PAGE_UP,
    PAGE_DOWN,

    /*
     * Editing
     */
    INSERT_KEY,
    DEL_KEY,
    BACKSPACE_KEY

} EditorKey;

/*
 * ============================================================================
 * Terminal Functions
 * ============================================================================
 */

/*
 * Enable raw terminal mode.
 */
void enableRawMode(void);

/*
 * Restore the original terminal settings.
 */
void disableRawMode(void);

/*
 * Read one key from the terminal.
 *
 * Returns either:
 *   - An ASCII character
 *   - One of the EditorKey values
 */
int readKey(void);

/*
 * Determine the current terminal size.
 *
 * Returns:
 *      0  -> Success
 *     -1  -> Failure
 */
int getWindowSize(int *rows, int *cols);

#endif /* TERMINAL_H */