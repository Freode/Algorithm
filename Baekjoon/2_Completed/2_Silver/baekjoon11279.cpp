// 실버 2 - 11279번 : 최대 힙
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>

using namespace std;

// 교환
void Swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 추가
void InsertHeap(vector<int>& heaps, int num)
{
    heaps.push_back(num);
    int index = (int)heaps.size() - 1;
    int parent = 0;
    // 최대 힙 만들기
    // 부모 노드랑 비교
    while(index > 0)
    {
        // 왼쪽 자식
        if(index % 2 == 1){ parent = (index - 1) / 2;}
        // 오른쪽 자식
        else{ parent = (index - 2) / 2;}

        // 자식이 부모보다 더 크다면 교체
        if(heaps[index] > heaps[parent])
        {
            Swap(heaps[index], heaps[parent]);
            index = parent;
        }
        // 그렇지 않다면, 중지
        else { break; }
    }
}

// 삭제
void DeleteHeap(vector<int>& heaps)
{
    // 최대 힙의 0번째 요소 출력하고 삭제
    cout << heaps[0] << "\n";

    int len = (int)heaps.size();

    // 마지막 요소를 처음으로 이동
    heaps[0] = heaps[len - 1];
    heaps.pop_back();
    len--;

    int index = 0, left = -1, right = -1;
    while(index < len)
    {
        left = -1;
        right = -1;
        // 자식 존재 여부 확인
        if(index * 2 + 1 < len){ left = index * 2 + 1; }
        if(index * 2 + 2 < len){ right = index * 2 + 2; }

        // 양쪽 자식 노드 확인
        if(right != -1)
        {
            // 왼쪽 자식이 더 큰 경우
            if(heaps[left] >= heaps[right] && heaps[left] > heaps[index])
            {
                Swap(heaps[left], heaps[index]);
                index = left;
            }
            // 오른쪽 자식이 더 큰 경우
            else if(heaps[left] < heaps[right] && heaps[right] > heaps[index])
            {
                Swap(heaps[right], heaps[index]);
                index = right;
            }
            // 둘 다 그렇지 않은 경우
            else{ break; }
        }
        // 왼쪽 자식 노드만 확인
        else if(left != -1)
        {
            // 왼쪽 자식이 더 큰 경우
            if(heaps[left] > heaps[index])
            {
                Swap(heaps[left], heaps[index]);
                index = left;
            }
            else{ break; }
        }
        // 자식 노드가 없을 경우
        else { break; }
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 입력
    int N;
    cin >> N;

    vector<int> heaps;
    int oper;
    // 연산 횟수만큼 실행
    for(int i = 0; i < N; i++)
    {
        cin >> oper;
        // 출력 및 삭제
        if(oper == 0)
        {   
            // heap에 아무것도 없으면 0출력
            if((int)heaps.size() == 0){ cout << "0\n"; }
            else{ DeleteHeap(heaps); }
        }
        // 추가
        else
        {
            InsertHeap(heaps, oper);
        }
    }
}