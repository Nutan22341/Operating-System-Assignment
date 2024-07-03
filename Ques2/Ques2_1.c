// for word command:--------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_usage()
{

    printf("Usage: ./CurrentFileName [-n|-d] [file_name]\n");
}
int Number_of_words(FILE *file){
    char ch;
    int words = 0;
    int characters = 0;
    while ((ch = fgetc(file)) != EOF)
    {
        characters++;
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
            words++;
    }
    if (characters > 0)
    {
        words++;
    }
    return words;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        print_usage();
        return 1;
    }
    char *filename = NULL;
    char *filename1 = NULL;

    if(argc==3){
        if(strcmp(argv[1],"-n")==0){
            
            FILE *file = NULL;
            filename = argv[2];
            file = fopen(filename,"r");
            int value = Number_of_words(file);
            printf("%d",value);
            fclose(file);
            exit(1);

        }
        else{
            print_usage();
            return 1;
        }
        
    }
    if(argc==4){
        if(strcmp(argv[1],"-d")==0){
            FILE *file = NULL;
            filename = argv[2];
            file = fopen(filename,"r");
            if(file==NULL){
                perror("Error in opening file");
                exit(1);
            }
            FILE *file1 = NULL;
            filename1 = argv[3];
        
            file1  = fopen(filename1,"r");
            if(file1==NULL){
                perror("Error in opening file");
                exit(1);
            }
            int diff = Number_of_words(file)- Number_of_words(file1);
            printf("%d",diff);
            fclose(file1);
            fclose(file);
            exit(1);
        }
        else{
            print_usage();
            return 1;
        }
    }
    else{
        print_usage();
        return 1;
    }
    return 0;
}