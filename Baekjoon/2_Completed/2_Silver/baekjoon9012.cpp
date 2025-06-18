// 실버 4 - 9012번 : 괄호
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void simulate(const string& input)
{
    int count = 0;
    bool result = true;
    for(const char& each : input)
    {
        if(each == '(')
            count++;

        else
            count--;

        // 만약에, 오른쪽 괄호가 더 많이 나오는 경우에는 정답 x
        if(count < 0)
        {
            result = false;
            break;
        }
    }

    // 입력 문자열을 모두 검사했음에도, 결과가 0초과라면, 정답 x
    if(count > 0)
        result = false;

    if(result == true)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 테스트 케이스 T
    int T;
    cin >> T;

    string input;
    for(int i = 0; i < T; i++)
    {
        cin >> input;
        simulate(input);
    }
}