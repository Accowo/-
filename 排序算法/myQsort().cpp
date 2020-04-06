#include <stdio.h> 
#include <string.h>
void myQsort(void *array,int size,int n,int (*pfun)(void *,void *));
int cmpint(void *a,void *b);
int cmpchar(void *a,void *b);
int cmpstr1(void *a,void *b);
int cmpstr2(void *a,void *b);
void myswap(void *a,void *b,int size);
int main(void){

	int a[5]={2,3,5,4,1};
	char buf[5]={'b','c','g','f','e'};
	char src[5][5]={"bbbb","cccc","eeee","aaaa","yyyy"};
	char *src2[5]={"bbbb","cccc","eeee","aaaa","yyyy"};
	int i; 
	
	myQsort(a,sizeof(int),5,cmpint);
	for(i=0;i<5;i++){
		printf("%d ",a[i]);
	} 
	printf("\n");
	
	myQsort(buf,sizeof(char),5,cmpchar);
	for(i=0;i<5;i++){
		printf("%c ",buf[i]);
	} 
	printf("\n");
	
	myQsort(src,5,5,cmpstr1);
	for(i=0;i<5;i++){
		printf("%s ",src[i]);
	} 
	printf("\n");
	
	myQsort(src2,4,5,cmpstr2);
	for(i=0;i<5;i++){
		printf("%s ",src2[i]);
	} 
	printf("\n");
	
	return 0; 
} 
void myQsort(void *array,int size,int n,int (*pfun)(void *,void *)){
	
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(pfun(array+j*size,array+(j+1)*size) ==1){
				myswap(array+j*size,array+(j+1)*size,size);
			}
		}
	}
} 
void myswap(void *a,void *b,int size){
	
	char buf[size];
	memcpy(buf,a,size);
	memcpy(a,b,size);
	memcpy(b,buf,size);
	
}
int cmpint(void *a,void *b){

	if( *(int *)a > *(int *)b ){
		return 1; 
	} 
	else{
		return 0;
	} 
} 
int cmpchar(void *a,void *b){
	
	if( *(char *)a > *(char *)b ){
		return 1; 
	} 
	else{
		return 0;
	} 
}
int cmpstr1(void *a,void *b){	//void *ָ�����ָ���κ����� 
	
/*	//a,b��ָ�� 
	 	char (*p1)[5]=(char (*)[5])a;//��������ָ��ָ��void *��Ҫǿ������ת�� 
	char (*p2)[5]=(char (*)[5])b; 
	if(strcmp(*p1,*p2) == 1){      //strcmp�Ĳ�������ָ�� 
		return 1;
	}
	else{
		return 0;
	} 
	*/ 
	if(strcmp(*(char (*)[5])a,*(char (*)[5])b) == 1){
		return 1;
	} 
	else{
		return 0;
	}
				
}
int cmpstr2(void *a,void *b){

	if(strcmp(*(char **)a,*(char **)b)==1){
		return 1;
	} 
	else{
		return 0;
	}
} 
/*
int **p��  //����ָ��ָ���1��ָ����int *����
//1.����ָ��1��ָ��,��ָ���ָ�� 
int a =10:
int *q=&a;
p=&q;
//a==*q==**p
//&a==q==*p

//2.p����ָ���ڶ�Ӧ��ָ������
int *b[10];
p=b;         

int c[3][4];
int **p=c;//����, ��ά����Ҫ��ָ��(����ָ��---int (*p)[4])��ָ�� 

      
*/
