// 실버 2 - 1927번 : 최소 힙
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>

using namespace std;

void Swap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

// 최소힙에 삽입
void Insert(vector<int> &heap, int num, int &len)
{
    heap.push_back(num);
    // heap[len] = num;
    len++;
    int index = len;
    int parent = 0;
    // index가 모두 유효할 때까지
    while(1 < index)
    {
        // 부모 노드 찾기

        // 홀수
        if(index % 2 == 1){parent = (index - 1) / 2;}
        // 짝수
        else{parent = index / 2;}

        // 부모가 자식보다 더 클 때, 교환
        if(heap[parent-1] > heap[index-1])
        {
            Swap(heap[parent-1], heap[index-1]);
        }
        // 그렇지 않다면, 중단
        else{ break; }
        index = parent;
    }
}

// 최소힙에 삭제
void Delete(vector<int> &heap, int& len)
{
    int index = 1;
    int left = 0, right = 0;
    int child = 0;
    // 길이가 0일 경우
    if(len == 0)
    {
        cout << "0\n";
    }
    // 길이가 0이 아닌 경우
    else
    {
        // 마지막 요소를 처음으로 이동
        cout << heap[0] << "\n";
        heap[0] = heap[len - 1];
        len--;
        heap.pop_back();
        // index는 1번부터 처리했는데 마지막 요소 번째인 len을 빼고 계산해서 문제가 발생.
        // --> while(index < len)
        while(index <= len)
        {
            left = 0, right = 0;
            // 자식 노드 존재하는지 확인
            if(index * 2 + 1 <= len){right = index * 2 + 1;}
            if(index * 2 <= len){left = index * 2;}
            // 오른쪽 노드가 존재할 때
            if(right != 0)
            {
                // 왼쪽 자식과 교환 - 단, 오른쪽 자식보다는 작음.
                if(heap[left-1] <= heap[right-1] && heap[left-1] < heap[index-1])
                {
                    child = left;
                    Swap(heap[child-1], heap[index-1]);
                    index = left;
                }

                // 오른쪽 자식과 교환
                else if(heap[left-1] > heap[right-1] && heap[right-1] < heap[index-1])
                {
                    child = right;
                    Swap(heap[child-1], heap[index-1]);
                    index = right;
                }
                // 교환을 하지 않은 경우
                else{ break; }
            }
            // 왼쪽 노드고 왼쪽 자식 크기가 더 작을 때
            else if(left != 0 && heap[left-1] < heap[index-1])
            {
                child = left;
                Swap(heap[child-1], heap[index-1]);
                index = left;
            }
            // 자식 노드가 존재하지 않거나 자식이 있어도 교환하지 않을 때
            else
            {
                index *= 2;
                break;
            }
        }
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

    vector<int> heap;
    int temp, len = 0;
    for(int i = 0; i < N; i++)
    {
        cin >> temp;

        // 0을 입력할 경우, 출가장 작은 값을 출력하고 제거
        if(temp == 0)
        {
            Delete(heap, len);
        }
        // 최소힙에 넣음
        else
        {
            Insert(heap, temp, len);
        }
    }
}