#include <cstdint>
#include <iostream>

#include "Graph.hpp"

int main(int argc, char const *argv[]) {

    uint32_t n, m;

    std::cin >> n >> m;
    Graph g(n);

    uint32_t u, v, a, l, c;
    for (uint32_t i = 0; i < m; i++) {
        std::cin >> u >> v >> a >> l >> c;
        g.add_connection(u - 1, v - 1, a, l, c);
    }

    g.find_min_crossing_time(0);

    for (auto v : g.get_villages()) {
        std::cout << v->get_crossing_time() << std::endl;
    }

    return 0;
}
