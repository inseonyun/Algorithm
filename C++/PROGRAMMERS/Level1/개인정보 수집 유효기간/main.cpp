#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> split_date(string s) {
    vector<int> res;
    
    int y_m_idx = s.find('.');
    string year = s.substr(0, y_m_idx);
    string tmp = s.substr(y_m_idx + 1, s.length());
    
    int m_d_idx = tmp.find('.');
    string mon = tmp.substr(0, m_d_idx);
    string day = tmp.substr(m_d_idx + 1, tmp.length());
    
    res.push_back(stoi(year));
    res.push_back(stoi(mon));
    res.push_back(stoi(day));
    
    return res;
}

bool calc_date(vector<int> today, vector<int> now, int terms_mon) {
    long long _today = today[0] * 12 * 28 + today[1] * 28 + today[2];
    long long _now = now[0] * 12 * 28 + now[1] * 28 + now[2];
    
    long long terms_day = terms_mon * 28;
    
    return _today >= _now + terms_day;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    int n = privacies.size();
    map<char, int> _terms;
    
    vector<int> _today = split_date(today);
    
    // init 
    for (string s : terms) {
        int space_idx = s.find(' ');
        _terms[s[0]] = stoi(s.substr(space_idx, s.length()));
    }
    
    for (int i = 0; i < n; i++) {
        int space_idx = privacies[i].find(' ');
        string date = privacies[i].substr(0, space_idx);
        int now_terms = _terms[privacies[i][privacies[i].length() - 1]];
        
        vector<int> _date = split_date(date);
        
        bool isRemove = calc_date(_today, _date, now_terms);
        
        if (isRemove) {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}
