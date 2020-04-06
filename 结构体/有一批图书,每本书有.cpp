/*1.有一批图书,每本书有:书名(name),作者(author) , 编号(num),出版日期(date)四个数据,
希望输入后按书名的字母顺序将各书的记录排列好,供以后查询。
今输入一本书的书名，如果查询到库中有此书，打印出此书的书名,作者,编号和出版日期。
如果查不到此书,则打印出"无此书"。 */ 
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
	 
 	printf("请按顺序输入书名,作者,编号,出版日期\n"); 
    for (i = 0; i < 4; i++){
    	printf("第%d本书:\n", i+1);
 		input(p+i); 
    }   
	for (i = 0; i < 4; i++){
    	printf("第%d本书---", i+1);
 		output(p+i); 
    }   
	
	printf("按书名的字母顺序排列:\n");
	
	sort(p,4); 
	
	for (i = 0; i < 4; i++){
    	printf("第%d本书---", i+1);
 		output(p+i); 
    }   

	printf("请输入查询的书名:\n");
	scanf("%s",B); 
	
	t = find(p,4,B);
	
	if (t == -1){
		printf("无此书!");
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
	
	printf("书名:%s 作者:%s 编号:%s ", p->name, p->author, p->num);
    printf("出版日期:%d.%d.%d\n", p->Date.year, p->Date.month, p->Date.day);
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
