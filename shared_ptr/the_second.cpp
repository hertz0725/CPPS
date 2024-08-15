// decode string
class Solution {
public:
    string decodeString(string s) {
        if (s.empty()) {
            return "";
        }

        std::stack<char> ch_stk;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ']') {
                ch_stk.push(s[i]);
            } else {
                std::string str_cnt;
                std::string unit;
                while (!ch_stk.empty() && ch_stk.top() != '[') {
                    unit += ch_stk.top();
                    ch_stk.pop();
                }

                ch_stk.pop();
                while (!ch_stk.empty() && std::isdigit(ch_stk.top())) {
                    str_cnt += ch_stk.top();
                    ch_stk.pop();
                }

                std::reverse(str_cnt.begin(), str_cnt.end());
                std::reverse(unit.begin(), unit.end());

                for (int j = 0; j < std::stoi(str_cnt); ++j) {
                    for (auto& ch : unit) {
                        ch_stk.push(ch);
                    }
                }
            }
        }

        std::string res_str;
        while (!ch_stk.empty()) {
            res_str += ch_stk.top();
            ch_stk.pop();
        }
        std::reverse(res_str.begin(), res_str.end());

        return res_str;
    }
};

// 3 sum 
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        if (arr.size() < 3) {
            return 0;
        }

        std::sort(arr.begin(), arr.end());

        size_t sum = 0;
        size_t MOD = 1e9 + 7;

        for (int i = 0; i < arr.size() - 2; ++i) {
            int tar = target - arr[i];
            
            int left = i + 1;
            int right = arr.size() - 1;

            while (left < right) {
                if (arr[left] + arr[right] > tar) {
                    right--;
                } else if (arr[left] + arr[right] < tar) {
                    left++;
                } else if (arr[left] != arr[right]) { // ==
                    int l_cnt = 1;
                    int r_cnt = 1;
                    while (arr[left] == arr[left+1]) {
                        l_cnt++;
                        left++;
                    }
                    while (arr[right] == arr[right-1]) {
                        r_cnt++;
                        right--;
                    }

                    sum += (l_cnt * r_cnt) % MOD;
                    left++;
                    right--;

                } else {
                    sum += (right - left + 1) * (right - left) / 2 % MOD;
                    break;
                }
            }
        }

        return sum % MOD;
    }
};
