// 골드 5 - 23048번 : 자연수 색칠하기
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 에라토스테네스의 체 사용

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 자연수 N
    int N;
    cin >> N;

    int count = 1;
    vector<int> checks(N+1, 0);
    checks[1] = 1;

    for(int i = 2; i <= N; i++)
    {
        if(checks[i] != 0)
            continue;
        
        count++;
        int check = i;
        while(check <= N)
        {
            checks[check] = count;
            check += i;
        }
    }

    cout << count << "\n";
    for(int i = 1; i <= N; i++)
    {
        cout << checks[i] << " ";
    }
    cout << "\n";
}