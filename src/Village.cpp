#include "Village.hpp"

Village::Village(uint32_t index_village) {
    this->m_index_village = index_village;
    this->m_crossing_time = UINT64_MAX;
    this->m_visited = false;
    this->m_parent_village = NULL_PARENT;
}

Village::Village(const Village &v) {
    this->m_index_village = v.get_index_village();
    this->m_crossing_time = v.get_crossing_time();
    this->m_visited = v.has_visited();
    this->m_parent_village = v.get_parent_village();
    this->m_connected_villages = std::vector<Connection*>(v.get_connected_villages());
}

Village &Village::operator=(const Village &v) {
    this->m_index_village = v.get_index_village();
    this->m_crossing_time = v.get_crossing_time();
    this->m_visited = v.has_visited();
    this->m_parent_village = v.get_parent_village();
    this->m_connected_villages = std::vector<Connection*>(v.get_connected_villages());

    return *this;
}

uint32_t Village::get_index_village() const {
    return this->m_index_village;
}

uint64_t Village::get_crossing_time() const {
    return this->m_crossing_time;
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

void Village::set_crossing_time(uint64_t crossing_time) {
    this->m_crossing_time = crossing_time;
}

void Village::set_visited(bool visit) {
    this->m_visited = visit;
}

void Village::set_parent_village(uint32_t index_parent_village) {
    this->m_parent_village = index_parent_village;
}

const std::vector<Connection*> &Village::get_connected_villages() const {
    return this->m_connected_villages;
}

void Village::add_connection_village(Connection* conn) {
    this->m_connected_villages.push_back(conn);
}

bool Village::CompareCrossingTime::operator()(const Village* const o1, const Village* const o2) {
    return o1->get_crossing_time() > o2->get_crossing_time();
}
