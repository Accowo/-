/*3.将10名职工的数据从键盘输入， 然后送入磁盘文件worker1. rec 中保存。
设职工数据包括：职工号、职工名、性别、年龄、工资，再从磁盘调入这些数据，
依次打印出来（用 fread和fwrite函数）。*/
/*
17211164100 卡特 0 25 10000
17211164101 拉克丝 0 26 9010
17211164102 雷克塞 0 24 8020
17211164103 阿狸 0 19 7030
17211164104 塞恩 1 41 10230
17211164105 阿卡丽 0 23 11030
17211164106 阿木木 1 19 5030
17211164107 奥恩 1 40 5550
17211164108 艾克 1 22 20030
17211164109 潘森 1 30 10030
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _DEBUG

#ifdef _DEBUG
#define DEBUG(fromat,...) printf("FILE: "__FILE__";      LINE: %d;     check:"fromat"\n", __LINE__, ##__VA_ARGS__)
#else
#define DEBUG(fromat,...)
#endif

typedef struct STAFF{
	int Number_size;
	int Name_size;
    char *Number;
    char *Name;
    char Sex;
    int Age;
    int Wage;
    struct STAFF *next;
}STAFF;

STAFF *CreatList(){
    STAFF *head = (STAFF *)malloc(sizeof(STAFF));
    if (head == NULL){
        exit(0);
    }
    head->next = NULL;
    return head;
}
void Add_List(STAFF *head){
	
    STAFF *p = head;
    STAFF *pnew = (STAFF *)malloc(sizeof(STAFF));
    if (pnew == NULL){
    	printf("申请内存出错\n");
        exit(0);
    }

    while(p->next != NULL){
        p = p->next;
    }
    
    char Number[20] = {'\0'};
    char Name[20] = {'\0'};
    char Sex;
    int Age;
    int Wage;
    
    scanf("%s %s %c", Number, Name, &Sex);
	scanf("%d %d", &Age, &Wage);
	pnew->Number_size = strlen(Number) + 1;
	pnew->Name_size = strlen(Name) + 1;
	
    pnew->Number = (char *)malloc(pnew->Number_size);
    pnew->Name = (char *)malloc(pnew->Name_size);
    if (pnew->Number == NULL || pnew->Name == NULL){
    	printf("申请内存出错\n");
        exit(0);
    }
	strcpy(pnew->Number, Number);
    strcpy(pnew->Name, Name);
    pnew->Sex = Sex;
    pnew->Age = Age;
    pnew->Wage = Wage;
    
    pnew->next = NULL;
    p->next = pnew;
}

void DisplayList(STAFF *head){

	STAFF *pos = head;
	printf("\t职工号\t\t姓名\t性别\t年龄\t工资\n");
	while(pos->next != NULL){
		pos = pos->next;
		printf("\t%s\t%s\t%c", pos->Number, pos->Name, pos->Sex);
		printf("\t%d\t%d\n", pos->Age, pos->Wage);
		
		DEBUG("职工号字节空间：%d ", pos->Number_size);
		DEBUG("名字字节空间：%d\n", pos->Name_size);
	}

}
void Write_List_TO_File(STAFF *head){
	
	STAFF *p = head;
	FILE *fp = fopen("worker1.rec","w");
	if (fp == NULL){
		printf("文件打开错误!");
		exit(0);
	}
	while (p->next != NULL){
		p = p->next;
		DEBUG("%d\n", sizeof(*p));
		DEBUG("%d\n", sizeof(STAFF));
		fwrite(p, sizeof(*p), 1, fp);
	}
	fclose(fp);
}
//void Read_List_From_File(STAFF *head){
//
//	STAFF *p = head;
//    STAFF *pnew = (STAFF *)malloc(sizeof(STAFF));//临时开的
//    STAFF *pnew2 = (STAFF *)malloc(sizeof(STAFF));
//    if (pnew == NULL){
//    	printf("申请内存出错\n");
//        exit(0);
//    }
//
//    char Number[20] = {'\0'};
//    char Name[20] = {'\0'};
//
//    pnew->Number = (char *)malloc(sizeof(Number));
//    pnew->Name = (char *)malloc(sizeof(Name));
//    
//	while (1){
//		fread(pnew, sizeof(*pnew), 1, fp);
//	}
//	
//    while(p->next != NULL){
//        p = p->next;
//    }
//
//    scanf("%s %s %c", Number, Name, &Sex);
//	scanf("%d %d", &Age, &Wage);
//
//    if (pnew->Number == NULL || pnew->Name == NULL){
//    	printf("申请内存出错\n");
//        exit(0);
//    }
//	strcpy(pnew->Number, Number);
//    strcpy(pnew->Name, Name);
//    pnew->Sex = Sex;
//    pnew->Age = Age;
//    pnew->Wage = Wage;
//
//    pnew->next = NULL;
//    p->next = pnew;
//
//
//    free(pnew);
//}
int main(void){

 
    STAFF *head = CreatList();
    printf("请按顺序输入职工号 职工名 性别(0-女 1-男) 年龄 工资\n");
    int n = 10;
    while (n--){
    	Add_List(head);
	}
	Write_List_TO_File(head);
	
//	STAFF *head2 = CreatList();
//
//	Read_List_From_File(head2);
//
	DisplayList(head);


    return 0;
}
