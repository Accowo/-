/*3.��10��ְ�������ݴӼ������룬 Ȼ����������ļ�worker1. rec �б��档
��ְ�����ݰ�����ְ���š�ְ�������Ա����䡢���ʣ��ٴӴ��̵�����Щ���ݣ�
���δ�ӡ�������� fread��fwrite��������*/
/*
17211164100 ���� 0 25 10000
17211164101 ����˿ 0 26 9010
17211164102 �׿��� 0 24 8020
17211164103 ���� 0 19 7030
17211164104 ���� 1 41 10230
17211164105 ������ 0 23 11030
17211164106 ��ľľ 1 19 5030
17211164107 �¶� 1 40 5550
17211164108 ���� 1 22 20030
17211164109 ��ɭ 1 30 10030
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define _DEBUG

#ifdef _DEBUG
#define DEBUG(fromat,...) printf("FILE: "__FILE__";      LINE: %d;     check:"fromat"\n", __LINE__, ##__VA_ARGS__)
#else
#define DEBUG(fromat,...)
#endif

typedef struct STAFF{
    char Number[20];
    char Name[20];
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
    	printf("�����ڴ����\n");
        exit(0);
    }

    while(p->next != NULL){
        p = p->next;
    }
    
    scanf("%s %s %c", pnew->Number, pnew->Name, &pnew->Sex);
	scanf("%d %d", &pnew->Age, &pnew->Wage);
    
    pnew->next = NULL;
    p->next = pnew;
}

void DisplayList(STAFF *head){

	STAFF *pos = head;
	printf("\tְ����\t\t����\t�Ա�\t����\t����\n");
	while(pos->next != NULL){
		pos = pos->next;
		printf("\t%s\t%s\t%c", pos->Number, pos->Name, pos->Sex);
		printf("\t%d\t%d\n", pos->Age, pos->Wage);
		
		DEBUG("ְ�����ֽڿռ䣺%d ", pos->Number_size);
		DEBUG("�����ֽڿռ䣺%d\n", pos->Name_size);
	}

}
void Write_List_TO_File(STAFF *head){
	
	STAFF *p = head;
	FILE *fp = fopen("worker1.rec","w");
	if (fp == NULL){
		printf("�ļ��򿪴���!");
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

void Read_List_From_File(STAFF *head){
	
	STAFF *p = head;
	FILE *fp = fopen("worker1.rec","r");
	fseek(fp, 0, SEEK_SET);
    while (!feof(fp)){
		STAFF *pnew = (STAFF *)malloc(sizeof(STAFF));
		if (pnew == NULL){
	    	printf("�����ڴ����\n");
	        exit(0);
	    }
    	fread(pnew, sizeof(*pnew), 1, fp);
		while(p->next != NULL){
		    p = p->next;
		}
		pnew->next = NULL;
		p->next = pnew;
		p = head;
	}
	fclose(fp);
}

int main(void){

//    STAFF *head = CreatList();
//    printf("�밴˳������ְ���� ְ���� �Ա�(0-Ů 1-��) ���� ����\n");
//    int n = 10;
//    while (n--){
//    	Add_List(head);
//	}
//	Write_List_TO_File(head);
//	DisplayList(head);

	STAFF *head2 = CreatList();

	Read_List_From_File(head2);

	DisplayList(head2);


    return 0;
}
