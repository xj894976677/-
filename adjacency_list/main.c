#include <stdio.h>
typedef struct ArcNode{    //表中关系
    int adjvex; //邻接点在数组中的位置下标
    struct ArcNode *next;   //指向下一个邻接点的指针
}ArcNode;
typedef struct VNode{   //表中数据
    int data;//数据
    ArcNode *firstarc;//指针
}VNode,AdjList[20];
typedef struct ALGraph{//邻接表结构体
    AdjList vertices;//链表--图中顶点及其各顶点的数组
    int vexnum; //顶点数
    int arcnum; //边数
}ALGraph;
int LocateVex(ALGraph *alg, int v){
    //先找到v1
    int i;
    for(i = 0; i < alg->arcnum; i++){
        if(alg->vertices[i].data == v){
            break;
        }
    }
    if(i >= alg->arcnum){
        return -1;
    }
    return i;
}
//链表入栈
ArcNode *insert(ArcNode *t, int temp){
    ArcNode *p = (ArcNode*)malloc(sizeof(ArcNode));
    p->adjvex = temp;
    p->next = t;
    t = p;
    return t;
}

void Create(ALGraph *ALG){//邻接表的输入
    printf("输入顶点数,边数\n");
    scanf("%d,%d",&(ALG->vexnum),&(ALG->arcnum));
    int i;
    for(i = 0; i < ALG->vexnum; i++){
        scanf("%d",&(ALG->vertices[i].data));
    }
    for(i = 0; i < ALG->vexnum; i++){
        ALG->vertices[i].firstarc = NULL;
    }
    for(i = 0; i < ALG->arcnum; i++){
        int v1, v2;
        scanf("%d,%d",&v1, &v2);
        //找到v1 v2数据的链表
        int n,m;
        m = LocateVex(ALG,v1);
        n = LocateVex(ALG,v2);
//        printf("%d,%d\n",m,n);
        //如果m位置 链表指针为空 则初始化链表,不然直接插入
        if(ALG->vertices[m].firstarc == NULL){
            ALG->vertices[m].firstarc = (ArcNode*)malloc(sizeof(ArcNode));
            ALG->vertices[m].firstarc->next = NULL;
        }
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
            if(ALG.vertices[i].firstarc->next == NULL){
                break;
            }
            printf("%d     ",ALG.vertices[i].firstarc->adjvex);
            ALG.vertices[i].firstarc = ALG.vertices[i].firstarc->next;
        }
        printf("\n");
    }
}
int main()
{
    ALGraph ALG;
    Create(&ALG);
    put(ALG);
    return 0;
}
