#include "../../common/structs.h"
#include <stdio.h>
#include <string.h>

CLI_VALUES DisplayMenu()
{
    CLI_VALUES cli_values;

    printf("Type: arrow_component \n");
    scanf("%s", &cli_values.type);

    printf("Path: \n");
    scanf("%s", &cli_values.path);

    printf("Name: \n");
    scanf("%s", &cli_values.name);

    return cli_values;
}

CLI_VALUES GetValuesFromArgs(int arg_size, char *args[])
{
    CLI_VALUES cli_values;

    strcpy(cli_values.type, args[1]);
    strcpy(cli_values.path, args[2]);
    strcpy(cli_values.name, args[3]);

    return cli_values;
}