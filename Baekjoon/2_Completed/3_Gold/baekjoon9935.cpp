// 골드 4 - 9935번 : 문자열 폭발
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

// 포인터로 벡터 안에 글자 쌓기
// 폭탄의 마지막 글자와 일치한다면, 포인터로 앞의 글자와 비교

// 성공 -> 포인터 위치만 옮김 -> 덮어쓰기
// 실패 -> 포인터 위치 복귀

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<char> store(1'000'001, ' ');
    int idx = 0;
    // 입력 문자열
    string input;
    cin >> input;
    int input_size = input.length();

    // 폭발 문자열
    string boom;
    cin >> boom;
    int boom_size = boom.length();

    // 입력 문자열 검사
    for(int i = 0; i < input_size; i++)
    {
        // 1. 폭발 문자열의 마지막 글자와 일치하지 않음.
        // 2. 입력된 문자열이 폭발 문자열보다 짧은 경우 -> 어차피 폭발 안함
        if(input[i] != boom[boom_size-1] || idx < boom_size-1)
        {
            store[idx] = input[i];
            idx++;
            continue;
        }

        // 폭발 문자열의 마지막 글자와 일치 -> 검사 필요
        bool b_boom = true;
        for(int check = 1; check < boom_size; check++)
        {
            // 폭발 문자열과 일치하지 않는 경우
            if(store[idx-check] != boom[boom_size-1-check])
            {
                b_boom = false;
                store[idx] = input[i];
                idx++;
                break;
            }
        }

        // 폭발 가능한 경우, 포인터만 옮기기
        if(b_boom){ idx -= (boom_size - 1); }
    }

    // 출력
    if(idx == 0)
    {
        cout << "FRULA\n";
    }
    else
    {
        for(int i = 0; i < idx; i++)
        {
            cout << store[i];
        }
        cout << "\n";
    }
}
