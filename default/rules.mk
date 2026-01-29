AUDIO_ENABLE = no
SPLIT_KEYBOARD = yes
SPLIT_USB_DETECT = yes

# Activer RGB_MATRIX et désactiver RGBLIGHT
RGB_MATRIX_ENABLE = yes
RGBLIGHT_ENABLE = no

# Optimisations pour économiser de l'espace
EXTRAFLAGS += -flto
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
MOUSEKEY_ENABLE = yes  # Nécessaire pour KC_MS_WH_UP/DOWN (scroll souris encodeur)