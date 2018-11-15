#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
string x,y,z;
int c[27],s=0;
bool f[27],t[27];
int main()
{
    memset(c,0,sizeof(c));
    memset(f,false,sizeof(f));
    memset(t,false,sizeof(t));
    cin>>x>>y>>z;
    for(int i=0;i<x.size();++i)
    {
        if(!f[x[i]-'A'+1]&&!t[y[i]-'A'+1])//判断密字是否用过和原信息中的字母有无相应密字
        {
            c[x[i]-'A'+1]=y[i];//存入相应密字的ASCLL码
            f[x[i]-'A'+1]=t[y[i]-'A'+1]=true;//密字和原信息字母使用过了
            ++s;    //往判断有多少字母有密字中的函数加一
        }    
        else if(c[x[i]-'A'+1]!=y[i])//如果密字不同于原来有的密字
        {
            cout<<"Failed";
            return 0;    
        }
    }
    if(s!=26)//密字不够26个字母
    {
        cout<<"Failed";
            return 0;    
    }
    for(int i=0;i<z.size();++i)//输出
    {
        printf("%c",c[z[i]-'A'+1]);    
    }
}  