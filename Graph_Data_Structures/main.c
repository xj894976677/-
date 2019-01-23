#include <stdio.h>
typedef struct ArcNode{    //���й�ϵ
    int adjvex; //�ڽӵ��������е�λ���±�
    struct ArcNode *next;   //ָ����һ���ڽӵ��ָ��
}ArcNode;
typedef struct VNode{   //��������
    int data;//����
    ArcNode *firstarc;//ָ��
}VNode,AdjList[20];
int visited[20]; //�������
typedef struct ALGraph{//�ڽӱ�ṹ��
    AdjList vertices;//����--ͼ�ж��㼰������������
    int vexnum; //������
    int arcnum; //����
}ALGraph;

//��ַ����
typedef struct Queue{
    int addr;
    struct Queue *next;
}queue;
//���
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
//����
queue *popque(queue *a){
    queue *temp = a->next;
    a->next = temp->next;
    free(temp);
    return a;
}
int LocateVex(ALGraph *alg, int v){
    //���ҵ�v1
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
//������ջ
ArcNode *insert(ArcNode *t, int temp){
    ArcNode *p = (ArcNode*)malloc(sizeof(ArcNode));
    p->adjvex = temp;
    p->next = t;
    return p;
}

void Create(ALGraph *ALG){//�ڽӱ������
    printf("���붥����,����\n");
    scanf("%d,%d",&(ALG->vexnum),&(ALG->arcnum));
    int i;
    for(i = 0; i < ALG->vexnum; i++){
        scanf("%d",&(ALG->vertices[i].data));
    }
    for(i = 0; i < ALG->vexnum; i++){
        ALG->vertices[i].firstarc = NULL;//ջ��ʼ����
    }
    for(i = 0; i < ALG->arcnum; i++){
        int v1, v2;
        printf("�����%d�������ݣ�",i+1);
        scanf("%d,%d",&v1, &v2);
        //�ҵ�v1 v2���ݵ�����
        int n,m;
        m = LocateVex(ALG,v1);
        n = LocateVex(ALG,v2);
//        printf("%d,%d\n",m,n);

        //v1����ָ�� ָ����й�ϵ�����������ݸ�ֵ
        ALG->vertices[m].firstarc = insert(ALG->vertices[m].firstarc,n);
    }
}
//�������
void put(ALGraph ALG){
    int i;
    printf("%d\n\n",ALG.vexnum);
    printf("λ��     ��ֵ     ����λ��\n");
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
    //���
    visited[v] = 1;
    printf("%d ",temp.vertices[v].data);
    while(temp.vertices[v].firstarc){
        int addr = temp.vertices[v].firstarc->adjvex;
        temp.vertices[v].firstarc = temp.vertices[v].firstarc->next;
        if(visited[addr] == 0){
            DFSvisit(temp,addr);
        }

    //��ǰ�ڵ�   ��Ϊ��    ��һ���ڵ�
    }
}
//������ȱ���
void DFSTraverse(ALGraph ALG){
    //��ʼ�����ʱ��Ϊ0   ��1Ϊ�����ʹ�
    int i;
    for(i = 0; i < ALG.vexnum; i++){
        visited[i] = 0;
    }
    for(i = 0; i < ALG.vexnum; i++){
        //�����������
        if(visited[i] == 0){
            DFSvisit(ALG,i);//���ʺ���
        }
    }
}
//������ȱ���
void BFSTraverse(ALGraph ALG){
    //��ʼ�����ʱ��
    int i;
    queue *que = (queue*)malloc(sizeof(queue));//��ʼ������
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
