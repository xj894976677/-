#include <stdio.h>
typedef struct Bracke{
    char bk;
    struct Bracke *next;
}bracke;
//��ջ
bracke *push(bracke *stack,char bk){
    bracke *new = (bracke*)malloc(sizeof(bracke));
    new->bk = bk;
    new->next = stack;
    stack = new;
    return new;
}
//��ջ
bracke *pop(bracke *stack){
    if(stack->next){
        bracke *temp = stack;
        printf("��ջ%c \n",stack->bk);
        stack = stack->next;
        printf("ͷ�ڵ�%c\n",stack->bk);
        free(temp);
        return stack;
    }else{
        printf("��ջ�޷����");
        return stack->next;
    }
}
int main()
{
    bracke *left = (bracke*)malloc(sizeof(bracke));
    left->bk = 0;
    left->next = NULL;
    char ch;
        while((ch = getchar()) != '\n'){
            if(left->bk == '(' && ch == ')'){
                left = pop(left);
            }
            if(left->bk == '{' && ch == '}'){
                left = pop(left);
            }
            if(left->bk == '[' && ch == ']'){
                left = pop(left);
            }
            if(ch == '(' || ch == '{' || ch == '['){
                printf("\n����ջ %c\n",ch);
                left = push(left,ch);
            }
        }
        left = pop(left);
        if(left == NULL){
            printf("\n����ƥ��\n");
        }else{
            printf("\n���Ų�ƥ��\n");
        }
    return 0;
}
