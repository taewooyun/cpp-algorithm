// 프로그래머스 [12939] - [최댓값과 최솟값]
// https://school.programmers.co.kr/learn/courses/30/lessons/12939
// 문자열로 주어진 정수들 중 최댓값과 최솟값을 찾아 "최솟값 최댓값" 형태로 반환하는 문제
// 시간복잡도: O(n)

#include <iostream>
#include <sstream>
#include <string>   

using namespace std;

// 핵심 아이디어
// - 입력: 공백으로 구분된 정수들이 담긴 문자열 s (예: "-1 2 3 4")
// - 출력: 최솟값과 최댓값을 공백으로 구분한 문자열 (예: "-1 4")
// - 핵심 로직: stringstream을 이용해 숫자를 하나씩 추출하면서 min/max를 갱신하고, 결과 문자열로 반환
string solution(string s){
    stringstream ss(s);
    int num, min = INT_MAX, max = INT_MIN;

    while (ss >> num){
        if(min > num) min = num;
        if(max < num) max = num;
    }

    return to_string(min) + " " + to_string(max);
}

int main() {
    // 테스트 케이스 실행
    auto answer = solution("-1 2 3 4");

    // 결과 출력
    cout << answer << endl;

    return 0;
}