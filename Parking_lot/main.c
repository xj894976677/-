#include <stdio.h>
/*
ģ��һ��ͣ����������֮����ջ
*/
typedef struct Stack{
    int addr;
    int time;
    struct Stack *next;
}stack;

//ͣ����ջ�ĳ�ʼ��
stack *initstack(){
    stack *head = (stack*)malloc(sizeof(stack));
    head->next = NULL;
}

//��ջ   α��ջ  ����Ϊ�ڵ�ͷ�ڵ㣺�ڵ㣻
stack *pushstack(stack *head,int time,int addr){
    stack *temp = (stack*)malloc(sizeof(stack));
    temp->addr = addr;
    temp->time = time;

    temp->next = head->next;
    head->next = temp;
    return head;
}

stack *fakewaitpush(stack *head, stack *temp){
    temp->next = head->next;
    head->next = temp;
    return head;
}
stack *fakestackpush(stack *head,stack *temp){
    temp->addr -= 1;
    temp->next = head->next;
    head->next = temp;
    return head;
}

//��ջ    ��ջ��Ϊ���֣�һ�����ջ���뿪ͣ������һ��α��ջ�����ͷſռ䣬����ֵΪ�ýڵ�
stack *popstack(stack *head,int time){
    stack *temp = head->next;
    printf("λ��%d�����뿪��Ӧ�շ�%dԪ \n",temp->addr,10*(time - temp->time));
    head->next = temp->next;
    free(temp);
    return head;
}

stack *fakestackpop(stack *head){
    stack *temp = head->next;
    head->next = temp->next;
    temp->next = NULL;
    return temp;
}
stack *fakewaitpop(stack *head){
    stack *temp = head->next;
    head->next = temp->next;
    return temp;
}
//����  ����β�ڵ�
stack *pushpueue(stack *rear,int addr){
    stack *temp = (stack*)malloc(sizeof(stack));
    rear->next = temp;
    temp->next = NULL;
    temp->addr = addr;
    return temp;
}
//����  �����׽ڵ�  α����  ��������ֵ
stack *poppueue(stack *front){
    stack *temp = front->next;
    front->next = temp->next;
    printf("����%d  ���복��\n",temp->addr);
    return temp;
}

void print(stack *parking, stack *front){
    printf("��ǰͣ����: \n");
    while(parking->next){
        parking = parking->next;
        printf("��λ�ã�%d   ��ʼʱ�䣺%d\n",parking->addr,parking->time);
    }

    int linenum = 0;
    while(front->next){
        ++linenum;
        front = front->next;
    }
    printf("��ǰ�ȴ����У�%d\n",linenum);
}
int main()
{
    int max = 5; //ͣ�����������5̨��
    int now = 0; //ͣ�������г���
    int line = 0; //�Ŷ�����
    stack *parking = initstack();//��ʼ��ͣ����
    stack *pue = initstack();//��ʼ������β��
    stack *front = pue; //��ʼ������ͷ�ڵ�
    stack *wait = initstack();//��ʼ���ȴ�ջ
    while(printf("��ѡ��:\n1-����ͣ������2-�뿪ͣ����, 3-��ʾ��ǰ����,0-�˳�ϵͳ\n")){
        int change;
        scanf("%d",&change);
        if(change == 0){
            return 0;
        }
        if(change == 1){
            if(now == 5){
                printf("ͣ���������������ŶӶ��еȺ�\n");
                ++line;
                pue = pushpueue(pue,line);
            }
            if(now != 5){
                printf("������ͣ����ʼʱ��: ");
                int time;
                scanf("%d",&time);
                ++now;
                pushstack(parking,time,now);
            }
        }
        if(change == 2){
            //����һ��������ĳ�ջ������ȴ�ջ��Ȼ������ջ��Ȼ����г���һ����ջ
            printf("�뿪����λ�ã�");
            int num;
            int leavetime;
            scanf("%d",&num);
            printf("�뿪��ʱ��:");
            scanf("%d",&leavetime);
            if(line == 0){
                int i;
                for(i = now; i > num; i--){
                    //α��ջ
                    stack *temp = fakestackpop(parking);
                    //α��ջ  ����ȴ�ջ
                    wait = fakewaitpush(wait,temp);
                }
                parking = popstack(parking,leavetime);   //���ջ
                for(i = now; i > num; i--){
                    //α��ջ
                    stack *temp = fakewaitpop(wait);
                    //α��ջ  ���복��ջ
                    parking = fakestackpush(parking,temp);
                }
            }else{
                int i;
                for(i = now; i > num; i--){
                    //α��ջ
                    stack *temp = fakestackpop(parking);
                    //α��ջ  ����ȴ�ջ
                    wait = fakewaitpush(wait,temp);
                }
                parking = popstack(parking,leavetime);   //���ջ
                for(i = now; i > num; i--){
                    //α��ջ
                    stack *temp = fakewaitpop(wait);
                    //α��ջ  ���복��ջ
                    parking = fakestackpush(parking,temp);
                }
                stack *pop = poppueue(front);
                pop->addr = 6;    //α��ջ����addr--
                pop->time = leavetime;
                parking = fakestackpush(parking,pop);
            }


        }
        if(change == 3){
            print(parking,front);
        }
    }
    //����ͣ����
    //�뿪ͣ����
    return 0;
}
