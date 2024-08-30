#include <stdio.h>
#include <assert.h>

// puts, strchr, strlen, strcpy, strncpy, strcat, strncat, fgets, strdup, getline

int puts(const char* str);
const char* strchr(const char* str, int symbol);
size_t strlen(const char* str);
char* strcpy(char* dest, const char* source);
char* strncpy(char* dest, const char* source, int num);
char* strcat(char* dest, const char* source);
char* strncat(char* dest, const char* source, int num);

int main(void){
    puts("Hello, world");

    char string1[] = "Hello, world";
    char string2[] = "Burn this crap";

    printf("%ld\n", strchr(string1, 'w') - string1 + 1);

    printf("%d\n", (int)strlen(string1));

    char string3[20];

    strcpy(string3, string2);
    printf("%s\n", string3);

    strncpy(string3, string2, 4);
    printf("%s\n", string3);

    strcat(string3, string2);
    printf("%s\n", string3);

    strncat(string3, string2, 6);
    printf("%s\n", string3);
}

int puts(const char* str){
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

const char* strchr(const char* str, int symbol){
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

size_t strlen(const char* str){
    assert(str != NULL);

    const char* ptr = str;

    while(*ptr != '\0'){
        //printf("%c", *ptr);
        ptr++;
    }
    return ptr - str;
}

char* strcpy(char* dest, const char* source){
    assert(dest != NULL);
    assert(source != NULL);

    const char* ptr_source = source;
    char* ptr_dest = dest;

    while (*ptr_source != '\0'){
        *ptr_dest = *ptr_source;
        ptr_source++;
        ptr_dest++;
    }
    *ptr_dest = '\0';
    return dest;
}

char* strncpy(char* dest, const char* source, int num){
    assert(dest != NULL);
    assert(source != NULL);

    char* ptr_dest = dest;

    while (*source != '\0' && num){
        *ptr_dest = *source;
        source++;
        ptr_dest++;
        num--;
    }
    *ptr_dest = '\0';
    return dest;
}

char* strcat(char* dest, const char* source){
    assert(dest != NULL);
    assert(source != NULL);

    const char* ptr_source = source;
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

char* strncat(char* dest, const char* source, int num){
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

char* fgets(char* str, int num, FILE* file){

}
