// 골드 5 - 12919번 : A 와 B 2
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int Calculate(const string inA, const string inB)
{
    // B의 개수 구하기
    int countB = 0, countA = 0;
    for(const char &each : inB)
    {
        if(each == 'B') countB++;
    }
    for(const char &each : inA)
    {
        if(each == 'A') countA++;
    }

    bool bIsReverse = ((countB - countA) % 2 == 0);
    int front = 0;
    int end = inB.length() - 1;

    // B의 검사 길이가 A랑 같아질 때까지
    while(inA.length() < end - front + 1)
    {
        int check = bIsReverse ? end : front;

        // B 제거
        if(inB[check] == 'B')
        {
            // 먼저 뒤집고
            bIsReverse = !bIsReverse;
        // A 제거 - 마지막 제거
        }

        if(bIsReverse)
        {
            end--;
        }
        else
        {
            front++;
        }
    }

    // 검사 시작
    for(int i = front; i <= end; i++)
    {
        // reverse인 경우가 정상이므로 B의 앞에서부터 검사
        // reverse가 아닌 경우는 B의 뒤에서부터 검사
        int check = bIsReverse ? i : end - (i - front);
        if(inA[i - front] != inB[check])
        {
            return 0;
        }
    }

    return 1;
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