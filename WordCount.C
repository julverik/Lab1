#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{

    FILE *filename = fopen(argv[2], "r");
    if (argc != 3)
    {
        printf("You have entered incorrect count of arguments");
        return -1;
    }

    if (filename == 0)
    {
        printf("This file does not exist");
        return -1;
    }

    int lines = 1, bytes = 0, words = 0;
    int option = 0;
    char symbol;

    if (strcmp(argv[1], "-l") == 0 || strcmp(argv[1], "--lines") == 0)
        option = 1;

    if (strcmp(argv[1], "-c") == 0 || strcmp(argv[1], "--bytes") == 0)
        option = 2;

    if (strcmp(argv[1], "-w") == 0 || strcmp(argv[1], "--words") == 0)
        option = 3;

    switch (option)
    {
    case 1:
    {
        if ((symbol = fgetc(filename)) == EOF)
        {
            printf("%d", lines - 1);
            fclose(filename);
            break;
        }
        else
        {
            while ((symbol = fgetc(filename)) != EOF)
                if (symbol == '\n')
                    lines++;
            printf("%d", lines);
            fclose(filename);
            break;
        }
    }

    case 2:
    {
        fseek(filename, 0, SEEK_END);
        bytes = ftell(filename);
        printf("%d", bytes);
        fclose(filename);
        break;
    }

    case 3:
    {

        int inside, outside;
        inside = 1;
        outside = 0;
        int checkword = outside;

        while ((symbol = fgetc(filename)) != EOF)
            if (symbol == ' ' || symbol == '\n')
                checkword = outside;
            else if (checkword == outside)
            {
                checkword = inside;
                words++;
            }

        printf("%d", words);
        fclose(filename);
        break;
    }
    }
}
