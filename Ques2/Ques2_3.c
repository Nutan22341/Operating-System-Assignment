#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

void print_usage() {
    printf("Usage: date [-d|-R] [file_name]\n");
    printf("-d : display time described by STRING\n");
    printf("-R : output date and time in RFC 5322 format\n");
}

int is_valid_option(char *arg) {
    return (strcmp(arg, "-d") == 0 || strcmp(arg, "-R") == 0);
}

int file_exists(char *filename) {
    struct stat file_stat;
    return (stat(filename, &file_stat) == 0);
}

void display_time(char *filename) {
    struct stat file_stat;
    if (stat(filename, &file_stat) != 0) {
        perror("Error");
        return;
    }
    printf("Last modified time: %s", ctime(&file_stat.st_mtime));
}

void display_rfc_format(char *filename) {
    struct stat file_stat;
    if (stat(filename, &file_stat) != 0) {
        perror("Error");
        return;
    }
    struct tm *tm_info;
    tm_info = localtime(&file_stat.st_mtime);
    char rfc_buffer[80];
    strftime(rfc_buffer, sizeof(rfc_buffer), "%a, %d %b %Y %H:%M:%S %z", tm_info);
    printf("RFC 5322 format: %s\n", rfc_buffer);
}

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3 || !is_valid_option(argv[1])) {
        print_usage();
        return 1;
    }

    char *target_filename;
    switch (argc) {
        case 2:
            target_filename = argv[1];
            break;
        case 3:
            target_filename = argv[2];
            break;
    }

    switch (argv[1][1]) {
        case 'd':
            display_time(target_filename);
            break;
        case 'R':
            display_rfc_format(target_filename);
            break;
    }

    return 0;
}
