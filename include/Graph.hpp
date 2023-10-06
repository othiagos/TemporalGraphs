#pragma once

#include <cstdint>
#include <memory>
#include <queue>
#include <vector>

#include "Village.hpp"

#define ZERO_AGE 0
#define ZERO_TIME 0
#define ZERO_COST 0
#define START_VILLAGE 0

class Graph {
private:
    uint32_t m_n;
    uint32_t m_m;
    std::vector<std::shared_ptr<Village>> m_villages;
    std::vector<std::shared_ptr<Connection>> m_connections;

    void add_n_village(uint32_t n_villages);

public:
    Graph(uint32_t n = 0, uint32_t m = 0);

    Graph(const Graph &g);

    Graph &operator=(const Graph &g);

    uint32_t get_n() const;

    uint32_t get_m() const;

    const std::vector<std::shared_ptr<Village>> &get_villages() const;

    void add_village();

    void add_connection(uint32_t first_index_village, uint32_t second_index_village,
                        uint32_t age_conn, uint32_t crossing_time, uint32_t construction_cost);

    void find_min_age_conn(uint32_t index_start_village);

    void find_min_crossing_time(uint32_t index_start_village);

    void find_min_construction_cost(uint32_t index_start_village);

    uint32_t find_smallest_achievable_year();

    uint32_t find_first_attainable_year();

    uint64_t find_lowest_possible_cost();
};
