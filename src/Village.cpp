#include "Village.hpp"

Village::Village(uint32_t index_village) {
    this->m_index_village = index_village;
    this->m_age_conn = UINT16_MAX;
    this->m_crossing_time = UINT32_MAX;
    this->m_construction_cost = UINT32_MAX;
    this->m_visited = false;
    this->m_parent_village = NULL_PARENT;
}

Village::Village(const Village &v) {
    this->m_index_village = v.get_index_village();
    this->m_age_conn = v.get_age_conn();
    this->m_crossing_time = v.get_crossing_time();
    this->m_construction_cost = v.get_construction_cost();
    this->m_visited = v.has_visited();
    this->m_parent_village = v.get_parent_village();
    this->m_connected_villages = std::vector(v.get_connected_villages());
}

Village &Village::operator=(const Village &v) {
    this->m_index_village = v.get_index_village();
    this->m_age_conn = v.get_age_conn();
    this->m_crossing_time = v.get_crossing_time();
    this->m_construction_cost = v.get_construction_cost();
    this->m_visited = v.has_visited();
    this->m_parent_village = v.get_parent_village();
    this->m_connected_villages = std::vector(v.get_connected_villages());

    return *this;
}

uint32_t Village::get_index_village() const {
    return this->m_index_village;
}

uint32_t Village::get_age_conn() const {
    return this->m_age_conn;
}

uint32_t Village::get_crossing_time() const {
    return this->m_crossing_time;
}

uint32_t Village::get_construction_cost() const {
    return this->m_construction_cost;
}

bool Village::has_visited() const {
    return this->m_visited;
}

uint32_t Village::get_parent_village() const {
    return this->m_parent_village;
}

void Village::set_index_village(uint32_t index_village) {
    this->m_index_village = index_village;
}

void Village::set_age_conn(uint32_t age_conn) {
    this->m_age_conn = age_conn;
}

void Village::set_crossing_time(uint32_t crossing_time) {
    this->m_crossing_time = crossing_time;
}

void Village::set_construction_cost(uint32_t construction_cost) {
    this->m_construction_cost = construction_cost;
}

void Village::set_visited(bool visit) {
    this->m_visited = visit;
}

void Village::set_parent_village(uint32_t index_parent_village) {
    this->m_parent_village = index_parent_village;
}

const std::vector<std::shared_ptr<Connection>> &Village::get_connected_villages() const {
    return this->m_connected_villages;
}

void Village::add_connection_village(const std::shared_ptr<Connection> &conn) {
    this->m_connected_villages.push_back(conn);
}
