#include <stdio.h>
#include <string.h>

int isAbleToCreateFile(char path[1024], char extension[11])
{
    FILE *pFile;
    char tempPath[1024];

    strcpy(tempPath, path);
    strcat(tempPath, extension);
    pFile = fopen(tempPath, "r");

    fclose(pFile);

    return pFile == 0;
}