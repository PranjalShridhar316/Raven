#include <termios.h>
#include <unistd.h>

#include "../include/terminal.h"


struct termios original;


/*
    Disable raw mode and restore terminal settings
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
    Enable raw terminal mode
*/
void enableRawMode(void)
{

    tcgetattr(
        STDIN_FILENO,
        &original
    );


    struct termios raw = original;


    raw.c_lflag &= ~(ECHO | ICANON);


    tcsetattr(
        STDIN_FILENO,
        TCSAFLUSH,
        &raw
    );

}


/*
    Read one keyboard character
*/
int readKey(void)
{

    char c;


    if(read(STDIN_FILENO,&c,1)==1)
    {
        return c;
    }


    return -1;
}