#include "tree.h"
int main(void)
{
	int op = 1;
	int num;//当前已有的树数
	char name[20];
	char filename[30];
	BiTree root,e,p;//树的根结点和待用结点
	TN Lhead=NULL,L=NULL;//顺序表表头结点和待用结点
	Lhead = (TN)malloc(sizeof(TNode));
	Lhead->next = NULL;
	Lhead->root = NULL;
	strcpy(Lhead->name,"The Head");
	while (op)
	{
		system("cls");
		num = 0;
		TN ph = Lhead;
		while (ph != NULL)
		{
			if (ph->next != NULL)
				num++;
			ph = ph->next;
		}
		if (num == 0) printf("\n当前无树，请新初始化一棵树！\n\n");
		else {
			printf("\n当前已有%d棵树！\n\n",num);
			printf("这些树的名字分别为:");
			ph = Lhead->next;
			for (int n = 1; n <= num; n++)
			{
				printf("%s ", ph->name);
				ph = ph->next;
			}
			if(L!=NULL) printf("\n\n当前操作的树的名字为：%s", L->name);
			else printf("\n\n当前无操作树，请输入23选择当前操作树！");
		}
		printf("\n\n");
		printf("      Menu for Linear Table On BiTree Structure \n");
		printf("-------------------------------------------------\n");
		printf("    	  1. InitBiTree        12. RightChild\n");
		printf("    	  2. DestroyBiTree     13. LeftSibling\n");
		printf("    	  3. CreateBiTree      14. RightSibling \n");
		printf("    	  4. ClearBitree       15. InsertChild\n");
		printf("    	  5. BiTreeEmpty       16. DeleteChild\n");
		printf("    	  6. BiTreeDepth       17. PreOrderTraverse\n");
		printf("    	  7. Root              18. InOrderTraverse\n");
		printf("    	  8. Value             19. PostOrderTraverse\n");
		printf("    	  9. Assign            20. LevelOrderTraverse\n");
		printf("    	 10. Parent            21. SaveData\n");
		printf("    	 11. LeftChild         22. LoadData\n");
		printf("    	  0. Exit              23. ChangeCurTree\n");
		printf("-------------------------------------------------\n");
		printf("    请选择你的操作[0~23]:");
		scanf("%d", &op);
		switch (op) {
		case 1://初始化一棵新树
			printf("请输入要新初始化的树的名字：\n");
			scanf("%s", name);
			if (InitBiTree(Lhead,name) == OK) {
				printf("二叉树初始化成功！\n");
			}
			else printf("初始化失败！\n");
			getchar(); getchar();
			break;
		case 2://销毁当前树
			if (L!=NULL) 
			{
				if (DestroyBiTree(Lhead, name) == OK) {
					L = NULL;
					printf("销毁该树成功！\n");
				}
				else printf("销毁失败！\n");
			}
			getchar(); getchar();
			break;
		case 3://创建树
			if (L != NULL)
			{
				printf("请输入树的元素(按照前序顺序)：\n");
				if(CreateBiTree(L->root)==OK) printf("创建树成功！\n");
				else printf("创建树失败！\n");
			}
			getchar();getchar();
			break;
		case 4://清空树
			if (L != NULL)
			{
				if (ClearBiTree(L->root) == OK) printf("清空树成功！\n");
				else printf("清空树失败！\n");
			}
			getchar(); getchar();
			break;
		case 5://判断树是否为空
			if (L != NULL)
			{
				if (BiTreeEmpty(L) == TRUE) printf("该树为空！\n");
				else printf("该树不为空！\n");
			}
			getchar(); getchar();
			break;
		case 6://求一棵树的深度
			if (L != NULL)
			{
				printf("该树的深度为 %d\n", BiTreeDepth(L->root));
			}
			getchar(); getchar();
			break;
		case 7://获得根结点
			if (L != NULL)
			{
					root = Root(L);
					printf("根结点元素为 %c",root->data);
			}
			getchar(); getchar();
			break;
		case 8://获得结点
			if (L != NULL)
			{
				char i;
				printf("请输入你要查找的结点的值：\n");
				getchar();
				scanf("%c", &i);
				if ((e = _FindPosition(L->root, i) )!= NULL)
					printf("该结点存在，且值为 %c\n", Value(e));
				else printf("该结点不存在！\n");
			}
			getchar(); getchar();
			break;
		case 9://结点赋值
			if (L != NULL)
			{
				TElemType n;
				char i;
				printf("请输入你要赋值的结点的值：\n");
				getchar();
				scanf("%c", &i);
				printf("请输入你想赋的值：\n");
				getchar();
				scanf("%c", &n);
				if ((e = _FindPosition(L->root, i)) != NULL)
				{
					if (Assign(L->root, e, n) == OK) printf("赋值成功！\n");
					else printf("赋值失败！\n");
				}
				else printf("该结点不存在！\n");
			}
			getchar(); getchar();
			break;
		case 10://获得双亲结点
			if (L != NULL)
			{
				char i;
				printf("请输入你要获得双亲的值：\n");
				getchar();
				scanf("%c", &i);
				if ((e = _FindPosition(L->root, i)) != NULL)
				{
					if (e->data==L->root->data) printf("该结点为根结点！\n");
					else {
						p = Parent(L->root, e);
						printf("该结点的双亲结点的值为： %c\n", p->data);
					}
				}
				else printf("该结点不存在！\n");
			}
			getchar(); getchar();
			break;
		case 11://获得左孩子结点
			if (L != NULL)
			{
				char i;
				printf("请输入你要获得左孩子的结点的值：\n");
				getchar();
				scanf("%c", &i);
				if ((e = _FindPosition(L->root, i)) != NULL)
				{
					p = LeftChild(L->root, e);
					if (p == NULL) printf("该结点左孩子为空结点！\n");
					else printf("该结点左孩子的值为 %c", p->data);
				}
				else printf("该结点不存在！\n");
			}
			getchar(); getchar();
			break;
		case 12://获得右孩子结点
			if (L != NULL)
			{
				char i;
				printf("请输入你要获得右孩子的结点的值：\n");
				getchar();
				scanf("%c", &i);
				if ((e = _FindPosition(L->root, i)) != NULL)
				{
					p = RightChild(L->root, e);
					if (p == NULL) printf("该结点右孩子为空结点！\n");
					else printf("该结点右孩子的值为 %c", p->data);
				}
				else printf("该结点不存在！\n");
			}
			getchar(); getchar();
			break;
		case 13://获得左兄弟结点
			if (L != NULL)
			{
				char ch;
				printf("请输入你要获得左兄弟的结点的元素值：\n");
				getchar();
				scanf("%c", &ch);
				if ((e = _FindPosition(L->root, ch)) != NULL)
				{
					p = LeftSibling(L->root, e);
					if (p == NULL) printf("无左兄弟！\n");
					else printf("左兄弟值为：%c\n", p->data);
				}
				else printf("该结点不存在！\n");
			}
			getchar(); getchar();
			break;
		case 14://获得右兄弟结点
			if (L != NULL)
			{
				char ch;
				printf("请输入你要获得右兄弟的结点的元素值：\n");
				getchar();
				scanf("%c", &ch);
				if ((e = _FindPosition(L->root, ch)) != NULL)
				{
					p = RightSibling(L->root, e);
					if (p == NULL) printf("无右兄弟！\n");
					else printf("右兄弟值为：%c\n", p->data);
				}
				else printf("该结点不存在！\n");
			}
			getchar(); getchar();
			break;
		case 15://插入子树
			if (L != NULL)
			{
				char ch;
				int i;
				printf("请输入你插入位置的结点的值：\n");
				getchar();
				scanf("%c", &ch);
				if ((e = _FindPosition(L->root, ch)) != NULL)
				{
					int LR;
					printf("插入为该结点的左子树请输入 0，插入为该结点的右子树请输入 1\n");
					scanf("%d", &LR);
					printf("插入一个新的节点请输入 0，插入一颗树请输入 1\n");
					scanf("%d", &i);
					if (i == 0)
					{
						BiTree newnode;
						newnode = (BiTree)malloc(sizeof(BiTNode));
						newnode->lchild = NULL;
						newnode->rchild = NULL;
						printf("请输入你新插入结点的值：\n");
						getchar();
						scanf("%c", &newnode->data);
						if (InsertChild(L->root, e, LR, newnode) == OK) printf("插入成功！\n");
						else printf("插入失败！\n");
					}
					if (i == 1)
					{
						printf("请输入该树的名称：\n");
						scanf("%s", name);
						if (Find(Lhead, name) != NULL)
						{
							BiTree newnode = Find(Lhead, name)->root;
							if (InsertChild(L->root, e, LR, newnode) == OK) printf("插入成功！\n");
							else printf("插入失败！\n");
						}
						else printf("该树不存在！\n");
					}
				}
				else printf("该结点不存在！\n");
			}
			getchar(); getchar();
			break;
		case 16://删除子树
			if (L != NULL)
			{
				char ch;
				int i;
				printf("请输入你删除位置的结点的值：\n");
				getchar();
				scanf("%c", &ch);
				if ((e = _FindPosition(L->root, ch)) != NULL)
				{
					int LR;
					printf("删除该结点的左子树请输入 0，删除该结点的右子树请输入 1\n");
					scanf("%d", &LR);
					if (DeleteChild(L->root, e, LR) == OK) printf("删除成功！\n");
					else printf("删除失败！\n");
				}
			}
			getchar(); getchar();
			break;
		case 17://前序遍历
			printf("先序遍历结果为：\n");
			PreOrderTraverse(L->root);
			getchar(); getchar();
			break;
		case 18://中序遍历
			printf("中序遍历结果为：\n");
			InOrderTraverse(L->root);
			getchar(); getchar();
			break;
		case 19://后序遍历
			printf("后序遍历结果为：\n");
			PostOrderTraverse(L->root);
			getchar(); getchar();
			break;
		case 20://层次遍历
			if (L != NULL)
			{
				int i = NumNode(L->root);
				BiTree treenodes[1024];
				printf("层次遍历结果为：\n");
				LevelOrderTraverse(L->root, treenodes, i + 1);
			}
			getchar(); getchar();
			break;
		case 21://保存数据
			printf("请输入文件名：\n");
			scanf("%s", filename);
			if (DataSave(L, filename) == OK) printf("数据保存成功！\n");
			else printf("数据保存失败！\n");
			getchar(); getchar();
			break;
		case 22://加载数据
			printf("请输入文件名：\n");
			scanf("%s", filename);
			FILE* fp;
			DataLoad(L, filename);
			getchar(); getchar();
			break;
		case 23://切换当前操作树
			printf("请输入需操作的树的名字！\n");
			scanf("%s", name);
			if (Find(Lhead, name) == NULL) printf("该树不存在，切换失败！\n");
			else {
				L = Find(Lhead, name);
				printf("切换成功，且当前操作树为 %s\n", L->name);
			}
			getchar(); getchar();
			break;
		case 0:
			break;
		}//end of switch
	}//end of while
	printf("欢迎下次再使用本系统！\n");
	return 0;
}//end of main
status InitBiTree(TN &L,char *name)
{//采用后进先出的方法插入结点
	TN p;	
	p = (TN)malloc(sizeof(TNode));
	if (p== NULL) return ERROR;
	p->next = L->next;
	L->next = p;
	p->root = NULL;
	strcpy(p->name, name);
	return OK;
}
status DestroyBiTree(TN &L,char *name)
{
	TN p, q;
	p = L;
	while (p->next)//找到p的前驱
	{
		if (!strcmp(p->next->name, name))//找到该树结点前驱
			break;
		p = p->next;
	}
	q = p->next;
	p->next = q->next;
	BiTree T = p->root;
	ClearBiTree(T);
	free(T);
	free(q);
	return OK;
}
status CreateBiTree(BiTree &T)//创建二叉树
{
	//先序构建二叉树
	char ch;
	while ((ch = getchar()) == '\n' || (ch == ' '))
		continue;
	if (ch == '#')   T = NULL;
	else
	{
		if (!(T = (BiTree)malloc(sizeof(BiTNode)))) return ERROR;//生成根结点
		T->data = ch;//数据域赋值
		CreateBiTree(T->lchild);//递归构造左子树
		CreateBiTree(T->rchild); //递归构造右子树
	}
	return OK;
}
status ClearBiTree(BiTree &T)
{
	if (T != NULL)
	{
		ClearBiTree(T->lchild);
		ClearBiTree(T->rchild);
		free(T);
		T = NULL;
	}
	return OK;
}
status BiTreeEmpty(TN L)
{
	if (L->root==NULL) return TRUE;//此时树为空
	return FALSE;
}
int BiTreeDepth(BiTree T)
{
	if (T != NULL) {
		if (BiTreeDepth(T->lchild) > BiTreeDepth(T->rchild))
			return BiTreeDepth(T->lchild) + 1;
		else return BiTreeDepth(T->rchild) + 1;
	}
	return 0;
}
BiTree Root(TN L)
{
	return L->root;
}
TElemType Value(BiTree T)
{
	return T->data;
}
BiTree FindPosition(BiTree T, int i)//由编号找到树中的结点
{
	BiTree p = T;
	int j, k, l;
	int point[20];
	j = i;
	k = -1;
	while(j != 1){//找到结点在第几层
		j /= 2;k++;
	}
	l = k;
	for (j = i / 2; k >= 0; k--)
	{
		point[k] = j / 2;
		j = j / 2;
	}
	k = l;
	for (l = 0; l <= k; l++)
	{
		if (point[l] == 0) p = p->lchild;
		else p = p->rchild;
	}
	if (i % 2 == 1 && p->rchild != NULL)
		return p->rchild;
	else if (i % 2 == 0 && p->lchild != NULL)
		return p->lchild;
	else return NULL;
}
status Assign(BiTree T, BiTree &e, TElemType value)
{
	if (Exist(T, e) == TRUE)
	{
		e->data = value;
		return OK;
	}
	return ERROR;
}
BiTree Parent(BiTree T, BiTree e)//获得双亲结点
{
	if ((T->lchild != NULL) || (T->rchild != NULL))
	{
		BiTree p;
		if ((T->lchild->data == e->data) || (T->rchild->data == e->data)) return T;
		else {
			if (p = Parent(T->lchild, e)) return p;
			if (p = Parent(T->rchild, e)) return p;
		}
	}
	return NULL;
}
BiTree LeftChild(BiTree T, BiTree e)//获得左孩子结点
{
	return e->lchild;
}
BiTree RightChild(BiTree T, BiTree e)//获得右孩子结点
{
	return e->rchild;
}
BiTree LeftSibling(BiTree T, BiTree e)//获得左兄弟结点
{
	BiTree parent;
	if (Parent(T, e) == NULL) return NULL;
	else {
		parent = Parent(T, e);
		if (parent->lchild->data == e->data) return NULL;
		else return parent->lchild;
	}
}
BiTree RightSibling(BiTree T, BiTree e)//获得右兄弟结点
{
	BiTree parent;
	if (Parent(T, e) == NULL) return NULL;
	else {
		parent = Parent(T, e);
		if (parent->rchild->data == e->data) return NULL;
		else return parent->rchild;
	}
}
status InsertChild(BiTree &T, BiTree &p, int LR, BiTree c)//插入子树
{
	if (Exist(T, p) == TRUE) {//结点p在树T中
		if (!LR)//插入c为T中p所指结点的左子树
		{
			if (p->lchild != NULL)//p有左子树
				c->rchild = p->lchild;
			p->lchild = c;
		}
		else//插入c为T中p所指结点的右子树
		{
			if (p->rchild != NULL)//p有右子树
				c->rchild = p->rchild;
			p->rchild = c;
		}
		return OK;
	}
	else return ERROR;
}
status DeleteChild(BiTree &T, BiTree &p, int LR)//删除子树
{
	if (!LR)//删除c为T中p所指结点的左子树
		ClearBiTree(p->lchild);
	else //删除c为T中p所指结点的右子树
		ClearBiTree(p->rchild);
	return OK;
}
void PreOrderTraverse(BiTree T)//前序遍历
{
	if (T)
	{
		printf("%c ", T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}
void InOrderTraverse(BiTree T)//中序遍历
{
	if (T)
	{	
		InOrderTraverse(T->lchild);
		printf("%c ", T->data);
		InOrderTraverse(T->rchild);
	}
}
void PostOrderTraverse(BiTree T)//后序遍历
{
	if (T)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%c ", T->data);
	}
}
status LevelOrderTraverse(BiTree &T, BiTree* tree,int i)
{
	int k, a;
	tree[0] = T;
	for (k = 1, a = 1; k <= i - 2; k++, a++) {
		if (tree[a - 1]->lchild == NULL);
		else { tree[k] = tree[a - 1]->lchild; k = k + 1; }
		if (tree[a - 1]->rchild == NULL) k--;
		else tree[k] = tree[a - 1]->rchild;
	}
	for (k = 0; k <= i - 2; k++) {
		printf("%c ", tree[k]->data);
	}
	return OK;
}
/*文件保存、加载数据功能实现*/
status DataSave(TN L, char *filename)//数据保存
{
	FILE* fp;
	if ((fp = fopen(filename, "w")) == NULL)
	{
		printf("File open error!\n ");
		return ERROR;
	}
	DataSaveUse(L->root, fp);
	fclose(fp);
	return OK;
}
void DataSaveUse(BiTNode * p, FILE * fin) {
	char c = '#';
	if (p != NULL) {
		fprintf(fin, "%c", p->data);
		DataSaveUse(p->lchild, fin);
		DataSaveUse(p->rchild, fin);
	}
	else fprintf(fin, "%c", c);
}
status DataLoad(TN &L, char *filename)//数据加载
{
	FILE* fp;
	int i,j=0;
	char temp[1024];
	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("File open error!\n ");
		return ERROR;
	}
	for (i = 0; fscanf(fp, "%c", temp + i) != EOF;i++);
	i = 0;
	if(DataLoadUse(L->root, temp, &i)==OK) printf("数据加载成功！\n");
	return OK;
}
status DataLoadUse(BiTree & T, char* temp,int *i)
{
	//先序构建二叉树
	char ch;
	ch =*(temp+*i);
	if (ch == '#') { T = NULL; i++;}
	else
	{
		if (!(T = (BiTree)malloc(sizeof(BiTNode)))) return ERROR;
		T->data = ch;//数据域赋值
		*i = *i + 1;
		DataLoadUse(T->lchild, temp, i);//递归构造左子树
		*i = *i + 1;
		DataLoadUse(T->rchild, temp, i);//递归构造右子树
	}
	return OK;

}
int NumNode(BiTree T)
{
	if (T != NULL)
	{
		return NumNode(T->lchild) + NumNode(T->rchild) + 1;
	}
	return 0;
}
TN Find(TN L, char *name)//由树名查找该树
{
	TN p;
	p = L;
	while (p)
	{
		if (!strcmp(p->name, name))//找到该树
			return p;//返回该树所在结点
		p = p->next;
	}
	return NULL;//未找到该树，返回空
}
BiTree _FindPosition(BiTree T, TElemType ch)//由值找到结点
{
	if (T == NULL) return NULL;
	if (ch == T->data) return T;
	else if (_FindPosition(T->lchild, ch) != NULL) return _FindPosition(T->lchild, ch);
	else return _FindPosition(T->rchild, ch);
}
status Exist(BiTree T, BiTree e)//判断结点是否在树中
{
	if (T == NULL || e == NULL) return FALSE;
	if (e == T) return TRUE;
	if (Exist(T->lchild, e) || Exist(T->rchild, e)) return TRUE;
	return FALSE;
}

