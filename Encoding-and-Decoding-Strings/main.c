#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rle.h"


int main()
{

    char temp_string[1000];
    printf("Enter a string:");
    scanf("%s",temp_string);

    int i = 0 ;
    while(i < strlen(temp_string) &&  temp_string[i]>= 'a' && temp_string[i]<='z')
         i++;

    if(i == strlen(temp_string)){

           encode(temp_string);
           Encoded* ptr_text = encode(temp_string);

      
       for(int i = 0 ;i< ptr_text->length;i++ )
                    printf("(%c,%d) ",ptr_text->arr[i]->c ,ptr_text->arr[i]->n);


        decode(ptr_text);
        char *orignal = decode(ptr_text);
        printf("-> %s \n",orignal);

        
        for(int i = 0 ; i< ptr_text->length ;i++ ){
                free(ptr_text->arr[i]);
            }
            free(ptr_text);
            free(orignal);




    }



else
    {

     printf("bad Input!");
        exit(0);

    }






    return 0;
}
