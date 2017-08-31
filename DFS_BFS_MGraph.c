#include<stdio.h>
#include<stdlib.h>
#define MaxVertexNum 100
#define FALSE 0
#define TRUE 1
#define INFINITY 65535
int Visited[MaxVertexNum];
typedef char Vertex;
typedef int weight;
typedef int Bool;
enum GraphType {
	DG,UG,DN,UN
}; 

typedef struct GNode{
	int Vertex;
	int Edge;
	Vertex Vertices[MaxVertexNum];
	weight EdgeW[MaxVertexNum][MaxVertexNum];
	enum GraphType GType;
}MGraph;
/*定义循环队列*/
typedef struct QNode{
	int Data[MaxVertexNum];
	int front;
	int rear;
}Queue;

MGraph* CreateMGraph(){
	MGraph* Graph;
	int i,j,k,w;
	
	Graph = (MGraph*)malloc(sizeof(MGraph));
	Graph->GType = UN;
	printf("请输入顶点数和边数：\n");
	scanf("%d,%d",&(Graph->Vertex),&(Graph->Edge));
	printf("请输入顶点信息（字符型）：\n");
	for(i=0;i<Graph->Vertex;i++){
		scanf(" %c",&(Graph->Vertices[i]));
	} 
	for(i=0;i<Graph->Vertex;i++){
		for(j=0;j<Graph->Vertex;j++){
			Graph->EdgeW[i][j] = INFINITY; 
		} 
	} 
	printf("请输入边<v1,v2>和权值：\n");
	for(i=0;i<Graph->Edge;i++){
		scanf("%d,%d,%d",&j,&k,&w);
		Graph->EdgeW[j][k] = w;
		Graph->EdgeW[k][j] = w;
	}
	
	return Graph;
}

void PrintMGraph(MGraph* Graph){
	int i,j;
	
	printf("  ");
	for(i=0;i<Graph->Vertex;i++){
	printf("%c  ",Graph->Vertices[i]);
    }
    printf("\n");
    for(i=0;i<Graph->Vertex;i++){
    	printf("%c",Graph->Vertices[i]);
    	for(j=0;j<Graph->Edge;j++){
   		if(Graph->EdgeW[i][j]==INFINITY){
		    printf(" **");
	    }
	    else{
    		printf(" %d",Graph->EdgeW[i][j]);
   	    }
		}
		printf("\n");
	}
}

void CreateQueue(Queue* Q){
	Q->front = Q->rear = 0;
}

void EnQueue(Queue* Q, int e){
	if((Q->rear+1)%MaxVertexNum==Q->front){
	//	printf("队列已经满！\n");
		return;
	}
	Q->Data[Q->rear] = e;
	Q->rear = (Q->rear+1)%MaxVertexNum;
}

void DeQueue(Queue* Q,int* e){
	if(Q->front==Q->rear){
	//	printf("队列已经空\n");
		return;
	}
	*e = Q->Data[Q->front];
	Q->front = (Q->front+1)%MaxVertexNum;
}

Bool IsEmptyQ(Queue* Q){
	if(Q->front == Q->rear){
		return TRUE;
	}
	else{
		return FALSE;
	}
}
void BFS_MGraph(MGraph* Graph){
	int i,j;
	Queue Q;
	
	for(i=0;i<Graph->Vertex;i++){
		Visited[i]  =FALSE;
	}
	CreateQueue(&Q);
	for(i=0;i<Graph->Vertex;++i){
		if(!Visited[i]){
			Visited[i] = TRUE;
			printf("%c ",Graph->Vertices[i]);
			EnQueue(&Q,i);
			while(!IsEmptyQ(&Q)){
				DeQueue(&Q,&i);
				for(j=0;j<Graph->Vertex;++j){
					if(!Visited[j]&&Graph->EdgeW[i][j]!=INFINITY){
						Visited[j] = TRUE;
						printf("%c ",Graph->Vertices[j]);
						EnQueue(&Q,j);
					}
				}
			}
		}
	}
}

void DFS(MGraph* Graph, int i){
	int j;
	
	Visited[i] = TRUE;
	printf("%c ",Graph->Vertices[i]);
	for(j=0;j<Graph->Vertex;j++){
		if(Graph->EdgeW[i][j]!=INFINITY&&!Visited[j]){
			DFS(Graph,j);
		}
	}
}

void DFS_MGraph(MGraph* Graph){
	int i,j;
	
	for(i=0;i<Graph->Vertex;i++){
		Visited[i] = FALSE;
	}
	for(i=0;i<Graph->Vertex;i++){
		if(!Visited[i]){
			DFS(Graph,i);
		}
	}
} 

int main(void){
	MGraph* Graph;
	
	Graph = CreateMGraph();
	PrintMGraph(Graph);
    printf("\n图的广度优先遍历："); 
	BFS_MGraph(Graph);
	printf("\n图的深度优先遍历："); 
	DFS_MGraph(Graph);
	
	return 0;
}
