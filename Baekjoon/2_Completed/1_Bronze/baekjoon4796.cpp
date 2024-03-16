// 브론즈 1 - 4796번 : 캠핑
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // 입력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 변수 선언
    int case_num = 1;
    int L = 1, P = 1, V = 1;
    int result = 0;
    // 입력
    while(true)
    {
        cin >> L >> P >> V;
        if(L == 0 && P == 0 && V == 0){ break;}

        result = V / P * L;
        result += min(L, V % P);
        // 출력
        cout << "Case "<< case_num << ": " << result << "\n";
        case_num++;
    }
}