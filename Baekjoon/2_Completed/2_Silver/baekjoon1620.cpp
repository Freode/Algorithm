// 실버 4 - 1920번 : 나는야 포켓몬 마스터 이다솜
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    int N, M;
    cin >> N >> M;

    // 포켓몬 도감
    unordered_map<string, int> book_name;
    unordered_map<int, string> book_number;

    // 도감에 포켓몬 입력
    string pocketmon;
    for(int i = 0; i < N; i++)
    {
        cin >> pocketmon;
        book_name[pocketmon] = i + 1;
        book_number[i + 1] = pocketmon;
    }

    // 포켓몬 번호 또는 이름 입력해서 찾기
    for(int i = 0; i < M; i++)
    {
        cin >> pocketmon;
        // 입력 경우가 숫자일 때
        if(pocketmon[0] >= '0' && pocketmon[0] <= '9')
        {
            cout << book_number[stoi(pocketmon)] << "\n";
        }
        // 입력 경우가 포켓몬 이름일 때
        else
        {
            cout << book_name[pocketmon] << "\n";
        }
    }

}