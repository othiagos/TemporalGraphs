#pragma once

#include <cstdint>
#include <memory>
#include <vector>

#include "Connection.hpp"

class Village {
private:
    uint32_t m_index_village;
    std::vector<std::shared_ptr<Connection>> m_connected_villages;

public:
    Village(uint32_t index_village);

    Village(const Village &v);

    Village &operator=(const Village &v);

    uint32_t get_index_village() const;

    void set_index_village(uint32_t index_village);

    const std::vector<std::shared_ptr<Connection>> &get_connected_villages() const;

    void add_connection_village(std::shared_ptr<Connection> conn);
};