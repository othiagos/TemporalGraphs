#include "Graph.hpp"

Graph::Graph(uint32_t n) {
    this->m_n = 0;
    this->m_m = 0;

    add_n_village(n);
}

Graph::Graph(const Graph &g) {
    this->m_n = g.get_n();
    this->m_m = g.get_m();
    this->m_villages = std::vector(g.get_villages());
}

Graph &Graph::operator=(const Graph &g) {
    this->m_n = g.get_n();
    this->m_m = g.get_m();
    this->m_villages = std::vector(g.get_villages());

    return *this;
}

uint32_t Graph::get_n() const {
    return this->m_n;
}

uint32_t Graph::get_m() const {
    return this->m_m;
}

void Graph::add_n_village(uint32_t n_villages) {
    this->m_n += n_villages;

    for (uint32_t i = 0; i < n_villages; i++)
        add_village();
}

const std::vector<std::shared_ptr<Village>> &Graph::get_villages() const {
    return this->m_villages;
}

void Graph::add_village() {
    uint32_t index = get_villages().size();
    std::shared_ptr<Village> village(new Village(index));
    this->m_villages.push_back(village);
}

void Graph::add_connection(uint32_t first_index_village, uint32_t second_index_village,
                           uint32_t age_conn, uint32_t crossing_time, uint32_t construction_cost) {

    std::shared_ptr<Connection> conn(new Connection(first_index_village, second_index_village,
                                                    age_conn, crossing_time, construction_cost));

    this->m_villages.at(first_index_village)->add_connection_village(conn);
    this->m_villages.at(second_index_village)->add_connection_village(conn);

    this->m_m++;
}

void Graph::find_min_distance(uint32_t index_start_village) {
    std::shared_ptr<Village> start_village = m_villages.at(index_start_village);
    start_village->set_crossing_time(ZERO_TIME);

    std::priority_queue<std::shared_ptr<Village>> queue;
    queue.push(start_village);

    while (!queue.empty()) {
        std::shared_ptr<Village> current_village = queue.top();
        queue.pop();

        if (current_village->has_visited())
            continue;

        for (auto conn : current_village->get_connected_villages()) {
            uint32_t index_neighbor = conn->get_neighbors(current_village->get_index_village());
            std::shared_ptr<Village> next_village = m_villages.at(index_neighbor);

            uint32_t new_distance = current_village->get_crossing_time() + conn->get_crossing_time();
            if (next_village->get_crossing_time() > new_distance) {
                next_village->set_crossing_time(new_distance);
                queue.push(next_village);
            }
        }
        current_village->set_visited(true);
    }
}