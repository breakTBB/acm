#include <bits/stdc++.h>

using namespace std;

int pre[1000];

int find(int x) //查找根节点

{

    int r = x;

    while (pre[r] != r) //返回根节点 r

        r = pre[r];

    int i = x, j;

    while (i != r) //路径压缩

    {

        j = pre[i]; // 在改变上级之前用临时变量  j 记录下他的值

        pre[i] = r; //把上级改为根节点

        i = j;
    }

    return r;
}

void join(int x, int y) //我想让虚竹和周芷若做朋友

{

    int fx = find(x), fy = find(y); //虚竹的老大是玄慈，芷若MM的老大是灭绝

    if (fx != fy) //玄慈和灭绝显然不是同一个人

        pre[fx] = fy; //方丈只好委委屈屈地当了师太的手下啦
}
int main()
{
    
}