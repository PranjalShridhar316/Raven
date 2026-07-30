/*
 * ============================================================================
 * Raven Editor
 * File        : terminal.c
 * Description : Terminal handling functions.
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>

#include "terminal.h"

/*
 * Stores the original terminal settings.
 */
static struct termios originalTermios;

/*
 * ============================================================================
 * Restore terminal settings.
 * ============================================================================
 */
void disableRawMode(void)
{
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &originalTermios) == -1)
    {
        perror("tcsetattr");
        exit(EXIT_FAILURE);
    }
}

/*
 * ============================================================================
 * Enable raw terminal mode.
 * ============================================================================
 */
void enableRawMode(void)
{
    if (tcgetattr(STDIN_FILENO, &originalTermios) == -1)
    {
        perror("tcgetattr");
        exit(EXIT_FAILURE);
    }

    struct termios raw = originalTermios;

    /*
     * Disable:
     *  ECHO    -> Don't print typed keys.
     *  ICANON  -> Read input one character at a time.
     */
    raw.c_lflag &= ~(ECHO | ICANON);

    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1)
    {
        perror("tcsetattr");
        exit(EXIT_FAILURE);
    }
}

/*
 * ============================================================================
 * Read one character from keyboard.
 * ============================================================================
 */
int readKey(void)
{
    char c;

    while (read(STDIN_FILENO, &c, 1) != 1)
    {
        /* Keep reading until one character is received */
    }

    return c;
}

/*
 * ============================================================================
 * Get terminal window size.
 *
 * Returns:
 *      0  -> Success
 *     -1  -> Failure
 * ============================================================================
 */
int getWindowSize(int *rows, int *cols)
{
    struct winsize ws;

    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1 ||
        ws.ws_col == 0)
    {
        return -1;
    }

    *rows = ws.ws_row;
    *cols = ws.ws_col;

    return 0;
}