#include <stdio.h>
typedef struct stu{
    char name[20];
    char sex[3];
    int age;
    char phone[15];
    char addr[10];
}Stu,*Pstu;
struct stu arr[100],Temp,null,see[100];
int i = 0;
int Print(){
    printf("*********************************************\n");
    printf("****** 1.���                   2.ɾ�� ******\n");
    printf("****** 3.����                   4.�޸� ******\n");
    printf("****** 5.��ʾ                   6.��� ******\n");
    printf("****** 7.����                   0.�˳� ******\n");
    printf("*********************************************\n");
    printf("��ѡ��");
    int text=0;
    scanf("%d",&text);
    switch (text) {
        case 1 :
            add();
            break;
        case 2 :
            del();
            break;
        case 3 :
            find();
            break;
        case 4 :
            change();
            break;
        case 5 :
            Print2();
            break;
        case 6 :
            delall();
            break;
        case 7 :
            sorting();
            break;
        case 0 :
            Print();
            break;
        default:
            printf("ָ�����\n");
            Print();
    }
    return 0;
}
int delall(){
    int k = 0;
    for(k = 0;k < i;k++){
        arr[k] = null;
    }
    i = 0;
    Print();
}
int change(){
    char name[20];
    char cname[20];
    char sex[3];
    int age;
    char phone[10];
    char addr[20];
    printf("������Ҫ���ĵ���ϵ�˵�������");
    scanf("%s",name);
    int k,m = 0;
    for(k = 0;k < i;k++){
        if(strcmp(arr[k].name,name) == 0){
            printf("name:");
            scanf("%s",arr[k].name);
            printf("sex:");
            scanf("%s",arr[k].sex);
            printf("age:");
            scanf("%d",&arr[k].age);
            printf("phone:");
            scanf("%s",arr[k].phone);
            printf("addr:");
            scanf("%s",arr[k].addr);
            m = 1;
        }
    }
    if(m == 0){
        printf("��������\n");
        Print();
    }
    printf("�޸ĳɹ�");
    Print();
    return 0;
}
int find(){
    char fin[20];
    printf("�������������в�ѯ��");
    scanf("%s",fin);
    int k,m = 0;
    for(k = 0;k < i;k++){
        if(strcmp(arr[k].name,fin) == 0){
            printf("name:%-15s sex:%-15s age:%-15d phone:%-15s addr:%-15s\n",arr[k].name,arr[k].sex,arr[k].age,arr[k].phone,arr[k].addr);
            m = 1;
        }
    }
    if(m = 0){
        printf("�޴���ϵ��");
        Print();
    }
    Print();
    return 0;
}
int sorting(){
    int j,k,m;
    for(j = 0;j < i - 1;j++){
        for(k = 0;k < i - j - 1;k++){
            m = 0;
            if(arr[k].age > arr[k + 1].age){
                Temp = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = Temp;
                m = 1;
            }
        }
        if(m == 0){
            break;
        }
    }
    Print();
    return 0;
}
int Print2(){
    int k = 0;
    for(k = 0;k < i;k++){
        printf("name:%-15s sex:%-15s age:%-15d phone:%-15s addr:%-15s\n",arr[k].name,arr[k].sex,arr[k].age,arr[k].phone,arr[k].addr);
    }
    Print();
    return 0;
}
int del(){
    char name[20];
    printf("������Ҫɾ���˵�����:");
    scanf("%s",name);
    int j=0;
    for(j = 0;j < i;j++){
        if(strcmp(arr[j].name,name) == 0){
            printf("NO");
            int k = j;
            for(k = j;k < i;k++){
                arr[k] = arr[k+1];
            }
            arr[k] = null;
            break;
        }
    }
    --i;
    printf("ɾ���ɹ�\n");
    Print();
    return 0;
}
int add(){
    char name[20];
    char sex[3];
    int age;
    char phone[10];
    char addr[20];
    printf("name:");
    scanf("%s",arr[i].name);
    printf("sex:");
    scanf("%s",arr[i].sex);
    printf("age:");
    scanf("%d",&arr[i].age);
    printf("phone:");
    scanf("%s",arr[i].phone);
    printf("addr:");
    scanf("%s",arr[i].addr);
    ++i;
    printf("��ӳɹ�\n");
    Print();
    return 0;
}
int main()
{
    Print();
    return 0;
}
