#include <stdio.h>
typedef struct Linklist{
    char ch;//������
    struct Linklist *next;//����ָ��
}link;
//��ʼ������   ����ֵ������õ������׵�ַ
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
        fflush(stdin);          //������뻺����
        scanf("%c",&ch);
        temp->next = (link*)malloc(sizeof(link));
        temp = temp->next;
        temp->ch = ch;
        temp->next = NULL;
    }
    return p;
}

//�������
void printlist(link *p){
    int i;
    while(p->next){
        p = p->next;
        printf("%c ",p->ch);
    }
    printf("\n");
}
//����  ��������������λ�ã���������
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
            printf("λ�ô���");
            return p;
        }
    }
    link *add = (link*)malloc(sizeof(link));
    add->next = temp->next;
    temp->next = add;
    add->ch = elem;
    return p;
}
//ɾ�� ����������  ɾ��λ��   ����ֵ������
link *dellist(link *p){
    int addr;
    printf("please input the addrss you want to delete: ");
    scanf("%d",&addr);
    int i;
    link *temp = p;
    for(i = 1; i < addr; i++){
        temp = temp ->next;
        if(temp->next == NULL){
            printf("λ�ô���");
            return p;
        }
    }
    link *f = temp->next;
    temp->next = temp->next->next;
    free(f);      //ע��Ҫ���ͷ��ڴ棬��Ȼtemp->next Ϊ���޷���ֵ
    return p;
}
//�޸�  ����������  �޸�λ��   �޸�ֵ   ����ֵ������
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
        printf("λ�ô���");
        return p;
    }
    for(i = 1; i <= addr; i++){
        temp = temp->next;
        if(temp->next == NULL){
            printf("λ�ô���");
            return p;
        }
    }
    temp->ch = elem;
    return p;

}
//����    ����������   λ��   �����ͣ�����
link *inquirylist(link *p){
    int addr;
    printf("please input addr you want to inquiry: ");
    scanf("%d",&addr);
    int i;
    link *temp = p;
    if(temp->next == NULL){
        printf("λ�ô���");
        return p;
    }
    for(i = 1; i <= addr; i++){
        temp = temp->next;
        if(temp->next == NULL){
            printf("λ�ô���");
            return p;
        }
    }
    printf("%c\n",temp->ch);
    return p;
}

int main()
{
    link *link = initlink();  //��ʼ��
    printlist(link);
    link = addlist(link);     //����
    printlist(link);
    link = dellist(link);     //ɾ��
    printlist(link);
    changelist(link);        //�޸�
    printlist(link);
    inquirylist(link);       //����
    printlist(link);
    return 0;
}
