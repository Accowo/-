#include <stdio.h>        
#include <string.h>                 			             	          //0的ASCLL码 48  
char single_Multiplication(char a,char b,char c,char sum[],int i);
void big_number_Multiplication(char str1[],char str2[],char sum[]);	
void reverse(char sum[]);		
int main(void){
	
	char str1[40];
	char str2[40];
	char sum[41]={'\0'};
	printf("请输入number1:"); 
	scanf("%s",str1);
	printf("请输入number2:"); 
	scanf("%s",str2); 
	
 	big_number_Multiplication(str1,str2,sum);
 	
 	reverse(sum);	
 	
	printf("相加所得:%s",sum);

	
	return 0;
} 
char single_Multiplication(char a,char b,char c,char sum[],int i){
	char t=(a-48)*(b-48)+(c-48);
		sum[i]=t%10+48;
	if(t>=10){
		return t/10+48;
	}
	else{
		return '0';
	}
}	
void big_number_Multiplication(char str1[],char str2[],char sum[],char sum1[],char sum2[]){
	int len1=strlen(str1);
	int len2=strlen(str2);
	int i=0;
	int j=0;
	char c='0';

	if(len1<len2){ 
		
		for(i=0;i<len2;i++){
			c=single_Multiplication(str1[len1-1-j],str2[len2-1-i],c,sum,i);
		} 
		j++; 
		for(i=0;i<len2;i++){
			c=single_Multiplication(str1[len1-1-j],str2[len2-1-i],c,sum1,i+1);
		} 
		j++; 
		for(i=0;i<len2;i++){
			c=single_Multiplication(str1[len1-1-j],str2[len2-1-i],c,sum2,i+2);
		} 
	}
	if(c > 48){
		sum[i]=c;
	}

}
void reverse(char sum[]){
	int len=strlen(sum); 
	int i;
	char temp;
	for(i=0;i<len/2;i++){
		temp=sum[i];
		sum[i]=sum[len-i-1];
		sum[len-i-1]=temp;
	} 
}		
