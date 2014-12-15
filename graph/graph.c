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

/*�ڽӱ��������ȱ���*/
void DFS(MGraph GL,int i)
{
	EdgeNode *p;
	
	visited[i] = TRUE;
	printf("%c ",GL->adjList[i].data);
	p=GL->adjList[i].firstedge;
	while(p)
	{
		if(!visited[p->adjvex])
		{
			DFS(GL,p->adjvex);
		}
		p=p->next;
	}
} 

void DFSTraverse(MGraph GL)
{
	int i;
	for(i=0;i<GL->numVertexes;++i)
	{
		visited[i] = FALSE;
	}
	for(i=0;i<GL.numVertexes;i++)
	{
		if(!visited[i])
		{
			DGF(GL,i);
		}
	}
}
/*�ڽӾ���Ĺ�ȱ����㷨*/ 
void BFSTraverse(MGaph G)
{
	for(i=0;i<G->numVertexes;i++)
	{
		visited[i] = FALSE;
	}
	InitQueue(&Q);
	for(i=0;i<G->numVertexes;i++)
	{
		if(!visited[i])
		{
			visited[i]=TRUE;
			printf("%c ",G.vexs[i]);
			EnQueue(&Q,i);
			while(!QueueEmpty(Q))
			{
				DeQueue(&Q,&i);
				for(j=0;j<G.numVertexes;j++)
				{
					if(G.arc[i][j]==1&&!visited[j])
					{
						visited[j]=TRUE;
						printf("%c ",G.vexs[j]);
						EnQueue(&Q,j);
					}
				}
			}
		}
	}
}

/*�ڽӱ�Ĺ�ȱ����㷨*/ 
void BFSTraverse(GraphAdjList GL)
{
	int i;
	EdgeNode *p;
	Queue Q;
	for(i=0;i<GL->numVertexes;i++)
	{
		visited[i] = FALSE;
	}
	InitQueue(&Q);
	for(i=0;i<G->numVertexes;i++)
	{
		if(!visited[i])
		{
			visited[i]=TRUE;
			printf("%c ",GL->adjList[i].data);
			EnQueue(&Q,i);
			while(!QueueEmpty(Q))
			{
				DeQueue(&Q,&i);
				p = GL->adjList[i].firstedge;
				while(p)
				{
					if(!visited[p->adjvex])
					{
						visited[p->adjvex]=TRUE;
						printf("%c ",GL->adjList[p->adjvex].data);
						EnQueue(&Q,p->adjvex);
					}
					p=p->next;
				}
			}
		}
	}
}
/*��С������
  1.Prim�㷨(δ�Ż�)*/ 
void MiniSpanTree_Prim(MGraph G)
{
	int i,j,k,min;
	int adjvex[MAXVEX];
	int lowcost[MAXVEX];
	lowcost[0] = 0;
	adjvex[0]=0;
	for(i=1;i<G.numVerteses;i++)
	{
		lowcost[i] = G.arc[0][i];
		adjvex[i] = 0;
	}
	for(i=0;i<G.numVertexes;i++)
	{
		min = INFINITY;
		while(j<G.numVertexes)
		{
			if(lowcost[j]!=0&&lowcost[j]<min)
			{
				min = lowcost[j];
				 k = j;
			}
			j++;
		} 
		printf("(%d,%d)",adjvex[k],k);
		lowcost[k]=0;
		for(j=1;j<G.numVertexes;j++)
		{
			if(lowcost[j]!=0&&G.arc[k][j]<lowcost[j])
			{
				lowcost[j] = G.arc[k][j];
				adjvex[j] = k;
			}
		}
	}
}



