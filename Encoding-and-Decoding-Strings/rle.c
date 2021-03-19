#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "rle.h"

Encoded * encode (char *text){

        int k=0;
        Encoded* word_ptr = (Encoded*)malloc(sizeof(Encoded));  
        word_ptr->length = 1;

       
        for(int i = 0 ; i < strlen(text); i++){
          if(text[k] != text[i] )

                {
                k = i;
                word_ptr->length++;
                }
           }


        


           word_ptr-> arr= (Pair**)malloc( (word_ptr->length) * sizeof(Pair*));
          
           for(int i = 0 ; i < word_ptr->length ; i++)
                    word_ptr->arr[i]=(Pair*)malloc(sizeof(Pair));

           
            int j = 0 ;
            word_ptr->arr[j]-> c = text[0];
            word_ptr->arr[j]->n = 0;

            for(int i = 0 ; i < strlen(text);i++)
            {

              if( word_ptr->arr[j]-> c == text[i])
                        word_ptr->arr[j]->n++;

              else
                {
                    j++;
                    word_ptr->arr[j]->c = text[i];
                    word_ptr->arr[j]->n++;

                }

            }



    return word_ptr;


}




char* decode (Encoded *word_encoded){

    int len= 0;
    char *decoded_word;

    for(int i = 0 ;i< word_encoded->length ; i++)
           len+=word_encoded->arr[i]->n;
        
     
        

    


   decoded_word = (char*)malloc( len * sizeof(char));

    int k = 0 ;
    for(int i= 0 ;  i< word_encoded->length ; i++)
    {
        for(int j = 0 ; j < word_encoded->arr[i]->n;j++)
               {

               decoded_word[k]=word_encoded->arr[i]->c;
               k++;
               }


    }






        return decoded_word;

}
