/*1.����һ���ṹ�����а���: ְ���š�ְ�������Ա����䡢���ʡ���ַ��
���ṹ�����Ͷ���һ���ṹ������, �Ӽ�������ÿ���ṹ��Ԫ�����������,
Ȼ����������ЩԪ�ص�����(��������ֻ������Ԫ��)��*/
#include <stdio.h>
struct staff{
    char number[10];
    char name[20];
    char sex[3];
    int age;
    char wage[10];
    char addr[10];
};
int main(void){

    struct staff sta[3];
    int i;
    
    printf("�밴˳������ְ����,����,�Ա�,����,����,��ַ\n"); 
    for (i = 0; i < 3; i++){
    	printf("%d��Ա��:\n", i+1);
        scanf("%s %s %s", sta[i].number, sta[i].name, sta[i].sex);
        scanf("%d %s %s", &sta[i].age, sta[i].wage, sta[i].addr);
    }   
    for (i = 0; i < 3; i++){
    	printf("%d��Ա��", i+1);
        printf("ְ����:%s ����:%s �Ա�:%s ", sta[i].number, sta[i].name, sta[i].sex);
        printf("����:%d ����:%s ��ַ:%s\n",sta[i].age, sta[i].wage, sta[i].addr);
    }   
    
    return 0; 
} 
