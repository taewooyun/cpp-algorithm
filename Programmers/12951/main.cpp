// 프로그래머스 [12951] - [JadenCase 문자열 만들기]
// https://school.programmers.co.kr/learn/courses/30/lessons/12951
// 문자열 s가 주어졌을 때, 각 단어의 첫 글자는 대문자, 나머지 글자는 소문자로 변환하는 문제
// 시간복잡도: O(n)

#include <iostream>

using namespace std;

// 핵심 아이디어
// - 입력: 단어와 공백으로 이루어진 문자열 s
// - 출력: 각 단어의 첫 글자는 대문자, 나머지는 소문자로 변환한 문자열
// - 핵심 로직: 공백을 기준으로 단어 경계를 판별하면서, 단어의 첫 문자는 toupper, 그 외 문자는 tolower 적용
string solution(string s) {
    bool isFirst = true;
    for(int i=0; i<s.size(); i++){
        char &c = s[i];
        if(s[i] == ' '){
            isFirst = true;
            continue;
        }
        if (isFirst) {
            c = static_cast<char>(toupper(static_cast<unsigned char>(c)));
            isFirst = false;
        } else {
            c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
        }
    }
    return s;
}

int main() {
    // 테스트 케이스 실행
    auto answer = solution("3people unFollowed me");

    // 결과 출력
    cout << answer << endl;

    return 0;
}