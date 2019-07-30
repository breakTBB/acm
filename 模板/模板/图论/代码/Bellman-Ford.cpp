/*
	Author :  zhr596082417
	Language : C++
	Problem : LG3385
*/
#include <stdio.h>
int dis[2010],u[3010],v[3010],w[3010];
void Bellman_Ford(int n,int m){//bellman-ford����ʼ���İ���
                                      //������Ҫ��ʼ��
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&u[i],&v[i],&w[i]);
    for(int k=1;k<=n;k++){
        int check=1;
        for(int i=1;i<=m;i++){
        	if(dis[v[i]]>dis[u[i]]+w[i])
                dis[v[i]]=dis[u[i]]+w[i],check=0;
        	if(w[i]>=0 && dis[u[i]]>dis[v[i]]+w[i])//֮ǰ���еĴ������������
                dis[u[i]]=dis[v[i]]+w[i],check=0;
        }
        if(check) break;
    }
    for(int i=1;i<=m;i++){
        if(dis[v[i]]>dis[u[i]]+w[i]){
            printf("YE5\n");
            return;
        }
     	if(w[i]>=0 && dis[u[i]]>dis[v[i]]+w[i]){//��Ȼ��������
            printf("YE5\n");
            return;
        }
    }
    printf("N0\n");
}
int main(){
    int t,n,m;
    scanf("%d",&t);
    while(t--)
        scanf("%d%d",&n,&m),Bellman_Ford(n,m);
}
