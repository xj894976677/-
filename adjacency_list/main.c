#include <stdio.h>
typedef struct ArcNode{    //���й�ϵ
    int adjvex; //�ڽӵ��������е�λ���±�
    struct ArcNode *next;   //ָ����һ���ڽӵ��ָ��
}ArcNode;
typedef struct VNode{   //��������
    int data;//����
    ArcNode *firstarc;//ָ��
}VNode,AdjList[20];
typedef struct ALGraph{//�ڽӱ�ṹ��
    AdjList vertices;//����--ͼ�ж��㼰������������
    int vexnum; //������
    int arcnum; //����
}ALGraph;
int LocateVex(ALGraph *alg, int v){
    //���ҵ�v1
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
//������ջ
ArcNode *insert(ArcNode *t, int temp){
    ArcNode *p = (ArcNode*)malloc(sizeof(ArcNode));
    p->adjvex = temp;
    p->next = t;
    t = p;
    return t;
}

void Create(ALGraph *ALG){//�ڽӱ������
    printf("���붥����,����\n");
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
        //�ҵ�v1 v2���ݵ�����
        int n,m;
        m = LocateVex(ALG,v1);
        n = LocateVex(ALG,v2);
//        printf("%d,%d\n",m,n);
        //���mλ�� ����ָ��Ϊ�� ���ʼ������,��Ȼֱ�Ӳ���
        if(ALG->vertices[m].firstarc == NULL){
            ALG->vertices[m].firstarc = (ArcNode*)malloc(sizeof(ArcNode));
            ALG->vertices[m].firstarc->next = NULL;
        }
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
