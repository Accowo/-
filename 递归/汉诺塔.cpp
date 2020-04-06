#include <stdio.h>
void hannuota(char a, char b, char c, int n); 
int t=0; 
int main(void){
	
	int f; 
	printf("选择层数:"); scanf("%d",&f); 
	printf("操作步骤:\n");
	hannuota('a', 'b', 'c', f); 
	
	return 0;
} 
void hannuota(char a, char b, char c, int n)
{
    if (n == 1){
        t++;
        printf("[%d]%c---->%c\n", t, a, c);
        return;
    }
    else{
        hannuota(a, c, b, n-1);
        hannuota(a, b, c, 1);
        hannuota(b, a, c, n-1);
    }
}

