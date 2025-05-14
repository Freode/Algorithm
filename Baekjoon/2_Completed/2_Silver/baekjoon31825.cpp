// 실버 5 - 31825번 : 알파벳과 쿼리 (Easy)
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 200 * 200 = 40'000

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 문자열 길이 N, 쿼리 개수 Q
    int N, Q;
    cin >> N >> Q;

    string input;
    cin >> input;

    int query, start, end;
    for(int i = 0; i < Q; i++)
    {
        cin >> query >> start >> end;

        // 찾기
        if(query == 1)
        {
            int result = 0;
            char cur = ' ';
            for(int idx = start-1; idx < end; idx++)
            {
                if(input[idx] != cur)
                {
                    cur = input[idx];
                    result++;
                }
            }   
            cout << result << "\n";
        }
        // 구간에 있는 알파벳 변경
        else
        {
            for(int idx = start-1; idx < end; idx++)
                input[idx] = (input[idx] - 'A' + 1) % 26 + 'A';
        }
    }
}