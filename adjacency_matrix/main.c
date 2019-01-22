#include <stdio.h>
//邻接矩阵
typedef struct Arc{
    int adj;    //对应无权值的图，用1或0表示相邻，对于带权值的图，直接权值
    char *info; //弧或者边额外含有的信息指针;
}ArcCell,AdjMatrix[20][20];
typedef struct mgraph{
    int vexs[20];    //存储图中顶点的数据
    AdjMatrix arcs; //二维数组存储顶点关系
                    //图的种类（可以省略）
    int vexnum;     //顶点数
    int arcnum;     //弧或边个数
}MGraph;
//根据顶点本身数据，判断出顶点在二维数组中的位置
int LocateVex(MGraph *G, int v){
    int i = 0;
    //遍历一维数组，找到变量V
    for(i = 0; i < G->vexnum; i++){
        if(G->vexs[i] == v){
            break;
        }
    }
    //如果找不到
    if(i >= G->vexnum){
        printf("未找到该变量");
        return -1;
    }
    return i;
}
//构造有向图
void Create(){

}
//构造无向图
void CreateDN(MGraph *G){
    //模拟录入一些数据
    scanf("%d,%d",&(G->vexnum),&(G->arcnum));//顶点数和边个数
    int i;

    for(i = 0; i < G->vexnum; i++){
        scanf("%d",&(G->vexs[i]));//顶点录入数据
    }
    int j;
    for(i = 0; i < G->vexnum; i++){    //初始化
        for(j = 0; j < G->vexnum; j++){
            G->arcs[i][j].adj = 0;
            G->arcs[i][j].info = NULL;
        }
    }
    //输入组成邻接矩阵的数据
    for(i = 0; i < G->arcnum; i++){
        int V1, V2;//顶点变量
        scanf("%d,%d",&V1, &V2);
        //根据顶点得出位置（二维数组的下标值）
        //通过功能函数确定两个顶点
        int n = LocateVex(G, V1);
        int m = LocateVex(G, V2);
        G->arcs[n][m].adj = 1;
        G->arcs[m][n].adj = 1;  //无向图的对称矩阵
    }
}

//矩阵输出的函数
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
