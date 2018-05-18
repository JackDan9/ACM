
#include <stdio.h>
#include <stdlib.h>
// #include <stdafx.h>
// #include "stdafx.h"

#define MAXCODELEN 7
#define MAXWEIGHT 10000

struct tagHuffmanNode
{
    int m_nWeight;
    int m_nParent;
    int m_nLChild;
    int m_nRChild;
};

struct tagHuffmanCode
{
    int m_nWeight;
    int m_nStart;
    int m_nBit[MAXCODELEN];
};

void Huffman (int w[], int n, tagHuffmanNode ht[], tagHuffmanCode hc[])
{
    int nTotalCount = 2 * n - 1;
    // 初始化填充好ht的所有权值, 包括叶子节点和分支节点
    for (int i = 0; i < nTotalCount; i++) 
    {
        if (i < n) {
            ht[i].m_nWeight = w[i];
        } else {
            ht[i].m_nWeight = 0;
        }
        ht[i].m_nParent = 0;
        ht[i].m_nLChild = ht[i].m_nRChild = 1;
    }
    // 构造一颗huffman树, 设置n-1个分支节点(非叶子)
    // 基本思想是: 对于没有设置父节点的节点集选出最小的两个, 最小的放置在左边, 次小的放置在右边
    // 设置好父节点和左右节点关系, 方便获得霍夫曼编码.
    int nCurMinWeight;
    int nCurSecondMinWeight;
    int nCurLeftChild;
    int nCurRightChild;
    for (int i = 0; i < n-1; i++)
    {
        nCurMinWeight = nCurSecondMinWeight = MAXWEIGHT;
        nCurLeftChild = nCurRightChild = 0;
        // 确定一个分支节点, 需要对n + i个节点进行筛算
        for (int j = 0; j < n + i; j++) 
        {
            if (ht[j].m_nWeight < nCurMinWeight && ht[j].m_nParent == 0)
            {
                nCurSecondMinWeight = nCurMinWeight;
                nCurRightChild = nCurLeftChild;
                nCurMinWeight = ht[j].m_nWeight;
                nCurLeftChild = j;
            }
            else if (ht[j].m_nWeight < nCurSecondMinWeight && ht[j].m_nParent == 0)
            {
                nCurSecondMinWeight = ht[j].m_nWeight;
                nCurRightChild = j;
            }
        }
        // 得到分支节点, 设置节点关系
        ht[n + i].m_nLChild = nCurLeftChild;
        ht[n + i].m_nRChild = nCurRightChild;
        ht[n + i].m_nWeight = nCurMinWeight + nCurSecondMinWeight;
        ht[nCurLeftChild].m_nParent = n + i;
        ht[nCurRightChild].m_nParent = n + i;
    }
    // Test
    for (int i = 0; i < nTotalCount; i++)
    {
        printf("--------------------------------------\n");
        printf("ht[%d].m_nWeight: %d\n", i, ht[i].m_nWeight);
        printf("ht[%d].m_nParent: %d\n", i, ht[i].m_nParent);
        printf("ht[%d].m_nLChild: %d\n", i, ht[i].m_nLChild);
        printf("ht[%d].m_nRChild: %d\n", i, ht[i].m_nRChild);
        // printf("--------------------------------------\n");
    }
    // 记录下来每个叶子节点的huffman编码
    // 基本思想: 对于建立好的Huffman树的每个叶子节点, 由编码的数组的末端也是从叶子节点最低端, 往上遍历
    // 如果是父节点的左节点那么用编码数组填1, 如果是父节点的右节点那么编码数组填0, 一直往上追溯到根节点.
    for (int k = 0; k < n; k++)
    {
        hc[k].m_nWeight = ht[k].m_nWeight;
        hc[k].m_nStart = n - 1; // start等于最大的值
        int nChlid = k;
        int nParent = ht[k].m_nParent;
        while (nParent != 0)
        {
            if (nChlid == ht[nParent].m_nLChild)
            {
                hc[k].m_nBit[hc[k].m_nStart] = 0;
            } 
            else if (nChlid == ht[nParent].m_nRChild)
            {
                hc[k].m_nBit[hc[k].m_nStart] = 1;
            }
            hc[k].m_nStart--;
            nChlid = nParent;
            nParent = ht[nChlid].m_nParent;
        }
        // 因为递减了需要增加, 得到正确的起始下标
        hc[k].m_nStart++;
    }
}

int main(int argc, char* argv[])
{
    int nDataNum = 7;
    int nWeight[] = {4, 2, 6, 8, 3, 2, 1};
    const int nMaxLen = 2 * nDataNum - 1;
    tagHuffmanNode *ht = new tagHuffmanNode[nMaxLen];
    tagHuffmanCode *hc = new tagHuffmanCode[nDataNum];
    Huffman(nWeight, nDataNum, ht, hc);
    for (int i = 0; i < 7; i++)
    {
        printf("index: %d, weight: %d, hc[%d].m_nBit: ", i, hc[i].m_nWeight, i);
        for (int j = hc[i].m_nStart; j < 7; j++)
        {
            printf("%d", hc[i].m_nBit[j]);
        }
        printf("\n");
    }
    delete [] ht;
    delete [] hc;
    while(1);
    return 0;
}