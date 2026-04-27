#include "layout.hpp"
#include "view.hpp"
#include "util.hpp"

void Layout::tile(std::vector<View *> &views, Box area, float master_ratio, int gap) {
    // Collect only mapped views
    std::vector<View *> mapped;
    for (auto *v : views) {
        if (v->mapped) mapped.push_back(v);
    }

    size_t n = mapped.size();
    if (n == 0) return;

    int g = gap;
    int ax = area.x + g;
    int ay = area.y + g;
    int aw = area.w - 2 * g;
    int ah = area.h - 2 * g;

    if (n == 1) {
        mapped[0]->set_geometry(ax, ay, aw, ah);
        return;
    }

    // Master pane on left
    int master_w = (int)(aw * master_ratio) - g / 2;
    int stack_x  = ax + master_w + g;
    int stack_w  = aw - master_w - g;

    // Master
    mapped[0]->set_geometry(ax, ay, master_w, ah);

    // Stack: divide vertically
    size_t ns = n - 1;
    int each_h = (ah - (int)(ns - 1) * g) / (int)ns;

    for (size_t i = 0; i < ns; ++i) {
        int sy = ay + (int)i * (each_h + g);
        mapped[i + 1]->set_geometry(stack_x, sy, stack_w, each_h);
    }
}
