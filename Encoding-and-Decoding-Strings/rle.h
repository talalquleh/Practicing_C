#ifndef HEADER
#define HEADER

typedef struct Pair{
char c;
unsigned int  n;

}Pair;


typedef struct Encoded {

unsigned int length ;
Pair **arr;

}Encoded;

Encoded * encode (char *text);
char* decode (Encoded *word_encoded);

#endif
