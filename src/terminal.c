#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

#include "terminal.h"

/*
 * Stores the original terminal settings.
 * These settings are restored when Raven exits.
 */
static struct termios originalTermios;

/*
 * Restore the terminal to its original state.
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
 * Enable raw mode.
 *
 * Raw mode allows Raven to receive keyboard input
 * one character at a time instead of waiting for Enter.
 */
void enableRawMode(void)
{
    if (tcgetattr(STDIN_FILENO, &originalTermios) == -1)
    {
        perror("tcgetattr");
        exit(EXIT_FAILURE);
    }

    struct termios raw = originalTermios;

    /* Disable echo and canonical mode */
    raw.c_lflag &= ~(ECHO | ICANON);

    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1)
    {
        perror("tcsetattr");
        exit(EXIT_FAILURE);
    }
}

/*
 * Read one character from the keyboard.
 */
int readKey(void)
{
    char c;

    while (read(STDIN_FILENO, &c, 1) != 1)
    {
        /* Keep trying until one character is read */
    }

    return c;
}