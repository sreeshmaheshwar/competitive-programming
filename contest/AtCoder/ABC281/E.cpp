#include <iostream>
#include <set>
#include <vector>

template<typename T> struct kth_sum_tree {
  private:
    std::multiset<T> chosen;
    std::multiset<T> cands;
    int k;
    T sum;

  public:
    kth_sum_tree(int _k) : k(_k), sum(T{}) {}

    T kth_sum() const { return sum; }

    void insert(T x) {
        if ((int) chosen.size() < k) {
            sum += x;
            chosen.insert(x);
        } else if (x < *chosen.rbegin()) {
            sum -= *chosen.rbegin();
            cands.insert(*chosen.rbegin());
            chosen.erase(prev(chosen.end()));
            sum += x;
            chosen.insert(x);
        } else {
            cands.insert(x);
        }
    }

    void erase(T x) {
        auto it = chosen.find(x);
        if (it == chosen.end()) {
            it = cands.find(x);
            cands.erase(it);
        } else {
            sum -= *it;
            chosen.erase(it);
            if (!cands.empty()) {
                sum += *cands.begin();
                chosen.insert(*cands.begin());
                cands.erase(cands.begin());
            }
        }
    }
};

int main() {
    int n, m, k; 
    std::cin >> n >> m >> k;

    std::vector<int> a(n);
    kth_sum_tree<long long> tree(k);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if (i < m) tree.insert(a[i]);
    }

    std::cout << tree.kth_sum() << " ";
    for (int i = 0; i + m < n; ++i) {
        tree.erase(a[i]);
        tree.insert(a[i + m]);
        std::cout << tree.kth_sum() << " ";
    }
}