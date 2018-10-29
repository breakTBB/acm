#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;


struct Student{
    char id[15];
    int score;
    int location_number;
    int local_rank;
}stu[30010];

bool cmp(Student a, Student b){
    if(a.score != b.score) return a.score>b.score;
    else return strcmp(a.id, b.id) < 0;
}
void patb1001(){
    int num, step = 0;
    scanf("%d", &num);
    while(num != 1){
        if(num % 2 == 0)num /= 2;
        else num = (3*num+1)/2;
        step++;
    }
    printf("%d",step);
}

void patb1032(){
    int count, school, score;
    int t[100010];
    scanf("%d", &count);
    fill(t,t+100010,0);
    while(count--){
        scanf("%d%d", &school, &score);
        t[school] += score;
    }
    int maxnum = t[0];
    int index = 0;
    for(int i = 0;i < 100010; i++){
        if(t[i]>maxnum){
            maxnum = t[i];
            index = i;
        }
    }
    printf("\n%d %d",index,maxnum);
}

void codeup1934(){
    int cnt,num[210],x;
    scanf("%d", &cnt);
    for(int i = 0;i < cnt; i++){
        scanf("%d",&num[i]);
    }
    scanf("%d", &x);
    for(int i = 0; i < cnt; i++){
        if(num[i]==x){
            printf("%d",i);
            return;
        }
    }
    printf("-1");
}

void patb1036(){
    int row, col;
    char chr;
    scanf("%d %c",&col, &chr);
    if(col % 2 == 0)row = col / 2;
    else row = (col + 1) / 2;
    //1
    for(int i = 0; i < col; i++){
        printf("%c",chr);
    }
    printf("\n");
    //2~row-1
    for(int i = 2; i < row; i++){
        printf("%c", chr);
        for(int j = 0; j < col - 2; j++){
            printf(" ");
        }
        printf("%c\n", chr);
    }
    //row
        for(int i = 0; i < col; i++){
        printf("%c",chr);
    }

}
bool isLeap(int year){
        return (year%100!=0&&year%4==0)||year%400==0;
    }
void codeup1928(){

    int month[13][2] = {{0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};
    int date1, date2;
    int y1, y2, m1, m2, d1, d2;
    int ans = 1;
    scanf("%d%d", &date1, &date2);
    if(date1>date2){
        int temp;
        temp = date1;
        date1 = date2;
        date2 = temp;
    }
    y1 = date1 / 10000;y2 = date2 / 10000;
    m1 = (date1 / 100) % 100;m2 = (date2 / 100)%100;
    d1 = date1 % 100;d2 = date2 % 100;
    while(y1<y2||m1<m2||d1<d2){
        ans++;
        d1++;
        if(d1 == month[m1][isLeap(date1)]+1){
            m1++;
            d1 = 1;
        }
        if(m1 == 13){
            y1++;
            m1 = 1;
        }
    }
    printf("%d",ans);
}
int ot10(int num, int P){
    int ans = 0;
    int product = 1;
    while(num != 0){
        ans += (num%10) * product;
        num /= 10;
        product*=P;
    }
    return ans;
}

void dec2o(int num,int Q){
    int z[40], index = 0;
    do{
        z[index++] = num % Q;
        num /= Q;
    }while(num != 0);
    // i = index
    for(int i = index-1; i >= 0; i-- ){
        printf("%d",z[i]);
    }
}

void o2dec(int num, int P){
    int ans = 0, product = 1;
    while(num != 0){
        ans += (num%10) * product;
        product *= P;
        num /= 10;
    }
    printf("%d",ans);
}

void patb1022(){
    int a, b, d;
    scanf("%d%d%d", &a, &b, &d);
    int sum = a + b;
    int ans[100], num=0;
    while(sum != 0){
        ans[num++] = (sum%d);
        sum /= d;
    }
    for(int i = num-1; i >=0; i--){
        printf("%d",ans[i]);
    }
}

bool judge(char str[]){
    int len = strlen(str);
    for(int i = 0; i < len / 2; i++){
        if(str[i] != str[len-i-1]){
            return false;
        }
    }
    return true;
}
void codeup5901(){
    const int maxn = 256;
    char str[maxn];
    while(gets(str)){
        bool flag = judge(str);
        if(flag==true){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}
void mypatb1009(){
    char chr;
    char str[80];
    int index = 0;
    while((chr = getchar(),chr!=EOF)){
        if(chr!=' '&&chr!='\n')str[index++] = chr;
        else{
            index--;
            for(int i = index; i >= 0; i--){
                putchar(str[i]);
            }
            putchar(' ');
            fill(str,str+80,'\0');
            index = 0;
        }
    }
}
void patb1009(){
    int num = 0;
    char ans[90][90];
    while(scanf("%s",ans[num])!=EOF){
        num++;
    }
    for(int i = num - 1; i >= 0; i--){
        printf("%s", ans[i]);
        if(i > 0) printf(" ");
    }
}
void selectsort(int num[], int n){
    for(int i = 0; i < n; i++){
        int index = i;
        for(int j = i; j < n; j++){
            if(num[j]<num[index]){
                index = j;
            }
        }
        swap(num[i],num[index]);
    }

}
//每个数 循环和之前的数比  放在比他小的前
void insertsort(int num[], int n){
    for(int i = 1; i < n; i++){
        int val = num[i];
        int l = i - 1;
        while(l >= 0&&val<num[l]){
            num[l+1] = num[l];
            l--;
        }
        num[l+1] = val;
    }
}
void pata1025(){
    int n, k, num = 0;//num总考生数
    scanf("%d", &n);//考场
    for(int i = 1; i <= n; i++){
        scanf("%d", &k);//考场人数
        for(int j = 0; j < k; j++){
            scanf("%s %d", stu[num].id, &stu[num].score);
            stu[num].location_number = i;
            num++;
        }
        sort(stu+num-k,stu+num,cmp);//这样每个考场都能成功排序
        stu[num-k].local_rank = i;
        for(int j = num - k + 1; j < num; j++){
            if(stu[j].score == stu[j-1].local_rank){
                stu[j].local_rank = stu[j-1].local_rank;
            }
            else{
                stu[j].local_rank = j + 1 - (num - k);
            }
        }
    }
    printf("%d\n", num);
    sort(stu, stu+num, cmp);
    int r = 1;
    for(int i = 0; i < num; i++){
        if(i > 0&&stu[i].score != stu[i-1].score){
            //r = l + 1;
        }
        printf("%s ", stu[i].id);
        printf("%d %d %d\n", r, stu[i].location_number,stu[i].local_rank);
    }
}

int ex2(long long n, long long m) {
    long long pingFangShu = n; // n 的 1 次方
    long long result = 1;
    //1000
    while (m != 0) {
    // 遇1累乘现在的幂
        if ((m & 1) != 0)
            result *= pingFangShu;
        // 每移位一次，幂累乘方一次
        //这不是pfs^2
        pingFangShu = pingFangShu * pingFangShu;
        // 右移一位
        m >>= 1;
    }
    return result;
}


int main()
{
    int n[10] = {8,3,6,2,5,2,1,9};
    insertsort(n,10);
    for(auto i : n){
        //printf("%d ",i);
    }
    printf("%d\n",ex2(7,80));
    printf("%d\n",pow(7,80));
    //patb1009();
    //codeup5901();
    //patb1022();
    //o2dec(1010,2);
    //puts("\n");
    //dec2o(10,2);
    //codeup1928();
    //patb1036();
    //codeup1934();
    //patb1032();
    //patb1001();
    system("pause");
    return 0;
}
