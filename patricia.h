/*
 * PATRICIA trie
 *
 */

#include <stdio.h>

#ifndef __PATRICIA_H__
#define __PATRICIA_H__

typedef struct patricia patricia_t;

patricia_t *PatriciaCreate();
patricia_t *PatriciaCreateFromString(const char *str);
void PatriciaDestroy(patricia_t *patricia);

int PatriciaInsert(patricia_t *patricia, const char *str);
int PatriciaRemove(patricia_t *patricia, const char *str);
int PatriciaFind(patricia_t *patricia, const char *str);

char** PatriciaGetAll(patricia_t *patricia);
void PatriciaEmpty(patricia_t *patricia);

#endif /* __PATRICIA_H__ */
