/**P1216 [USACO1.5][IOI1994]数字三角形 Number Triangles
题目描述：
观察下面的数字金字塔。
写一个程序来查找从最高点到底部任意处结束的路径，使路径经过数字的和最大。每一步可以走到左下方的点也可以到达右下方的点。

        7 
      3   8 
    8   1   0 
  2   7   4   4 
4   5   2   6   5 
在上面的样例中,从 7 \to 3 \to 8 \to 7 \to 57→3→8→7→5 的路径产生了最大

输入格式：
第一个行一个正整数 rr ,表示行的数目。
后面每行为这个数字金字塔特定行包含的整数。

输出格式：
单独的一行,包含那个可能得到的最大的和。

样例：
输入:
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5 

输出：
30
**/

/**
解题思路：用dp从下往上递归，不断找到最大，要注意的时输入并不是金字塔形状的，所以写状态方程时要注意下标。
**/

AC代码：
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=10005;
int a[maxn][maxn],f[maxn][maxn];
int main()
{
    int r;
    cin>>r;
    int i,j;
    for(i=0; i<r; i++)
    {
        for(j=0; j<=i; j++)
        {
            cin>>a[i][j];
            f[i][j]=0;
        }
    }
    for(i=r-1;i>=0;i--)
    {
        for(j=i;j>=0;j--)
        {
            f[i][j]=max(f[i+1][j],f[i+1][j+1])+a[i][j];
        }
    }
    cout<<f[0][0]<<endl;
    return 0;
}






