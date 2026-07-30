#ifndef TERMINAL_H
#define TERMINAL_H


/*
    Enable terminal raw mode.

    Raw mode allows Raven to capture
    keyboard input directly.
*/
void enableRawMode(void);


/*
    Restore terminal settings
    before exiting Raven.
*/
void disableRawMode(void);


/*
    Read a single keyboard input.
*/
int readKey(void);


#endif