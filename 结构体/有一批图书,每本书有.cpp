/*1.��һ��ͼ��,ÿ������:����(name),����(author) , ���(num),��������(date)�ĸ�����,
ϣ���������������ĸ˳�򽫸���ļ�¼���к�,���Ժ��ѯ��
������һ����������������ѯ�������д��飬��ӡ�����������,����,��źͳ������ڡ�
����鲻������,���ӡ��"�޴���"�� */ 
/*abc lihua 19123 2020.3.7
sky liming 19124 2019.6.5
life lijuan 19125 2018.9.14 
world liyuanjun 19126 2019.5.17 */
#include <stdio.h>
#include <string.h> 
struct date{ 
	int year;
	int month;
	int day; 
};

struct book{ 
	char name[20]; 
	char author[20];
	char num[20];
	struct date Date; 
}; 
void input(struct book *p);
void output(struct book *p);
void sort(struct book *p, int n);
void swap(struct book *p, struct book *q);
int find(struct book *p, int n, char *B);
int main(void){
	
	struct	book Book[4],*p = Book;
	int i;
	int t;
	char B[20]; 
	 
 	printf("�밴˳����������,����,���,��������\n"); 
    for (i = 0; i < 4; i++){
    	printf("��%d����:\n", i+1);
 		input(p+i); 
    }   
	for (i = 0; i < 4; i++){
    	printf("��%d����---", i+1);
 		output(p+i); 
    }   
	
	printf("����������ĸ˳������:\n");
	
	sort(p,4); 
	
	for (i = 0; i < 4; i++){
    	printf("��%d����---", i+1);
 		output(p+i); 
    }   

	printf("�������ѯ������:\n");
	scanf("%s",B); 
	
	t = find(p,4,B);
	
	if (t == -1){
		printf("�޴���!");
	}
	else{
		output(p+t); 
	} 
	
	
	return 0;
} 
void input(struct book *p){
 
    scanf("%s %s %s", p->name, p->author, p->num);
    scanf("%d.%d.%d", &p->Date.year, &p->Date.month, &p->Date.day);
}
void output(struct book *p){
	
	printf("����:%s ����:%s ���:%s ", p->name, p->author, p->num);
    printf("��������:%d.%d.%d\n", p->Date.year, p->Date.month, p->Date.day);
}
void sort(struct book *p, int n){

	int i,j; 
	for (i = 0;i < n-1; i++){
		for (j = 0; j < n-1-i; j++){
			if (strcmp( (p+j)->name, (p+j+1)->name) == 1){
				swap(p+j,p+j+1);  
			} 
		}	
	} 
} 
void swap(struct book *p, struct book *q){
	
	struct book t;
	t = *p;
	*p = *q;
	*q = t;
}
int find(struct book *p, int n, char *B){

	int i;
	for(i = 0; i < n; i++){
		if (strcmp(B,(p+i)->name) == 0){
		 	return i;
		} 
	}
	return -1;
}
