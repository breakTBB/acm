/* Description

You have just moved from Waterloo to a big city. The people here speak an incomprehensible dialect of a foreign language. Fortunately, you have a dictionary to help you understand them.

Input

Input consists of up to 100,000 dictionary entries, followed by a blank line, followed by a message of up to 100,000 words. Each dictionary entry is a line containing an English word, followed by a space and a foreign language word. No foreign word appears more than once in the dictionary. The message is a sequence of words in the foreign language, one word on each line. Each word in the input is a sequence of at most 10 lowercase letters.

Output

Output is the message translated to English, one word per line. Foreign words not in the dictionary should be translated as "eh".

Sample Input

dog ogday
cat atcay
pig igpay
froot ootfray
loops oopslay

atcay
ittenkay
oopslay

Sample Output

cat
eh
loops */

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    map<string, string> mp;
    string s1, s2, s3;
    while(getline(cin, s1)) {
        if(s1[0] == 0) break;
        stringstream ss(s1);
        ss >> s2 >> s3;
        mp[s2] = s3;
    }
    while(cin >> s1) {
        auto it = mp.find(s1);
        if(it != mp.end())
            cout << (*it).second << "\n";
        else
            printf("eh\n");
    }
    system("pause");
    return 0;
}
