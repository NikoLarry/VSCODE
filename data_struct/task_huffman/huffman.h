#include<iostream>
#include<string.h>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;


//冒泡排序法，按每个字符出现次数由小到大排 
// char_table为排序后的频次结果
// char_name为排序后的字符数组
// count为数量
void sort(int char_table[], unsigned char char_name[], int count)                 
{
    int temp;
    char temp_name;
    for (int i=count-2; i>=0; i--)
    {
        for (int j=0; j<=i;j++)
        {
            if (char_table[j]>char_table[j+1])
            {
                temp=char_table[j];
                temp_name=char_name[j];
                char_table[j]=char_table[j+1];
                char_name[j]=char_name[j+1];
                char_table[j+1]=temp;
                char_name[j+1]=temp_name;
            }
        }
    }
}


// 统计字符出现的频次
// char_table为频次结果
// src_data为字符数组
// length为输入数据长度
void count_freq(int char_table[], unsigned char src_data[], int length)
{
    for (int j=0;j<length;j++)
    {
        (char_table[src_data[j]])++;
    }
}




//定义结点类，有左右结点
class Node
{
	public:
		int count;
		unsigned char name;
		Node* left;
		Node* right;
		Node():
			left(nullptr),right(nullptr){}		//构造函数 
		Node(unsigned char char_name, int char_count):			
			left(nullptr),right(nullptr),count(char_count),name(char_name){}
		Node(const Node& node)											//拷贝函数	
			{
				count=node.count;
				name=node.name;
				if (node.left)
				{
					left=new Node();
					*left=*node.left;
				}
				else
					left=nullptr;
				if (node.right)
				{
					right=new Node();
					*right=*node.right;
				}
				else
					right=nullptr;
			}
		bool operator < (const Node& node) const			//重载< 
		{											
			return count > node.count;
		}
};


//定义哈夫曼树类 
class HuffTree
{     
	public:
		Node* root;			        			//头结点

        int len;					            // 字符类型数量
		vector<int> vec_count; 		            // 权重容器，用于存放各个字符出现的频次
		vector<unsigned  char> vec_name; 		// 字符名容器，用于存放字符
		unordered_map<unsigned char, string> encode_table; 	//编码表，存放各个字符对应的哈夫曼编码 
		 
		//构造函数，char_name为字符名数组，char_table为字符出现次数数组，n为字符类型数量 
		HuffTree(unsigned char char_name[],int char_table[],int n)		
		{
			for (int i=0;i<n;i++)
			{
				vec_count.push_back(char_table[i]);			//从小到大排序 
				vec_name.push_back(char_name[i]);
			}
			len=n;
		}

		//生成哈夫曼树 
		void BuildTree()
		{
			//------------------begin----------------
			{
				priority_queue<Node> pq;

				// 将字符频次和字符名作为叶子节点加入优先队列
				for (int i = 0; i < len; i++)
				{
					Node* leaf = new Node(vec_name[i], vec_count[i]);
					pq.push(*leaf);
				}

				// 构建哈夫曼树
				while (pq.size() > 1)
				{
					Node* left = new Node(pq.top());
					pq.pop();
					Node* right = new Node(pq.top());
					pq.pop();

					// 创建新的父节点，左子节点为出队的较小节点，右子节点为出队的较大节点
					Node* parent = new Node('$', left->count + right->count);
					parent->left = left;
					parent->right = right;

					pq.push(*parent);
				}

				// 根节点即为哈夫曼树的根
				root = new Node(pq.top());
		}





            //------------------end-------------------
		}


		//根据哈夫曼树生成编码,node是结点,code是该结点对应编码 
		void BuildEncode(Node* node,string code)
		{
			//------------------begin---------------- 
			if(node == nullptr)
				return;
            if(node->left == nullptr && node->right == nullptr)
			{
				encode_table[node->name] = code;
        		return;
			}                                                                                                            
			BuildEncode(node->left, code + '0');
			BuildEncode(node->right, code + '1');

            //------------------end-------------------
		}


		//判断是node结点否为字符的编码
		bool IsEmpty(Node* node) { return (node==nullptr)? 1:0; }
		bool IsEncode(Node* node)			
		{
			if (!IsEmpty(node))
			{
				if (node->left==nullptr && node->right==nullptr)
					return true;
			}
			return false;
		}

		
		//解压函数，code为编码，res存放解码后的结果 
		void Unpack(string code,string &res)					
		{

			//------------------begin---------------- 
		Node* current = root;
		for (char c : code)
		{
			if (c == '0')
			{
				current = current->left;
			}
			else if (c == '1')
			{
				current = current->right;
			}

			// 判断当前节点是否为叶子节点
			if (current->left == nullptr && current->right == nullptr)
			{
				res += current->name;
				current = root; // 重置为根节点，继续下一个编码的解码
			}
    	}



            //------------------end-------------------
		}
};


