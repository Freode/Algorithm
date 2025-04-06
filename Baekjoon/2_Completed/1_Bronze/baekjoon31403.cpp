// 브론즈 4 - 31403번 : A + B - c
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    
    string sa = to_string(a);
    string sb = to_string(b);
    sa += sb;
    
    cout << a + b - c << "\n";
    cout << stoi(sa) - c << "\n";
}