#include "car.h"
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define MAXCHAR 1000


//The token ";" is used to make separations between lines
const char readCSV(){
	FILE *fp;
    char row[MAXCHAR];
    char *token;

    fp = fopen("requirements/Free_Test_Data_200KB_CSV-1","r");

    while ( fgets(row, MAXCHAR, fp) != EOF )
    {
        fgets(row, MAXCHAR, fp);
        printf("Row: %s", row);

        token = strtok(row, ",");

        while(token != NULL)
        {
            printf("Token: %s\n", token);
            token = strtok(NULL, ",");
        }

    }
    return NULL;
}

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

void readField(){
	char line[1024];
    while (fgets(line, 1024, stdin))
	{
		char* tmp = strdup(line);
		printf("Field 3 would be %s\n", getfield(tmp, 3));
		// NOTE strtok clobbers tmp
		free(tmp);
	}
}
