#include<iostream>
using namespace std;
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode,*LinkList;

LinkList H[13];    //链地址法，13个单链表

void Hash(int e)
{   
    //基于链地址法的散列表的插入
    /**************begin************/
	int k = e%13;
    LNode *T = new LNode;
    if(H[k]->next==NULL)
    {
        H[k]->next = T;
        T->data = e;
        T->next = NULL;
    } 
    else
    {
        T = H[k]->next;
        while(T->next!=NULL)
        {
            T = T->next;
        }
        LNode *T1 = new LNode;
        T->next = T1;
        T1->data = e;
        T->next->next = NULL;
    }






    /**************end************/
}


void Input(int n)
{//输入数据
	for(int i=0;i<13;i++)     //建立13个带有头结点的单链表
	{
		H[i]=new LNode;
		H[i]->next=NULL;
	}
	while(n--)          //输入n个关键字,构造散列表
	{
		int e;
		cin>>e;
		Hash(e);
	}
}


void Output()
{//输出数据
	for(int i=0;i<13;i++)
	{
		cout<<i;                 //输出散列地址
		LinkList p=H[i]->next;   //p初始化为链表的首元结点
		while(p)
		{
			cout<<" "<<p->data;
			p=p->next;
		}
		cout<<endl;
	}
}


int main()
{
	int n;
	cin>>n;
 	if(n > 0)    
	{
		Input(n);     //输入数据
		int k;      //需要插入的关键字k
		cin>>k;
		Hash(k);
		Output();  //输出数据
	}
	return 0;
}