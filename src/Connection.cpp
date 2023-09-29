#include "Connection.hpp"

Connection::Connection(uint32_t first_index_village, uint32_t second_index_village,
                       uint32_t age_conn, uint32_t crossing_time, uint32_t construction_cost) {
    this->m_first_index_village = first_index_village;
    this->m_second_index_village = second_index_village;
    this->m_age_conn = age_conn;
    this->m_crossing_time = crossing_time;
    this->m_construction_cost = construction_cost;
}

Connection::Connection(const Connection &conn) {
    this->m_first_index_village = conn.get_first_index_village();
    this->m_second_index_village = conn.get_second_index_village();
    this->m_age_conn = conn.get_age_conn();
    this->m_crossing_time = conn.get_crossing_time();
    this->m_construction_cost = conn.get_construction_cost();
}

Connection &Connection::operator=(const Connection &conn) {
    this->m_first_index_village = conn.get_first_index_village();
    this->m_second_index_village = conn.get_second_index_village();
    this->m_age_conn = conn.get_age_conn();
    this->m_crossing_time = conn.get_crossing_time();
    this->m_construction_cost = conn.get_construction_cost();

    return *this;
}

uint32_t Connection::get_first_index_village() const {
    return this->m_first_index_village;
}

uint32_t Connection::get_second_index_village() const {
    return this->m_second_index_village;
}

uint32_t Connection::get_age_conn() const {
    return this->m_age_conn;
}

uint32_t Connection::get_crossing_time() const {
    return this->m_crossing_time;
}

uint32_t Connection::get_construction_cost() const {
    return this->m_crossing_time;
}

uint32_t Connection::get_neighbors(uint32_t my_index_village) const {
    if (this->m_first_index_village != my_index_village)
        return m_first_index_village;

    if (this->m_second_index_village != my_index_village)
        return m_second_index_village;

    throw std::invalid_argument(
        "index of the village not belonging to the connection: provided index " +
        std::to_string(my_index_village));
}

void Connection::set_first_index_village(uint32_t index_village) {
    this->m_first_index_village = index_village;
}

void Connection::set_second_index_village(uint32_t index_village) {
    this->m_second_index_village = index_village;
}

void Connection::set_age_conn(uint32_t new_age) {
    this->m_age_conn = new_age;
}

void Connection::set_crossing_time(uint32_t new_crossing_time) {
    this->m_crossing_time = new_crossing_time;
}

void Connection::set_construction_cost(uint32_t new_construction_cost) {
    this->m_construction_cost = new_construction_cost;
}
