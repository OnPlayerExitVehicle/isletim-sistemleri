#include"parser.h"
#include<string.h>

int parse(char* input, char* command, char** args)
{
	char* temp = strtok(input, " ");
	if(temp == NULL)
	{
		args[0] = temp;
		return 0;
	}
	memcpy(command, temp, sizeof(temp));
	//command[sizeof(temp)] = '\0';
	//printf("Parser command = %s\n", command);
	int res = 1;
	args[0] = temp;
	
	while(temp != NULL && res< 10)
	{
		temp = strtok(NULL, " ");
		args[res] = temp;
		if(temp == NULL)
		{
			return res;
		}
		res++;
	}
	
	temp = strtok(NULL, " ");
	args[res] = temp;
	if(temp == NULL)
	{
		return res;
	}
	
	return -1;
}
