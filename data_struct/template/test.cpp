#include <iostream>					// 编译预处理命令
using namespace std;				// 使用命名空间std 

/*// 结点类
struct Node
{
	// 数据成员:
	int data;		// 数据成分
	Node* next;		// 指针成分

	// 无参数的构造函数模板
	Node() { data = 0; next = nullptr; };
	// 已知数据元素值和指针建立结点
	Node(const int& e, Node* link = nullptr) { data = e;next = link; };
};


int josephus(int n, int k) {
	// 创建循环链表  
	Node* head = new Node(1);
	Node* tail = head;
	for (int i = 2; i <= n; i++) {
		tail->next = new Node(i);
		tail = tail->next;
	}
	tail->next = head;

    //------------------------------------begin----------------------------
	// 删除节点,直到剩下最后一个节点  
	int last_val;
	Node* m = tail;
    for(int i=1; i<=n-1; i++)
    {
        for(int j=1; j<=k-1; j++)
        {
            m = m->next;
        }
		Node* kill = m->next;
        m->next = m->next->next;
		delete kill;
    }
    last_val = m->data;
    // 输出最后剩下的节点
    return last_val;
    //------------------------------------begin----------------------------
}

int main() {
	int step = 3;
	int num = 0;
	cin >> num;
	int last_val= josephus(num, step);
	cout<< last_val;
	system("pause");
	return 0;
}*/
int main(){
	int m;
	int *direc = new int[m+1];
	m = 1;
	for(int k = 0;k<10;k++)
	{
		m++;
		direc[m] = k;
	}
	return 0;
}