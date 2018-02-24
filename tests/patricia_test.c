/*
 * PATRICIA trie
 *
 */

#include <string.h>
#include <stdio.h>
#include "../patricia.h"

/* black box testing */
struct patricia
{
    char *data;
    size_t bits;
    patricia_t *child;
};

int InsertTest();
int CreateTest();

int main()
{
    int actual_value = 0;
    
    actual_value |= CreateTest();
    actual_value |= InsertTest();

    return (actual_value);
}

int CreateTest()
{
    char *word = "word";
    patricia_t *patricia = PatriciaCreate();
    if (NULL == patricia)
    {
        printf("Bad PatriciaCreate!\n");
        return (1);
    }
    
    PatriciaDestroy(patricia);
    
    patricia = PatriciaCreateFromString(word);
    if (NULL == patricia)
    {
        printf("Bad PatriciaCreateFromString!\n");
        
        return (1);
    }
    
    if (NULL == patricia->data)
    {
        printf("Bad PatriciaCreateFromString: NULL == patricia->data!\n");
        PatriciaDestroy(patricia);
        return (1);
    }
    
    if (0 != strcmp(patricia->data, word))
    {
        printf("Bad PatriciaCreateFromString: 0 != strcmp(patricia->data, word)!\n");
        PatriciaDestroy(patricia);
        return (1);
    }
    
    if (strlen(word) * 8 != patricia->bits)
    {
        printf("Bad PatriciaCreateFromString: strlen(word) * 8 != patricia->bits!\n");
        PatriciaDestroy(patricia);
        return (1);
    }
    
    PatriciaDestroy(patricia);
    
    return (0);
}

int InsertTest()
{
    char *word = "word";
    patricia_t *patricia = PatriciaCreate();
    
    if (NULL == patricia)
    {
        printf("Bad PatriciaCreate!\n");
        return (1);
    }
    
    if (PatriciaInsert(patricia, word))
    {
        printf("Bad PatriciaInsert!\n");
        PatriciaDestroy(patricia);
        return (1);
    }
    
    PatriciaDestroy(patricia);
    
    return (0);
}
