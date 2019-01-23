#include <stdio.h>
typedef struct ArcNode{    //表中关系
    int adjvex; //邻接点在数组中的位置下标
    struct ArcNode *next;   //指向下一个邻接点的指针
}ArcNode;
typedef struct VNode{   //表中数据
    int data;//数据
    ArcNode *firstarc;//指针
}VNode,AdjList[20];
int visited[20]; //遍历标记
typedef struct ALGraph{//邻接表结构体
    AdjList vertices;//链表--图中顶点及其各顶点的数组
    int vexnum; //顶点数
    int arcnum; //边数
}ALGraph;

//地址队列
typedef struct Queue{
    int addr;
    struct Queue *next;
}queue;
//入队
queue *insque(queue *a, int num){
    queue *temp = a;
    queue *new = (queue*)malloc(sizeof(queue));
    new->next = NULL;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new;
    new->addr = num;
    return a;
}
//出队
queue *popque(queue *a){
    queue *temp = a->next;
    a->next = temp->next;
    free(temp);
    return a;
}
int LocateVex(ALGraph *alg, int v){
    //先找到v1
    int i;
    for(i = 0; i < alg->vexnum; i++){
        if(alg->vertices[i].data == v){
            break;
        }
    }
    if(i >= alg->vexnum){
        return -1;
    }
    return i;
}
//链表入栈
ArcNode *insert(ArcNode *t, int temp){
    ArcNode *p = (ArcNode*)malloc(sizeof(ArcNode));
    p->adjvex = temp;
    p->next = t;
    return p;
}

void Create(ALGraph *ALG){//邻接表的输入
    printf("输入顶点数,边数\n");
    scanf("%d,%d",&(ALG->vexnum),&(ALG->arcnum));
    int i;
    for(i = 0; i < ALG->vexnum; i++){
        scanf("%d",&(ALG->vertices[i].data));
    }
    for(i = 0; i < ALG->vexnum; i++){
        ALG->vertices[i].firstarc = NULL;//栈初始化空
    }
    for(i = 0; i < ALG->arcnum; i++){
        int v1, v2;
        printf("输入第%d条边数据：",i+1);
        scanf("%d,%d",&v1, &v2);
        //找到v1 v2数据的链表
        int n,m;
        m = LocateVex(ALG,v1);
        n = LocateVex(ALG,v2);
//        printf("%d,%d\n",m,n);

        //v1链表指针 指向表中关系，令其中数据赋值
        ALG->vertices[m].firstarc = insert(ALG->vertices[m].firstarc,n);
    }
}
//输出函数
void put(ALGraph ALG){
    int i;
    printf("%d\n\n",ALG.vexnum);
    printf("位置     数值     关联位置\n");
    for(i = 0; i < ALG.vexnum; i++){
        printf("%d    ",i);
        printf("%d     ",ALG.vertices[i].data);
        while(ALG.vertices[i].firstarc){
            printf("%d     ",ALG.vertices[i].firstarc->adjvex);
            ALG.vertices[i].firstarc = ALG.vertices[i].firstarc->next;
        }
        printf("\n");
    }
}
void DFSvisit(ALGraph temp, int v){
    //输出
    visited[v] = 1;
    printf("%d ",temp.vertices[v].data);
    while(temp.vertices[v].firstarc){
        int addr = temp.vertices[v].firstarc->adjvex;
        temp.vertices[v].firstarc = temp.vertices[v].firstarc->next;
        if(visited[addr] == 0){
            DFSvisit(temp,addr);
        }

    //当前节点   不为空    下一个节点
    }
}
//深度优先遍历
void DFSTraverse(ALGraph ALG){
    //初始化访问标记为0   则1为被访问过
    int i;
    for(i = 0; i < ALG.vexnum; i++){
        visited[i] = 0;
    }
    for(i = 0; i < ALG.vexnum; i++){
        //顶点出发访问
        if(visited[i] == 0){
            DFSvisit(ALG,i);//访问函数
        }
    }
}
//广度优先遍历
void BFSTraverse(ALGraph ALG){
    //初始化访问标记
    int i;
    queue *que = (queue*)malloc(sizeof(queue));//初始化队列
    que->next = NULL;
    for(i = 0; i < ALG.vexnum; i++){
        visited[i] = 0;
    }
    for(i = 0; i < ALG.vexnum; i++){
        if(visited[i] == 0){
            que = insque(que,i);
        }
        while(que->next != NULL){
            int addr = que->next->addr;
            if(visited[addr] == 0){
                visited[addr] = 1;
                que = popque(que);
                printf("%d ",ALG.vertices[addr].data);
                while(ALG.vertices[addr].firstarc){
                    que = insque(que,ALG.vertices[addr].firstarc->adjvex);
                    ALG.vertices[addr].firstarc = ALG.vertices[addr].firstarc->next;

                }
            }
        }
    }

}
int main()
{
    ALGraph ALG;
    Create(&ALG);
    put(ALG);
    DFSTraverse(ALG);
    printf("\n");
    BFSTraverse(ALG);
    return 0;
}
