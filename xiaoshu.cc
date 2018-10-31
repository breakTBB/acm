#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    cout.setf(ios::showpoint);
    // double d = 3.14159;
    // cout << setprecision(8) << d << endl;
    cout << oct << 010 << endl;
    cout << dec << 0x16 << endl;
    cout << setiosflags(ios::uppercase) 
    << hex << 15 << endl;
    cout << setiosflags(ios::showpos)
    << dec << 10 << endl;
    

    system("pause");
    return 0;
}
