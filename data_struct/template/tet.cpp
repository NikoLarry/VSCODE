#include<iostream>
#include<math.h>
using namespace std; 


// 循环列表约瑟夫问题
struct Node
{   
    int data;
    Node* next;
    Node(){data = 0; next = nullptr;};
    Node(const int& i, Node* link = nullptr)
    {
    data = i;
    next = link;
    };
};
int josef(int n,int k=3)
{
    //创个链表
    Node* head = new Node(1);           //创建头结点
    Node* tail = head;                  // 初始时末尾结点的指针指在头结点上
    for(int i=2;i<=n;i++)                //插尾法循环生成新节点
    {
        tail->next = new Node(i);       //末尾结点指针的地址域赋值为下一节点地址
        tail = tail->next;              // 末尾结点更新为新生成结点
    }
    tail->next = head;                  //最后末尾节点指向开头

    // 循环出局
    Node* ptr = tail;
    while (ptr->next != ptr)          //指针的地址域不是本身说明省下不止一人
    {
        for(int i=1;i<k;i++)    
        {   
            ptr = ptr->next;            // 指针不断移动到out人之前停下来
        }
        Node* out = ptr->next;          // 取出out的结点地址
        ptr->next = ptr->next->next;    // 跳过out的结点与下一节点连接
        delete out;                     // 释放out 结点
    }

    int last = ptr->data;
    delete ptr;
    return last;
}

int main()
{
    int n,k=3;
    cin >> n;
    int x = josef(n,k);
    cout << x;
    system("pause");
    return 0;
}






/* double f(double x){
    double a =exp(-0.05*x)*sin(0.1*M_PI*x);
    return a;
}
double g(double x){
    double a =exp(-0.05*x)*cos(0.15*M_PI*x);
    return a;
}
main(){
    double a;
    double b[8]={0,1,2,2,2};
    cout<<f(a)<<endl;
    cout<<g(a)<<endl;
    system("pause");
    return 0;
} */
/* input
main(){
    int a[10],i,b;
    for(i=0;i<10;i++)
    {
        scanf("%d",&b);
        a[i]=b;
    }
    for(i=0;i<30;i++)
    {a[i]=i;}
    for(i=0;i<30;i++)
    for(i=0;i<10;i++)
    {printf("%d",a[i]);}
    cout<<a[5];
    system("pause");
    return 0;


} */
/* YangHuitriangle
main(){
    int n;
    cin>>n;
    int a[n][n],i,j;
    for(i=0;i<n;i++)
        {for(j=0;j<i+1;j++){
            if(i==j||j==0){
                a[i][j]=1;
            }
            else
                a[i][j]=a[i-1][j]+a[i-1][j-1];
            cout<<a[i][j]<<"\t";}
        cout<<"\n";}
    system("pause");
    return 0;
}  */
