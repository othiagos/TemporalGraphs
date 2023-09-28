#pragma once

#include <cstdint>
#include <memory>
#include <vector>

#include "Village.hpp"

class Graph {
private:
    uint32_t m_n;
    uint32_t m_m;
    std::vector<std::shared_ptr<Village>> m_villages;

    void add_n_village(uint32_t n_villages);

public:
    Graph(uint32_t n = 0);

    Graph(const Graph &g);

    Graph &operator=(const Graph &g);

    uint32_t get_n() const;

    uint32_t get_m() const;

    const std::vector<std::shared_ptr<Village>> &get_villages() const;

    void add_village();

    void add_connection(uint32_t first_index_village, uint32_t second_index_village,
                        uint32_t age_conn, uint32_t crossing_time, uint32_t construction_cost);
};