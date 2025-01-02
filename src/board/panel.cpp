#include "../../include/board/panel.hpp"

Panel::Panel(u16 id, PanelType type, const std::bitset<4>& enters, const std::bitset<4>& exits):
    panelID{id}, type{type}, enters{enters}, exits{exits} {}

PanelType Panel::getType() const {
    return type;
}

void Panel::setType(PanelType newType) {
    type = newType;
}
