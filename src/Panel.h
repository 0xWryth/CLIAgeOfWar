#ifndef CLIAGEOFWAR_PANEL_H
#define CLIAGEOFWAR_PANEL_H

#include <initializer_list>

enum class Panel { Top, Left, Right, Bottom };

constexpr std::initializer_list<Panel> all_Panel = {Panel::Top, Panel::Left, Panel::Right, Panel::Bottom};

#endif //CLIAGEOFWAR_PANEL_H
