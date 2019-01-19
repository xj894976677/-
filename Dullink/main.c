#include <stdio.h>
typedef struct link{
    struct link *prior;
    char elem;
    struct link *next;
}link;

//��ʼ������
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

//����
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
    //��һ��λ��  �м�λ��   ĩβλ��   �߼��Ƿ���ͬ
    //��һ��λ��  ��λ����Ҫ����
    //�м�λ��   ǰ��ָ�����
    //ĩβλ��   ����ĩβָ��
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
//ɾ��
link *dellink(link *head){
    int addr;
    char elem;
    printf("please input elem you want to delete: ");
    fflush(stdin);
    scanf("%c",&elem);
    //ɾ��ͷ��  �м�  β��  �߼��Ƿ���ͬ
    //ɾ��ͷ��  �����׵�ַ�ı�
    //ɾ���м�  ǰ������
    //ɾ��β��  ǰnextΪ��
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

//��ѯ   �޸�
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
