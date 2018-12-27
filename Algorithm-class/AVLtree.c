#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
//typedef enum {false,true} bool;

typedef int T;
static int compare(T *a;T*b)//用于应对非常数类型的比较
{
	//比较大于返回1 等于返回0 小于返回-1
	
}
typedef struct AvlNode{     
	T data;
	int height; //
	struct AvlNode* left;
	struct AvlNode* right;
} AVLtree ;

#define max(a,b) ((a)>(b)?(a):(b))
	//????
AVLtree* Insert(AVLtree* t, T x);
//????
bool Delete(AVLtree** t, T x);
//????????????
bool Contains(AVLtree* t, const T x);
//????
void InorderTraversal(AVLtree* t);
//????
void PreorderTraversal(AVLtree* t);
//找树中最大�?
AVLtree* FindMax(AVLtree *t);
//找树中最小�?
AVLtree* FindMin(AVLtree *t);
//private: static
//获取节点高度
int GetHeight(AVLtree const *t);
//??? ?
AVLtree* rotateLL(AVLtree* t);
//??? ?
AVLtree* rotateRR(AVLtree * t);
//??? ??
AVLtree* rotateLR(AVLtree* t);
//??? ??
AVLtree* rotateRL(AVLtree* t);

AVLtree* FindMax(AVLtree *t)
{
	if (t == NULL)
		return NULL;
	if (t->right == NULL)
		return t;
	return FindMax(t->right);
}
AVLtree* FindMin(AVLtree *t)
{
	if (t == NULL)
		return NULL;
	if (t->left == NULL)
		return t;
	return FindMin(t->left);
}

int GetHeight(AVLtree const *t)
{
	if (t == NULL)
		return -1;
	else
		return t->height;
}

AVLtree* rotateLL(AVLtree *t)
{
	AVLtree *q = t->left;
	t->left = q->right;
	q->right = t;
	//t = q;
	t->height = max(GetHeight(t->left), GetHeight(t->right)) + 1;
	q->height = max(GetHeight(q->left), GetHeight(q->right)) + 1;
	return q;
}
AVLtree* rotateRR(AVLtree* t)
{
	AVLtree* q = t->right;
	t->right = q->left;
	q->left = t;
	//t = q;
	t->height = max(GetHeight(t->left), GetHeight(t->right)) + 1;
	q->height = max(GetHeight(q->left), GetHeight(q->right)) + 1;
	return q;
}
AVLtree* rotateLR(AVLtree* t)
{

	rotateRR(t->left);
	return rotateLL(t);
}
AVLtree* rotateRL(AVLtree* t)
{
	rotateLL(t->right);
	return rotateRR(t);
}
AVLtree* Insert(AVLtree* t, T x)
{
	if (t == NULL)
	{
		t = calloc(1,sizeof(AVLtree));
		t->data=x;
		return t;
	}
	else if (x < t->data)//compare()==-1
	{
		t->left=Insert(t->left, x);
		//??????
		if (GetHeight(t->left) - GetHeight(t->right) > 1)
		{
			//????? ?????

			if (x < t->left->data)//??
				t = rotateLL(t);
			else                  //??
				t = rotateLR(t);
		}
	}
	else if (x > t->data)//compare()==1
	{
		t->right=Insert(t->right, x);
		if (GetHeight(t->right) - GetHeight(t->left) > 1)
		{
			if (x > t->right->data)
				t = rotateRR(t);
			else
				t = rotateRL(t);
		}
	}
	else
		;//数据重复
	t->height = max(GetHeight(t->left), GetHeight(t->right)) + 1;
   return t;
}
bool Delete(AVLtree ** t, T x)
{
    bool left=false,right=false;
	//t?? ?????????
	if (*t == NULL)
		return false;
	//?????????
	else if ((*t)->data == x)//0==compare()
	{
		//???????
		if ((*t)->left != NULL && (*t)->right != NULL)
		{
			//??????,????????????,???????
			if (GetHeight((*t)->left) > GetHeight((*t)->right))
			{
				(*t)->data = FindMax((*t)->left)->data;
				Delete(&((*t)->left), (*t)->data);
			}
			else//???????,????????????,???????
			{
				(*t)->data = FindMin((*t)->right)->data;//结构体也可赋值
				Delete(&((*t)->right), (*t)->data);
			}
		}
		else
		{//??????????,??????????????????
			AVLtree* old = *t;
			(*t) = (*t)->left ? (*t)->left: (*t)->right;//t?????????
			free(old);
			return true;
		}
	}
	else if (x < (*t)->data)////compare()==-1
	{
		//???????????
		left=Delete(&(*t)->left, x);
		//????????????
		if (GetHeight((*t)->right) - GetHeight((*t)->left) > 1)
		{
			if (GetHeight((*t)->right->left) > GetHeight((*t)->right->right))
			{
				//RL???
				(*t) = rotateRL(*t);
			}
			else
			{//RR???
				(*t) = rotateRR(*t);
			}
		}
		else//?????? ??????
		{
			(*t)->height = max(GetHeight((*t)->left), GetHeight((*t)->right)) + 1;
		}
	}
	else//???????????
	{
		//?????????
		right=Delete(&(*t)->right, x);
		//??????
		if (GetHeight((*t)->left) - GetHeight((*t)->right) > 1)
		{
			if (GetHeight((*t)->left->right) > GetHeight((*t)->left->left))
			{
				//LR???
				(*t) = rotateLR(*t);
			}
			else
			{
				//LL???
				(*t) = rotateLL(*t);
			}
		}
		else//????? ????
		{
			(*t)->height = max(GetHeight((*t)->left), GetHeight((*t)->right)) + 1;
		}
	}
	return left||right;
}

bool Contains(AVLtree* t, const T x)
{
	if (t == NULL)
		return false;
	if (x < t->data)
		return Contains(t->left, x);
	else if (x > t->data)
		return Contains(t->right, x);
	else
		return true;
}
void InorderTraversal(AVLtree* t)
{
	if (t)
	{
		InorderTraversal(t->left);
		//cout <'< t->data << ' ';
		printf("%d ",t->data );
		InorderTraversal(t->right);
	}
}

void PreorderTraversal(AVLtree* t)
{
	if (t)
	{
		//cout << t->data << ' ';
		printf("%d ",t->data );
		PreorderTraversal(t->left);
		PreorderTraversal(t->right);
	}
}
int main () 
{
	T nums[7]={18,14,-2,-99,19,20,78};
	AVLtree* head=NULL;
	bool tmp=false;
	int i;
	for(i=0;i<7;i++)
	{
		head=Insert(head,nums[i]);
	}
	printf("inoder \n");
	InorderTraversal(head);
	printf("\n preoder \n");
	PreorderTraversal(head);

	tmp=Contains(head,20);
	printf("\nthe contain 20 is %d \n",tmp);
	tmp=Contains(head,50);
	printf("the contain 50 is %d \n",tmp);

	tmp=Delete(&head,20);
	printf("delete 20  is %d \n",tmp);
	tmp=Delete(&head,21);
	printf("delete 21 is %d \n",tmp);
	tmp=Delete(&head,-99);
	printf("delete is %d \n",tmp);
    tmp=Delete(&head,20);
	printf("delete 20  is %d \n",tmp);
	printf("inoder \n");
	InorderTraversal(head);
	printf("preoder \n");
	PreorderTraversal(head);
	printf("\n hello https://tool.lu/\n");
	return 0;
}