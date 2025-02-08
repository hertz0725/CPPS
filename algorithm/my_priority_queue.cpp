#include <iostream>
#include <vector>

template <class T, class Container = std::vector<T>,
         class Cmp = std::less<class Container::value_type>>
class my_priority_queue {
public:
    my_priority_queue() = default;

public:
    const T& top() {
        if (_data.size() == 0) {
            throw std::out_of_range("out of range xxx");
        }

        return _data.front();
    }

    void push(T item) {
        _data.push_back(item);
        sift_up(_data.size() -1);

        //std::cout << "after push: \n";

        //for (auto nu : _data) {
        //    std::cout << nu << ", ";
        //}

        //std::cout << "\n";
    }

    void pop() {
        if (_data.size() == 0) {
            return;
        }

        _data[0] = _data.back();
        _data.pop_back();

        sink(0);

        //std::cout << "after sink: \n";

        //for (auto nu : _data) {
        //    std::cout << nu << ", ";
        //}

        //std::cout << "\n";

    }

    bool empty() {
        return _data.empty();
    }

public:
    void sift_up(int index) {
        if (index <= 0 || index >= _data.size()) {
            return;
        }

        while (index > 0) {
            int parent = (index - 1) / 2;

            if (!_cmp(_data[parent], _data[index])) {
                break;
            }

            std::swap(_data[parent], _data[index]);

            index = parent;
        }
    }

    void sink(int index) {
        if (index < 0 || index >= _data.size()) {
            return;
        }

        while (true) {
            int max_idx = index;
            int left = index * 2 + 1;
            int right = left + 1;

            if (left < _data.size() && _cmp(_data[max_idx], _data[left])) {
                max_idx = left;
            }

            if (right < _data.size() && _cmp(_data[max_idx], _data[right])) {
                max_idx = right;
            }

            if (max_idx == index) {
                break;
            }

            std::swap(_data[index], _data[max_idx]);

            index = max_idx;
        }
    }

private:
    Container _data;
    Cmp _cmp;
};


int main() {
    struct cmp {
        bool operator() (int left, int right) {
            return left > right;
        }
    };

    my_priority_queue<int, std::vector<int>, cmp> my_pq;

    my_pq.push(9);
    my_pq.push(0);
    my_pq.push(5);
    my_pq.push(3);
    my_pq.push(4);
    my_pq.push(6);


    while (!my_pq.empty()) {
        std::cout << "top " <<  my_pq.top() << ", \n";
        my_pq.pop();
    }

    return 0;
}
