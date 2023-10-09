#pragma once

#include <cstdint>
#include <list>
#include <memory>

#include "Connection.hpp"

#define NULL_PARENT -1

class Village {
private:
    uint32_t m_index_village;
    uint64_t m_age_conn;
    uint64_t m_crossing_time;
    uint64_t m_construction_cost;
    bool m_visited;
    int32_t m_parent_village;
    std::list<uint32_t> m_connected_villages;

public:
    Village(uint32_t index_village);

    Village(const Village &v);

    Village &operator=(const Village &v);

    uint32_t get_index_village() const;

    uint64_t get_age_conn() const;

    uint64_t get_crossing_time() const;

    uint64_t get_construction_cost() const;

    bool has_visited() const;

    uint32_t get_parent_village() const;

    const std::list<uint32_t> &get_connected_villages() const;

    void set_index_village(uint32_t index_village);

    void set_age_conn(uint64_t age_conn);

    void set_crossing_time(uint64_t crossing_time);

    void set_construction_cost(uint64_t construction_cost);

    void set_visited(bool visit);

    void set_parent_village(uint32_t index_parent_village);

    void add_connection_village(uint32_t conn);

    struct CompareAgeConn {
        bool operator()(const std::shared_ptr<Village> &o1, const std::shared_ptr<Village> &o2);
    };

    struct CompareCrossingTime {
        bool operator()(const std::shared_ptr<Village> &o1, const std::shared_ptr<Village> &o2);
    };

    struct CompareConstructionCost {
        bool operator()(const std::shared_ptr<Village> &o1, const std::shared_ptr<Village> &o2);
    };
};
