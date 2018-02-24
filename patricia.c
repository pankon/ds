/*
 * PATRICIA trie
 *
 */

#include <string.h>
#include <stdlib.h>
#include "patricia.h"

struct patricia
{
    char *data;
    size_t bits;
    patricia_t *child;
};

patricia_t *PatriciaCreate()
{
    patricia_t *patricia = malloc(sizeof(patricia_t));
    
    if (NULL == patricia)
    {
        return (NULL);
    }
    
    patricia->data = NULL;
    patricia->bits = 0;
    patricia->child = NULL; /* everything is lazy here */

    return (patricia);
}

static int PatriciaSetString(patricia_t *patricia, const char *str)
{
    char *buffer = NULL;
    size_t len = strlen(str);
    buffer = malloc(len + 1);
    if (NULL == buffer)
    {
        PatriciaDestroy(patricia);
        return (1);
    }
    
    patricia->data = strcpy(buffer, str);
    patricia->bits = len * 8;
    
    return (0);
}

patricia_t *PatriciaCreateFromString(const char *str)
{
    patricia_t *patricia = NULL;
    if (NULL == str)
    {
        return (NULL);
    }
    
    patricia = PatriciaCreate();
    if (NULL == patricia)
    {
        return (NULL);
    }
    
    if (1 == PatriciaSetString(patricia, str))
    {
        PatriciaDestroy(patricia);
        return (NULL);
    }

    return (patricia);
}

void PatriciaDestroy(patricia_t *patricia)
{
    if (NULL == patricia)
    {
        return;
    }
    
    if (NULL != patricia->child)
    {
        PatriciaDestroy(patricia->child);
        PatriciaDestroy(patricia->child + 1);
        free(patricia->child);
        patricia->child = NULL;
    }
    
    free(patricia->data);
    patricia->data = NULL;
    patricia->bits = 0;
    
    free(patricia);
    patricia = NULL;
    
    return;    
}

int PatriciaInsert(patricia_t *patricia, const char *str)
{
    int i = 0;
    char *xor = NULL;
    if (NULL == str)
    {
        return (1);
    }
    
    if (NULL == patricia->data)
    {
        return (PatriciaSetString(patricia, str));
    }
    
    xor = malloc(patricia->bits / 8 + 1);
    if (NULL == xor)
    {
        return (1);
    }
    
    for (i = 0; patricia->bits / 8 > i && 0 != str[i]; ++i)
    {
        xor[i] = patricia->data[i] ^ str[i];
        printf("xor[%d] = 0x%x\n", i, xor[i]);
    }

    return (1);
}

int PatriciaRemove(patricia_t *patricia, const char *str)
{
    return (1);
}

int PatriciaFind(patricia_t *patricia, const char *str)
{
    return (1);
}

char** PatriciaGetAll(patricia_t *patricia)
{
    return (NULL);
}

void PatriciaEmpty(patricia_t *patricia)
{

}

