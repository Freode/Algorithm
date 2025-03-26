// 골드 5 - 1099번 : 알 수 없는 문장
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 단어 N개
// 각 단어 : 0번 또는 그 이상 나타날 수 있음

// 문장
// 문자의 순서 변경 가능
// 단어를 공백 없이 붙여서 쓴 것

// 비용 : 원래 단어 위치와 다른 위치에 있는 문자의 개수만큼 그 순서를 바꾼 단어를 만드는 비용
// abc -> abc : 0
// abc -> acb, cba, bac : 2
// abc -> bca, cab : 3

// 문장읠 길이 최대 50
// 둘째 줄부터 단어 개수 N

// 정답 출력, 없으면 -1

// ex)
// neotowheret
// one : o != n, n != e, e != 0 -> 비용 3
// two : t == t, w != o, o != w -> 비용 2
// three : t != h, h != e, r == r, e == e, e != t -> 비용 3
// 총합 8

// abba
// ab -> ab = 0
// ab -> ba = 2
// 총합 2

// 문장 검사 시작 위치 -> idx
// 단어와 비교 -> -1일 경우
// 아예 일치하지 않을 때는 어떻게 판단?

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

}