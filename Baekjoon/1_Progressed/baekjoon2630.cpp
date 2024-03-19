// 실버 2 - 2630번 : 색종이 만들기
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <queue>
#include <math>

using namespace std;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 크기 입력
    int N;
    cin >> N;

    // 2의 몇 제곱인지 찾기
    int square = 0;
    for(int i = 1; i < 8; i++)
    {
        if(pow(2, i) == N)
        {
            square = i;
            break;
        }
    }

}