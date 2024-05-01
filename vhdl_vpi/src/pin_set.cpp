#include "pin_set.hpp"
#include "pin.hpp"

pin_set::pin_set() {}

/// adds [p] to pin set
void pin_set::add_pin(pin p) {
    pins.push_back(p);
}

/// returns true if [p] exists on pin set
bool pin_set::pin_exists(pin p) const {
    for (const auto& p2 : pins) {
        if (p.id == p2.id)
            return true;
    }
    return false;
}

/// returns true if [p] exists on pin set
bool pin_set::pin_exists(const std::string& pin_id) const {
    for (const auto& p : pins) {
        if (p.id == pin_id)
            return true;
    }
    return false;
}

/// returns pointer to pin by his identifier
pin* pin_set::get_pin(const std::string& pin_id) {
    for (auto& p : pins) {
        if (p.id == pin_id)
            return &p;
    }
    fprintf(stderr, "VPI_ERROR: Something went wrong @ get_pin");
    // TODO: returning a pointer can be a really bad idea because pins is a std::vector
    return nullptr;
}

/// returns pin's signal value by his identifier
bool pin_set::get_pin_value(const std::string& pin_id) const {
    for (const auto& p : pins) {
        if (p.id == pin_id)
            return p.get_value();
    }
    fprintf(stderr, "VPI_ERROR: Something went wrong @ get_pin_value");
    return 0;
}

/// returns net's signal value by his net name and index (e.g cout[3] = cout, 3)
bool pin_set::get_pin_value(const std::string& net_name, std::size_t index) const {
    for (const auto& p : pins) {
        if (p.net_name == net_name && p.index == index)
            return p.get_value();
    }
    fprintf(stderr, "VPI_ERROR: Something went wrong @ get_pin_value");
    return 0;
}

/// returns a net pointer to pin's by his identifier
vpiHandle pin_set::get_pin_net(const std::string& pin_id) const {
    for (const auto& p : pins) {
        if (p.id == pin_id)
            return p.net;
    }
    fprintf(stderr, "VPI_ERROR: Something went wrong @ get_pin_net");
    return nullptr;
}

/// returns a net pointer to pin's by signal name
vpiHandle pin_set::get_pin_net(const std::string& net_name, std::size_t index) const {
    for (const auto& p : pins) {
        if (p.net_name == net_name && p.index == index)
            return p.net;
    }
    fprintf(stderr, "VPI_ERROR: Something went wrong @ get_pin_net");
    return nullptr;
}

/// prints pin set
void pin_set::debug_pin_set() const {
    for (const auto& p : pins) {
        p.debug_pin();
    }
}