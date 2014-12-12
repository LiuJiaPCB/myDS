/*图的临接矩阵存储*/
typedef char VertexType;
typedef int  EdgeType;
#define MAXVEX 100
#define INFINITY 65535

typedef struct
{
	VertexType vexs[MAXVEX];
	EdgeType   arc[MAXVEX][MAXVEX];
	int numVertexes,numEdges;
} MGraph;

void CreateGraph(MGraph *G)
{
	int i,j,k,weight;
	printf("输入定点数和边数：\n");
	scanf("%d,%d",&G->numVertexes,&G->numEdges);
	for(i = 0;i<G->numVertexes;i++)
	{
		scanf(&G->vexs[i]);
	}
	
	for(i=0;i<G->numVertexes;i++)
	{
		for(j=0;j<G->numVertexes;j++)
		{
			G->arc[i][j]=INFINITY;
		}
	}
	
	for(k=0;k<G->numEdges;k++)
	{
		printf("输入边(vi,vj)上的下标i,下标j和权w:\n");
		scanf("%d,%d,%d",&i,&j,&weight);
		G->arc[i][j]=weight;
		G->arc[j][i]=G->arc[i][j];
	}
}

