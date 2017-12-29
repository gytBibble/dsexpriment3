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
typedef char TElemType; //����Ԫ�����Ͷ���

/* �������Ķ�������洢�ṹ*/
typedef struct BiTNode {
	//int key;//�жϽ��Ԫ���Ƿ�Ϊ�յı��
	TElemType data;
	struct BiTNode *lchild, *rchild;//���Һ���ָ��
}BiTNode, *BiTree;

/*ʵ�ֶ�����˳���ṹ*/
typedef struct TNode {
	char name[20];//��������
	TNode *next;//ָ����һ���
	BiTNode *root;//ָ������ָ��
}TNode,*TN;

/*------���������ĺ�������------*/
status InitBiTree(TN &L, char *name);//��ʼ��������
status DestroyBiTree(TN &L, char *name);//���ٶ�����
status CreateBiTree(BiTree &T);//����������
status ClearBiTree(BiTree &T);//��ն�����
status BiTreeEmpty(TN L);//�ж��ն�����
int BiTreeDepth(BiTree T);//����������
BiTree Root(TN L);//��ȡ���ڵ�
TElemType Value(BiTree T);//��ý��
status Assign(BiTree T, BiTree &e, TElemType value);//��㸳ֵ
BiTree Parent(BiTree T,BiTree e);//���˫�׽��
BiTree LeftChild(BiTree T,BiTree e);//������ӽ��
BiTree RightChild(BiTree T,BiTree e);//����Һ��ӽ��
BiTree LeftSibling(BiTree T, BiTree e);//������ֵܽ��
BiTree RightSibling(BiTree T, BiTree e);//������ֵܽ��
status InsertChild(BiTree &T, BiTree &p, int LR, BiTree c);//��������
status DeleteChild(BiTree &T, BiTree &p, int LR);//ɾ������
void PreOrderTraverse(BiTree T);//ǰ�����
void InOrderTraverse(BiTree T);//�������
void PostOrderTraverse(BiTree T);//�������
status LevelOrderTraverse(BiTree &T, BiTree* tree,int i);

status DataSave(TN L, char *filename);//���ݱ���
status DataLoad(TN &L, char *filename);//���ݼ���
void DataSaveUse(BiTNode * p, FILE * fin);
status DataLoadUse(BiTree & T, char* temp, int *);

status Exist(BiTree T, BiTree e);
TN Find(TN L, char *name);//���������Ҹ�����ǰ��
BiTree FindPosition(BiTree T, int i);//�ɱ���ҵ����еĽ��
BiTree _FindPosition(BiTree T, TElemType ch);//��ֵ�ҵ����
int NumNode(BiTree T);


