#ifndef TERMINAL_H
#define TERMINAL_H

/*
 * ============================================================================
 * Raven Editor
 * File        : terminal.h
 * Description : Terminal handling functions.
 * ============================================================================
 */

/*
 * Enable terminal raw mode.
 *
 * Raw mode allows Raven to capture
 * keyboard input directly.
 */
void enableRawMode(void);

/*
 * Restore terminal settings
 * before exiting Raven.
 */
void disableRawMode(void);

/*
 * Read a single keyboard input.
 */
int readKey(void);

/*
 * Get the current terminal size.
 *
 * Parameters:
 *   rows - Pointer to store the number of terminal rows.
 *   cols - Pointer to store the number of terminal columns.
 *
 * Returns:
 *   0  -> Success
 *  -1  -> Failure
 */
int getWindowSize(int *rows, int *cols);

#endif /* TERMINAL_H */