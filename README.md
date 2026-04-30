<div align="center">


*A **Cxtremely** minimal tiling Wayland compositor.*

<br/>

</div>


## ⚡ Install (Arch Linux)

```bash
sudo pacman -S cmake pkgconf wlroots wayland wayland-protocols \
               libxkbcommon libinput pixman
```

```bash
git clone https://github.com/noxwm/noxwm
cd noxwm
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel
./build/noxwm
```


## 🎨 Customization

All customization is done by editing source files and recompiling. After **any** edit, rebuild with:

```bash
cmake --build build --parallel
```


### 🖥️ Terminal

Open `src/config.cpp`:

```cpp
terminal = "kitty";      // default
terminal = "foot";
terminal = "wezterm";
terminal = "alacritty";
terminal = "ghostty";
```


### 🪟 Layout & Gaps

Open `src/config.cpp`:

```cpp
gap          = 6;       // px gap between all windows and screen edges
master_ratio = 0.55f;   // how much width the master window takes (0.0 - 1.0)
```

| `master_ratio` | Effect |
|:---|:---|
| `0.5f` | Even 50/50 split |
| `0.65f` | Bigger master pane |
| `0.4f` | Smaller master, more stack room |


### 🎨 Colors

Open `src/config.cpp`. All colors are RGBA floats from `0.0` to `1.0`:

```cpp
bg_color        = {0.10f, 0.10f, 0.15f, 1.0f};  // background
active_border   = {0.3f,  0.6f,  1.0f,  1.0f};  // focused window border
inactive_border = {0.3f,  0.3f,  0.3f,  1.0f};  // unfocused window border
```

Common presets:
```cpp
// Catppuccin Mauve
active_border = {0.78f, 0.59f, 0.96f, 1.0f};

// Nord Frost
active_border = {0.53f, 0.75f, 0.85f, 1.0f};

// Rose (noxwm default palette)
active_border = {0.67f, 0.42f, 0.42f, 1.0f};

// Orange
active_border = {0.91f, 0.40f, 0.23f, 1.0f};
```


### ⌨️ Keybindings

Open `src/keybinds.cpp`, inside `KeybindManager::setup_defaults()`:

```cpp
// Basic launch
add(MOD, XKB_KEY_b, [](Server *s) {
    s->spawn("firefox");
});

// With Shift
add(MODS, XKB_KEY_f, [](Server *s) {
    s->spawn("thunar");
});

// With Ctrl
const uint32_t MOD_CTRL = WLR_MODIFIER_LOGO | WLR_MODIFIER_CTRL;
add(MOD_CTRL, XKB_KEY_l, [](Server *s) {
    s->spawn("swaylock");
});
```

Common keysym names:

| Key | Constant |
|:---|:---|
| Enter | `XKB_KEY_Return` |
| Space | `XKB_KEY_space` |
| a–z | `XKB_KEY_a` – `XKB_KEY_z` |
| F1–F12 | `XKB_KEY_F1` – `XKB_KEY_F12` |
| Arrows | `XKB_KEY_Left` `XKB_KEY_Right` `XKB_KEY_Up` `XKB_KEY_Down` |


### 🔲 Border Width

Open `src/config.cpp`:

```cpp
border_width = 2;   // px — set to 0 for no borders
```

### 🚀 Autostart

Open `src/server.cpp`, at the bottom of `Server::init()` before `return true`:

```cpp
spawn("waybar");
spawn("dunst");
spawn("swww-daemon");
```

## ⌨️ Default Keybindings

| Keybind | Action |
|:---|:---|
| `Super + Enter` | Launch kitty |
| `Super + Q` | Close window |
| `Super + J` | Focus next |
| `Super + K` | Focus previous |
| `Super + Shift + Q` | Exit |


## 🗂 Structure

```
src/          → compositor source
protocols/    → xdg-shell generated headers
scripts/      → build helpers
docs/         → keybindings reference
```

## 🔗 Related

- [noxwmctl](https://github.com/noxwm/noxwmctl) — IPC client for noxwm

