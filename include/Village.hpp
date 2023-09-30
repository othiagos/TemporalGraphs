#pragma once

#include <cstdint>
#include <memory>
#include <vector>

#include "Connection.hpp"

class Village {
private:
    uint32_t m_index_village;
    uint32_t m_crossing_time;
    bool m_visited;
    std::vector<std::shared_ptr<Connection>> m_connected_villages;

public:
    Village(uint32_t index_village);

    Village(const Village &v);

    Village &operator=(const Village &v);

    uint32_t get_index_village() const;

    uint32_t get_crossing_time() const;

    bool has_visited() const;

    const std::vector<std::shared_ptr<Connection>> &get_connected_villages() const;

    void set_index_village(uint32_t index_village);

    void set_crossing_time(uint32_t crossing_time);

    void set_visited(bool visit);

    void add_connection_village(std::shared_ptr<Connection> conn);
};
