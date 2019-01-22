#include <stdio.h>
//�ڽӾ���
typedef struct Arc{
    int adj;    //��Ӧ��Ȩֵ��ͼ����1��0��ʾ���ڣ����ڴ�Ȩֵ��ͼ��ֱ��Ȩֵ
    char *info; //�����߱߶��⺬�е���Ϣָ��;
}ArcCell,AdjMatrix[20][20];
typedef struct mgraph{
    int vexs[20];    //�洢ͼ�ж��������
    AdjMatrix arcs; //��ά����洢�����ϵ
                    //ͼ�����ࣨ����ʡ�ԣ�
    int vexnum;     //������
    int arcnum;     //����߸���
}MGraph;
//���ݶ��㱾�����ݣ��жϳ������ڶ�ά�����е�λ��
int LocateVex(MGraph *G, int v){
    int i = 0;
    //����һά���飬�ҵ�����V
    for(i = 0; i < G->vexnum; i++){
        if(G->vexs[i] == v){
            break;
        }
    }
    //����Ҳ���
    if(i >= G->vexnum){
        printf("δ�ҵ��ñ���");
        return -1;
    }
    return i;
}
//��������ͼ
void Create(){

}
//��������ͼ
void CreateDN(MGraph *G){
    //ģ��¼��һЩ����
    scanf("%d,%d",&(G->vexnum),&(G->arcnum));//�������ͱ߸���
    int i;

    for(i = 0; i < G->vexnum; i++){
        scanf("%d",&(G->vexs[i]));//����¼������
    }
    int j;
    for(i = 0; i < G->vexnum; i++){    //��ʼ��
        for(j = 0; j < G->vexnum; j++){
            G->arcs[i][j].adj = 0;
            G->arcs[i][j].info = NULL;
        }
    }
    //��������ڽӾ��������
    for(i = 0; i < G->arcnum; i++){
        int V1, V2;//�������
        scanf("%d,%d",&V1, &V2);
        //���ݶ���ó�λ�ã���ά������±�ֵ��
        //ͨ�����ܺ���ȷ����������
        int n = LocateVex(G, V1);
        int m = LocateVex(G, V2);
        G->arcs[n][m].adj = 1;
        G->arcs[m][n].adj = 1;  //����ͼ�ĶԳƾ���
    }
}

//��������ĺ���
void show(MGraph *G){
    int i,j;
    for(i = 0; i < G->vexnum; i++){
        for(j = 0; j < G->vexnum; j++){
           printf("%d",G->arcs[i][j].adj);
        }
        printf("\n");
    }
}
int main()
{
    MGraph test;
    CreateDN(&test);
    show(&test);
    return 0;
}
