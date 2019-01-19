#include <stdio.h>
typedef struct link{
    struct link *prior;
    char elem;
    struct link *next;
}link;

//初始化链表
link *initlink(){
    link *head = (link*)malloc(sizeof(link));
    head->elem = 0;
    head->next = NULL;
    head->prior = NULL;
    printf("please input the link size: ");
    int size;
    scanf("%d",&size);
    printf("please input the 1 elem: ");
    fflush(stdin);
    scanf("%c",&head->elem);
    int i;
    link *temp = head;
    for(i = 2; i <= size; i++){
        printf("please input the %d elem: ",i);
        link *elem = (link*)malloc(sizeof(link));
        temp->next = elem;
        elem->prior = temp;
        elem->next = NULL;
        fflush(stdin);
        scanf("%c",&elem->elem);
        temp = elem;
    }
    return head;
}

//插入
link *addlink(link *head){
    char elem;
    int addr;
    printf("please input the addr and elem you want to add\n");
    scanf("%d",&addr);
    fflush(stdin);
    scanf("%c",&elem);
    link *ad = (link*)malloc(sizeof(link));
    ad->elem = elem;
    ad->next = NULL;
    ad->prior = NULL;
    //第一个位置  中间位置   末尾位置   逻辑是否相同
    //第一个位置  首位置需要更换
    //中间位置   前后指针更改
    //末尾位置   更改末尾指针
    link *temp = head;
    if(addr == 1){
        ad->next = head;
        head->prior = ad;
        head = ad;
    }else{
        int i;
        for(i = 2; i < addr; i++){
            temp = temp->next;
        }
        ad->next = temp->next;
        ad->prior = temp;
        temp->next->prior = ad;
        temp->next = ad;
    }
    return head;
}
//删除
link *dellink(link *head){
    int addr;
    char elem;
    printf("please input elem you want to delete: ");
    fflush(stdin);
    scanf("%c",&elem);
    //删除头部  中间  尾部  逻辑是否相同
    //删除头部  链表首地址改变
    //删除中间  前后相连
    //删除尾部  前next为空
    link *temp = head;
    while(temp){
        if(temp->elem == elem){
            if(temp->prior == NULL){
                temp->next->prior = NULL;
                head = temp->next;
                free(temp);
                temp = head;
            }else{
                if(temp->next == NULL){
                    temp->prior->next = NULL;
                    free(temp);
                    return head;
                }else{
                    temp->prior->next = temp->next;
                    temp->next->prior = temp->prior;
                    link *del = temp;
                    temp = temp->next;
                    free(del);
                }
            }
        }else{
            temp = temp->next;
        }
    }
    return head;
}

//查询   修改
void printlist(link *p){
    int i;
    while(p){
        printf("%c ",p->elem);
        p = p->next;
    }
    printf("\n");
}
int main()
{
    link *p = initlink();
    printlist(p);
    p = addlink(p);
    printlist(p);
    p = dellink(p);
    printlist(p);
    return 0;
}
