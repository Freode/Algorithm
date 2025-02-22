// 실버 1 - 28117번 : prlong longf
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 문자열 길이
    int N;
    cin >> N;

    // 문자열 입력
    string info;
    cin >> info;

    // 초기 값
    int result = 1;

    vector<int> seq;
    int cur_seq = 0;

    // 연속된 long 개수에 따라 경우를 미리 구하기
    vector<int> dp(21, 1);
    dp[2] = 2;
    for(int i = 3; i < 21; i++){ dp[i] = dp[i-1] + dp[i-2]; }

    // 문자열 검사
    for(int i = 0; i < N+1; i++)
    {   
        string check_sub;
        // 범위 안일 경우
        if(i+3 < N+1)
        {
            check_sub = info.substr(i, 4);
        }

        // long이면, 검사 지점을 4칸 미루기
        if(check_sub == "long")
        {
            cur_seq++;
            // 1칸은 나중에 미뤄짐.
            i+=3;
        }
        else
        {
            // 현재 long 연속 개수를 추가해서 넣기
            if(cur_seq != 0)
            {
                seq.push_back(cur_seq);
            }
            cur_seq = 0;
        }
    }

    // 연속된 long 개수를 곱하기에 따라 곱하기
    for(const int& each : seq)
    {
        result *= dp[each];
    }
    cout << result << "\n";
}