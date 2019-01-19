#include <stdio.h>
typedef struct Linklist{
    char ch;//数据域
    struct Linklist *next;//后置指针
}link;
//初始化链表   返回值：构造好的链表首地址
link *initlink(){
    int i,length;
    char ch;
    printf("please input link length: ");
    scanf("%d",&length);
    link *temp = (link*)malloc(sizeof(link));
    link *p = temp;
    temp->next = NULL;
    for(i = 1; i <= length; i++){
        printf("please input list %d elem:",i);
        fflush(stdin);          //清空输入缓冲区
        scanf("%c",&ch);
        temp->next = (link*)malloc(sizeof(link));
        temp = temp->next;
        temp->ch = ch;
        temp->next = NULL;
    }
    return p;
}

//输出链表
void printlist(link *p){
    int i;
    while(p->next){
        p = p->next;
        printf("%c ",p->ch);
    }
    printf("\n");
}
//插入  参数：链表，增加位置，增加数据
link *addlist(link *p){
    link *temp = p;
    int addr;
    char elem;
    printf("please input addr and elem you want to add:\n");
    printf("addr: ");
    scanf("%d",&addr);
    fflush(stdin);
    printf("elem: ");
    scanf("%c",&elem);
    int i;
    for(i = 1; i < addr; i++){
        temp = temp->next;
        if(temp->next == NULL){
            printf("位置错误");
            return p;
        }
    }
    link *add = (link*)malloc(sizeof(link));
    add->next = temp->next;
    temp->next = add;
    add->ch = elem;
    return p;
}
//删除 参数：链表  删除位置   返回值：链表
link *dellist(link *p){
    int addr;
    printf("please input the addrss you want to delete: ");
    scanf("%d",&addr);
    int i;
    link *temp = p;
    for(i = 1; i < addr; i++){
        temp = temp ->next;
        if(temp->next == NULL){
            printf("位置错误");
            return p;
        }
    }
    link *f = temp->next;
    temp->next = temp->next->next;
    free(f);      //注意要后释放内存，不然temp->next 为空无法赋值
    return p;
}
//修改  参数：链表  修改位置   修改值   返回值：链表
link *changelist(link *p){
    link *temp = p;
    int addr;
    char elem;
    printf("please input addr and elem you want to change:\n");
    printf("addr: ");
    scanf("%d",&addr);
    fflush(stdin);
    printf("elem: ");
    scanf("%c",&elem);
    int i;
    if(temp->next == NULL){
        printf("位置错误");
        return p;
    }
    for(i = 1; i <= addr; i++){
        temp = temp->next;
        if(temp->next == NULL){
            printf("位置错误");
            return p;
        }
    }
    temp->ch = elem;
    return p;

}
//查找    参数：链表   位置   返回型：链表
link *inquirylist(link *p){
    int addr;
    printf("please input addr you want to inquiry: ");
    scanf("%d",&addr);
    int i;
    link *temp = p;
    if(temp->next == NULL){
        printf("位置错误");
        return p;
    }
    for(i = 1; i <= addr; i++){
        temp = temp->next;
        if(temp->next == NULL){
            printf("位置错误");
            return p;
        }
    }
    printf("%c\n",temp->ch);
    return p;
}

int main()
{
    link *link = initlink();  //初始化
    printlist(link);
    link = addlist(link);     //增加
    printlist(link);
    link = dellist(link);     //删除
    printlist(link);
    changelist(link);        //修改
    printlist(link);
    inquirylist(link);       //查找
    printlist(link);
    return 0;
}
