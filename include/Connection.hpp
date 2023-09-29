#pragma once

#include <cstdint>
#include <stdexcept>

class Connection {
private:
    uint32_t m_first_index_village;
    uint32_t m_second_index_village;
    uint32_t m_age_conn;
    uint32_t m_crossing_time;
    uint32_t m_construction_cost;

public:
    Connection(uint32_t first_index_village, uint32_t second_index_village, uint32_t age_conn,
               uint32_t crossing_time, uint32_t construction_cost);

    Connection(const Connection &conn);

    Connection &operator=(const Connection &conn);

    uint32_t get_first_index_village() const;

    uint32_t get_second_index_village() const;

    uint32_t get_age_conn() const;

    uint32_t get_crossing_time() const;

    uint32_t get_construction_cost() const;

    uint32_t get_neighbors(uint32_t my_index_village) const;

    void set_first_index_village(uint32_t index_village);

    void set_second_index_village(uint32_t index_village);

    void set_age_conn(uint32_t new_age);

    void set_crossing_time(uint32_t new_crossing_time);

    void set_construction_cost(uint32_t new_construction_cost);
};
