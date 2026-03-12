// 골드 3 - 3663번 : 고득점
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 무조건 한 방향으로 이동은 또 아님. -> ECAAAAAAB
// 이동 비용이 더 짧은 쪽에서 이동
// 알파벳 변경 비용 + 이동 비용

// 기본은 앞으로(오른쪽으로)
// 연속된 A가 있는 경우 돌아가는게 더 나은지 확인하기

int simulate(const string& s)
{
    int result = 0;
    // 알파벳 변경 비용
    for(const char& c : s)
    {
        result += min(c - 'A', 'Z' - c + 1);
    }

    // 이동 비용
    int len = (int)s.size();
    int move = len - 1;

    for(int idx = 0; idx < len; idx++)
    {
        int next = idx + 1;

        // 연속된 A 구간이 끝날 때까지 확인
        while(next < len && s[next] == 'A')
        {
            next++;
        }

        // 앞->뒤
        // 뒤->앞
        move = min(move, 2 * idx + (len - next));
        move = min(move, 2 * (len - next) + idx);
    }

    result += move;

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    string s;
    for(int i = 0; i < T; i++)
    {
        cin >> s;
        cout << simulate(s) << "\n";
    }
}