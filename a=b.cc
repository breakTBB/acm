#include <bits/stdc++.h>

using namespace std;
const int maxn = 10000010;
char a[maxn],b[maxn];

int judge() {
    int flag = 1;
    int al, ar;
    int bl, br;
    // scanf("%s %s",a,b);
    int signofa;
    int signofb;

    if(a[0]=='+' || a[0]=='-'){
        signofa=a[0];
        if(a[0]=='+')a[0] = '0';
        else a[0] = '1';
    }
    else signofa='+';

    if(b[0]=='+' || b[0]=='-'){
        signofb=b[0];
        if(b[0]=='+')b[0] = '0';
        else b[0] = '1';
    }
    else signofb='+';

    if(signofa!=signofb) {
        puts("NO");
        return 0;
    }
    
    int lena = strlen(a);
    int lenb = strlen(b);
    al = 0;
    bl = 0;
    ar = lena - 1;
    br = lenb - 1;
    
    int index = 0;


    while(a[index]=='0'&&index<lena) {
        al = index+1;
        index++;
    }
    index = 0;



    while(b[index]=='0'&&index<lenb) {
        bl = index + 1;
        index++;
    }
    index = lena - 1;
    while(a[index]=='0'&&index>=0) {
        ar = index - 1;
        index--;
    }
    index = lenb - 1;
    while(b[index]=='0'&&index>=0) {
        br = index -1;
        index--;
    }



    int pointa = 0;
    int pointb = 0;
    int ixx=al;

    for(; ixx <= ar; ixx++) {
        if(a[ixx] == '.'){
            break;
        }
                    pointa = ixx;
        
    }
    ixx =bl;
    for(; ixx <= br; ixx++) {
        if(b[ixx] == '.'){
            break;
        }
                    pointb = ixx;
    }
    

    int zsLenOfa = pointa - al;
    int zsLenOfb = pointb - bl;
    int xsLenofa = ar - pointa;
    int xsLenofb = br - pointb;

    // if(a[0]=='+' || a[0]=='-')xsLenofa--;
    // if(b[0]=='+' || b[0]=='-')xsLenofb--;


    if(zsLenOfa!=zsLenOfb||xsLenofa!=xsLenofb){
        flag = 0;
    }

    if(0){//ar-al!=br-bl
        flag = 0;
    } else {
        while(al<=ar) {
            if(a[al]!=b[bl]) {
                flag = 0;
            }
            al++;
            bl++;
        }

        if(flag)puts("YES");
        else puts("NO");

    }
}

int main() {
    while(~scanf("%s %s",a,b)) {
        judge();
    }
}