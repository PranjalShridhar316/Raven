/*
 * ============================================================================
 * Raven Editor
 * File        : row.c
 * Description : Row management.
 * ============================================================================
 */

#include <stdlib.h>

#include "row.h"

/*
 * Initialize one row.
 */
void rowInit(EditorRow *row)
{
    row->size = 0;
    row->chars = NULL;
}

/*
 * Free one row.
 */
void rowFree(EditorRow *row)
{
    free(row->chars);

    row->chars = NULL;
    row->size = 0;
}