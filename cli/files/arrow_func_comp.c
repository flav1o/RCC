#include <stdio.h>
#include "../../common/structs.h"

void createFile(const char *path, const char *content)
{
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
    sprintf(content, "export PropTypes{};");
    createFile(path, content);

    sprintf(path, "%s.styles.tsx", fileInfo.path);
    sprintf(content, "import { StyleSheet } from 'react-native';\n\nexport const styles = StyleSheet.create({});");
    createFile(path, content);

    return 0;
}
