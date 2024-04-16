// 실버 4 - 17219번 : 비밀번호 찾기
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 입력
    int M, N;
    cin >> M >> N;

    map<string, string> urls;

    // url과 비밀번호 입력
    string url, password;
    for(int i = 0; i < M; i++)
    {
        cin >> url >> password;
        urls[url] = password;
    }

    // url의 비밀번호 출력
    for(int i = 0; i < N; i++)
    {
        cin >> url;
        cout << urls[url] << "\n";
    }
}