/*
 * ============================================================================
 * Raven Editor
 * File        : terminal.c
 * Description : Terminal engine.
 * ============================================================================
 */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

#include "terminal.h"

static struct termios original;

/*
 * ============================================================================
 * Disable Raw Mode
 * ============================================================================
 */

void disableRawMode(void)
{
    tcsetattr(
        STDIN_FILENO,
        TCSAFLUSH,
        &original
    );
}

/*
 * ============================================================================
 * Enable Raw Mode
 * ============================================================================
 */

void enableRawMode(void)
{
    if (tcgetattr(STDIN_FILENO, &original) == -1)
    {
        perror("tcgetattr");
        exit(EXIT_FAILURE);
    }

    atexit(disableRawMode);

    struct termios raw = original;

    /*
     * Input flags
     */
    raw.c_iflag &=
        ~(BRKINT |
          ICRNL |
          INPCK |
          ISTRIP |
          IXON);

    /*
     * Output flags
     */
    raw.c_oflag &= ~(OPOST);

    /*
     * Control flags
     */
    raw.c_cflag |= (CS8);

    /*
     * Local flags
     */
    raw.c_lflag &=
        ~(ECHO |
          ICANON |
          IEXTEN |
          ISIG);

    /*
     * Timeout
     */
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 1;

    if (tcsetattr(
            STDIN_FILENO,
            TCSAFLUSH,
            &raw) == -1)
    {
        perror("tcsetattr");
        exit(EXIT_FAILURE);
    }
}

/*
 * ============================================================================
 * Read One Key
 * ============================================================================
 */

int readKey(void)
{
    int nread;
    char c;

    while ((nread = read(STDIN_FILENO, &c, 1)) != 1)
    {
        if (nread == -1 && errno != EAGAIN)
        {
            perror("read");
            exit(EXIT_FAILURE);
        }
    }

    if (c == '\x1b')
    {
        char seq[3];

        if (read(STDIN_FILENO, &seq[0], 1) != 1)
            return '\x1b';

        if (read(STDIN_FILENO, &seq[1], 1) != 1)
            return '\x1b';

        if (seq[0] == '[')
        {
            if (seq[1] >= '0' &&
                seq[1] <= '9')
            {
                if (read(STDIN_FILENO,
                         &seq[2],
                         1) != 1)
                {
                    return '\x1b';
                }

                if (seq[2] == '~')
                {
                    switch (seq[1])
                    {
                        case '1':
                            return HOME_KEY;

                        case '3':
                            return DEL_KEY;

                        case '4':
                            return END_KEY;

                        case '5':
                            return PAGE_UP;

                        case '6':
                            return PAGE_DOWN;

                        case '7':
                            return HOME_KEY;

                        case '8':
                            return END_KEY;
                    }
                }
            }
            else
            {
                switch (seq[1])
                {
                    case 'A':
                        return ARROW_UP;

                    case 'B':
                        return ARROW_DOWN;

                    case 'C':
                        return ARROW_RIGHT;

                    case 'D':
                        return ARROW_LEFT;

                    case 'H':
                        return HOME_KEY;

                    case 'F':
                        return END_KEY;
                }
            }
        }

        return '\x1b';
    }

    return c;
}

/*
 * ============================================================================
 * Get Window Size
 * ============================================================================
 */

int getWindowSize(int *rows, int *cols)
{
    struct winsize ws;

    if (ioctl(
            STDOUT_FILENO,
            TIOCGWINSZ,
            &ws) == -1 ||
        ws.ws_col == 0)
    {
        return -1;
    }

    *cols = ws.ws_col;
    *rows = ws.ws_row;

    return 0;
}