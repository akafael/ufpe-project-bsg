#include "car.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


//The token ";" is used to make separations between lines
const char* getfield(char* line, int num)
{
	const char* tok;
	for (tok = strtok(line, ";");
			tok && *tok;
			tok = strtok(NULL, ";\n"))
	{
		if (!--num)
			return tok;
	}
	return NULL;
}

void readCSV(){
    Car line[1024];
    while (fgets(line, 1024, stdin))
	{
		char* tmp = strdup(line);
		printf("Car Data: %s\n", getfield(tmp, 1));
		// NOTE strtok clobbers tmp
		free(tmp);
	}
}