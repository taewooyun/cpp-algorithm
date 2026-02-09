// 프로그래머스 [12915] - [문자열 내 마음대로 정렬하기]
// https://school.programmers.co.kr/learn/courses/30/lessons/12915
// 문자열로 구성된 리스트를 특정 인덱스 기준으로 정렬하는 문제
// 시간복잡도: O(N log N)

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 핵심 아이디어
// - 핵심 로직: 특정 인덱스를 기준으로 정렬하되 동일한 값일 경우 사전순으로 정렬
vector<string> solution(vector<string> strings, int n) {
    sort(strings.begin(), strings.end(), [n](const string& a, const string& b) {
        return a[n] == b[n] ? a < b : a[n] < b[n];
    });
    return strings;
}

int main() {
    // 테스트 케이스 실행
    auto answer = solution({"abce", "abcd", "cdx"}, 2);

    // 결과 출력
    for(auto it : answer){
        cout << it <<" ";
    }
    cout << endl;

    return 0;
}