#include"list.h"
#include<stdio.h>
#include<stdlib.h>

List InitList(){
    List H;

    H = (List)malloc(sizeof(LinkList));
    if(!H){
        printf("initialize list fail\n");
        exit(-1);
    }
    else{
        H->Data = -1;
        H->Next = NULL;
    }
    
}

List FindKey(List H, int postion){
    List ptr=H;
    int i=0;
    while(ptr&&i<postion){
        ptr = ptr->Next;
        i++;
    }

    if(i == postion){
        return ptr;
    }
    else{
        return NULL;
    }


}
List AnyplaceInsert(List H,int postion,type_t data){
    List p,s;
    int i;
    if(postion == 1){
        p = (List)malloc(sizeof(LinkList));
        if(!p){
            printf("AnyplaceInsert malloc fail\n");
            exit(-1);
        }
        p->Data = data;
        p->Next = H->Next;
        H->Next = p;
        return H;
    }
    p = FindKey( H,postion-1);
    if(!p){
        printf("AnyplaceInser illegal\n");
        exit(-1);
    }
    else{
        s = (List)malloc(sizeof(LinkList));
        s->Data = data;

        s->Next = p->Next;
        p->Next = s;
        
        return H;
    }
}

int DeleteNode(List H, int postion){
    List s,ptr=H->Next;
    
    if(postion == 1){
        H->Next = H->Next->Next;
        free(ptr);
        return 1;
    }
    ptr = FindKey(H,postion-1);
    if(!ptr&&!ptr->Next){
        printf("Dlete was illegal\n");
        return -1;
    }
    else{
        s = ptr->Next;
        ptr->Next = s->Next;
        free(s);

        return 1;
    }
}

List ReverseList(List H){
    List p,q,t;

    p = H;
    q = NULL;

    while(p){
        t = p->Next;
        p->Next = q;
        q = p;
        p = t;
    }

    return q;
}

void PrintList(List H){
    List ptr = H->Next;

    while(ptr){
        printf("%d ",ptr->Data);
        ptr = ptr->Next;
    }
    printf("\n");
}

void PrintReverse(List H){
    List ptr = H;

    while(ptr->Next){
        printf("%d ",ptr->Data);
        ptr = ptr->Next;
    }
    printf("\n");
}

List CreateJoseph(){
    List H = NULL,p,t;
    int n,i;
    
    printf("input a number:");
    scanf("%d",&n);
    if(n>1){
        H = (List)malloc(sizeof(LinkList));
        if(!H){
            printf("CreateJoseph malloc fail\n");
            exit(-1);
        }
        H->Data = 1;
        H->Next = NULL;
        p = H;
        for(i=2;i<(n+1);i++){
        //    printf("for loop");
            t = (List)malloc(sizeof(LinkList));
            if(!t){
                printf("CreateJoseph malloc fail\n");
                exit(-1);
            }
            t->Data = i;
            t->Next = p->Next;
            p->Next = t;
            p = t;
        }
    }
        else return NULL;

        p->Next = H;
        return H;   
}

void PrintJoseph(List H){
    List p = H;

    while(p->Next!=H){
        printf("%d ",p->Data);
        p = p->Next;
    }
    printf("%d\n",p->Data);

}

int DeleteJoseph(List H, int m, int k){
    List p,q;
    int i;
    p = H;

    if(m<1)
    return 0;
    //指向要报数的前一个
    while(p->Next->Data != m){
        p = p->Next;
    }
    printf("t->next=>data:%d\n",p->Next->Data);

    while(p->Next!=p){
        for(i=0;i<(k-1);i++){
            p=p->Next;//p指向待删除的节点前一个节点
        }
        q = p->Next;//指向待删除的元素
        p->Next = q->Next;
        //p->Next->Next = p->Next;
        printf("delete the element:%d\n",q->Data);
        free(q);
        q = NULL;

    }
    printf("the last element:%d\n",p->Data);
    
 }

cir_list create_cir_list(){
    cir_list H;
    
    H = (cir_list)malloc(sizeof(cir_double_list));
    if(!H){
        printf("create_cir_list malloc fail\n");
        exit(-1);
    }

    H->Data = -1;
    H->next = H;
    H->prior = H;

    return H;
}

cir_list cir_list_insert(){
    cir_list H,p;
    type_t data;
    H = (cir_list)malloc(sizeof(cir_double_list));
    if(!H){
        printf("create_cir_list malloc fail\n");
        exit(-1);
    }

    H->Data = -1;
    H->next = H;
    H->prior = H;

    while(scanf("%d",&data),data){
        p = (cir_list)malloc(sizeof(cir_double_list));
        if(!p){
            printf("cir_list_insert malloc fail\n");
            exit(-1);
        }
        p->Data = data;
        //insert
       p->prior = H->prior;
       p->next = H->prior->next;
       H->prior->next = p; 
       H->prior = p;
       
    }
    
    return H;
}

void cir_list_print(cir_list H){
    cir_list ptr=H;

    while(ptr->next!=H){
        ptr = ptr->next;
        printf("%d ",ptr->Data);
    }
    printf("\n");
}

cir_list cir_list_findkey(cir_list H,int postion){
    cir_list ptr=H;
    int i=0;

    if(postion <1){
        return NULL;
    }

    while(i<postion){
        ptr = ptr->next;
        i++;
        if(ptr == H){
            return NULL;
        }
    }

    return ptr;
}

int delete_cir_node(cir_list H, int postion){
    cir_list p = H,ptr;
    
    if(postion<0){
        printf("1the postion illega\n");
        return -1;
    }
    ptr = cir_list_findkey(H,postion);
    if(!ptr){
        printf("2the psotion illegal\n");
        return -1;
    }
    else{
        if(!ptr->next){
            printf("3the postion illgeal\n");
            return -1;
        }
        else{
            ptr->prior->next = ptr->next;
            ptr->next->prior = ptr->prior;
            printf("delete the element:%d\n",ptr->Data);
            free(ptr);
            ptr = NULL;
            return 0;
        }
    }

}

void cir_list_anyinsert(cir_list H, int postion, int data){
    cir_list p,t;

    if(postion<0){
        printf("1insert illegal\n");
        return;
    }
    t = cir_list_findkey(H,postion);
    if(!t){
        printf("2insert illegal\n");
        return;
    }
    else{
        p = (cir_list)malloc(sizeof(cir_double_list));
        if(!p){
            printf("cir_list_insert malloc fail\n");
            exit(-1);
        }
        p->Data = data;
        t = t->prior;
        p->next = t->next;
        p->prior = t;
        t->next->prior = p;
        t->next = p;

        printf("insert success:%d!\n",data);
        return;
        
    }
}
