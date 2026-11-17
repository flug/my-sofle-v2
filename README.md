# Sofle v2 Custom Firmware

[![Build QMK Firmware](https://github.com/flug/my-sofle-v2/actions/workflows/build.yml/badge.svg)](https://github.com/flug/my-sofle-v2/actions/workflows/build.yml)
[![QMK](https://img.shields.io/badge/QMK-Firmware-blue)](https://qmk.fm/)
[![License: GPL v2](https://img.shields.io/badge/License-GPL%20v2-blue.svg)](https://www.gnu.org/licenses/old-licenses/gpl-2.0.en.html)

Configuration de firmware QMK personnalisée pour le clavier **SplitKB Aurora Sofle v2** avec contrôleur **Liatris** (RP2040).

## ✨ Fonctionnalités

- 🎨 **RGB Matrix** avec effet "goutte d'eau" réactif aux touches
- 🖥️ **Affichage OLED** avec icônes de couches personnalisées
- 🎛️ **Encodeurs rotatifs** :
  - Gauche : Défilement souris (scroll vertical)
  - Droit : Navigation entre les couches
- 🎹 **3 couches actives** + 1 couche de configuration RGB/média
- 🔧 **Support VIA** activé côté firmware pour le remapping dynamique, si l'application VIA dispose d'une définition compatible
- 🎵 **Touches multimédia** sur la couche symboles
- ⚡ **Optimisé** pour économiser l'espace firmware

## 🗺️ Organisation des couches

| Couche | Nom | Description |
|--------|-----|-------------|
| 0 | `_DEFAULT` | Layout QWERTY standard |
| 1 | `_PERCENT` | Nombres, F-keys, symboles, touches multimédia (!@#$% → Play/Prev/Next/Mute/Vol-) |
| 2 | `_CODE` | Navigation, clipboard (Ctrl+Z/X/C/V), édition de code |
| 3 | Config | Contrôles RGB et média (accessible via MO(3)) |

## 📥 Installation rapide

### Télécharger le firmware pré-compilé

1. Allez dans [Releases](https://github.com/flug/my-sofle-v2/releases)
2. Téléchargez le fichier `.uf2` de la release `latest`
3. Passez votre clavier en mode bootloader :
   - Double-clic sur le bouton **RESET** du contrôleur Liatris
   - Un lecteur USB nommé `RPI-RP2` devrait apparaître
4. Copiez le fichier `.uf2` sur ce lecteur
5. Le clavier redémarre automatiquement avec le nouveau firmware

## 🛠️ Compilation locale

### Prérequis

**Windows:**
1. Téléchargez [QMK MSYS](https://msys.qmk.fm/)
2. Installez dans `C:\QMK_MSYS` (ou autre emplacement)
3. Ouvrez **QMK MSYS** depuis le menu Démarrer
4. Lancez `qmk setup` pour installer `qmk_firmware`

**Linux/Mac:**
```bash
# Installer QMK CLI
python3 -m pip install --user qmk
qmk setup
```

### Configurer le userspace (une seule fois)

Ce dépôt est un [QMK Userspace](https://docs.qmk.fm/newbs_external_userspace) : le keymap vit ici, en dehors de `qmk_firmware`.

```bash
cd /chemin/vers/my-sofle-v2
qmk config user.overlay_dir="$(realpath .)"
```

### Compiler

```bash
qmk userspace-compile
```

Le fichier `splitkb_aurora_sofle_v2_rev1_flug_liatris.uf2` est généré à la racine du dépôt.

### Flasher

```bash
qmk flash -kb splitkb/aurora/sofle_v2/rev1 -km flug -e CONVERT_TO=liatris
```

Ou copiez le `.uf2` sur le lecteur `RPI-RP2` (mode bootloader).

## 🔧 Développement

### Structure du projet

```
my-sofle-v2/
├── qmk.json                              # Cibles de build du userspace
├── keyboards/splitkb/aurora/sofle_v2/keymaps/flug/
│   ├── keymap.json                       # Layout des touches (format QMK Configurator)
│   ├── features.c                        # Logique (encodeurs, OLED, RGB, multimédia)
│   ├── layer_images.h                    # Icônes OLED des couches (512 bytes chacune)
│   ├── config.h                          # Configuration QMK et RGB Matrix
│   └── rules.mk                          # Features QMK activées/désactivées
└── .github/workflows/build.yml           # CI/CD (workflows officiels QMK Userspace)
```

### Modifier le layout

**Option 1 : QMK Configurator (GUI)**
1. Allez sur [config.qmk.fm](https://config.qmk.fm)
2. Chargez `keyboards/splitkb/aurora/sofle_v2/keymaps/flug/keymap.json`
3. Modifiez les touches puis téléchargez le JSON
4. Remplacez le `keymap.json` du dépôt

QMK compile directement le `keymap.json`, aucune conversion en C n'est nécessaire.

**Option 2 : Édition directe**
Modifiez `features.c` pour changer la logique (encodeurs, OLED, RGB, etc.)

### VIA

Le firmware active `VIA_ENABLE = yes`. Si l'application VIA ne détecte pas le clavier après flash, importez une définition compatible avec `splitkb/aurora/sofle_v2/rev1` ou utilisez la version web de VIA avec l'onglet design activé.

## 🤖 CI/CD Automatique

Le firmware est compilé par GitHub Actions avec les workflows officiels QMK Userspace :

- ✅ **Pull request** → Build de vérification (firmware disponible en artifact)
- 🚀 **Push sur `main`** → Build + mise à jour de la release [`latest`](https://github.com/flug/my-sofle-v2/releases/tag/latest)
- 📅 **Tous les lundis à 2h UTC** → Rebuild avec la dernière version de QMK
- 🖱️ **Déclenchement manuel** → **Actions** → **Build QMK firmware** → **Run workflow**

## 🎮 Fonctionnalités spéciales

### Encodeur gauche : Défilement souris
- Rotation : Scroll vertical (haut/bas)
- Debouncing de 50ms pour éviter les sauts

### Encodeur droit : Sélection de couche
- Rotation horaire : Couche suivante (0→1→2→0)
- Rotation anti-horaire : Couche précédente (0→2→1→0)

### Touches multimédia sur Layer 1
Quand la couche `_PERCENT` est active, les symboles `!@#$%` deviennent :
- `!` → Play/Pause
- `@` → Piste précédente
- `#` → Piste suivante
- `$` → Mute
- `%` → Volume -

### RGB Matrix
- **Couleur de base** : Blanc (HSV 0, 0, 255)
- **Effet** : SOLID_REACTIVE_SIMPLE (goutte d'eau)
- **Vitesse** : 128
- **Sleep** : S'éteint automatiquement en cas d'inactivité

## 📚 Ressources

- [Documentation QMK](https://docs.qmk.fm/)
- [SplitKB Aurora Sofle v2](https://splitkb.com/products/aurora-sofle-v2)
- [Liatris Controller](https://splitkb.com/products/liatris)
- [QMK Configurator](https://config.qmk.fm/)

## 🤝 Contribution

Les contributions sont les bienvenues ! N'hésitez pas à :
- Ouvrir une **Issue** pour signaler un bug
- Proposer une **Pull Request** pour améliorer le firmware
- Partager vos idées de fonctionnalités

## 📝 License

Ce projet est sous licence GPL v2, conformément à QMK Firmware.
