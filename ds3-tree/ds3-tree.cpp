// ds3-tree.cpp: 定义控制台应用程序的入口点。
//

#include"stdafx.h"
#include <stdio.h> 
#include <stdlib.h>
#include <malloc.h>
#include <iostream>
typedef int DataType;
using namespace std;

typedef struct BitNode{ 
	DataType data;
	struct BitNode *lchild, *rchild;
}BitNode,*BitTree;

int BinTreeInit(BitTree *BT) {
	return NULL;
}
void BinTreeCreat(BitTree &BT) {
	int ch;
	cin >> ch;
	if (ch == '#')
		BT = NULL;
	else {
		BT = new BitNode;
		BT->data = ch;
		BinTreeCreat(BT->lchild);
		BinTreeCreat(BT->rchild);
	}
}
int main()
{
    return 0;
}

