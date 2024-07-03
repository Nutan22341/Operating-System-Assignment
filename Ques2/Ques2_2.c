#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void print_usage()
{
    printf("Usage: dir [-r|-v] [dir_name]\n");
}

int main(int argc, char *argv[])
{
    if (argc <= 2)
    {
        print_usage();
        exit(1);
    }
    int remove_existing = 0;
    int verbose = 0;
    char *dirname = NULL;
    // do with no. of argc
    if (argc == 3)
    {
        // rum for just file
        if (strcmp(argv[1], "dir") == 0)
        {
            dirname = argv[2];
            verbose = 0;
            remove_existing = 0;
        }
        else
        {
            printf("Error");
            exit(1);
        }
    }
    else if (argc == 4)
    {
        if (strcmp(argv[1], "dir")==0)
        {
            if (strcmp(argv[2], "-r") == 0)
            {
                remove_existing = 1;
                verbose = 0;
            }
            else if (strcmp(argv[2], "-v") == 0)
            {
                remove_existing = 0;
                verbose = 1;
            }
            else
            {
                printf("Error");
                exit(1);
            }
            dirname = argv[3];
        }
        else
        {
            printf("Error");
            exit(1);
        }
        // normal run
    }
    else if (argc == 5)
    {
        if (strcmp(argv[1], "dir") == 0)
        {
            if (strcmp(argv[2], "-r") == 0)
            {
                remove_existing = 1;
            }
            else if (strcmp(argv[2], "-v") == 0)
            {
                verbose = 1;
            }
            else
            {
                printf("Error");
                exit(1);
            }
            dirname = argv[4];
        }
        else
        {
            printf("Error");
            exit(1);
        }
        if (strcmp(argv[1], "dir") == 0)
        {
            if (strcmp(argv[3], "-r") == 0)
            {
                remove_existing = 1;
            }
            else if (strcmp(argv[3], "-v") == 0)
            {
                verbose = 1;
            }
            else
            {
                printf("Error");
                exit(1);
            }
            dirname = argv[4];
        }
        else
        {
            printf("Error");
            exit(1);
        }

        //
    }
    else
    {
        printf("Error");
        exit(1);
    }
    struct stat st;
    if (stat(dirname, &st) == 0)
    {
        if (verbose)
        {
            printf("Stored all the details about the directory in the struct stat\n");
        }
        if (remove_existing)
        {
            if (verbose)
            {
                printf("Checking if it is a valid directory\n");
            }
            if (S_ISDIR(st.st_mode))
            {
                if (verbose)
                {
                    printf("Directory is valid\n");
                }
                if (rmdir(dirname) != 0)
                {
                    perror("Error Permission denied!!!");
                    exit(1);
                }
                if (verbose)
                {
                    printf("Removed the previous directory with the same name\n");
                }
            }
            else
            {
                if (verbose)
                {
                    printf("Removed the previous directory with the same name\n");
                }
                if (unlink(dirname) != 0)
                {
                    perror("Error Permission denied!!!");
                    exit(1);
                }
            }
        }
        else
        {
            printf("Directory already exists.\n");
            exit(1);
        }
    }
    // making the directory
    int a = mkdir(dirname, 0777);
    if (a != 0)
    {
        printf("Error Creation of directory failed!!! ");
        exit(1);
    }

    if (verbose)
    {
        printf("Created directory: %s\n", dirname);
    }

    chdir(dirname);
    return 0;
}