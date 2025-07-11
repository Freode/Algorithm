// 골드 2 - 1007번 : 벡터 매칭
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 벡터의 합 -> 최솟값
// 좌표 -> 100,000 보다 작거나 같은 정수
// 절대 오차 10^(-6)까지 허용

// N : 1~20


int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    
    for(int i = 0; i < T; i++)
    {
        int H, W, N;
        cin >> H >> W >> N;
        
        int floor = N % H;
        int num = N / H + 1;
        
        if(floor == 0)
        {
            floor = H;
            num--;
        }

        cout << floor * 100 + num << "\n";
    }

}