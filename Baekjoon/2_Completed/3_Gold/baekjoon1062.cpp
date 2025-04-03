// 골드 4 - 1062번 : 가르침
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

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
// 백트래킹?

// 글자의 개수, 글자 값 -> 글자 값이 더 많은 것을 best로 판단?
// [현재 단어 위치][앞에 단어를 사용한 개수]

// 단어 50개 사용 여부 -> 2^50
// 글자 26개 사용 여부 -> 2^26 중에서 a,c,i,n,t 5개 사용 -> 2^21
// 글자 사용 가능한 것을 int로 변환한 뒤, or 연산해서 같으면, 통과시키기

vector<int> g_words;

// 문장을 bit로 변환
int changeBit(const string& word)
{
    // 글자 존재 여부 확인
    vector<bool> letters(26, false);
    for(const char& each : word)
    {
        letters[each - 'a'] = true;
    }

    // 글자 존재 여부에 따라 비트 계산
    int result = 0;
    for(const bool& letter : letters)
    {
        result = result << 1;
        if(letter) 
            result++;
    }

    return result;
}   

// 단어 입력
void inputWords(const int N)
{
    g_words = vector<int>(N);

    string input;
    for(int i = 0; i < N; i++)
    {
        cin >> input;
        int word = changeBit(input);
        g_words[i] = word;
        // cout << g_words[i] << "\n";
        // cout << bitset<26>(g_words[i]) << "\n";
    }
}


// 해당 허용 글자를 기준으로 몇 개의 단어가 통과되는지 검사
int search(const string letters)
{
    int result = 0;
    // 허용 글자를 숫자로 변환
    int check = changeBit(letters);

    // 각 단어별로 검사
    for(const int& word : g_words)
    {
        // or 연산해서 같으면, 사용할 수 있는 단어로 통과
        if(check == (check | word))
            result++;
    }

    return result;
}

// 허용 글자 정하기
int makeLetter(const string letters, const int idx, const int cnt, const int& K)
{
    // 허용 글자를 모두 정했으면, 탐색
    if(cnt == K)
        return search(letters);

    // 허용 글자를 아직 정하는 중
    int result = 0;

    for(int i = idx; i < 26; i++)
    {
        char letter = i + 'a';
        // 이미 검사한 글자
        if(letter == 'a' || letter == 'c' || letter == 'i' || letter == 'n' || letter == 't')
            continue;

        string next = letters + letter;
        int temp = makeLetter(next, i + 1, cnt + 1, K);
        result = max(result, temp);
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
    int result = makeLetter("acint", 0, 5, K);

    cout << result << "\n";
}