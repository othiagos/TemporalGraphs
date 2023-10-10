#include "Graph.hpp"

Graph::Graph(uint32_t n, uint32_t m) {
    this->m_n = n;
    this->m_m = m;
    this->m_villages.reserve(n);
    this->m_connections.reserve(m);

    add_n_village(n);
}

Graph::Graph(const Graph &g) {
    this->m_n = g.get_n();
    this->m_m = g.get_m();
    this->m_villages = std::vector<Village*>(g.get_villages());
    this->m_connections = std::vector<Connection*>(g.get_connections());
}

Graph &Graph::operator=(const Graph &g) {
    this->m_n = g.get_n();
    this->m_m = g.get_m();
    this->m_villages = std::vector<Village*>(g.get_villages());
    this->m_connections = std::vector<Connection*>(g.get_connections());

    return *this;
}

Graph::~Graph() {
    for (Village* v : m_villages)
        delete v;

    for (Connection* c : m_connections)
        delete c;
}

uint32_t Graph::get_n() const {
    return this->m_n;
}

uint32_t Graph::get_m() const {
    return this->m_m;
}

void Graph::add_n_village(uint32_t n_villages) {
    for (uint32_t i = 0; i < n_villages; i++)
        add_village();
}

const std::vector<Village*> &Graph::get_villages() const {
    return this->m_villages;
}

const std::vector<Connection*> &Graph::get_connections() const {
    return this->m_connections;
}

void Graph::add_village() {
    this->m_villages.emplace_back(new Village(m_villages.size()));
}

void Graph::add_connection(uint32_t first_index_village, uint32_t second_index_village,
                           uint32_t age_conn, uint32_t crossing_time, uint32_t construction_cost) {

    this->m_connections.emplace_back(new Connection(first_index_village, second_index_village,
                                                    age_conn, crossing_time, construction_cost));

    this->m_villages[first_index_village]->add_connection_village(m_connections.back());
    this->m_villages[second_index_village]->add_connection_village(m_connections.back());
}

void Graph::find_min_age_conn(uint32_t index_start_village) {
    for (const auto &v : this->m_villages) {
        v->set_visited(false);
        v->set_parent_village(NULL_PARENT);
    }

    Village* start_village = m_villages[index_start_village];
    start_village->set_age_conn(ZERO_AGE);

    // define a min priority queue
    std::priority_queue<Village*, std::vector<Village*>, Village::CompareAgeConn> queue;
    queue.push(start_village);

    while (!queue.empty()) {
        Village* current_village = queue.top();
        queue.pop();

        if (current_village->has_visited())
            continue;

        for (auto conn : current_village->get_connected_villages()) {
            uint32_t index_neighbor = conn->get_neighbor(current_village->get_index_village());
            Village* next_village = m_villages[index_neighbor];

            uint64_t new_age = current_village->get_age_conn() + conn->get_age_conn();
            if (next_village->get_age_conn() > new_age) {
                next_village->set_age_conn(new_age);
                next_village->set_parent_village(current_village->get_index_village());
                queue.push(next_village);
            }
        }
        current_village->set_visited(true);
    }
}

void Graph::find_min_crossing_time(uint32_t index_start_village) {
    // for (const auto &v : this->m_villages) {
    //     v->set_visited(false);
    //     v->set_parent_village(NULL_PARENT);
    // }

    Village* start_village = m_villages[index_start_village];
    start_village->set_crossing_time(ZERO_TIME);

    // define a min priority queue
    std::priority_queue<Village*, std::vector<Village*>, Village::CompareCrossingTime> queue;
    queue.push(start_village);

    while (!queue.empty()) {
        Village* current_village = queue.top();
        queue.pop();

        if (current_village->has_visited())
            continue;

        for (auto conn : current_village->get_connected_villages()) {
            uint32_t index_neighbor = conn->get_neighbor(current_village->get_index_village());
            Village* next_village = m_villages[index_neighbor];

            uint64_t new_time = current_village->get_crossing_time() + conn->get_crossing_time();
            if (next_village->get_crossing_time() > new_time) {
                next_village->set_crossing_time(new_time);
                next_village->set_parent_village(current_village->get_index_village());
                queue.push(next_village);
            }
        }
        current_village->set_visited(true);
    }
}

void Graph::find_min_construction_cost(uint32_t index_start_village) {
    for (const auto &v : this->m_villages) {
        v->set_visited(false);
        v->set_parent_village(NULL_PARENT);
    }

    Village* start_village = m_villages[index_start_village];
    start_village->set_construction_cost(ZERO_TIME);

    // define a min priority queue
    std::priority_queue<Village*, std::vector<Village*>, Village::CompareConstructionCost> queue;
    queue.push(start_village);

    while (!queue.empty()) {
        Village* current_village = queue.top();
        queue.pop();

        if (current_village->has_visited())
            continue;

        for (auto conn : current_village->get_connected_villages()) {
            uint32_t index_neighbor = conn->get_neighbor(current_village->get_index_village());
            Village* next_village = m_villages[index_neighbor];

            uint64_t new_cost = current_village->get_construction_cost() + conn->get_construction_cost();
            if (next_village->get_construction_cost() > new_cost) {
                next_village->set_construction_cost(new_cost);
                next_village->set_parent_village(current_village->get_index_village());
                queue.push(next_village);
            }
        }
        current_village->set_visited(true);
    }
}

uint32_t Graph::find_smallest_achievable_year() {
    find_min_crossing_time(START_VILLAGE);

    std::vector<Connection*> best_conn;
    for (Connection *conn : this->m_connections) {
        uint32_t fi = conn->get_first_index_village();
        uint32_t si = conn->get_second_index_village();

        if (m_villages[fi]->get_parent_village() == si) {
            best_conn.push_back(conn);
        } else if (m_villages[si]->get_parent_village() == fi) {
            best_conn.push_back(conn);
        }
    }

    uint32_t max_age = best_conn.front()->get_age_conn();
    for (const auto &v : best_conn) {
        uint32_t value = v->get_age_conn();
        if (value > max_age) {
            max_age = value;
        }
    }
    return max_age;
}

uint32_t Graph::find_first_attainable_year() {
    find_min_age_conn(START_VILLAGE);

    std::vector<Connection*> best_conn;
    for (Connection *conn : this->m_connections) {
        uint32_t fi = conn->get_first_index_village();
        uint32_t si = conn->get_second_index_village();

        if (m_villages[fi]->get_parent_village() == si) {
            best_conn.push_back(conn);
        } else if (m_villages[si]->get_parent_village() == fi) {
            best_conn.push_back(conn);
        }
    }

    uint32_t max_age = best_conn.front()->get_age_conn();
    for (const auto &v : best_conn) {
        uint32_t value = v->get_age_conn();
        if (value > max_age) {
            max_age = value;
        }
    }
    return max_age;
}

uint64_t Graph::find_lowest_possible_cost() {
    find_min_construction_cost(START_VILLAGE);

    std::vector<Connection*> best_conn;
    for (Connection *conn : this->m_connections) {
        uint32_t fi = conn->get_first_index_village();
        uint32_t si = conn->get_second_index_village();

        if (m_villages[fi]->get_parent_village() == si) {
            best_conn.push_back(conn);
        } else if (m_villages[si]->get_parent_village() == fi) {
            best_conn.push_back(conn);
        }
    }

    uint64_t sum_cost = 0;
    for (const auto &v : best_conn) {
        sum_cost += v->get_construction_cost();
    }
    return sum_cost;
}
