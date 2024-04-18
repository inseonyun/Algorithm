#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    for (vector<int> d : data) {
        int val_idx;
    
        if (ext == "code") {
                val_idx = 0;
        } else if (ext == "date") {
                val_idx = 1;
        } else if (ext == "maximum") {
                val_idx = 2;
        } else {
                val_idx = 3;
        }
        if (d[val_idx] < val_ext)
            answer.push_back(d);
    }

    if (sort_by == "code") {
        sort(answer.begin(), answer.end(), [](vector<int> a, vector<int> b){
                return a[0] < b[0];
            });
    } else if (sort_by == "date") {
            sort(answer.begin(), answer.end(), [](vector<int> a, vector<int> b){
                return a[1] < b[1];
            });
    } else if (sort_by == "maximum") {
            sort(answer.begin(), answer.end(), [](vector<int> a, vector<int> b){
                return a[2] < b[2];
            });
    } else {
            sort(answer.begin(), answer.end(), [](vector<int> a, vector<int> b){
                return a[3] < b[3];
            });
    }
    
    return answer;
}
