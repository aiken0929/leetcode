//round-robin queue
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define DATALEN 128
typedef int ElemType;
typedef int status;

#ifdef NOCNT 
typedef struct Node
{
	ElemType * data;
	int Size;
	int front;//head
	int rear;//tail
}SqQueue;
SqQueue * createQueue(ElemType * dat,int size)
{
	SqQueue * res=(SqQueue * )calloc(1,sizeof(SqQueue));
	res->Size=size;
	res->data=dat;
	return res;
}
status EnQueue(SqQueue * Q,ElemType elem )
{
	if((Q->rear+1)% DATALEN ==Q->front)
		reurn OVERFLOW;
	Q->data[Q->rear]=elem;
	Q->rear=(Q->rear+1)%DATALEN;
	return OK;
}
status OutQueue(SqQueue * Q,ElemType *p_elem)
{
	if(Q->front ==Q->rear)
		return ERROR;
	*p_elem=Q->data[Q->front];
	Q->front=(Q->front+1)%DATALEN;
	return OK;
}
bool IsEmpty(SqQueue *Q)
{
	return Q->front == Q->rear?true:false;
}
bool IsFull(SqQueue *Q)
{
	if((Q->rear+1)%DATALEN == Q->front%DATALEN)
		return true£»
	return false£»
}
#endif

#ifdef USECNT
typedef struct Node
{
	ElemType *base;
	int cnt;
	int front;
	int rear;
}SQueue;
SQueue * SQueueInit(ElemType *dat)
{
	SQueue * res=(SQueue *)calloc(1,sizeof(SQueue));
	res->base=dat;
	return res;
}
bool isEmpty(SQueue* Q)
{
	return Q->cnt==0;
}
bool isFull(SQueue * Q)
{
	return Q->cnt==DATALEN;
}
status EnQueue(SQueue *Q,ElemType dat)
{
	if(Q->cnt == DATALEN)
		return OVERFLOW;
	Q->base[Q->rear]=dat;
	Q->rear=(Q->rear+1)%DATALEN;
	Q->cnt++;
	return OK;
}
status OutQueue(SQueue *Q,ElemType *dat)
{
	if(0==Q->cnt)
		return OVERFLOW;
	*dat = Q->base[Q->front];
	Q->front=(Q->front+1)%DATALEN;
	Q->cnt--;
	return OK;
}
#endif