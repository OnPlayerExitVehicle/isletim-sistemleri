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
	command = temp;
	int res = i;
	args[0] = temp;
	
	while(temp != NULL && res< 11)
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