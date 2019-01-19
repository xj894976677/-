#include <stdio.h>
/*
模拟一个停车场：队列之后入栈
*/
typedef struct Stack{
    int addr;
    int time;
    struct Stack *next;
}stack;

//停车场栈的初始化
stack *initstack(){
    stack *head = (stack*)malloc(sizeof(stack));
    head->next = NULL;
}

//入栈   伪入栈  参数为节点头节点：节点；
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

//出栈    出栈分为两种，一种真出栈，离开停车场，一种伪出栈，不释放空间，返回值为该节点
stack *popstack(stack *head,int time){
    stack *temp = head->next;
    printf("位置%d车以离开，应收费%d元 \n",temp->addr,10*(time - temp->time));
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
//入列  传入尾节点
stack *pushpueue(stack *rear,int addr){
    stack *temp = (stack*)malloc(sizeof(stack));
    rear->next = temp;
    temp->next = NULL;
    temp->addr = addr;
    return temp;
}
//出列  传入首节点  伪出列  传出出列值
stack *poppueue(stack *front){
    stack *temp = front->next;
    front->next = temp->next;
    printf("出列%d  进入车库\n",temp->addr);
    return temp;
}

void print(stack *parking, stack *front){
    printf("当前停车场: \n");
    while(parking->next){
        parking = parking->next;
        printf("车位置：%d   开始时间：%d\n",parking->addr,parking->time);
    }

    int linenum = 0;
    while(front->next){
        ++linenum;
        front = front->next;
    }
    printf("当前等待队列：%d\n",linenum);
}
int main()
{
    int max = 5; //停车场最大容量5台车
    int now = 0; //停车场现有车辆
    int line = 0; //排队人数
    stack *parking = initstack();//初始化停车场
    stack *pue = initstack();//初始化队列尾部
    stack *front = pue; //初始化队列头节点
    stack *wait = initstack();//初始化等待栈
    while(printf("请选择:\n1-进入停车场，2-离开停车场, 3-显示当前队列,0-退出系统\n")){
        int change;
        scanf("%d",&change);
        if(change == 0){
            return 0;
        }
        if(change == 1){
            if(now == 5){
                printf("停车场已满，进入排队队列等候\n");
                ++line;
                pue = pushpueue(pue,line);
            }
            if(now != 5){
                printf("请输入停车开始时间: ");
                int time;
                scanf("%d",&time);
                ++now;
                pushstack(parking,time,now);
            }
        }
        if(change == 2){
            //出来一个，后面的出栈，进入等待栈，然后在入栈，然后队列出来一个入栈
            printf("离开车的位置：");
            int num;
            int leavetime;
            scanf("%d",&num);
            printf("离开的时间:");
            scanf("%d",&leavetime);
            if(line == 0){
                int i;
                for(i = now; i > num; i--){
                    //伪出栈
                    stack *temp = fakestackpop(parking);
                    //伪入栈  进入等待栈
                    wait = fakewaitpush(wait,temp);
                }
                parking = popstack(parking,leavetime);   //真出栈
                for(i = now; i > num; i--){
                    //伪出栈
                    stack *temp = fakewaitpop(wait);
                    //伪入栈  进入车库栈
                    parking = fakestackpush(parking,temp);
                }
            }else{
                int i;
                for(i = now; i > num; i--){
                    //伪出栈
                    stack *temp = fakestackpop(parking);
                    //伪入栈  进入等待栈
                    wait = fakewaitpush(wait,temp);
                }
                parking = popstack(parking,leavetime);   //真出栈
                for(i = now; i > num; i--){
                    //伪出栈
                    stack *temp = fakewaitpop(wait);
                    //伪入栈  进入车库栈
                    parking = fakestackpush(parking,temp);
                }
                stack *pop = poppueue(front);
                pop->addr = 6;    //伪入栈会令addr--
                pop->time = leavetime;
                parking = fakestackpush(parking,pop);
            }


        }
        if(change == 3){
            print(parking,front);
        }
    }
    //进入停车场
    //离开停车场
    return 0;
}
