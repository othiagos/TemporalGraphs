#pragma once

#include <cstdint>
#include <queue>
#include <vector>

#include "Village.hpp"

#define ZERO_TIME 0
#define START_VILLAGE 0

class Graph {
private:
    uint32_t m_n;
    uint32_t m_m;
    std::vector<Village*> m_villages;
    std::vector<Connection*> m_connections;

    void add_n_village(uint32_t n_villages);

public:
    Graph(uint32_t n = 0, uint32_t m = 0);

    Graph(const Graph &g);

    Graph &operator=(const Graph &g);

    ~Graph();

    uint32_t get_n() const;

    uint32_t get_m() const;

    const std::vector<Village*> &get_villages() const;

    const std::vector<Connection*> &get_connections() const;

    void add_village();

    void add_connection(uint32_t first_index_village, uint32_t second_index_village,
                        uint32_t age_conn, uint32_t crossing_time, uint32_t construction_cost);

    void find_min_crossing_time(uint32_t index_start_village);

    template <class Compare>
    void mst_prim(uint32_t index_start_village, std::vector<Connection*> *min_tree, Compare);

    uint32_t find_smallest_achievable_year();

    uint32_t find_first_attainable_year();

    uint64_t find_lowest_possible_cost();
};
