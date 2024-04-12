// 골드 5 - 5430번 : AC
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <sstream>
#include <string>
#include <deque>

using namespace std;

// stringstream 학습

// stream
// 실제 입력이나 출력이 표현된 데이터의 이상화된 흐름
// 운영체제가 입력과 출력을 다루기 위해 가상으로 만들어 준 것으로 중간 역할

// buffer
// 스트림은 내부에 버퍼라는 임시 메모리 공간을 가짐.
// 버퍼를 이용하면 프로그램의 입출력을 효율적으로 처리

// stringstream
// 문자열에서 동작하는 스트림 클래스
// 문자열에서 내가 원하는 자료형의 데이터를 추출할 때, 사용

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 입력
    int T;
    cin >> T;

    // 명령어 개수와 숫자 배열
    string opers, temp_array;
    // 숫자 개수
    int n = 0;
    // 구분자
    char comma, open_bracket, close_bracket;
 
    for(int i = 0; i < T; i++)
    {
        // 입력
        cin >> opers;
        cin >> n;
        cin >> temp_array;
        
        // stringstream 선언
        // ss.str(temp_array)로도 초기화 가능.
        stringstream ss(temp_array);

        // 숫자 배열에서 현재 숫자를 담을 임시 변수
        int num;
        // 숫자를 담을 벡터
        deque<int> numbers;

        // '[' 버퍼 읽기
        ss >> open_bracket;
        // 숫자 읽기
        while(ss >> num)
        {
            numbers.push_back(num);
            // ',' 버퍼 읽기
            ss >> comma;
        }
        // ']' 버퍼 읽기
        ss >> close_bracket;

        // 명령 수행
        bool is_reverse = false;
        bool is_error = false;
        for(char& oper : opers)
        {
            // 순서 뒤집기
            if(oper == 'R')
            {
                is_reverse = !is_reverse;
            }
            // 버리기
            else
            {
                // 버릴 숫자가 없으면, error로 종료
                if((int)numbers.size() == 0)
                {
                    is_error = true;
                    break;
                }
                // 순서 뒤집기 여부에 따라 버리는 숫자 결정
                else
                {
                    if(is_reverse == true){ numbers.pop_back(); }
                    else{ numbers.pop_front(); }
                }
            }
        }

        // 결과 출력
        if(is_error == true){ cout << "error\n"; }
        else
        {
            cout << "[";
            int len = (int)numbers.size();
            int temp_print_num = 0;
            for(int i = 0; i < len; i++)
            {
                // 요소 출력
                temp_print_num = is_reverse ? numbers.back() : numbers.front();
                cout << temp_print_num;
                // 요소 제거
                if(is_reverse){ numbers.pop_back(); }
                else{ numbers.pop_front(); }
                // 콤마 출력
                if(i != len - 1){ cout << ","; }
            }
            cout << "]\n";
        }
    }
}