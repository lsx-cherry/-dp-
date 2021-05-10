/**P1434 [SHOI2002]滑雪
题目描述：
Michael 喜欢滑雪。这并不奇怪，因为滑雪的确很刺激。可是为了获得速度，滑的区域必须向下倾斜，而且当你滑到坡底，你不得不再次走上坡或者等待升降机来载你。Michael 想知道在一个区域中最长的滑坡。区域由一个二维数组给出。数组的每个数字代表点的高度。下面是一个例子：
1   2   3   4   5
16  17  18  19  6
15  24  25  20  7
14  23  22  21  8
13  12  11  10  9
一个人可以从某个点滑向上下左右相邻四个点之一，当且仅当高度会减小。在上面的例子中，一条可行的滑坡为 2424－1717－1616－11（从 2424 开始，在 11 结束）。当然 2525－2424－2323－\ldots…－33－22－11 更长。事实上，这是最长的一条。

输入格式：
输入的第一行为表示区域的二维数组的行数 RR 和列数 CC。下面是 RR 行，每行有 CC 个数，代表高度(两个数字之间用 11 个空格间隔)。

输出格式：
输出区域中最长滑坡的长度。

样例：
输入：
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
输出：
25
**/

/**解题思路：dfs+记忆化搜索，但用dfs会TCE,记忆化搜索是用一个变量来标记某一个点是否已经被搜索过，这样可以减少搜索的次数。**/

AC代码：
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1000;
int dx[4]= {0,0,-1,1};
int dy[4]= {1,-1,0,0};
int f[maxn][maxn],a[maxn][maxn];
bool W[maxn][maxn];
int r,c;
int dfs(int x,int y)//坐标
{
    if(W[x][y])
    {
        return f[x][y];
    }
    int i;
    for(i=0; i<4; i++)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx>=0&&xx<=c&&yy>=0&&yy<=r&&a[x][y]>a[xx][yy])
        {
            dfs(xx,yy);//求出满足要求的
            f[x][y]=max(f[x][y],f[xx][yy]+1);//状态方程
        }
    }
    W[x][y]=true;
    return f[x][y];
}
int main()
{
    cin>>r>>c;
    int i,j;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            cin>>a[i][j];
            f[i][j]=1;
            W[i][j]=false;
        }
    }
    int ans=0;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            ans=max(ans,dfs(i,j));
        }
    }
    cout<<ans<<endl;
    return 0;
}

