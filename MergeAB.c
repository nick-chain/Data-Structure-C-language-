#include<stdio.h>
#include<stdlib.h>
typedef struct node* List;
struct node{
	int data;
	List next;
};

List ReadList()
{
	List L,t,head;
	int data,N;
	head = (List)malloc(sizeof(struct node));
	if(head == NULL)
	{
		printf("No enough to mallocate!\n");
		exit(0);
	}
	t = head;
	scanf("%d",&N);
	while(N--)
	{
		L = (List)malloc(sizeof(struct node));
		scanf("%d",&data);
		L->data = data;
		t->next = L;
		t = L;
	}
	t->next = NULL;
	
	return head;
}

/*List ReadList()
{
	List L,t,head;
	int N;
	head = (List)malloc(sizeof(struct node));
	head->next = NULL;
	t = head;
	scanf("%d",&N);
	while(N--)
	{
		L = (List)malloc(sizeof(struct node));
		scanf("%d",&(L->data));
		L->next = t->next;
		t->next = L;
		t=L;
	}
	return head;
}*/
List MergeAB(List ha,List hb)
{
 List t1,t2,t3,hc;
 hc = ha;
 t1 = ha->next;
 t2 = hb->next;
 t3 =hc;
 while(t1&&t2)
 {
 	if(t1->data<t2->data)
 	{
 		t3->next = t1;
 		t1 = t1->next;
 		t3 = t3->next;
	 }
	 else
	 {
	 	t3->next = t2;
	 	t2 = t2->next;
	 	t2 = t3->next;
	 }
	 while(t1)
	 {
	 	t3->next = t1;
	 }
	 while(t2)
	 {
	 	t3->next = t2;
	 }	 
 }
	return hc;
}

void PrintHc(List hc)
{
	List t;
	t = hc->next;
    int flag=0;
    if(hc==NULL)
    {
    	printf("NULL");
	}
	while(hc!=NULL)
	{
		if(flag)
		{
			printf(" ");
		}
		else
		{
			flag = 1;
			printf("%d",hc->data);
			hc = hc->next;
		}
	}
	}

int main(void)
{
	List ha,hb,hc;
	ha = ReadList();
	hb = ReadList();
	hc =  MergeAB(ha,hb);
	PrintHc(hc);
	
	return 0;
}
