// 브론즈 1 - 33556번 : Java String Equals
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 두 문자열 입력
    string A, B;
    cin >> A >> B;

    // 둘 다 일반 문자열
    string result1, result2;
    if(A != "null" && B != "null")
    {
        result1 = (A == B) ? "true" : "false";

        transform(A.begin(), A.end(), A.begin(), ::tolower);
        transform(B.begin(), B.end(), B.begin(), ::tolower);
        result2 = (A == B) ? "true" : "false";
    }
    // 둘 중 하나가 객체인데 아무것도 없다고 인식
    else
    {
        // A가 null이면, 항상 예외 발생
        if(A == "null")
        {
            result1 = "NullPointerException";
            result2 = "NullPointerException";
        }
        else
        {
            // 항상 거짓
            result1 = "false";
            result2 = "false";
        }
    }

    cout << result1 << "\n";
    cout << result2 << "\n";
}