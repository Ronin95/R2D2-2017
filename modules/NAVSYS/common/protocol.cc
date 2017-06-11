#include "protocol.hh"

sf::Packet & operator>>(sf::Packet & lhs, command c) {
    lhs >> static_cast<command>(c);
    return lhs;
}

sf::Packet & operator<<(sf::Packet & lhs, const command & c) {
    lhs << static_cast<int>(c);//std::underlying_type<command>::type
    return lhs;
}

sf::Packet & operator>>(sf::Packet & lhs, path nodes) {
    lhs >> nodes.startNode >> nodes.endNode;
    return lhs;
}

sf::Packet & operator<<(sf::Packet & lhs, const path & nodes) {
    lhs << nodes.startNode << nodes.endNode;
    return lhs;
}