#include "StringTokenizer.h"



int StringTokenizer(char *str){


	int i = 0;
	printf("\n--------------------------");
	printf("\nlength of str = %d\n", strlen(str));
	
	while(i <= strlen(str) ){
	printf("[%d],",i);
	
		if( isdigit(str[i]) )
		{
			
		printf("[%c]\n",str[i]);// currentstate = IntegerState;
		
		}else if ( isalpha(str[i] ) || str[0] == '\0' ||  str == NULL || ispunct(str[i]))
		{
			printf("Error\n");
			return -1; //error();
		
		}else if( (str[i] == ' '&& isdigit(str[i-1])) || (str[i] == '\n'&& isdigit(str[i-1]) ) ||( str[i] == '\0' && isdigit(str[i-1])  ) )
		{
			printf("Create Token\n");
			 // createIntegerToken(atoi(str));  //atoi(ptrNumberText); //convert the char to int
			
		}
		i++;
		
	}
	
	
   return 0;
}

