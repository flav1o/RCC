#include "./common/structs.h"
#include "./cli/verifications/files.c"
#include "./cli/menu/menu.c"
#include "./cli/files/files.c"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    CLI_VALUES cli_values;
    FILE *pFile;
    char extensions[4][11] = {".types.ts",
                              ".tsx",
                              ".styles.ts",
                              ".service.ts"};

    if (argc <= 3)
        cli_values = DisplayMenu();

    if (argc >= 4)
        cli_values = GetValuesFromArgs(argc, argv);

    for (int i = 0; i < 4; i++)
    {
        int isAble = isAbleToCreateFile(cli_values.path, extensions[i]);

        if (!isAble)
        {
            printf("\033[1;31mThis files already exist\033[0m\n");
            return 0;
        }
    }

    CreateFiles(cli_values);

    return 0;
}
