// 골드 4 - 1062번 : 가르침
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <bitset>

using namespace std;

// 단어 개수 N, K개
// N -> 1~50, K -> 0~26
// 단어는 영어 소문자, 길이 8~15
// 모든 단어 중복 x

// K개 글자만 가르침 -> 학생들은 K개의 글자로만 이루어진 단어를 읽을 수 있음.
// K개의 글자를 가르칠 때 -> 읽을 수 있는 단어 개수가 최대 구하기

// 남극 언어 -> 접두사 : anta, 접미사 : tica

// 최소 K가 5이상 되어야 단어를 읽는 경우가 나옴.
// a n t i c

// 사용 단어를 비트로 변환 
// 단어는 해당 글자가 있으면, 읽을 수 있음.

// ex)
// 3 6              abcdefghijklmnopqrstuvwxyz
// antarctica       10100000100001000101000000 -> 6
// antahellotica    10101001100100100001000000 -> 8
// antacartica      10100000100001000101000000 -> 6

// 9 8              abcdefghijklmnopqrstuvwxyz
// antabtica        11100000100001000001000000 -> 6
// antaxtica        10100000100001000001000100 -> 6
// antadtica        10110000100001000001000000 -> 6
// antaetica        10101000100001000001000000 -> 6
// antaftica        10100100100001000001000000 -> 6
// antagtica        10100010100001000001000000 -> 6
// antahtica        10100001100001000001000000 -> 6
// antajtica        10100000110001000001000000 -> 6
// antaktica        10100000101001000001000000 -> 6

// 처음에 단어 변환 -> 15글자 * 50문장
// K개 이하인 단어로 고정하고 or 연산해서 검사 -> K개 이하 만족 시, +1
// 근데 계속 or을 누적해야 하는데?

// dp랑 섞어야 하나?
// 백트래킹? -> 시간 초과

struct Word
{
    int value;
    int count;
};

vector<Word> g_words;

// 문장을 bit로 변환
pair<int, int> changeBit(const string& word)
{
    // 글자 존재 여부 확인
    vector<bool> letters(26, false);
    for(const char& each : word)
    {
        letters[each - 'a'] = true;
    }

    // 글자 존재 여부에 따라 비트 계산
    int result = 0;
    int count = 0;
    for(const bool& letter : letters)
    {
        result = result << 1;
        if(letter) 
        {
            result++;
            count++;
        }
    }

    return {result, count};
}   

// 숫자를 bit로 변환해서 개수 찾기
int checkBit(const int base)
{
    int count = 0;
    int num = base;

    // 사용 글자 개수 찾기
    while(num > 0)
    {
        if(num % 2 == 1) count++;
        num = num >> 1;
    }

    return count;
}

// 단어 입력
void inputWords(const int N)
{
    g_words = vector<Word>(N);

    string input;
    for(int i = 0; i < N; i++)
    {
        cin >> input;
        pair<int, int> word = changeBit(input);
        g_words[i].value = word.first;
        g_words[i].count = word.second;
        // cout << g_words[i] << "\n";
        // cout << bitset<26>(g_words[i]) << "\n";
    }
}

// 해당 단어를 기준으로 몇 단어까지 알 수 있는지 확인
int search(const Word& base, const int start, const int cnt, const int K)
{
   // 각 단어와 조합
    int count = cnt;
    int result = cnt;
    for(int idx = start; idx < g_words.size(); idx++)
    {
        // 글자 개수가 K개를 이미 넘으면, 무시
        if(g_words[idx].count > K) continue;

        int value = base.value | g_words[idx].value;
        int check = checkBit(value);

        // K개 초과면, 무시
        if(check > K) continue;
        
        // 누적
        count++;
        int temp = search({value, check}, idx + 1, count, K);
        result = max(result, temp);
        count--;
    }
 
    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 단어 개수 N, 가르칠 글자 수 K
    int N, K;
    cin >> N >> K;

    // 단어 입력
    inputWords(N);

    // 시뮬레이션
    int result = search({0, 0}, 0, 0, K);

    cout << result << "\n";
}