# Program idea
encoding strings is done like this:\
aaabbccc -> (a, 3) (b, 2) (c, 3)\
and decoding strings is the exact opposite.\
to illustrate this here is a sample input/output :\
input: aaabbccc\
output: 3a2b3c -> aaabbccc
## Files
main.c, contains only main function.\
rle.h header, contains struct definitions and the declarations of encode and decode functions.\
rle.c contains the defition of encode and decode functions.

