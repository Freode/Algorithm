// 골드 5 - 2201번 : 암호코드
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// f(n)

// f(n-1) = 1또는 2일 때(단, f(n-1) = 2이면, f(n)은 6이하),
// f(n) = f(n-1) + f(n-2)
// f(n-1)에서 1~9에 해당하는 글자 경우를 추가하고
// f(n-2)에서 11~26에 해당하는 글자 경우를 추가

// 10과 20은 f(n) = f(n-1)로 적용
// a와 b가 j와 t로 변경
// 단, n-2번째 값이 1또는 2인 경우 -f(n-2)를 해야함.
// 예시 : 110

// f(n-1) = 2이면서 f(n)이 7 이상, f(n-1)이 3이상일 때
// f(n) = f(n-1)
// f(n-1)에서 1~9에 해당하는 글자 경우를 추가

// f(1) = 1
// f(2) = 1 또는 2
// f(1)과 f(2)가 10~26이면, 2 나머지는 1

// 암호해독이 잘못되어 0이 나오는 경우
// 1) 0앞에 3이상
// 2) 0이 연속
// 3) 1번째 수가 0인 경우

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    string input;
    cin >> input;

    vector<int> cases(input.length(), 1);
    int continus_zero = 0;

    // 첫 번째 자리가 0인지 확인
    if((int)input[0] - 48 == 0)
    {
        cout << "0\n";
    }
    // 첫 번째 자리가 0이 아님
    else
    {
        // 검사
        for(int i = 1; i < cases.size(); i++)
        {
            // 0 확인 검사
            if((int)input[i] - 48 == 0)
            {
                continus_zero++;
                if(continus_zero == 2)
                {
                    cases[cases.size() - 1] = 0;
                    break;
                }
                // 10, 20인 경우
                if((int)input[i-1] - 48 <= 2)
                {
                    cases[i] = cases[i-1];
                    // 110처럼 11에서는 경우가 2가지였으나 110에서 경우가 1가지로 줄었을 때 고려
                    // 1110
                    if(i >= 2 && ((int)input[i-2] - 48 == 1 || (int)input[i-2] - 48 == 2))
                    {
                        cases[i] -= (i == 2) ? cases[i-2] : cases[i-3];
                        // 음수인 경우, 다시 더하기
                        if ( cases[i] < 0)
                        {
                            cases[i] += 1000000;
                        }
                    }
                }
                // 30 이상
                else
                {
                    cases[cases.size() - 1] = 0;
                    break;
                }

            }
            // 11~26, 20제외
            // f(n) = f(n-1) + f(n-2)
            else if((int)input[i-1] - 48 == 1 || ((int)input[i-1] - 48 == 2 && (int)input[i] - 48 <= 6))
            {
                continus_zero = 0;
                // i = 1일 떄, n-2번째가 없어서
                if(i == 1)
                {
                    cases[1] = 2;
                }
                else
                {
                    cases[i] = (cases[i-1] + cases[i-2]) % 1000000;
                }
            }
            // 1~9
            // f(n) = f(n-1)
            else
            {
                continus_zero = 0;
                cases[i] = cases[i-1];
            }
        }

        // 출력
        cout << cases[cases.size()-1] << "\n";
    }
}