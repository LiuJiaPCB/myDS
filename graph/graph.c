/*ͼ���ڽӾ���洢*/
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
	printf("���붨�����ͱ�����\n");
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
		printf("�����(vi,vj)�ϵ��±�i,�±�j��Ȩw:\n");
		scanf("%d,%d,%d",&i,&j,&weight);
		G->arc[i][j]=weight;
		G->arc[j][i]=G->arc[i][j];
	}
}

/*ͼ���ڽӱ�洢*/
typedef char VertexType;
typedef int  EdgeType;

typedef struct EdgeNode
{
	int adjvex;
	EdgeType weight;
	struct EdgeNode *next;
} EdgeNode;

typedef struct VertexNode
{
	VertexType data;
	EdgeNode *firstedge;
}VertexNode,AdjList[MAXVEX];

typedef struct 
{
	AdjList adjList;
	int numVertexes,numEdges;
}GraphAdjList; 

void CreateALGraph(GraphAdjList *G)
{
	int i,j,k;
	EdgeNode *e;
	printf("���붥�����ͱ�����\n")��
	scanf("%d,%d",&G->numVertexes,&G->numEdges);
	for(i=0;i<G->numVertexes;i++)
	{
		scanf(&G->adjList[i].data);
		G->adjList[i].firstedge = NULL;
	} 
	for(k=0;k<G->numEdges;k++)
	{
		printf("�����(vi,vj)�ϵĶ�����ţ�\n");
		scanf("%d,%d",&i,&j);
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		
		e->adjvex=j;
		e->next = G->adjList[i].firstedge;
		G->adjList[i].firstedge = e;
		
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		
		e->adjvex=i;
		e->next = G->adjList[j].firstedge;
		G->adjList[j].firstedge = e; 
	}
}

/*�ڽӾ����������ȱ���*/
typedef int Boolean;
Boolean visited[MAX];

void DFS(MGraph G,int i)
{
	int j;
	visited[i] = TRUE;
	printf("%c ".G.vexs[i]);
	for(j=0;j<G.numVertexes;j++)
	{
		if(G.arc[i][j]==1&&!visited[j])
		{
			DFS(G,j);
		}
	}
} 

void DFSTraverse(MGraph G)
{
	int i;
	for(i=0;i<G.numVertexes;i++)
	{
		visited[i] = TRUE;
	}
	for(i=0;i<G.numVertexes;i++)
	{
		if(!visited[i])
		{
			DFS(G,i);
		}
	}
}
