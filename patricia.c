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

static char *BufferCopy(const char *str, size_t *len)
{
    char *buffer = NULL;
    if (0 == *len) /* user requests length */
    {
        *len = strlen(str);
        buffer = malloc(*len + 1);
        if (NULL == buffer)
        {
            return (NULL);
        }
        
        return (strcpy(buffer, str));
    }
    
    /* else user sends length */
    buffer = malloc(*len + 1);
    if (NULL == buffer)
    {
        return (NULL);
    }
    
    return (strncpy(buffer, str, *len)); 
}

static int PatriciaSetString(patricia_t *patricia, const char *str)
{
    char *buffer = NULL;
    size_t len = 0;
    buffer = BufferCopy(str, &len);
    if (NULL == buffer)
    {
        PatriciaDestroy(patricia);
        return (1);
    }
    
    patricia->data = buffer;
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

static int PatriciaBranch(patricia_t *patricia, int char_idx, unsigned char data)
{
    unsigned char mask = 0x80;
    /* get n of branches and allocate an array of proper size */
    
    while (mask != 0)
    {
        if (0x0 != (mask & data))
        {
            /* copy last_i - i bits into appropriate buffer */
            printf("Branch: %d, %d\n", mask, data);
        }
        
        mask >>= 1;
    }
    
    /* create all children and string together */

    return (0); /* bad */
}

int PatriciaInsert(patricia_t *patricia, const char *str)
{
    int i = 0;
    char *xor = NULL;
    char *original = NULL; /* make a copy so data can be freely overwritten */
    size_t original_len = 0;
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
    
    original = BufferCopy(patricia->data, &original_len);
    if (NULL == original)
    {
        return (1);
    }   
    
    for (i = 0; original_len > i && 0 != str[i]; ++i)
    {
        xor[i] = original[i] ^ str[i];
        printf("xor[%d] = 0x%x\n", i, xor[i]);
        if (PatriciaBranch(patricia, i, xor[i]))
        {
            /* Only should fail if memory failure */
            return (1);
        }
    }
    
    free(original);
    original = NULL;
    free(xor);
    xor = NULL;

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

