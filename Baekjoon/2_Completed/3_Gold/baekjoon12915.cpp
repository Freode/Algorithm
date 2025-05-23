// 골드 5 - 12915번 : 대회 개최
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 입력
    int E, EM, M, MH, H;
    cin >> E >> EM >> M >> MH >> H;

    int result = 0;
    bool bContinue = true;
    while(bContinue)
    {
        // EM 단계 문제 하나를 E로 사용
        if(E == 0 && EM != 0)
        {
            EM--;
            E = 1;
        }
        if(M == 0)
        {
            // EM과 MH 중 더 많이 남은 문제를 사용
            if(EM < MH)
            {
                M = 1;
                MH--;
            }
            else if(EM > MH)
            {
                M = 1;
                EM--;
            }
            else if(EM == MH && EM != 0)
            {
                M = 1;
                EM--;
            }
        }
        if(H == 0 && MH != 0)
        {
            MH--;
            H = 1;
        }

        // check
        if(E > 0 && M > 0 && H > 0)
        {
            E--;
            M--;
            H--;
            result++;
        }
        // 더 이상 대회를 개최할 수 없음
        else
        {
            break;
        }
    }
    cout << result << "\n";
}