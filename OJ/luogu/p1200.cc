#include <bits/stdc++.h>

char star[10];
char team[10];

int main() {
    scanf("%s", star);
    scanf("%s", team);
    int sa = 1, ta = 1;
    int starlen = strlen(star);
    int teamlen = strlen(team);
    for(int i = 0; i < starlen; i++) {
        sa *= star[i] - 'A' + 1;
    }
    for(int i = 0; i < teamlen; i++) {
        ta *= team[i] - 'A' + 1;
    }

    if(ta % 47 == sa % 47)printf("GO");
    else printf("STAY");
}

// #include <iostream>
// int main()
// {
//     using namespace std;
//     int a = 1 , b = 1;
//     char v;
//     while ( (v = cin.get() ) != '\n') a *= v - 'A' + 1;
//     while ( (v = cin.get() ) != '\n') b *= v - 'A' + 1;
//     if (a % 47 == b % 47) cout << "GO";
//     else cout << "STAY";
//     return 0;
// }