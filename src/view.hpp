#pragma once

extern "C" {
#include <wlr/types/wlr_xdg_shell.h>
#include <wlr/types/wlr_scene.h>
#include <wayland-server-core.h>
}

struct Server;

struct View {
    Server *server;

    struct wlr_xdg_toplevel *toplevel;
    struct wlr_scene_tree   *scene_tree;

    // Geometry assigned by layout
    int x, y, w, h;

    bool mapped;

    // Wayland signal listeners
    struct wl_listener map;
    struct wl_listener unmap;
    struct wl_listener destroy;
    struct wl_listener request_move;
    struct wl_listener request_resize;
    struct wl_listener request_maximize;
    struct wl_listener request_fullscreen;

    // Initialize and attach listeners
    void init(Server *srv, struct wlr_xdg_toplevel *tl, struct wlr_scene_tree *tree);
    void focus();
    void set_geometry(int x, int y, int w, int h);

    // Bring to front in scene graph
    void raise();
};
