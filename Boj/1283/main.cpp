// 백준 [1283] - [단축키 지정]
// https://www.acmicpc.net/problem/1283
// 문장으로 주어진 문자열에서 단축키를 중복되지 않게 선택하는 문제
// 시간복잡도: O(N*L)
// N: 문장 개수, L: 한 문장의 길이

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <cctype>

using namespace std;

// - 핵심 로직: 해쉬를 사용한 사용 여부 판단
int main()
{
    int n;
    cin >> n;     // 문장 개수 입력
    cin.ignore(); // 개행 문자 제거 (getline 사용 대비)

    unordered_set<char> keys; // 이미 사용된 단축키 저장
    vector<string> result;    // 최종 결과 저장

    // 각 문장 처리
    for (int i = 0; i < n; ++i)
    {
        string str;
        getline(cin, str); // 한 줄 전체 입력

        vector<string> tokens;  // 문장을 단어 단위로 분리
        bool completed = false; // 단축키를 찾았는지 여부

        // 문자열을 공백 기준으로 분리
        stringstream ss(str);
        string token;

        while (getline(ss, token, ' '))
        {
            tokens.push_back(token);
        }

        for (string &token : tokens)
        {
            // 대소문자 구분 없이 비교
            char target = tolower((unsigned char)token[0]);

            // 아직 사용되지 않은 문자라면 선택
            if (!keys.count(target))
            {
                keys.insert(target); // 단축키 등록

                // 첫 글자에 [] 추가
                token.insert(0, "[");
                token.insert(2, "]");

                completed = true;
                break; // 한 개만 선택하면 종료
            }
        }

        if (!completed)
        {
            for (string &token : tokens)
            {
                // 첫 글자는 이미 검사했으므로 j = 1부터 시작
                for (int j = 1; j < token.size(); ++j)
                {
                    char target = tolower((unsigned char)token[j]);

                    // 아직 사용되지 않은 문자라면 선택
                    if (!keys.count(target))
                    {
                        keys.insert(target); // 단축키 등록

                        // 해당 위치에 [] 삽입
                        token.insert(j, "[");
                        token.insert(j + 2, "]");

                        completed = true;
                        break;
                    }
                }

                // 이미 찾았으면 더 탐색하지 않음
                if (completed)
                    break;
            }
        }

        str.clear();

        for (string &token : tokens)
        {
            if (!str.empty())
                str.append(" "); // 단어 사이 공백 추가

            str.append(token);
        }

        // 결과 저장
        result.push_back(str);
    }

    for (string &s : result)
    {
        cout << s << endl;
    }

    return 0;
}