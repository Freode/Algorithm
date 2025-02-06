// 브론즈 5 - 9086번 : 문자열
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <string>

using namespace std;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 테스트 케이스 입력
    int T;
    cin >> T;

    // 각각 입력
    string temp;
    for(int i = 0; i < T; i++)
    {
        cin >> temp;
        cout << temp[0] << temp[temp.size() - 1] << "\n";
    }

}