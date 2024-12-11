#pragma once

#include "timer.h" // Nécessaire pour gérer les timers dans QMK

static const char PROGMEM logo[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xFC, 0x6C, 0x6C, 0x6C, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x03, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xFE,
    0x80, 0x80, 0x80, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x7F, 0xFF, 0x80, 0xC0,
    0xFF, 0x3E, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x80, 0x80, 0x80, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x80, 0xC0,
    0xE0, 0xF0, 0x00, 0x00, 0x00, 0x00,
    0x1E, 0x7F, 0x61, 0x41, 0x79, 0x78,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x80, 0xC0,
    0xE0, 0xF0, 0x78, 0x3C, 0x9E, 0xCF,
    0xE7, 0xF3, 0x79, 0x3C, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x80, 0xC0,
    0xE0, 0xF0, 0x78, 0x3C, 0x9E, 0xCF,
    0xE7, 0xF3, 0x79, 0x3C, 0x9E, 0xCF,
    0xE7, 0xF3, 0x79, 0x3C, 0x1E, 0x0F,
    0x00, 0x00, 0x00, 0x00, 0x80, 0xC0,
    0xE0, 0xF0, 0x78, 0x3C, 0x9E, 0xCF,
    0xE7, 0xF3, 0x79, 0x3C, 0x9E, 0xCF,
    0xE7, 0xF3, 0x79, 0x3C, 0x1E, 0x0F,
    0x07, 0x03, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x78, 0x3C, 0x9E, 0xCF,
    0xE7, 0xF3, 0x79, 0x3C, 0x9E, 0xCF,
    0xE7, 0xF3, 0x79, 0x3C, 0x1E, 0x0F,
    0x07, 0x03, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x9E, 0xCF,
    0xE7, 0xF3, 0x79, 0x3C, 0x1E, 0x0F,
    0x07, 0x03, 0x01, 0x00, 0x00, 0x00,
    0x80, 0x80, 0x80, 0x80, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x07, 0x03, 0x01, 0x00, 0x00, 0x00,
    0x80, 0xC0, 0xE0, 0x70, 0x38, 0x1C,
    0x0E, 0xE7, 0xF3, 0xF1, 0xF1, 0xF3,
    0xE7, 0x0E, 0x1C, 0x38, 0x70, 0xE0,
    0xC0, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xF0, 0xF8, 0x9C,
    0x0E, 0x07, 0x63, 0xF1, 0xF8, 0xF8,
    0xF8, 0xF8, 0x60, 0x01, 0x03, 0x03,
    0x03, 0x03, 0x01, 0x60, 0xF0, 0xF8,
    0xF8, 0xF8, 0xF9, 0x63, 0x07, 0x0E,
    0x9C, 0xF8, 0xF0, 0x00, 0x00, 0x00,
    0x01, 0x03, 0x07, 0x0E, 0x1C, 0x38,
    0x71, 0xE1, 0xC1, 0x81, 0x00, 0x3C,
    0x7C, 0x7E, 0x7E, 0x7C, 0x3C, 0x00,
    0x80, 0xC1, 0xE1, 0x71, 0x39, 0x1C,
    0x0E, 0x07, 0x03, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x03,
    0x07, 0x0E, 0x1C, 0x18, 0x18, 0x1C,
    0x0E, 0x07, 0x03, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00,
};

// Variables pour gérer le dé-bouncing des encodeurs
static uint32_t last_encoder_update_time[2] = {0, 0}; // Deux encodeurs
const uint32_t encoder_update_interval = 50; // Intervalle minimal entre deux mises à jour en millisecondes

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // Affiche le logo sur l'écran principal (côté maître)
        oled_write_raw_P(logo, sizeof(logo));
    } else {
        // Affiche les informations de couche active sur l'écran esclave
        oled_write_ln_P(PSTR("Mode: "), false);

        switch (get_highest_layer(layer_state)) {
            case 0:
                oled_write_ln_P(PSTR("Normal"), false);
                break;
            case 1:
                oled_write_ln_P(PSTR("Standard"), false);
                break;
            case 4:
                oled_write_ln_P(PSTR("Gaming"), false);
                break;
            default:
                oled_write_ln_P(PSTR("Inconnu"), false);
                break;
        }
    }
    return false; // Empêche le dessin par défaut du clavier
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
            tap_code(KC_WH_U); // Mouse Wheel Up
        } else {
            tap_code(KC_WH_D); // Mouse Wheel Down
        }
    } else if (index == 1) { // Encodeur de droite
        uint8_t next_layer = 0;
        if (clockwise) {
            next_layer = (get_highest_layer(layer_state) + 1) % 3; // Passe à la couche suivante (0 -> 1 -> 4 -> 0)
        } else {
            next_layer = (get_highest_layer(layer_state) == 0) ? 2 : get_highest_layer(layer_state) - 1; // Revient à la couche précédente
        }
        layer_move(next_layer);
    }

    return true; // Indique que l'action est gérée ici
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // Met à jour l'OLED en fonction du changement de couche
    if (is_keyboard_master()) {
        oled_clear();
        oled_write_ln_P(PSTR("Mode: "), false);

        switch (get_highest_layer(state)) {
            case 0:
                oled_write_ln_P(PSTR("Normal"), false);
                break;
            case 1:
                oled_write_ln_P(PSTR("Standard"), false);
                break;
            case 4:
                oled_write_ln_P(PSTR("Gaming"), false);
                break;
            default:
                oled_write_ln_P(PSTR("Inconnu"), false);
                break;
        }
    }

    return state;
}