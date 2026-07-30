#ifndef SCREEN_H
#define SCREEN_H

/*
 * ============================================================================
 * Raven Editor
 * File        : screen.h
 * Description : Screen rendering engine.
 * ============================================================================
 */

/*
 * Append Buffer
 *
 * Stores the entire screen in memory before writing
 * it to the terminal in one operation.
 */
typedef struct
{
    char *buffer;
    int length;

} AppendBuffer;

/*
 * Initialize an empty append buffer.
 */
#define ABUF_INIT {NULL, 0}

/*
 * Append Buffer Functions
 */
void abAppend(AppendBuffer *ab, const char *s, int len);
void abFree(AppendBuffer *ab);

/*
 * Screen Rendering Functions
 */
void editorDrawRows(AppendBuffer *ab);
void editorRefreshScreen(void);

#endif /* SCREEN_H */