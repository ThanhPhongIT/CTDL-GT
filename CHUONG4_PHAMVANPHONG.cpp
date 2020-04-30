#include<iostream>
using namespace std;

struct NODE
{
    int data;
    NODE* pLeft;
    NODE* pRight;
};
NODE* CreateNode(int x)
{
    NODE* p = new NODE();
    p->data = x;
    p->pLeft = p->pRight = NULL;
    return p;
}
NODE* FindInsert(NODE* root, int x)
{
    if (root == NULL)
    {
        return NULL;
    }
    NODE* p = root;
    NODE* f = p;
    while (p != NULL)
    {
        f = p;
        if (p->data > x)
        {
            p = p->pLeft;
        }
        else
        {
            p = p->pRight;
        }
    }        
    return f;
}
void InsertNode(NODE* &root, int x)
{
    NODE* n = CreateNode(x);
    if (root == NULL)
    {
        root = n;
        return;
    }
    else
    {
        NODE* f = FindInsert(root, x);
        if (f != NULL)
        {
            if (f->data > x)
            {
                f->pLeft = n;
            }
            else
            {
                f->pRight = n;
            }
        }
    }
}
void CreateTree(NODE* &root, int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        InsertNode(root, a[i]);
    }
}
int SearchNode_Re(NODE* root, int &x)
{
    if (root == NULL)
        return 0;
 
	if (root->data == x)
	{
		return 1;
	}
	if (root->data > x)
	{
		SearchNode_Re(root->pLeft, x);
	}
	else
	{
		SearchNode_Re(root->pRight, x);
	}
}
void Ghep(NODE* &R1,NODE* R2)
{
	if(R1 == NULL)
		R1=R2;
	else Ghep(R1->pRight,R2);
}
NODE* Cha(NODE* Root, int &u, NODE* Q)
{
	NODE* M=Root;
	while (1)
	{
		if (Q->data<M->data)
		if (M->pLeft==Q){
		u=-1; 
		return M;
	}
	else M = M->pLeft;
	else if (M->pRight==Q){
	u=1; 
	return M;
	}
	else M=M->pRight;
	}
}
void Xoa(NODE* &Root, NODE* Q)
{
	int u;
	NODE* M;
	Ghep(Q->pLeft, Q->pRight);
	if (Q==Root) Root=Root->pLeft;
	else{
	M = Cha(Root, u, Q);
	if (u==-1)
	M->pLeft= Q->pLeft;
	else M->pRight= Q->pLeft;
	}
	delete Q;
}
void NLR(NODE* root)
{
	if (root != NULL)
	{
		cout<<root->data<<"  ";
		NLR(root->pLeft);
		NLR(root->pRight);
	}
}

int main(){
	NODE* root = NULL;
	int a[] = {15,7,24,2,10,20,34,9,12,55};
	int n = 10;
	CreateTree(root,a,n);
	cout<<"Cay vua duyet theo thu tu truoc la:"<<endl;
	NLR(root);
	cout<<endl;
	InsertNode(root, 28);
	cout<<"Cay vua them nut 28 va duyet theo thu tu truoc la:"<<endl;
	NLR(root);
	int k;
	cout<<"\nNhap vao khoa k: ";	cin>>k;
	if(SearchNode_Re(root, k) == 0){
		cout<<"khong co khoa k tren cay!"<<endl;
	}else{
		NODE* n = CreateNode(k);
		Xoa(root,n);
		NLR(root);
	};
	
	return 0;
}


