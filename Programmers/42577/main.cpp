// 프로그래머스 [42577] - 전화번호 목록
// https://school.programmers.co.kr/learn/courses/30/lessons/42577
// 어떤 번호가 다른 번호의 접두어인 경우가 있는지 검사하는 문제
// 해시와 문자열 자르기를 이용
// 시간복잡도: O(N * L) (N = 전화번호 수, L = 평균 전화번호 길이)

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 핵심 아이디어
// - 모든 전화번호를 해시맵에 저장
// - 각 번호의 접두어(앞부분 부분 문자열)가 해시맵에 존재하면 false
bool solution(vector<string> phone_book) {
    bool answer = true;

    unordered_map<string, bool> hashMap;

    // 모든 전화번호를 해시맵에 추가
    for (string number : phone_book) {
        hashMap[number] = true;
    }

    // 각 전화번호에 대해, 앞부분 접두어가 해시맵에 존재하는지 확인
    for (string number : phone_book) {
        for (int i = 1; i < number.length(); i++) {
            string s = number.substr(0, i);  // 접두어 추출

            // 접두어가 다른 전화번호로 존재하면 false 조건
            if (hashMap.find(s) != hashMap.end()) {
                answer = false;
                break;
            }
        }

        // 접두어 충돌이 확인되면 전체 반복 종료
        if (!answer) break;
    }

    return answer;
}

int main() {
    // 테스트 케이스 실행
    auto answer = solution({"12","123","1235","567","88"});

    // 결과 출력
    cout << answer << endl;

    return 0;
}