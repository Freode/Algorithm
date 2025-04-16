// 골드 5 - 25427번 : DKSH를 찾아라
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 그냥 DKSH 글자만 남기기
// 남겼을 때, DKSH가 되는 경우의 수
// 즉, a번째 문자 D, b번째 문자 K, c번째 문자 S, d번째 문자 H
// a < b < c < d를 만족하는 경우의 수 구하기

// 글자 길이 -> N (1~100'000)
// 둘째 줄 -> 문자열

// 1번
// 11
// DABKCDSEFHH

// 일단 DKSH만 남기기

// DKSHH -> 2가지 경우

// DDKSHH -> 4가지 경우
// DDKDKSHH -> 10가지 경우

// DKSH
// S -> 뒤에 H 개수 
// K -> 뒤에 SH 개수
// D -> 뒤에 KSH 개수 

// H -> 1개 추가
// S -> 기존 SH 개수 + 현재 H 경우
// K -> 기존 KSH 개수 + 현재 SH 경우
// D -> 기존 DKSH 개수 + 현재 KSH 경우

// DKSHDKSHDKSH
// (좌표, 개수)
// D : (0,15)(4,5)(8,1)
// K : (1,10)(5,4)(9,1)
// S : (2,6)(6,3)(10,1)
// H : (3,3)(7,2)(11,1)

// int 범위 벗어남
using ll = long long;

ll simulate(const string& input)
{
    // 뒤에서 검사
    ll h_count = 0;
    ll sh_count = 0;
    ll ksh_count = 0;
    ll dksh_count = 0;

    for(int i = input.length()-1; i >= 0; i--)
    {
        // H 개수 증가
        if(input[i] == 'H')
            h_count++;

        // 기존 SH 경우 + 현재 H 경우
        else if(input[i] == 'S')
            sh_count += h_count;

        // 기존 KSH 경우 + 현재 SH 경우
        else if(input[i] == 'K')
            ksh_count += sh_count;

        // 기존 DKSH 경우 + 현재 KSH 경우
        else if(input[i] == 'D')
            dksh_count += ksh_count;
    }

    return dksh_count;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 글자 길이 N
    int N;
    cin >> N;

    // 문자열 입력
    string input;
    cin >> input;

    cout << simulate(input) << "\n";
}