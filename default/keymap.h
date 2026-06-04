#pragma once

#include "timer.h"
#include "quantum.h"
#include "rgb_matrix.h"

#define _DEFAULT 0
#define _PERCENT 1
#define _CODE 2
#define _CONFIG 3

// Inclure le fichier d'images des couches
#include "layer_images.h"

// Variables pour gérer le dé-bouncing des encodeurs
static uint32_t last_encoder_update_time[2] = {0, 0}; // Deux encodeurs
const uint32_t encoder_update_interval = 50; // Intervalle minimal entre deux mises à jour en millisecondes

static void render_layer_status(uint8_t layer) {
    switch (layer) {
        case _DEFAULT:
        case _PERCENT:
        case _CODE:
            oled_write_raw_P(layer_icons[layer], _IMAGE_SIZE);
            break;
        case _CONFIG:
            oled_write_ln_P(PSTR("CONFIG"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Inconnu"), false);
            break;
    }
}

bool oled_task_user(void) {
    static uint8_t last_rendered_layer = 255;
    uint8_t layer = get_highest_layer(layer_state);

    if (layer != last_rendered_layer) {
        oled_clear();
        last_rendered_layer = layer;
    }

    render_layer_status(layer);
    return false; // Empêche le dessin par défaut du clavier
}

// Configuration des LEDs RGB avec effet goutte d'eau
void keyboard_post_init_user(void) {
    // Activer les LEDs RGB au boot, mais ne pas écraser le mode/couleur stockés en EEPROM.
    rgb_matrix_enable();
}

// Fonction pour envoyer uniquement des événements de défilement de souris sans affecter le volume
// Utilise les keycodes standard au lieu des fonctions pointing_device
void send_mouse_scroll(bool is_up) {
    if (is_up) {
        tap_code16(MS_WHLU);  // Mouse wheel up (QK_MOUSE_WHEEL_UP)
    } else {
        tap_code16(MS_WHLD);  // Mouse wheel down (QK_MOUSE_WHEEL_DOWN)
    }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    uint32_t current_time = timer_read32();
    if (current_time - last_encoder_update_time[index] < encoder_update_interval) {
        // Trop tôt depuis la dernière mise à jour
        return false;
    }
    last_encoder_update_time[index] = current_time;

    if (index == 0) { // Encodeur de gauche
        if (clockwise) {
            send_mouse_scroll(true); // Défilement vers le haut sans affecter le volume
        } else {
            send_mouse_scroll(false); // Défilement vers le bas sans affecter le volume
        }
    } else if (index == 1) { // Encodeur de droite
        uint8_t current_layer = get_highest_layer(layer_state);
        if (current_layer > _CODE) {
            current_layer = _DEFAULT;
        }

        if (clockwise) {
            layer_move((current_layer + 1) % 3); // Passe à la couche suivante (0 -> 1 -> 2 -> 0)
        } else {
            layer_move((current_layer == _DEFAULT) ? _CODE : current_layer - 1); // Reviens à la couche précédente
        }
    }

    return true; // Indique que l'action est gérée ici
}

// Fonction pour gérer les touches multimédia dans la couche _PERCENT
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Vérifie si nous sommes dans la couche _PERCENT
    if (IS_LAYER_ON(_PERCENT)) {
        // Intercepte les touches !@#$% et les remplace par des touches multimédia
        switch (keycode) {
            case KC_EXLM:  // Touche !
                if (record->event.pressed) {
                    tap_code(KC_MPLY);  // Play/Pause
                    return false;  // Ne pas traiter la touche originale
                }
                break;
            case KC_AT:    // Touche @
                if (record->event.pressed) {
                    tap_code(KC_MPRV);  // Piste précédente
                    return false;  // Ne pas traiter la touche originale
                }
                break;
            case KC_HASH:  // Touche #
                if (record->event.pressed) {
                    tap_code(KC_MNXT);  // Piste suivante
                    return false;  // Ne pas traiter la touche originale
                }
                break;
            case KC_DLR:   // Touche $
                if (record->event.pressed) {
                    tap_code(KC_MUTE);  // Muet
                    return false;  // Ne pas traiter la touche originale
                }
                break;
            case KC_PERC:  // Touche %
                if (record->event.pressed) {
                    tap_code(KC_VOLD);  // Volume -
                    return false;  // Ne pas traiter la touche originale
                }
                break;
        }
    }

    // Traitement normal pour toutes les autres touches
    return true;
}
