# Changelog

Tous les changements notables de ce projet seront documentés dans ce fichier.

Le format est basé sur [Keep a Changelog](https://keepachangelog.com/fr/1.0.0/),
et ce projet adhère au [Semantic Versioning](https://semver.org/lang/fr/).

## [Unreleased]

### Added
- CI/CD automatique avec builds hebdomadaires
- Build manuel à la demande via GitHub Actions
- Mise à jour automatique vers la dernière version de QMK
- Fichier `build-info.txt` dans les releases
- Documentation complète (README.md, CLAUDE.md, CONTRIBUTING.md)
- Script `compile_qmk.bat` pour compilation rapide sous Windows
- Support toolchain ARM dans la CI

### Changed
- Amélioration du workflow CI avec meilleures gestions d'erreurs
- Releases automatiques marquées comme pre-release
- Tags différenciés pour builds auto/manuel/standard

## [1.0.0] - 2025-01-29

### Added
- Configuration initiale du firmware pour SplitKB Aurora Sofle v2
- Support du contrôleur Liatris (RP2040)
- 3 couches actives + 1 couche de configuration
- Encodeur gauche : Défilement souris avec debouncing 50ms
- Encodeur droit : Navigation entre couches
- Affichage OLED avec icônes de couches personnalisées (512 bytes)
- RGB Matrix avec effet "goutte d'eau" (SOLID_REACTIVE_SIMPLE)
- Couleur de base blanche (HSV 0, 0, 255)
- Touches multimédia sur layer 1 (!@#$% → Play/Prev/Next/Mute/Vol-)
- Split keyboard avec synchronisation des états
- Optimisations firmware pour économiser l'espace

### Features détaillées

#### Layers
- **Layer 0 (_DEFAULT)** : Layout QWERTY standard
- **Layer 1 (_PERCENT)** : Nombres, F-keys, symboles, multimédia
- **Layer 2 (_CODE)** : Navigation, clipboard (Ctrl+Z/X/C/V)
- **Layer 3** : Contrôles RGB et média

#### RGB Matrix
- Mode : SOLID_REACTIVE_SIMPLE
- Vitesse : 128
- Sleep automatique
- Effets inutiles désactivés pour économiser ~4KB

#### OLED
- Côté master : Affiche "Mode: " + icône de couche
- Côté secondary : Affiche icône de couche directement
- Synchronisation via `SPLIT_LAYER_STATE_ENABLE`

#### Configuration QMK
- `SPLIT_KEYBOARD = yes`
- `SPLIT_USB_DETECT = yes`
- `MASTER_LEFT`
- `RGB_MATRIX_ENABLE = yes`
- `RGBLIGHT_ENABLE = no`
- `CONSOLE_ENABLE = no` (économie d'espace)
- `COMMAND_ENABLE = no` (économie d'espace)
- `MOUSEKEY_ENABLE = no` (économie d'espace)

[Unreleased]: https://github.com/flug/my-sofle-v2/compare/v1.0.0...HEAD
[1.0.0]: https://github.com/flug/my-sofle-v2/releases/tag/v1.0.0
