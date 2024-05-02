// 골드 5 - 9251번 : LCS
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    string a, b;
    cin >> a >> b;

    vector<int> a_letters(26,0);
    vector<int> b_letters(26,0);

    // 첫 번째 문자열 분석
    for(int i = 0; i < (int)a.size(); i++)
    {
        a_letters[(int)a[i] - 65]++;
    }
    // 두 번째 문자열 분석
    for(int i = 0; i < (int)b.size(); i++)
    {
        b_letters[(int)b[i] - 65]++;
    }

    // 두 문자열 분석한 결과 중에서 
    int result = 0;
    for(int i = 0; i < 26; i++)
    {
        result += min(a_letters[i], b_letters[i]);
    }

    // 출력
    cout << result << "\n";
}