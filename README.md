# noctis

Minimal tiling Wayland compositor. Clean, fast, no bloat.

## Features

- Master-stack tiling layout
- `.nox` config format — no quotes, no brackets, just clean `key = value`
- Wallpaper via `swww`
- Autostart support
- Custom keybinds

## Dependencies

Arch:
```bash
pacman -S wlroots wayland wayland-protocols libxkbcommon pixman swww
```

## Build

```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel
```

## Setup

```bash
mkdir -p ~/.config/noctis
cp config/config.nox ~/.config/noctis/
cp config/wallpaper.jpg ~/.config/noctis/
./build/noctis
```

## Config — `~/.config/noctis/config.nox`

```
general {
    terminal     = kitty
    gap          = 6
    master_ratio = 0.55
    border_width = 2
    wallpaper    = ~/.config/noctis/wallpaper.jpg
}

colors {
    background      = #1a1a26
    active_border   = #AB6C6A
    inactive_border = #333333
}

autostart {
    exec = waybar
    exec = dunst
}

bind = SUPER, Return, exec, kitty
bind = SUPER, Q, close
bind = SUPER, J, focus_next
bind = SUPER, K, focus_prev
bind = SUPER SHIFT, Q, exit
```

## Default Keybinds

| Keys              | Action          |
|-------------------|-----------------|
| Super + Return    | Launch terminal |
| Super + Q         | Close window    |
| Super + J         | Focus next      |
| Super + K         | Focus prev      |
| Super + Shift + Q | Exit            |

## Themes

See `examples/` — copy any `.nox` file to `~/.config/noctis/config.nox`.

## TTY / Seat permissions

```bash
pacman -S seatd
systemctl enable --now seatd
usermod -aG seat $USER
# re-login then run noctis
```
