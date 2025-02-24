// 골드 5 - 12919번 : A 와 B 2
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int Calculate(const string &inA, const string inB)
{
    // 결과가 같을 때
    if(inA.size() == inB.size())
    {
        // 결과가 같을 때
        if(inA == inB) return 1;
        return 0;
    }

    int result = 0;
    // 결과 B에서 출발 A로 역추적

    // 1. A를 뒤에서 추가 -> 마지막에 A를 제거
    int size = inB.length();
    if(inB[size - 1] == 'A')
    {
        string next = inB;
        next.erase(next.size()-1);
        result = Calculate(inA, next);
    }
    // 2. B를 추가하고 문자열 뒤집기
    // => 시작점이 B인지 검사
    if(inB[0] == 'B')
    {
        string next = inB;
        next.erase(0, 1);
        reverse(next.begin(), next.end());
        result = max(result, Calculate(inA, next));
    }

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string A, B;
    cin >> A >> B;

    int result = Calculate(A, B);
    cout << result << "\n";
}