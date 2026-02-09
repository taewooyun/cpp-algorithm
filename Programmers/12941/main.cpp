// 프로그래머스 [12941] - [최솟값 만들기]
// https://school.programmers.co.kr/learn/courses/30/lessons/12941
// 주어진 두 배열의 원소를 곱한 값의 전체 합을 구하는 문제
// 시간복잡도: O(n log n)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 핵심 아이디어
// - 입력: int 배열 2개
// - 출력: 각 배열 원소 곱의 총 합
// - 핵심 로직: 곱한 값의 최소는 원소 합이 가장 적은것이 최소를 의미하기 때문에 각각 오름차, 내림차순으로 정렬 후 곱함
int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<>());

    for(int i=0; i<A.size(); i++) answer += A[i] * B[i];

    return answer;
}

int main() {
    // 테스트 케이스 실행
    auto answer = solution({1, 4, 2}, {5, 4, 4});

    // 결과 출력
    cout << answer << endl;

    return 0;
}