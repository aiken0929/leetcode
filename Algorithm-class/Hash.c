typedef int T;
#define SIZE  10 //size of hash
typedef struct _NODE
{
	T data;
	struct _NODE* next;
}NODE;
 
typedef struct _HASH_TABLE
{
	NODE* value[SIZE];
}HASH_TABLE;
int hashfunT(T * data) //self define
{
}
int hashcmp(T * a,T* b)
{
}
HASH_TABLE* create_hash_table()
{
	HASH_TABLE* pHashTbl = (HASH_TABLE*)malloc(sizeof(HASH_TABLE));//or calloc
	memset(pHashTbl, 0, sizeof(HASH_TABLE));
	
	return pHashTbl;
}

NODE* find_data_in_hash(HASH_TABLE* pHashTbl, T data)
{
	if(NULL ==  pHashTbl)
	{
		return NULL;
	}
 
	NODE* pNode = pHashTbl->value[data % 10];
	if(NULL == pNode)
	{
		return NULL;
	}
 
	while(pNode)
	{
		if(data == pNode->data)
		{
			return pNode;
		}
		pNode = pNode->next;
	}
	return NULL;
}
 
int insert_data_into_hash(HASH_TABLE* pHashTbl, int data)
{
	NODE* pNode;
	if(NULL == pHashTbl)
	{
		return 0;
	}
 
	if(NULL == pHashTbl->value[data % 10])
	{
		pNode = (NODE*)malloc(sizeof(NODE));
		memset(pNode, 0, sizeof(NODE));
		pNode->data = data;
		pHashTbl->value[data % 10] = pNode;
		return 1;
	}
 
	if(NULL != find_data_in_hash(pHashTbl, data))
	{
		return 0;
	}
 
	pNode = pHashTbl->value[data % 10];
	/* Insert into the tail
	while(NULL != pNode->next)
	{
		pNode = pNode->next;
	}
	*/
	NODE* tmp=pNode->next;
	pNode->next = (NODE*)malloc(sizeof(NODE));
	memset(pNode->next, 0, sizeof(NODE));
	pNode->next->data = data;
	pNode->next->next=tmp;
	return 1;
}
 
int delete_data_from_hash(HASH_TABLE* pHashTbl, int data)
{
	NODE* pHead=NULL;
	NODE *pNode=NULL;
 
	if(NULL == pHashTbl || NULL == pHashTbl->value[data % 10])
	{
		return 0;
	}
 
	pNode = find_data_in_hash(pHashTbl, data);
	if(NULL == pNode)
	{
		return 0;
	}
 
	if(pNode == pHashTbl->value[data % 10])
	{
		pHashTbl->value[data % 10] = pNode->next;
		goto final;
	}
 
	pHead = pHashTbl->value[data % 10];
	while(pNode != pHead ->next)
	{
		pHead = pHead->next;
	}
	pHead->next = pNode->next;
 
final:
	free(pNode);
	return 1;
}

