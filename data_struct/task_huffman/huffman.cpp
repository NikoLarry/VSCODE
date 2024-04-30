#include <iostream>
#include <fstream>
#include <string.h>
#include <cmath>
#include<stdio.h>
#include<stdlib.h>
#include "huffman.h"
using namespace std;
//////////////////////////////// 
/*
编译环境 -std=c++11 
该程序对空格和换行符均编码，默认当输入为回车且前一个字符不是.时结束,若想输入多行，在回车前加上英文句号. 
*/
/////////////////////////////

//主函数，初始化变量，调用其他函数 
int main()
{
	int length=0; 
	int char_table[128]={0};
	unsigned char char_name[128]={'a'};
	int count=0;

////////////////////////////////////////////////////////////  案例 
	// unsigned char src_data[13]={"happppyyaaaa"};length=12;
	//unsigned char src_data[16]={"abbbdddddeeeeee"};length=15;
/////////////////////////////////////////////////////////////
	string src_string;
	cin >> src_string;
	unsigned char src_data[256];
	memset(src_data, 0, 256);
	memcpy(src_data, src_string.c_str(), src_string.size());
	length = src_string.size();
	// ASCII码表中前128个
	for (int j=0;j<128;j++)
	{
		char_name[j]=j;
	}

	// 统计频次
	count_freq(char_table, src_data, length);
	
	// 统计源文本中出现的字符数量
	for (int j=0; j < 128; j++) {
		if (char_table[j] != 0) {
			count += 1;
		}
	}
	
	unsigned char *new_char_name = new unsigned char[count];
	int *new_char_table = new int[count];
	
	// 
	int index = 0;
	for (int j=0; j < 128; j++) {
		if (char_table[j] != 0) {
			new_char_name[index] = char_name[j];
			new_char_table[index] = char_table[j];
			index += 1;
		}
	}


	// 对频次进行排序
	sort(new_char_table, new_char_name, count);

	// 构建哈夫曼树 
	HuffTree hf(new_char_name, new_char_table, count);
	hf.BuildTree();

	// 构建哈夫曼编码表
	string code;
	code.clear();
	cout<<"code table:"<<endl;
	hf.BuildEncode(hf.root,code);
	for(int i=3;i<hf.len+3;i++)
	{
		cout << hf.vec_name[i%4] << ":" << hf.encode_table[hf.vec_name[i%4]] << endl;
	}

	// 对源数据进行编码
	string encoded_data;
	for (int j=0; j<length; ++j) {
		encoded_data += hf.encode_table[src_data[j]];
	}

	cout<<"encoded data:"<<endl;
	cout << encoded_data << endl;

	// 哈夫曼解码 
	string unpack_code;
	unpack_code.clear();
	hf.Unpack(encoded_data, unpack_code);		
	cout<<"decoded data:"<<endl;
	cout<<unpack_code << endl;
	return 0;
}

