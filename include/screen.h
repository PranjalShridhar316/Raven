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
 * ============================================================================
 * Append Buffer
 * ============================================================================
 */

typedef struct
{
    char *buffer;
    int length;

} AppendBuffer;

#define APPEND_BUFFER_INIT { NULL, 0 }

/*
 * ============================================================================
 * Append Buffer Functions
 * ============================================================================
 */

void abAppend(AppendBuffer *ab, const char *s, int len);
void abFree(AppendBuffer *ab);

/*
 * ============================================================================
 * Screen Drawing
 * ============================================================================
 */

void editorDrawRows(AppendBuffer *ab);
void editorDrawCursor(AppendBuffer *ab);

/*
 * ============================================================================
 * Screen Refresh
 * ============================================================================
 */

void editorRefreshScreen(void);

#endif /* SCREEN_H */