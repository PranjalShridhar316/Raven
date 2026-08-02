#ifndef SCREEN_H
#define SCREEN_H

typedef struct
{
    char *buffer;
    int length;
} AppendBuffer;

#define APPEND_BUFFER_INIT {NULL, 0}

void abAppend(AppendBuffer *ab, const char *s, int len);
void abFree(AppendBuffer *ab);

void editorDrawRows(AppendBuffer *ab);
void editorDrawCursor(AppendBuffer *ab);

void editorRefreshScreen(void);

#endif