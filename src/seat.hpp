#pragma once

extern "C" {
#include <wlr/types/wlr_seat.h>
#include <wlr/types/wlr_compositor.h>
#include <wayland-server-core.h>
}

struct Server;

// Find the topmost wlr_surface and its surface-local coordinates at (lx, ly)
struct wlr_surface *desktop_surface_at(
    Server *server, double lx, double ly, double *sx, double *sy);
