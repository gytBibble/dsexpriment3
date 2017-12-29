#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2

typedef int status;
typedef char TElemType; //数据元素类型定义

/* 二叉树的二叉链表存储结构*/
typedef struct BiTNode {
	//int key;//判断结点元素是否为空的标记
	TElemType data;
	struct BiTNode *lchild, *rchild;//左右孩子指针
}BiTNode, *BiTree;

/*实现多树的顺序表结构*/
typedef struct TNode {
	char name[20];//树的名称
	TNode *next;//指向下一结点
	BiTNode *root;//指向树的指针
}TNode,*TN;

/*------基本操作的函数声明------*/
status InitBiTree(TN &L, char *name);//初始化二叉树
status DestroyBiTree(TN &L, char *name);//销毁二叉树
status CreateBiTree(BiTree &T);//创建二叉树
status ClearBiTree(BiTree &T);//清空二叉树
status BiTreeEmpty(TN L);//判定空二叉树
int BiTreeDepth(BiTree T);//求二叉树深度
BiTree Root(TN L);//获取根节点
TElemType Value(BiTree T);//获得结点
status Assign(BiTree T, BiTree &e, TElemType value);//结点赋值
BiTree Parent(BiTree T,BiTree e);//获得双亲结点
BiTree LeftChild(BiTree T,BiTree e);//获得左孩子结点
BiTree RightChild(BiTree T,BiTree e);//获得右孩子结点
BiTree LeftSibling(BiTree T, BiTree e);//获得左兄弟结点
BiTree RightSibling(BiTree T, BiTree e);//获得右兄弟结点
status InsertChild(BiTree &T, BiTree &p, int LR, BiTree c);//插入子树
status DeleteChild(BiTree &T, BiTree &p, int LR);//删除子树
void PreOrderTraverse(BiTree T);//前序遍历
void InOrderTraverse(BiTree T);//中序遍历
void PostOrderTraverse(BiTree T);//后序遍历
status LevelOrderTraverse(BiTree &T, BiTree* tree,int i);

status DataSave(TN L, char *filename);//数据保存
status DataLoad(TN &L, char *filename);//数据加载
void DataSaveUse(BiTNode * p, FILE * fin);
status DataLoadUse(BiTree & T, char* temp, int *);

status Exist(BiTree T, BiTree e);
TN Find(TN L, char *name);//由树名查找该树的前驱
BiTree FindPosition(BiTree T, int i);//由编号找到树中的结点
BiTree _FindPosition(BiTree T, TElemType ch);//由值找到结点
int NumNode(BiTree T);


