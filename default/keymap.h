#pragma once

#include "timer.h"
// Inclure uniquement rgb_matrix.h et quantum.h
#include "rgb_matrix.h"
#include "quantum.h"

#define _DEFAULT 0
#define _PERCENT 1
#define _CODE 2

// Inclure le fichier d'images des couches
#include "layer_images.h"
 

// Variables pour gérer le dé-bouncing des encodeurs
static uint32_t last_encoder_update_time[2] = {0, 0}; // Deux encodeurs
const uint32_t encoder_update_interval = 50; // Intervalle minimal entre deux mises à jour en millisecondes

// Variables pour gérer l'affichage des couches actives
static uint8_t current_layer = 0;

bool oled_task_user(void) {
    if (!is_keyboard_master()) {
        // Affiche le logo sur l'écran principal (côté maître)
        oled_write_raw_P(logo, sizeof(logo));
    } 
    return false; // Empêche le dessin par défaut du clavier
}

// Configuration des LEDs RGB avec effet goutte d'eau
void keyboard_post_init_user(void) {
    // Activer les LEDs RGB
    rgb_matrix_enable();
    
    // Définir la couleur de base blanche (mode RGB)
    rgb_matrix_sethsv(0, 0, 255);  // HSV: 0 = rouge, 0 = pas de saturation (blanc), 255 = luminosité max
    
    // Activer l'effet goutte d'eau (solid reactive)
    // Utiliser l'ID de l'effet au lieu de la constante qui n'est pas disponible
    rgb_matrix_mode_noeeprom(1);  // Mode 1 correspond à SOLID_REACTIVE_SIMPLE dans la plupart des configurations
    
    // Configurer la vitesse de l'effet (plus petit = plus rapide)
    rgb_matrix_set_speed(128);
}

// Fonction pour envoyer uniquement des événements de défilement de souris sans affecter le volume
// Utilise les keycodes standard au lieu des fonctions pointing_device
void send_mouse_scroll(bool is_up) {
    if (is_up) {
        register_code(KC_MS_WH_UP);
        unregister_code(KC_MS_WH_UP);
    } else {
        register_code(KC_MS_WH_DOWN);
        unregister_code(KC_MS_WH_DOWN);
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
        if (clockwise) {
            current_layer = (current_layer + 1) % 3; // Passe à la couche suivante (0 -> 1 -> 2 -> 0)
            layer_move(current_layer);
        } else {
            current_layer = (current_layer == 0) ? 2 : current_layer - 1; // Reviens à la couche précédente
            layer_move(current_layer);
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

layer_state_t layer_state_set_user(layer_state_t state) {
    if (!is_keyboard_master()) {
        return state; // S'assure que cette partie ne tourne que sur le maître
    }
    oled_write_ln_P(PSTR("Mode: "), false);
    switch (get_highest_layer(state)) {
        case 0:
            oled_write_raw_P(layer_icons[_DEFAULT], _IMAGE_SIZE);
            break;
        case 1:
            oled_write_raw_P(layer_icons[_PERCENT], _IMAGE_SIZE);
            break;
        case 2:  // Corrigé de 4 à 2 pour correspondre à la définition _CODE
            oled_write_raw_P(layer_icons[_CODE], _IMAGE_SIZE);
            break;
        default:
            oled_write_ln_P(PSTR("Inconnu"), false);
            break;
    }

    return state;
}
