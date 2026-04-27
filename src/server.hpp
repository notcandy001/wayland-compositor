#pragma once

extern "C" {
#include <wayland-server-core.h>
#include <wlr/backend.h>
#include <wlr/render/allocator.h>
#include <wlr/render/wlr_renderer.h>
#include <wlr/types/wlr_compositor.h>
#include <wlr/types/wlr_subcompositor.h>
#include <wlr/types/wlr_data_device.h>
#include <wlr/types/wlr_output_layout.h>
#include <wlr/types/wlr_scene.h>
#include <wlr/types/wlr_xdg_shell.h>
#include <wlr/types/wlr_seat.h>
#include <wlr/types/wlr_cursor.h>
#include <wlr/types/wlr_xcursor_manager.h>
}

#include <vector>
#include <string>

#include "view.hpp"
#include "layout.hpp"
#include "keybinds.hpp"
#include "config.hpp"

struct Output;  // forward

struct Server {
    // Core Wayland/wlroots objects
    struct wl_display          *display        = nullptr;
    struct wlr_backend         *backend        = nullptr;
    struct wlr_renderer        *renderer       = nullptr;
    struct wlr_allocator       *allocator      = nullptr;
    struct wlr_compositor      *compositor     = nullptr;
    struct wlr_output_layout   *output_layout  = nullptr;
    struct wlr_scene           *scene          = nullptr;
    struct wlr_scene_output_layout *scene_layout = nullptr;

    // Shell
    struct wlr_xdg_shell       *xdg_shell      = nullptr;

    // Input
    struct wlr_seat            *seat           = nullptr;
    struct wlr_cursor          *cursor         = nullptr;
    struct wlr_xcursor_manager *cursor_mgr     = nullptr;

    // State
    std::vector<View *>   views;       // all known toplevels
    std::vector<Output *> outputs;     // all connected outputs
    View                 *focused_view = nullptr;

    // Layout engine
    Layout         layout;
    KeybindManager keybinds;

    // Backend listeners
    struct wl_listener new_output;
    struct wl_listener new_input;
    struct wl_listener new_xdg_toplevel;

    // Cursor listeners
    struct wl_listener cursor_motion;
    struct wl_listener cursor_motion_absolute;
    struct wl_listener cursor_button;
    struct wl_listener cursor_axis;
    struct wl_listener cursor_frame;

    // Seat listeners
    struct wl_listener request_cursor;
    struct wl_listener request_set_selection;

    bool init();
    void run();
    void destroy();

    // Focus helpers
    void focus_view(View *view);
    void focus_next();
    void focus_prev();

    // Layout trigger
    void apply_layout();

    // Get usable area for tiling (from first output)
    Box get_output_box();

    // Spawn a process
    void spawn(const std::string &cmd);
};
