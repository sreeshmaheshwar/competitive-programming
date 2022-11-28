#include <iostream>
#include <vector>
#include <queue>

struct digraph {
  private:
    std::vector<std::vector<int>> adj;
    std::vector<int> in_degree;
    int n;

  public:
    digraph(int _n) : adj(_n), in_degree(_n), n(_n) {}

    void add_edge(int a, int b) {
        adj[a].push_back(b);
        in_degree[b]++;
    }

    /* Returns the lexicographically least topological sort of the graph
       if it exists. Otherwise, returns a vector of size less than n. */
    std::vector<int> topo_sort() {
        /* The nodes with current indegree of zero. */
        std::priority_queue<int, std::vector<int>, std::greater<int>> candidates;
        for (int i = 0; i < n; ++i) 
            if (in_degree[i] == 0) 
                candidates.push(i);

        /* The mimimal topological order, initially empty. */
        std::vector<int> order;
        while (!candidates.empty()) {
            int i = candidates.top(); 
            candidates.pop();
            
            /* Since i is the least node with current indegree zero,
               we can confidently add it to the topological order. */
            order.push_back(i);

            /* Iterate over neighbours, adding all new candidates. */
            for (int j : adj[i]) {
                in_degree[j]--;
                if (in_degree[j] == 0) 
                    candidates.push(j);
            }
        }
        return order;
    }
};

/* 
Example main program, solution to:
https://atcoder.jp/contests/abc223/tasks/abc223_d 
*/

int main() {
    int n, m;
    std::cin >> n >> m;

    digraph graph(n);

    for (int i = 0, a, b; i < m; ++i)
        std::cin >> a >> b, graph.add_edge(a - 1, b - 1);
    
    auto order = graph.topo_sort();

    if ((int) order.size() < n) {
        std::cout << -1;
    } else {
        for (int node : order) {
            std::cout << node + 1 << " ";
        }
    }
}