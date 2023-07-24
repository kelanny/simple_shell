#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char **_arg_parser(char *lineptr);
void start_process(char **args);
#endif
