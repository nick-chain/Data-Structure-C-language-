#ifndef __HAHS_H__
#define __HAHS_H__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define N 11

typedef int  data_t;

//封装hash表的结构
typedef struct hashtbl{
	data_t *h;
	int length;
}hash_tbl, *hash_tp;

void init_hash(hash_tp *hp, int m);
void create_hash(hash_tp hp, data_t *a);
int hash_search(hash_tp hp, int key);
void hash_show(hash_tp hp, int hash_val);

#endif
