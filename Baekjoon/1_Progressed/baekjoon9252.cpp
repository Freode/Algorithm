// 골드 4 - 9252번 : LCS 2
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

//      A C A Y K P
// C	0 1 1 1 1 1 
// A	1 1 2 2 2 2
// P	1 1 2 2 2 3
// C	1 2 2 2 2 3
// A	1 2 3 3 3 3
// K	1 2 3 3 4 4

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    string a, b;
    cin >> a >> b;

    vector<vector<int>> cases(b.size()+1, vector<int>(a.size()+1, 0));
    string result = "";

    // b - 검사할 줄부터 하나씩 검사
    for(int i = 1; i <= b.size(); i++)
    {
        for(int j = 1; j <= a.size(); j++)
        {
            // 글자가 같은 경우
            if(b[i-1] == a[j-1])
            {
                // 1. 앞 줄에서 오기 
                // 2. 이전 경우에서 오기
                cases[i][j] = cases[i-1][j-1] + 1;
                
            }
            // 글자가 다른 경우
            else
            {
                cases[i][j] = max(cases[i-1][j], cases[i][j-1]);
            }
        }
    }

    // 도착지에서 역추적 - 틀림
    int j = b.size();
    for(int i = a.size()-1; i >= 0; i--)
    {
        // 경우가 달라질 때, 추가되므로 그 때의 문자 추가
        if(cases[j][i+1] != cases[j][i])
        {
            result = a[i] + result;
        }
    }

    // 출력
    if(cases[b.size()][a.size()] == 0)
    {
        cout << "0\n";
    }
    else
    {
        cout << cases[b.size()][a.size()] << "\n";
        cout << result << "\n";
    }
}