# Sofle v2 Custom Firmware

[![Build QMK Firmware](https://github.com/flug/my-sofle-v2/actions/workflows/qmk.yml/badge.svg)](https://github.com/flug/my-sofle-v2/actions/workflows/qmk.yml)
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
2. Téléchargez le fichier `firmware.uf2` de la dernière release
3. Passez votre clavier en mode bootloader :
   - Double-clic sur le bouton **RESET** du contrôleur Liatris
   - Un lecteur USB nommé `RPI-RP2` devrait apparaître
4. Copiez le fichier `firmware.uf2` sur ce lecteur
5. Le clavier redémarre automatiquement avec le nouveau firmware

## 🛠️ Compilation locale

### Prérequis

**Windows:**
1. Téléchargez [QMK MSYS](https://msys.qmk.fm/)
2. Installez dans `C:\QMK_MSYS` (ou autre emplacement)
3. Ouvrez **QMK MSYS** depuis le menu Démarrer

**Linux/Mac:**
```bash
# Installer QMK CLI
python3 -m pip install --user qmk
qmk setup
```

### Compiler

```bash
# Se positionner dans le dossier du projet
cd /chemin/vers/my-sofle-v2

# Convertir le JSON en C (si modifié)
make convert

# Compiler le firmware
make compile
```

Le fichier `.uf2` sera généré dans `~/qmk_firmware/.build/`

### Script Windows (raccourci)

Double-cliquez sur `compile_qmk.bat` pour compiler automatiquement.

## 🔧 Développement

### Structure du projet

```
my-sofle-v2/
├── default/              # Fichiers source du firmware
│   ├── keymap.h         # Logique principale (encodeurs, OLED, RGB)
│   ├── layer_images.h   # Icônes OLED des couches (512 bytes chacune)
│   ├── config.h         # Configuration QMK et RGB Matrix
│   └── rules.mk         # Features QMK activées/désactivées
├── map/
│   └── keymap.json      # Layout des touches (format QMK Configurator)
├── .github/workflows/
│   └── qmk.yml          # CI/CD automatique
├── Makefile             # Commandes de build simplifiées
└── copy_to_qmk.bat      # Copie les fichiers vers QMK (Windows)
```

### Modifier le layout

**Option 1 : QMK Configurator (GUI)**
1. Allez sur [config.qmk.fm](https://config.qmk.fm)
2. Chargez `map/keymap.json`
3. Modifiez les touches
4. Téléchargez le JSON
5. Remplacez `map/keymap.json`
6. Exécutez `make convert` pour générer le C

**Option 2 : Édition directe**
Modifiez `default/keymap.h` pour changer la logique (encodeurs, OLED, RGB, etc.)

### Tester les modifications

```bash
# Compiler
make compile

# Flasher (le clavier doit être en mode bootloader)
# Copiez manuellement le .uf2 ou utilisez:
qmk flash -e CONVERT_TO=liatris -kb splitkb/aurora/sofle_v2/rev1 -km custom
```

## 🤖 CI/CD Automatique

Le firmware est compilé automatiquement par GitHub Actions :

- ✅ **À chaque push** sur `main` → Release standard
- 📅 **Tous les lundis à 2h UTC** → Build automatique avec la dernière version de QMK
- 🚀 **Déclenchement manuel** → Build à la demande

Les builds automatiques/manuels sont marqués comme **pre-release** et incluent un fichier `build-info.txt` avec les détails de compilation.

### Déclencher un build manuel

1. Allez dans **Actions** → **Build QMK Firmware**
2. Cliquez sur **Run workflow**
3. (Optionnel) Spécifiez une branche QMK différente
4. Récupérez le firmware dans les **Releases**

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
