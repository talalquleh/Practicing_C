#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct
{
    char name[30];
    char type;
    int kg;
    int exc;
}info;

int size=1;



int main(){

char choice ;
info **pass=(info**)malloc(sizeof(info*));


do
{

printf("------------------------------------------------------------------------\n");
printf("A: add new passenger\n");
printf("Q: stop the program\n");
printf("L: list the passengers on the database\n");
printf("D: delete a passenger from the database\n");
printf("------------------------------------------------------------------------\n");
printf("the current number of passengers on database is %d\n",size-1);
printf("--> choose from the menu [case insensitive] :");
scanf("%s",&choice);  


switch(choice)
{
        case 'q':
        case 'Q':
                  printf("//////////////////================================//////////////////////\n");
                    printf("--> goodbye,hope to see you again :)\n");
                    for(int i= 1 ; i <= size-1 ; i++)
                            free(pass[i]);

                    free(pass);
                    exit(0);

        case 'a':
        case 'A':
             printf("//////////////////================================//////////////////////\n");
             printf("Enter passenger info\n");
            size++;
            pass=realloc(pass,size*sizeof(info*));
            pass[size-1]=malloc(sizeof(info));
            printf("Enter the name : ");
            scanf("%s",pass[size-1]->name);
            printf("Enter the class (F,B,E) [case insensitive] : ");
            scanf("\n");
            scanf("%c",&pass[size-1]->type);
           
            switch (pass[size-1]->type)
                        {
                        case 'f':
                        case 'F':
                                    printf("Enter baggage weight (limit.30kg): ");
                                    scanf("%d",&pass[size-1]->kg);
                               
                                    if(pass[size-1]->kg>30)    pass[size-1]->exc=pass[size-1]->kg-30;
                                    printf("--> data read successfully\n");
                                    break;

                        case 'b':
                        case 'B':
                                   printf("Enter baggage weight (limit.25kg): ");
                                    scanf("%d",&pass[size-1]->kg);
                                   
                                    if(pass[size-1]->kg>25)   pass[size-1]->exc = pass[size-1]->kg-25;
                                    printf("--> data read successfully\n");
                                    break;
                        case 'e':
                        case 'E':
                                   printf("Enter baggage weight (limit.20kg): ");
                                    scanf("%d",&pass[size-1]->kg);
                                    if(pass[size-1]->kg>20)     pass[size-1]->exc=pass[size-1]->kg-20;
                                   printf("--> data read successfully\n");
                                    break;
                        
                        default:
                                    size--;
                                    printf("invalid class\n");
                                    printf("--> back to the menu\n");
                                    pass=realloc(pass,size*sizeof(info*));
                                    break;
                                
                                
                        }
                    
                    break;
               
            
            case 'l':
            case 'L':
                        printf("//////////////////================================//////////////////////\n");
                        if(size==1)     printf("there are no passengers on the list yet\n");
                        else
                        {
                        printf("Passengers stored in the base are:\n");
                        for(int i = 1; i <= size-1 ; i++)
                                printf("Passenger: %s \t Extra Baggage : %d kg \t Additional fees: %d USD \n",pass[i]->name,pass[i]->exc,pass[i]->exc*10);
                        } 
                        break;
                    
        case'd':
        case'D':
                    printf("//////////////////================================//////////////////////\n");
                printf("Enter the name you want to delete:");
                char t_name[30];
                scanf("%s",t_name);
                int j = 1 ;
                while(j<=size-1 && strcmp(t_name, pass[j]->name)!=0)
                            j++;
                
                if(j>size-1)     printf("the name '%s' is not found in the database\n",t_name);
                else
                {
                    
                 printf("the passenger '%s'  succesfully deleted from the database\n",pass[j]->name);
                    for(int i =  j ; i+1<=size-1 ; i++ )
                    {
                        strcpy(pass[i]->name,pass[i+1]->name);
                        pass[i]->kg=pass[i+1]->kg;
                        pass[i]->exc=pass[i+1]->exc;
                    }
                    free(pass[size-1]);
                    size--;
                    pass=realloc(pass,size*sizeof(info));
                }
               
                break;
                


        default:
             printf("//////////////------------//////////////////////\n");
            printf("--> invalid type entered\n");
            printf("--> try again\n");
            break;



}

} while (1);

    return 0 ; 
}
