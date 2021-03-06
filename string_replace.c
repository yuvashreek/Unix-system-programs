﻿/*
*  Name: Yuvashree
*  
A program in C that replaces every occurrence of a given pattern in every line of a given text file with a sequence of asterisks of the same length as the pattern .
 The output generated by the program is be sent to the standard output.


*  Bug report: “No bugs, and all the features have been implemented”  */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]){

        //initializations
        FILE *fp;
        int count=0;
        char programName[20];
        strcpy(programName, argv[0]);
        char caseSensitive[2];
        strcpy(caseSensitive, argv[1]);
        int noOfCommands = argc;
        char stringToBeReplaced[15];
        int casesense;


        //Usage feature check
        if( noOfCommands==4 && (strcmp(caseSensitive,"-i")==0) ){
                fp = fopen(argv[2],"r");
                casesense = 0;
                strcpy(stringToBeReplaced, argv[3]);

        }
        else if ( noOfCommands == 3  ){
                fp = fopen(argv[1],"r");
                casesense = 1;
                strcpy(stringToBeReplaced, argv[2]);
        }
        else {
                printf("Usage: %s [-i] <filename> <pattern> \n",programName);
                exit(1);

        }

        //checking pattern length
        while(stringToBeReplaced[count]!='\0'){
                count+=1;
                if(count>=15){
                        printf("please give pattern to be replaced below 15 characters\n");
                        exit(1);
                }
        }

        //checking file
        if(fp==NULL){
        fprintf(stderr,"Error opening file\n " );
        exit(1);
        }

        //calling function for replacing string with *
        stringReplace(fp,casesense,stringToBeReplaced);
        fclose(fp);
        return(0);
}

int stringReplace(FILE *filep, int casesense, char stringToBeReplaced[15]){
        char input[301];
        int j;
        int sizeOfStr = strlen(stringToBeReplaced);
        int incr = 0;
        char ash[sizeOfStr];

        //creating array of *
        for (incr;incr<sizeOfStr;incr++){
                ash[incr]='*';
        }

        //loop for wrinting file in input (array of char)
        while(!feof(filep)){
                int i=0;
                memset(input, 0, sizeof(input));
                fgets(input,300,filep);



        //loop exetutes till end of input
        while(input[i]!='\0'){


                int size = strlen(stringToBeReplaced);
                j=0;
                char temp[size];
                memset(temp, 0, sizeof(temp));

                //compare each char wtih first letter of given pattern
                //if there is a match next char is compared
                if( (casesense==1 &&  stringToBeReplaced[j]==input[i]) || (casesense==0 && tolower( stringToBeReplaced[j])==tolower(input[i])) ){


                        int tempcount = 0;
                        while(size>=1){
                                if(size==1){
                                        printf(ash);
                                        i+=1;
                                        break;
                                }
                                temp[tempcount]=input[i];

                                tempcount += 1;
                                i+=1;
                                j+=1;
                                size-=1;


                                //compared remaining char
                                // if all char matches with pattern, * is printed
                                if((casesense==1 && stringToBeReplaced[j]==input[i]) || (casesense==0 && tolower(stringToBeReplaced[j])==tolower(input[i]))){
                                        if(size==1){
                                                printf(ash);

                                                i+=1;
                                                break;
                                        }

                                }
                                else{
                                        printf(temp);


                                        size=0;
                                        break;
                                }

                        }

                }
                else{
                printf("%c",input[i]);
                i+=1;
                }

        }


}

        return(0);
}
