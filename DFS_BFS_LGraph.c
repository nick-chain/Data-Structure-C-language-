#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define MaxVertexNum 100
typedef int Bool;
typedef char Vertex;
typedef int Edgew;
enum GraphType{
	DG,UG,DN,UN
};
int Visited[MaxVertexNum];

typedef struct ENode{//边节点 
	int AdjV;
	Edgew weight;
	struct ENode* next; 
}EdgeNode;

typedef struct VNode{//边表头节点 
	Vertex vertex;
	EdgeNode *FirstEdge;
}AdjVNode;

typedef AdjVNode AdjList[MaxVertexNum];
typedef struct GNode{
	int vertex;
	int edge;
	enum GraphType GType;
	AdjList adjlist;
}LGraph; 
//建立循环队列
typedef struct QNode{
	int Data[MaxVertexNum];
	int front;
	int rear;
}Queue;

void CreateQueue(Queue* Q){
	Q->front  =Q->rear = 0;
}

void EnQueue(Queue* Q, int e){
	if((Q->rear+1)%MaxVertexNum==Q->front){
		printf("队列已经满！");
		return; 
	}
	Q->Data[Q->rear] = e;
	Q->rear = (Q->rear+1)%MaxVertexNum;
}

int DeQueue(Queue* Q){
	int item;
	
	if(Q->front==Q->rear){
		printf("队列已经空！");
		return; 
	}
	item = Q->Data[Q->front];
	Q->front = (Q->front+1)%MaxVertexNum;
	
	return item;
}

Bool IsEmpty(Queue* Q){
	if(Q->front==Q->rear){
		return TRUE;
	}
	else{
		return FALSE;
	}
}

LGraph* CreateLGraph(){
	LGraph* Graph;
	EdgeNode* E;
	int i,j,k,w;
	
	Graph = (LGraph*)malloc(sizeof(LGraph));
	Graph->GType = DN;
	printf("请输入顶点数和边数：\n");
	scanf("%d,%d",&(Graph->vertex),&(Graph->edge));
	printf("请输顶点信息（字符型）\n");
	for(i=0;i<Graph->vertex;i++){
		scanf(" %c",&(Graph->adjlist[i].vertex));
	}
	for(i=0;i<Graph->vertex;i++){
		Graph->adjlist[i].FirstEdge = NULL;
	}
	printf("请输入边<v1,v2>和权值：\n");
	for(i=0;i<Graph->edge;i++){
		scanf("%d,%d,%d",&j,&k,&w);
		E = (EdgeNode*)malloc(sizeof(EdgeNode));
		E->AdjV = k;
		E->weight = w;
		E->next = Graph->adjlist[j].FirstEdge;
		Graph->adjlist[j].FirstEdge = E;
	}
	
	return Graph;
	
}

void PrintLGraph(LGraph* Graph){
	EdgeNode* E;
	int i;
	
	for(i=0;i<Graph->vertex;i++){
		printf("[%d %c]->",i,Graph->adjlist[i].vertex);
		E = Graph->adjlist[i].FirstEdge;
		while(E){
			printf("[%d %d]->",E->weight,E->AdjV);
			E = E->next;
		}
		printf("\n");
	} 
}

void DFS(LGraph* Graph, int i){
	EdgeNode* E;
	Queue Q;
	int temp;
	
	CreateQueue(&Q);
	printf("%c ",Graph->adjlist[i].vertex);
	Visited[i] = TRUE;
	EnQueue(&Q,i);
	while(!IsEmpty(&Q)){
		temp = DeQueue(&Q);
		E = Graph->adjlist[temp].FirstEdge;
		for(;E;E = E->next){
		    if(!Visited[E->AdjV]){
			    DFS(Graph,E->AdjV);
		    }
        }
	}
}
void DFS_LGraph(LGraph* Graph){
	int i;

	for(i=0;i<Graph->vertex;i++){
		Visited[i] = FALSE;
	} 
	for(i=0;i<Graph->vertex;i++){
		if(!Visited[i]){
			DFS(Graph,i);
		}
	}
	printf("\n"); 
}

void BFS(LGraph* Graph, int i){
	EdgeNode* E;
	Queue Q;
	int j,k,temp;
	
    printf("%c ",Graph->adjlist[i].vertex);
	Visited[i] = TRUE;
	CreateQueue(&Q);
	EnQueue(&Q,i);
	while(!IsEmpty(&Q)){
		temp = DeQueue(&Q);
		E = Graph->adjlist[temp].FirstEdge;
		while(E){
			if(!Visited[E->AdjV]){
				printf("%c ",Graph->adjlist[E->AdjV].vertex);
				Visited[E->AdjV] = TRUE;
				EnQueue(&Q,E->AdjV);
			}
			E = E->next;
		}
	}
		
}
void BFS_LGraph(LGraph* Graph){
	int i;
	
	for(i=0;i<Graph->vertex;i++){
		Visited[i] = FALSE;
	}
	for(i=0;i<Graph->vertex;i++){
		if(!Visited[i]){
			BFS(Graph,i);
		}
	}
}

void DeLGraph(LGraph* Graph){
	EdgeNode *E,*W;
	int i;
	
	for(i=0;i<Graph->vertex;i++){
		E = Graph->adjlist[i].FirstEdge;
		while(E){
			W = E;
			E = E->next;
			free(W);
		}
	}
}
int main(void){
	LGraph* Graph;
	
	Graph = CreateLGraph();
    PrintLGraph(Graph);
   	printf("邻接表深度优先遍历如下：\n");
	DFS_LGraph(Graph);
	printf("邻接表广度优先遍历如下：\n");
	BFS_LGraph(Graph);
	DeLGraph(Graph);
	
	return 0; 
} 
