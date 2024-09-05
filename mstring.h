#ifndef MSTRING_FILE
#define MSTRING_FILE

const int BUFFER_SIZE = 64;

int mputs(const char* str);
const char* mstrchr(const char* str, int symbol);
size_t mstrlen(const char* str);
char* mstrcpy(char* dest, const char* source);
char* mstrncpy(char* dest, const char* source, size_t num);
char* mstrcat(char* dest, const char* source);
char* mstrncat(char* dest, const char* source, size_t num);
char* mfgets(char* str, size_t num, FILE* file);
char* mstrdup(const char* str);
size_t mgetline(char** line_pnt, size_t* buffer_cap, FILE* file);
void moveBuffer(char* dest, const char* src, size_t* num, size_t add);

#endif
