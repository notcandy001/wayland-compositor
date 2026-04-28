# Keybindings

The modifier key is **Super** (Win/Logo key).

| Keybind | Action |
|---|---|
| `Super + Enter` | Launch terminal (`alacritty` by default) |
| `Super + Q` | Close focused window |
| `Super + J` | Focus next window |
| `Super + K` | Focus previous window |
| `Super + Shift + Q` | Exit compositor |

## Changing the Terminal

Edit `src/config.cpp` and change the `terminal` field:

```cpp
terminal = "foot";   // or kitty, wezterm, etc.
```

## Adding Keybinds

In `src/keybinds.cpp`, inside `KeybindManager::setup_defaults()`:

```cpp
add(MOD, XKB_KEY_b, [](Server *s) {
    s->spawn("firefox");
});
```

`MOD` is `WLR_MODIFIER_LOGO`. Combine modifiers with `|`:

```cpp
const uint32_t MOD_SHIFT = WLR_MODIFIER_LOGO | WLR_MODIFIER_SHIFT;
add(MOD_SHIFT, XKB_KEY_e, [](Server *s) {
    s->spawn("thunar");
});
```
