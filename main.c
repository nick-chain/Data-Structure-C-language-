#include"cphash.h"

int main(void){
    char ch;
    type_t a[] = {23, 34, 14, 38, 46, 16, 68, 15, 7, 31, 26};
    type_t key;
    int postion;
    HashTable* H;

    //除数取上线,得出哈希表大小
    int TableSize = (int)ceil((sizeof(a)/sizeof(int))/0.75);
    H = InitHash(TableSize);
    CreateHash(H,a,sizeof(a)/sizeof(int));

    while(1){
        printf("please input key:");
        scanf("%d",&key);
        postion = HashSearch(H,key);
        if(postion == -1){
            printf("Search error\n");
        }
        else{
            printf("Search %d at %d\n",key,postion);
        }
        printf("continue?(Y/y)");
		while(getchar() != '\n');
		scanf("%c",  &ch);
		if(ch == 'y' || ch == 'Y')
				continue;
		else
				break;
    }

    return 0;
}
