// 브론즈 3 - 31798번 : 단원평가
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;

    int result = 0;
    if(a == 0)
        result = c * c - b;
    else if(b == 0)
        result = c * c - a;
    else
        result = sqrt(a + b);

    cout << result << "\n";
}