#pragma once

#include <cstdint>
#include <vector>

#include "Connection.hpp"

#define NULL_PARENT -1

class Village {
private:
    uint32_t m_index_village;
    uint64_t m_crossing_time;
    bool m_visited;
    int32_t m_parent_village;
    std::vector<Connection *> m_connected_villages;

public:
    Village(uint32_t index_village);

    Village(const Village &v);

    Village &operator=(const Village &v);

    uint32_t get_index_village() const;

    uint64_t get_crossing_time() const;

    bool has_visited() const;

    uint32_t get_parent_village() const;

    const std::vector<Connection *> &get_connected_villages() const;

    void set_index_village(uint32_t index_village);

    void set_crossing_time(uint64_t crossing_time);

    void set_visited(bool visit);

    void set_parent_village(uint32_t index_parent_village);

    void add_connection_village(Connection *conn);

    struct CompareCrossingTime {
        bool operator()(const Village *const o1, const Village *const o2);
    };
};
