/*1.定义一个结构体其中包括: 职工号、职工名、性别、年龄、工资、地址。
按结构体类型定义一个结构体数组, 从键盘输入每个结构体元素所需的数据,
然后逐个输出这些元素的数据(可设数组只有三个元素)。*/
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
    
    printf("请按顺序输入职工号,姓名,性别,年龄,工资,地址\n"); 
    for (i = 0; i < 3; i++){
    	printf("%d号员工:\n", i+1);
        scanf("%s %s %s", sta[i].number, sta[i].name, sta[i].sex);
        scanf("%d %s %s", &sta[i].age, sta[i].wage, sta[i].addr);
    }   
    for (i = 0; i < 3; i++){
    	printf("%d号员工", i+1);
        printf("职工号:%s 姓名:%s 性别:%s ", sta[i].number, sta[i].name, sta[i].sex);
        printf("年龄:%d 工资:%s 地址:%s\n",sta[i].age, sta[i].wage, sta[i].addr);
    }   
    
    return 0; 
} 
