#include <stdio.h>
typedef struct Bracke{
    char bk;
    struct Bracke *next;
}bracke;
//入栈
bracke *push(bracke *stack,char bk){
    bracke *new = (bracke*)malloc(sizeof(bracke));
    new->bk = bk;
    new->next = stack;
    stack = new;
    return new;
}
//出栈
bracke *pop(bracke *stack){
    if(stack->next){
        bracke *temp = stack;
        printf("出栈%c \n",stack->bk);
        stack = stack->next;
        printf("头节点%c\n",stack->bk);
        free(temp);
        return stack;
    }else{
        printf("空栈无法输出");
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
                printf("\n左入栈 %c\n",ch);
                left = push(left,ch);
            }
        }
        left = pop(left);
        if(left == NULL){
            printf("\n括号匹配\n");
        }else{
            printf("\n括号不匹配\n");
        }
    return 0;
}
