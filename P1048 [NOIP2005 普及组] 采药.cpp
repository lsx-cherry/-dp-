/**P1048 [NOIP2005 普及组] 采药
题目描述：辰辰是个天资聪颖的孩子，他的梦想是成为世界上最伟大的医师。为此，他想拜附近最有威望的医师为师。医师为了判断他的资质，给他出了一个难题。医师把他带到一个到处都是草药的山洞里对他说：“孩子，这个山洞里有一些不同的草药，采每一株都需要一些时间，每一株也有它自身的价值。我会给你一段时间，在这段时间里，你可以采到一些草药。如果你是一个聪明的孩子，你应该可以让采到的草药的总价值最大。”
如果你是辰辰，你能完成这个任务吗？

输入格式：
第一行有 22 个整数 TT（1 \le T \le 10001≤T≤1000）和 MM（1 \le M \le 1001≤M≤100），用一个空格隔开，TT 代表总共能够用来采药的时间，MM 代表山洞里的草药的数目。
接下来的 MM 行每行包括两个在 11 到 100100 之间（包括 11 和 100100）的整数，分别表示采摘某株草药的时间和这株草药的价值。
输出格式：
输出在规定的时间内可以采到的草药的最大总价值。

样例：
输入
70 3
71 100
69 1
1 2
输出
3

**/

/**
解题思路:这是一道典型的01背包问题，用一维数组和dp即可，重点是dp的状态方程是：f[j]=max(f[j],f[j-t[i]]+w[i]];

AC代码：
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int w[110],t[110],f[1100];//w表示每个草药的价值，t表示每个草药所花费的时间，f[i]表示花费i时间时可以获得草药的最大价值。
int main()
{
    int T,m;
    cin>>T>>m;
    int i,j;
    for(i=0;i<m;i++)
    {
        cin>>t[i]>>w[i];
    }
    for(i=0;i<m;i++)
    {
        for(j=T;j>=t[i];j--)
        {
            f[j]=max(f[j],f[j-t[i]]+w[i]);
        }
    }
    cout<<f[T]<<endl;
    return 0;
}
