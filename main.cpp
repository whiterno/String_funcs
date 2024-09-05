#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "mstring.h"

// puts, strchr, strlen, strcpy, strncpy, strcat, strncat, fgets, strdup, getline

int main(void){
    mputs("Hello, world");

    char string1[] = "Hello, world";
    char string2[] = "Burn this crap";

    printf("%ld\n", mstrchr(string1, 'w') - string1 + 1);

    printf("%d\n", (int)mstrlen(string1));

    char string3[20];

    mstrcpy(string3, string2);
    printf("%s\n", string3);

    mstrncpy(string3, string2, 4);
    printf("%s\n", string3);

    mstrcat(string3, string2);
    printf("%s\n", string3);

    mstrncat(string3, string2, 6);
    printf("%s\n", string3);

    char string4[20];
    mfgets(string4, 20, stdin);
    printf("%s\n", string4);

    char* string5 = mstrdup("Hello, John!");
    printf("%s\n", string5);

    char* buff = NULL;
    size_t buff_cap = 0;
    mgetline(&buff, &buff_cap, stdin);
    printf("%s\n", buff);
}

int mputs(const char* str){
    if (str == NULL){
        return EOF;
    }

    const char* ptr = str;

    while (*ptr != '\0'){
        putchar(*(ptr++));
    }
    putchar('\n');
    return '\n';
}

const char* mstrchr(const char* str, int symbol){
    assert(str != NULL);

    const char* ptr = str;

    while(*ptr != '\0'){
        if (*ptr == symbol){
            return ptr;
        }
        ptr++;
    }
    return NULL;
}

size_t mstrlen(const char* str){
    assert(str != NULL);

    const char* ptr = str;

    while(*ptr != '\0'){
        ptr++;
    }
    return ptr - str;
}

char* mstrcpy(char* dest, const char* source){
    assert(dest != NULL);
    assert(source != NULL);

    char* ptr_dest = dest;

    while (*source != '\0'){
        *ptr_dest = *source;
        source++;
        ptr_dest++;
    }
    *ptr_dest = '\0';
    return dest;
}

char* mstrncpy(char* dest, const char* source, size_t num){
    assert(dest != NULL);
    assert(source != NULL);

    char* ptr_dest = dest;

    while (*source != '\0' && num){
        *ptr_dest = *source;
        source++;
        ptr_dest++;
        num--;
    }
    if (num != 0){
        while (num--){
            *ptr_dest = '\0';
            ptr_dest++;
        }
    }
    return dest;
}

char* mstrcat(char* dest, const char* source){
    assert(dest != NULL);
    assert(source != NULL);

    char* ptr_dest = dest;

    while (*ptr_dest != '\0'){
        ptr_dest++;
    }
    while (*source != '\0'){
        *ptr_dest = *source;
        ptr_dest++;
        source++;
    }
    *ptr_dest = '\0';
    return dest;
}

char* mstrncat(char* dest, const char* source, size_t num){
    assert(dest != NULL);
    assert(source != NULL);

    const char* ptr_source = source;
    char* ptr_dest = dest;

    while (*ptr_dest != '\0'){
        ptr_dest++;
    }
    while (*source != '\0' && num){
        *ptr_dest = *source;
        ptr_dest++;
        source++;
        num--;
    }
    *ptr_dest = '\0';
    return dest;
}

char* mfgets(char* str, size_t num, FILE* file){
    assert(str);
    assert(file);

    int character = 0;
    char* pnt_str = str;

    while ((character = getc(file)) != EOF && (num - 1)){
        if (character == '\n'){
            *pnt_str = '\n';
            pnt_str++;
            break;
        }
        *pnt_str = character;
        pnt_str++;
        num--;
    }

    if (pnt_str == str){
        return NULL;
    }
    *pnt_str = '\0';
    return str;
}

char* mstrdup(const char* str){
    assert(str);

    char* pnt = (char*)calloc(mstrlen(str) + 1, sizeof(char));
    mstrcpy(pnt, str);

    return pnt;
}

size_t mgetline(char** line_pnt, size_t* buffer_cap, FILE* file){
    assert(buffer_cap);
    assert(file);

    int character = 0;
    size_t counter = 0;
    char add_buffer[BUFFER_SIZE];

    if (*line_pnt == NULL){
        *line_pnt = (char*)calloc(0, sizeof(char));
        *buffer_cap = 0;
    }

    while ((character = getc(file)) != EOF){
        add_buffer[counter % BUFFER_SIZE] = character;
        counter++;
        if (counter % BUFFER_SIZE == 0){
            moveBuffer(*line_pnt, add_buffer, buffer_cap, BUFFER_SIZE);
        }
        if (character == '\n'){
            break;
        }
    }
    if (counter % BUFFER_SIZE != 0){
        moveBuffer(*line_pnt, add_buffer, buffer_cap, counter % BUFFER_SIZE);
    }
    void* res = realloc(*line_pnt, ++*buffer_cap);
    *(*line_pnt + *buffer_cap - 1) = '\0';

    return counter;
}

void moveBuffer(char* dest, const char* src, size_t* num, size_t add){
    assert(dest);
    assert(src);
    assert(num);

    *num += add;
    void* res = realloc(dest, *num);
    mstrncpy(dest + *num - add, src, add);
}
