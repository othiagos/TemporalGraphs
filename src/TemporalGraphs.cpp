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

    uint32_t small_year = g.find_smallest_achievable_year();

    for (auto v : g.get_villages()) {
        std::cout << v->get_crossing_time() << std::endl;
    }
    std::cout << small_year << std::endl;

    uint32_t first_year = g.find_first_attainable_year();
    std::cout << first_year << std::endl;

    uint32_t lowest_cost = g.find_lowest_possible_cost();
    std::cout << lowest_cost << std::endl;

    return 0;
}
