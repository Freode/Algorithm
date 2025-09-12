// 브론즈 3 - 17945번 : 통학의 신
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// -1'000 ~ 1'000까지 검사

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;

    a = a << 1;
    int result = -1001;
    for(int i = -1000; i <= 1000; i++)
    {
        if(i * i + a * i + b != 0)
            continue;

        // 중근
        if(result == i)
            break;

        cout << i << " ";
    }
    cout << "\n";

}