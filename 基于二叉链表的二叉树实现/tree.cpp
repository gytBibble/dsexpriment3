#include "tree.h"
int main(void)
{
	int op = 1;
	int num;//��ǰ���е�����
	char name[20];
	char filename[30];
	BiTree root,e,p;//���ĸ����ʹ��ý��
	TN Lhead=NULL,L=NULL;//˳����ͷ���ʹ��ý��
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
		if (num == 0) printf("\n��ǰ���������³�ʼ��һ������\n\n");
		else {
			printf("\n��ǰ����%d������\n\n",num);
			printf("��Щ�������ֱַ�Ϊ:");
			ph = Lhead->next;
			for (int n = 1; n <= num; n++)
			{
				printf("%s ", ph->name);
				ph = ph->next;
			}
			if(L!=NULL) printf("\n\n��ǰ��������������Ϊ��%s", L->name);
			else printf("\n\n��ǰ�޲�������������23ѡ��ǰ��������");
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
		printf("    ��ѡ����Ĳ���[0~23]:");
		scanf("%d", &op);
		switch (op) {
		case 1://��ʼ��һ������
			printf("������Ҫ�³�ʼ�����������֣�\n");
			scanf("%s", name);
			if (InitBiTree(Lhead,name) == OK) {
				printf("��������ʼ���ɹ���\n");
			}
			else printf("��ʼ��ʧ�ܣ�\n");
			getchar(); getchar();
			break;
		case 2://���ٵ�ǰ��
			if (L!=NULL) 
			{
				if (DestroyBiTree(Lhead, name) == OK) {
					L = NULL;
					printf("���ٸ����ɹ���\n");
				}
				else printf("����ʧ�ܣ�\n");
			}
			getchar(); getchar();
			break;
		case 3://������
			if (L != NULL)
			{
				printf("����������Ԫ��(����ǰ��˳��)��\n");
				if(CreateBiTree(L->root)==OK) printf("�������ɹ���\n");
				else printf("������ʧ�ܣ�\n");
			}
			getchar();getchar();
			break;
		case 4://�����
			if (L != NULL)
			{
				if (ClearBiTree(L->root) == OK) printf("������ɹ���\n");
				else printf("�����ʧ�ܣ�\n");
			}
			getchar(); getchar();
			break;
		case 5://�ж����Ƿ�Ϊ��
			if (L != NULL)
			{
				if (BiTreeEmpty(L) == TRUE) printf("����Ϊ�գ�\n");
				else printf("������Ϊ�գ�\n");
			}
			getchar(); getchar();
			break;
		case 6://��һ���������
			if (L != NULL)
			{
				printf("���������Ϊ %d\n", BiTreeDepth(L->root));
			}
			getchar(); getchar();
			break;
		case 7://��ø����
			if (L != NULL)
			{
					root = Root(L);
					printf("�����Ԫ��Ϊ %c",root->data);
			}
			getchar(); getchar();
			break;
		case 8://��ý��
			if (L != NULL)
			{
				char i;
				printf("��������Ҫ���ҵĽ���ֵ��\n");
				getchar();
				scanf("%c", &i);
				if ((e = _FindPosition(L->root, i) )!= NULL)
					printf("�ý����ڣ���ֵΪ %c\n", Value(e));
				else printf("�ý�㲻���ڣ�\n");
			}
			getchar(); getchar();
			break;
		case 9://��㸳ֵ
			if (L != NULL)
			{
				TElemType n;
				char i;
				printf("��������Ҫ��ֵ�Ľ���ֵ��\n");
				getchar();
				scanf("%c", &i);
				printf("���������븳��ֵ��\n");
				getchar();
				scanf("%c", &n);
				if ((e = _FindPosition(L->root, i)) != NULL)
				{
					if (Assign(L->root, e, n) == OK) printf("��ֵ�ɹ���\n");
					else printf("��ֵʧ�ܣ�\n");
				}
				else printf("�ý�㲻���ڣ�\n");
			}
			getchar(); getchar();
			break;
		case 10://���˫�׽��
			if (L != NULL)
			{
				char i;
				printf("��������Ҫ���˫�׵�ֵ��\n");
				getchar();
				scanf("%c", &i);
				if ((e = _FindPosition(L->root, i)) != NULL)
				{
					if (e->data==L->root->data) printf("�ý��Ϊ����㣡\n");
					else {
						p = Parent(L->root, e);
						printf("�ý���˫�׽���ֵΪ�� %c\n", p->data);
					}
				}
				else printf("�ý�㲻���ڣ�\n");
			}
			getchar(); getchar();
			break;
		case 11://������ӽ��
			if (L != NULL)
			{
				char i;
				printf("��������Ҫ������ӵĽ���ֵ��\n");
				getchar();
				scanf("%c", &i);
				if ((e = _FindPosition(L->root, i)) != NULL)
				{
					p = LeftChild(L->root, e);
					if (p == NULL) printf("�ý������Ϊ�ս�㣡\n");
					else printf("�ý�����ӵ�ֵΪ %c", p->data);
				}
				else printf("�ý�㲻���ڣ�\n");
			}
			getchar(); getchar();
			break;
		case 12://����Һ��ӽ��
			if (L != NULL)
			{
				char i;
				printf("��������Ҫ����Һ��ӵĽ���ֵ��\n");
				getchar();
				scanf("%c", &i);
				if ((e = _FindPosition(L->root, i)) != NULL)
				{
					p = RightChild(L->root, e);
					if (p == NULL) printf("�ý���Һ���Ϊ�ս�㣡\n");
					else printf("�ý���Һ��ӵ�ֵΪ %c", p->data);
				}
				else printf("�ý�㲻���ڣ�\n");
			}
			getchar(); getchar();
			break;
		case 13://������ֵܽ��
			if (L != NULL)
			{
				char ch;
				printf("��������Ҫ������ֵܵĽ���Ԫ��ֵ��\n");
				getchar();
				scanf("%c", &ch);
				if ((e = _FindPosition(L->root, ch)) != NULL)
				{
					p = LeftSibling(L->root, e);
					if (p == NULL) printf("�����ֵܣ�\n");
					else printf("���ֵ�ֵΪ��%c\n", p->data);
				}
				else printf("�ý�㲻���ڣ�\n");
			}
			getchar(); getchar();
			break;
		case 14://������ֵܽ��
			if (L != NULL)
			{
				char ch;
				printf("��������Ҫ������ֵܵĽ���Ԫ��ֵ��\n");
				getchar();
				scanf("%c", &ch);
				if ((e = _FindPosition(L->root, ch)) != NULL)
				{
					p = RightSibling(L->root, e);
					if (p == NULL) printf("�����ֵܣ�\n");
					else printf("���ֵ�ֵΪ��%c\n", p->data);
				}
				else printf("�ý�㲻���ڣ�\n");
			}
			getchar(); getchar();
			break;
		case 15://��������
			if (L != NULL)
			{
				char ch;
				int i;
				printf("�����������λ�õĽ���ֵ��\n");
				getchar();
				scanf("%c", &ch);
				if ((e = _FindPosition(L->root, ch)) != NULL)
				{
					int LR;
					printf("����Ϊ�ý��������������� 0������Ϊ�ý��������������� 1\n");
					scanf("%d", &LR);
					printf("����һ���µĽڵ������� 0������һ���������� 1\n");
					scanf("%d", &i);
					if (i == 0)
					{
						BiTree newnode;
						newnode = (BiTree)malloc(sizeof(BiTNode));
						newnode->lchild = NULL;
						newnode->rchild = NULL;
						printf("���������²������ֵ��\n");
						getchar();
						scanf("%c", &newnode->data);
						if (InsertChild(L->root, e, LR, newnode) == OK) printf("����ɹ���\n");
						else printf("����ʧ�ܣ�\n");
					}
					if (i == 1)
					{
						printf("��������������ƣ�\n");
						scanf("%s", name);
						if (Find(Lhead, name) != NULL)
						{
							BiTree newnode = Find(Lhead, name)->root;
							if (InsertChild(L->root, e, LR, newnode) == OK) printf("����ɹ���\n");
							else printf("����ʧ�ܣ�\n");
						}
						else printf("���������ڣ�\n");
					}
				}
				else printf("�ý�㲻���ڣ�\n");
			}
			getchar(); getchar();
			break;
		case 16://ɾ������
			if (L != NULL)
			{
				char ch;
				int i;
				printf("��������ɾ��λ�õĽ���ֵ��\n");
				getchar();
				scanf("%c", &ch);
				if ((e = _FindPosition(L->root, ch)) != NULL)
				{
					int LR;
					printf("ɾ���ý��������������� 0��ɾ���ý��������������� 1\n");
					scanf("%d", &LR);
					if (DeleteChild(L->root, e, LR) == OK) printf("ɾ���ɹ���\n");
					else printf("ɾ��ʧ�ܣ�\n");
				}
			}
			getchar(); getchar();
			break;
		case 17://ǰ�����
			printf("����������Ϊ��\n");
			PreOrderTraverse(L->root);
			getchar(); getchar();
			break;
		case 18://�������
			printf("����������Ϊ��\n");
			InOrderTraverse(L->root);
			getchar(); getchar();
			break;
		case 19://�������
			printf("����������Ϊ��\n");
			PostOrderTraverse(L->root);
			getchar(); getchar();
			break;
		case 20://��α���
			if (L != NULL)
			{
				int i = NumNode(L->root);
				BiTree treenodes[1024];
				printf("��α������Ϊ��\n");
				LevelOrderTraverse(L->root, treenodes, i + 1);
			}
			getchar(); getchar();
			break;
		case 21://��������
			printf("�������ļ�����\n");
			scanf("%s", filename);
			if (DataSave(L, filename) == OK) printf("���ݱ���ɹ���\n");
			else printf("���ݱ���ʧ�ܣ�\n");
			getchar(); getchar();
			break;
		case 22://��������
			printf("�������ļ�����\n");
			scanf("%s", filename);
			FILE* fp;
			DataLoad(L, filename);
			getchar(); getchar();
			break;
		case 23://�л���ǰ������
			printf("��������������������֣�\n");
			scanf("%s", name);
			if (Find(Lhead, name) == NULL) printf("���������ڣ��л�ʧ�ܣ�\n");
			else {
				L = Find(Lhead, name);
				printf("�л��ɹ����ҵ�ǰ������Ϊ %s\n", L->name);
			}
			getchar(); getchar();
			break;
		case 0:
			break;
		}//end of switch
	}//end of while
	printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
	return 0;
}//end of main
status InitBiTree(TN &L,char *name)
{//���ú���ȳ��ķ���������
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
	while (p->next)//�ҵ�p��ǰ��
	{
		if (!strcmp(p->next->name, name))//�ҵ��������ǰ��
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
status CreateBiTree(BiTree &T)//����������
{
	//���򹹽�������
	char ch;
	while ((ch = getchar()) == '\n' || (ch == ' '))
		continue;
	if (ch == '#')   T = NULL;
	else
	{
		if (!(T = (BiTree)malloc(sizeof(BiTNode)))) return ERROR;//���ɸ����
		T->data = ch;//������ֵ
		CreateBiTree(T->lchild);//�ݹ鹹��������
		CreateBiTree(T->rchild); //�ݹ鹹��������
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
	if (L->root==NULL) return TRUE;//��ʱ��Ϊ��
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
BiTree FindPosition(BiTree T, int i)//�ɱ���ҵ����еĽ��
{
	BiTree p = T;
	int j, k, l;
	int point[20];
	j = i;
	k = -1;
	while(j != 1){//�ҵ�����ڵڼ���
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
BiTree Parent(BiTree T, BiTree e)//���˫�׽��
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
BiTree LeftChild(BiTree T, BiTree e)//������ӽ��
{
	return e->lchild;
}
BiTree RightChild(BiTree T, BiTree e)//����Һ��ӽ��
{
	return e->rchild;
}
BiTree LeftSibling(BiTree T, BiTree e)//������ֵܽ��
{
	BiTree parent;
	if (Parent(T, e) == NULL) return NULL;
	else {
		parent = Parent(T, e);
		if (parent->lchild->data == e->data) return NULL;
		else return parent->lchild;
	}
}
BiTree RightSibling(BiTree T, BiTree e)//������ֵܽ��
{
	BiTree parent;
	if (Parent(T, e) == NULL) return NULL;
	else {
		parent = Parent(T, e);
		if (parent->rchild->data == e->data) return NULL;
		else return parent->rchild;
	}
}
status InsertChild(BiTree &T, BiTree &p, int LR, BiTree c)//��������
{
	if (Exist(T, p) == TRUE) {//���p����T��
		if (!LR)//����cΪT��p��ָ����������
		{
			if (p->lchild != NULL)//p��������
				c->rchild = p->lchild;
			p->lchild = c;
		}
		else//����cΪT��p��ָ����������
		{
			if (p->rchild != NULL)//p��������
				c->rchild = p->rchild;
			p->rchild = c;
		}
		return OK;
	}
	else return ERROR;
}
status DeleteChild(BiTree &T, BiTree &p, int LR)//ɾ������
{
	if (!LR)//ɾ��cΪT��p��ָ����������
		ClearBiTree(p->lchild);
	else //ɾ��cΪT��p��ָ����������
		ClearBiTree(p->rchild);
	return OK;
}
void PreOrderTraverse(BiTree T)//ǰ�����
{
	if (T)
	{
		printf("%c ", T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}
void InOrderTraverse(BiTree T)//�������
{
	if (T)
	{	
		InOrderTraverse(T->lchild);
		printf("%c ", T->data);
		InOrderTraverse(T->rchild);
	}
}
void PostOrderTraverse(BiTree T)//�������
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
/*�ļ����桢�������ݹ���ʵ��*/
status DataSave(TN L, char *filename)//���ݱ���
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
status DataLoad(TN &L, char *filename)//���ݼ���
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
	if(DataLoadUse(L->root, temp, &i)==OK) printf("���ݼ��سɹ���\n");
	return OK;
}
status DataLoadUse(BiTree & T, char* temp,int *i)
{
	//���򹹽�������
	char ch;
	ch =*(temp+*i);
	if (ch == '#') { T = NULL; i++;}
	else
	{
		if (!(T = (BiTree)malloc(sizeof(BiTNode)))) return ERROR;
		T->data = ch;//������ֵ
		*i = *i + 1;
		DataLoadUse(T->lchild, temp, i);//�ݹ鹹��������
		*i = *i + 1;
		DataLoadUse(T->rchild, temp, i);//�ݹ鹹��������
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
TN Find(TN L, char *name)//���������Ҹ���
{
	TN p;
	p = L;
	while (p)
	{
		if (!strcmp(p->name, name))//�ҵ�����
			return p;//���ظ������ڽ��
		p = p->next;
	}
	return NULL;//δ�ҵ����������ؿ�
}
BiTree _FindPosition(BiTree T, TElemType ch)//��ֵ�ҵ����
{
	if (T == NULL) return NULL;
	if (ch == T->data) return T;
	else if (_FindPosition(T->lchild, ch) != NULL) return _FindPosition(T->lchild, ch);
	else return _FindPosition(T->rchild, ch);
}
status Exist(BiTree T, BiTree e)//�жϽ���Ƿ�������
{
	if (T == NULL || e == NULL) return FALSE;
	if (e == T) return TRUE;
	if (Exist(T->lchild, e) || Exist(T->rchild, e)) return TRUE;
	return FALSE;
}

