#include <stdio.h>
#include <stdlib.h>
#include "../../common/structs.h"
#include <direct.h>

void createFile(const char *path, const char *content)
{
    char *folder = strrchr(path, '/');
    if (folder != NULL)
    {
        char *folderPath = malloc(folder - path + 1);
        strncpy(folderPath, path, folder - path);
        folderPath[folder - path] = '\0';
        _mkdir(folderPath);
        free(folderPath);
    }

    FILE *pFile = fopen(path, "w");
    fprintf(pFile, "%s", content);
    fclose(pFile);
}

int CreateArrowFuncFiles(CLI_VALUES fileInfo)
{
    char path[1024];
    char content[1024];

    sprintf(path, "%s.tsx", fileInfo.path);
    sprintf(content, "import React, {FC} from 'react';\n\nexport const %s: FC<PropTypes> = ({}) => {\n\treturn ( \n\n\t);\n}", fileInfo.name);
    createFile(path, content);

    sprintf(path, "%s.types.ts", fileInfo.path);
    sprintf(content, "export interface PropTypes {};");
    createFile(path, content);

    sprintf(path, "%s.styles.tsx", fileInfo.path);
    sprintf(content, "import { StyleSheet } from 'react-native';\n\nexport const styles = StyleSheet.create({});");
    createFile(path, content);

    return 0;
}
