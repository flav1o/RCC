#include "./arrow_func_comp.c"
#include "../../common/structs.h"
#include "../../common/enums.h"
#include <stdio.h>

int CreateFiles(CLI_VALUES fileInfo)
{
    if (strcmp(fileInfo.type, "arrow_component") == 0)
    {
        CreateArrowFuncFiles(fileInfo);
        printf("\n\033[1;32mCreating %s Files...\033[0m\n", fileInfo.name);
    }

    return 0;
}
