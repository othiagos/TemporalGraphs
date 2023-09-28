#include "Village.hpp"

Village::Village(uint32_t index_village) {
    this->m_index_village = index_village;
}

Village::Village(const Village &v) {
    this->m_index_village = v.get_index_village();
    this->m_connected_villages = std::vector(v.get_connected_villages());
}

Village &Village::operator=(const Village &v) {
    this->m_index_village = v.get_index_village();
    this->m_connected_villages = std::vector(v.get_connected_villages());

    return *this;
}

uint32_t Village::get_index_village() const {
    return this->m_index_village;
}

void Village::set_index_village(uint32_t index_village) {
    this->m_index_village = index_village;
}

const std::vector<std::shared_ptr<Connection>> &Village::get_connected_villages() const {
    return this->m_connected_villages;
}

void Village::add_connection_village(std::shared_ptr<Connection> conn) {
    this->m_connected_villages.push_back(conn);
}
