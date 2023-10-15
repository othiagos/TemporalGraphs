#include <cstdint>
#include <iostream>

#include "Graph.hpp"

int main(int argc, char const *argv[]) {

    uint32_t n, m;

    scanf("%d%d", &n, &m);
    Graph g(n, m);

    uint32_t u, v, a, l, c;
    for (uint32_t i = 0; i < m; i++) {
        scanf("%d%d%d%d%d", &u, &v, &a, &l, &c);
        g.add_connection(u - 1, v - 1, a, l, c);
    }

    g.find_min_crossing_time(START_VILLAGE);
    for (auto v : g.get_villages())
        std::cout << v->get_crossing_time() << '\n';

    uint32_t small_year = g.find_smallest_achievable_year();
    std::cout << small_year << '\n';

    uint32_t first_year = g.find_first_attainable_year();
    std::cout << first_year << '\n';

    uint64_t lowest_cost = g.find_lowest_possible_cost();
    std::cout << lowest_cost << '\n';

    return 0;
}
