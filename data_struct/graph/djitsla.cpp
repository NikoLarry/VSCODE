#include<iostream>

#define MAXSIZE 100                    //最大数量
#define MaxInt 32767                   //最大值

#define OK 1
#define ERROR 0
#define OVERFLOW -2

using namespace std;


/////////////////////////////////////////////////////
// 顺序栈类模板
template<class ElemType>
class SqStack
{
protected:
    // 数据成员:
    ElemType* elems;												// 元素存储空间
    int maxSize;													// 栈最大元素个数
    int count;														// 元素个数

public:
    // 抽象数据类型方法声明及重载编译系统默认方法声明:
    SqStack(int size);								                // 构造函数模板
    bool Empty() const;												// 判断栈是否为空
    bool Push(const ElemType& e);									// 入栈
    bool Pop(ElemType& e);											// 出栈
};


// 顺序栈类模板的实现部分
template<class ElemType>
SqStack<ElemType>::SqStack(int size)
// 操作结果：构造一个最大元素个数为size的空栈
{
    maxSize = size;													// 最大元素个数
    elems = new ElemType[maxSize];									// 分配存储空间
    count = 0;														// 空栈元素个数为0
}

template<class ElemType>
bool SqStack<ElemType>::Empty() const
// 操作结果：如栈为空，则返回true，否则返回false
{
    return count == 0;												// count == 0表示栈为空
}

template<class ElemType>
bool SqStack<ElemType>::Push(const ElemType& e)
// 操作结果：将元素e追加到栈顶,如成功则返加true,如栈已满将返回false
{
    if (count == maxSize)
    {	// 栈已满
        return false;												// 入栈失败
    }
    else
    {	// 操作成功
        elems[count] = e;											// 将元素e追加到栈顶 
        count++;													// 入栈成功后元素个数自加1 
        return true;												// 入栈成功
    }
}

template<class ElemType>
bool SqStack<ElemType>::Pop(ElemType& e)
// 操作结果：如栈非空,删除栈顶元素,并用e返回栈顶元素,返回true,否则
//	返回false
{
    if (Empty())
    {	// 栈空
        return false;												// 失败
    }
    else
    {	// 操作成功
        e = elems[count - 1];										// 用e返回栈顶元素
        count--;													// 出栈成功后元素个数自减1
        return true;												// 成功
    }
}
/////////////////////////////////////////////////////


int Dist[MAXSIZE];        //Dist[i]记录从源到终端的当前最短
int Path[MAXSIZE];        //路径[i]记录是从源到终端上vi的当前最小序列号


typedef struct DAGraph
{
    char vexs[MAXSIZE];                 //顶点表
    int  arcs[MAXSIZE][MAXSIZE];        //邻接矩阵
    int  vexnum;                        //顶点总数
    int  arcnum;                        //图中边的总数
} DAGraph;

//根据给定顶点值，查找对应序号
int LocateVex(DAGraph G, char u)
{
    for (int i = 0; i < G.vexnum; i++)
    {
		if (u == G.vexs[i]) return i;
    }
    return ERROR;
}

//根据给定顶点序号，查找对应顶点值
char OrigialVex(DAGraph G, int u)
{
    return G.vexs[u];
}


//用邻接矩阵保存图信息
int CreateGraph(DAGraph& G, int spot, int edge)
{
    G.vexnum=spot;
    G.arcnum=edge;
    int i,j,k,w;
    char v1,v2;
    for(i=0;i<G.vexnum;++i)
        cin>>G.vexs[i];       //输入
    for(i=0;i<G.vexnum;++i) 
        for(j=0;j<G.vexnum;++j)
            G.arcs[i][j]=MaxInt;
    for(k=0;k<G.arcnum;++k)                     
    {
        cin>>v1>>v2>>w;       ///输入附着到第一个面板的标签
        i=LocateVex(G, v1);
        j=LocateVex(G, v2);  //确定v1和2之间的位置
        G.arcs[i][j]=w;    
    }
    return OK;
}


void ShortestPath_DIJ(DAGraph G, char V)
{
	//用Dijkstra算法求有向网G的v0顶点到其余顶点的最短路径
    /**************begin************/
    int v0 = LocateVex(G, V);
    int find[G.vexnum];
    int j;
    for(int i=0;i<G.vexnum;i++)
    {
        Dist[i] = G.arcs[v0][i];
        Path[i] = -1;
        find[i] = 0;
    }
    find[v0] = 1;
    Dist[v0] = 0;
    for(j=1;j<G.vexnum;j++)
    {
        int min = MaxInt;
        for(int w=0;w<G.vexnum;w++)//找最出当前最小权值
        {
            if(!find[w] && Dist[w]<min)
            {
                j = w;
                min = Dist[w];
            }
        }
        find[j] = 1;
        for(int k=0;k<G.vexnum;k++) //修正最小值
        {
            if(find[k]!=1 && ((min+G.arcs[j][k])<Dist[k]))
            {
                Dist[k] =  min+G.arcs[j][k];
                Path[k] = j;
            }
        }
    }
    /**************begin************/
}

//打印从起点到顶点V的最短路径序列
void PrintPath(DAGraph G, int v)
{
    SqStack<int> S(100);
    int index = Path[v];
    while (index != -1)
    {
        S.Push(index);
        index = Path[index];
    }
    while (!S.Empty())
    {
        S.Pop(index);
        cout << OrigialVex(G, index) << " ";
    }
    cout << OrigialVex(G, v) << endl;
}


int main()
{
    char a, b;
    int n, m;
    cin >> n >> m;
    if (n != 0 && m != 0) 
    {
        DAGraph G;
        CreateGraph(G, n, m);          //创建图
        cin>>a>>b;                     //输入起点,输入终点
        ShortestPath_DIJ(G, a);        //搜索最短路径                     
        int v = LocateVex(G, b);       //找到终点的序号
        cout << Dist[v] << endl;       //输出起点到终点的距离
        cout << a <<' ';
        PrintPath(G, v);               //输出起点到终点的路径
    }
    return 0;
}