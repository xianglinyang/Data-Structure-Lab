// Week 4_1
/*
 * 提供以下几个测试样例检查自己的代码：
 * 1. ""
 * 2. "010010"
 * 3. "0279245687407"
 */

#include <string>
#include <vector>

vector<string> is_ip(string seq) {
    vector<string> result;
    string empty;
    int start = 0;
    valid(start, seq, empty, result);

    return result;
}

void valid(int dot_amount, string &sub, string valid_part, vector<string> &res) {
    if (sub.empty()) return;
    // The first 3 fields of IP address.
    if (dot_amount < 3) {
        for (unsigned long dot_pos = 0; dot_pos < 3; dot_pos++) {
            string former_str = sub.substr(0, dot_pos + 1);
            string later_str;
            if (dot_pos + 1 < sub.size())
                later_str = sub.substr(dot_pos + 1, sub.size() - dot_pos - 1);
            else
                return;

            int former_int = stoi(former_str);

            // Continue to put next dot.
            if (valid_field(former_str))
                valid(dot_amount + 1, later_str, valid_part + former_str + '.', res);
            else return;
        }
    }
        // The last field of IP address.
    else if (dot_amount == 3) {
        if (sub.size() > 3) return;
        else {
            int last_field = stoi(sub);
            // Valid IP address.
            if (valid_field(sub)) {
                valid_part += sub;
                res.push_back(valid_part);
            }
            return;
        }
    }
}

bool valid_field(string const & field) {
    if (field.size() < 4) {
        int field_int = stoi(field);
        if (-1 < field_int && field_int < 256) {
            return (field == string("0") || field[0] != '0');
        }
        else return false;
    }
    else return false;
}


// Week 4_2
/* 可搜索"minimum edit distance"获取相关资料，学习dynamic programming
 * 本题理解上有一定难度，建议慢慢掌握
 */
int minDistance(string word1, string word2) {

    int l1 = word1.size();
    int l2 = word2.size();

    vector<int> f(l2+1, 0);
    for (int j = 1; j <= l2; ++j)
        f[j] = j;

    for (int i = 1; i <= l1; ++i)
    {
        int prev = i;
        for (int j = 1; j <= l2; ++j)
        {
            int cur;
            if (word1[i-1] == word2[j-1]) {
                cur = f[j-1];
            } else {
                cur = min(min(f[j-1], prev), f[j]) + 1;
            }

            f[j-1] = prev;
            prev = cur;
        }
        f[l2] = prev;
    }
    return f[l2];

}