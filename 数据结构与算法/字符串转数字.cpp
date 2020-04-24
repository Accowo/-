#include <stdio.h>
#include <string.h>
#include <math.h>
int main(){
	
	char str[] = "2344";
	int strTOnum = 0;
	int j;
	int i;
	for (i = strlen(str) - 1; i >= 0; i--){
		j = strlen(str) - i - 1;
		
		strTOnum += (str[i] - '0') * pow(10, j);
	}
	
	printf("%d", strTOnum);
	
	return 0;
}
