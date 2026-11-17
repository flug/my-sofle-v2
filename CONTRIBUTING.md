# Guide de contribution

Merci de votre intérêt pour contribuer à ce projet de firmware QMK !

## 🚀 Comment contribuer

### Signaler un bug

1. Vérifiez que le bug n'a pas déjà été signalé dans les [Issues](https://github.com/flug/my-sofle-v2/issues)
2. Créez une nouvelle issue avec le template "Bug Report"
3. Incluez :
   - Description détaillée du problème
   - Étapes pour reproduire
   - Comportement attendu vs comportement observé
   - Version du firmware (trouvée dans `build-info.txt`)

### Proposer une fonctionnalité

1. Ouvrez une issue avec le template "Feature Request"
2. Décrivez :
   - La fonctionnalité souhaitée
   - Le cas d'usage
   - L'impact sur l'espace firmware (si connu)

### Soumettre une Pull Request

1. **Fork** le projet
2. **Créez une branche** : `git checkout -b feature/ma-fonctionnalite`
3. **Testez vos modifications** :
   ```bash
   qmk userspace-compile
   # Flashez et testez sur le clavier physique
   ```
4. **Vérifiez l'espace firmware** :
   - Le Liatris a des limites de mémoire
   - Si votre modif augmente la taille, documentez-le
5. **Commitez** : `git commit -m "feat: description de la fonctionnalité"`
6. **Pushez** : `git push origin feature/ma-fonctionnalite`
7. **Ouvrez une PR** sur GitHub

## 📝 Standards de code

### Style de commit

Utilisez les [Conventional Commits](https://www.conventionalcommits.org/):

- `feat:` Nouvelle fonctionnalité
- `fix:` Correction de bug
- `docs:` Documentation seulement
- `style:` Formatage, pas de changement de code
- `refactor:` Refactoring sans changer le comportement
- `perf:` Amélioration de performance
- `test:` Ajout de tests
- `chore:` Tâches de maintenance

Exemples :
```
feat: add tap dance for Space key
fix: correct OLED layer display on secondary side
docs: update README with new layer layout
```

### Code C

- Suivez le [style guide QMK](https://docs.qmk.fm/#/coding_conventions_c)
- Utilisez des noms de variables descriptifs
- Commentez les sections complexes
- Testez sur du matériel réel avant de soumettre

### Considérations importantes

#### Espace firmware limité
Le Liatris (RP2040) a des limites. Lors de l'ajout de features :
- Vérifiez la taille du firmware après compilation
- Documentez l'augmentation dans la PR
- Envisagez de désactiver des features existantes si nécessaire

#### Compatibilité
- Testez que le firmware compile toujours
- Testez sur les deux côtés du split (master et secondary)
- Vérifiez que les encodeurs fonctionnent toujours
- Vérifiez que l'OLED s'affiche correctement

## 🧪 Tester localement

### Compiler
```bash
qmk userspace-compile
```

### Vérifier la taille
<!-- coderabbit-ai-generated:v1 -->

<!-- coderabbit-ai-generated-section:v1:52ade65f3112e84be9d8fec0ca57027b6e3e432d1534be4483a5c2cd38f5d178 -->

Après `qmk userspace-compile`, depuis la racine du dépôt (Linux, macOS ou QMK MSYS), mesurez le fichier produit :
```bash
wc -c < splitkb_aurora_sofle_v2_rev1_flug_liatris.uf2
```
Le résultat est la taille du fichier en octets. Notez sa valeur avant et après vos modifications dans la PR.

Comparez cette taille à la flash disponible pour le firmware dans la configuration QMK utilisée (région flash du script de liaison, moins les zones réservées, notamment à l’EEPROM). Le Liatris possède 16 Mio physiques (16 777 216 octets), mais QMK peut configurer une région plus petite : ne prenez pas toute la capacité physique comme budget utilisable.

Le [format UF2](https://github.com/microsoft/uf2#file-format) inclut des en-têtes et du remplissage : sa taille sur disque surestime les données flashées. Une taille inférieure au budget disponible constitue donc une comparaison prudente ; si elle le dépasse, vérifiez les sections et adresses de l’ELF/map du build avant de conclure à un dépassement réel. Cette mesure ne dépend pas des journaux de compilation.


<!-- /coderabbit-ai-generated:v1 -->
### Flasher
1. Double-clic sur le bouton RESET du Liatris
2. Copiez le `.uf2` sur le lecteur `RPI-RP2`
3. Testez toutes les couches et fonctionnalités

## 🐛 Déboguer

### Activer la console
Dans `keyboards/splitkb/aurora/sofle_v2/keymaps/flug/rules.mk`, temporairement :
```makefile
CONSOLE_ENABLE = yes
```

Puis utilisez [QMK Toolbox](https://github.com/qmk/qmk_toolbox) pour voir les logs.

### OLED ne s'affiche pas
- Vérifiez `OLED_ENABLE = yes` dans `rules.mk`
- Vérifiez que les images de couches sont bien définies
- Testez sur les deux côtés du split

### RGB ne fonctionne pas
- Vérifiez `RGB_MATRIX_ENABLE = yes` dans `rules.mk`
- Vérifiez que `RGBLIGHT_ENABLE = no`
- Vérifiez les defines dans `config.h`

## 📚 Ressources

- [QMK Documentation](https://docs.qmk.fm/)
- [QMK Discord](https://discord.gg/qmk)
- [Aurora Sofle Documentation](https://docs.splitkb.com/hc/en-us/articles/6271110257180-Aurora-Sofle-v2)

## ❓ Questions

Si vous avez des questions, n'hésitez pas à :
- Ouvrir une [Discussion GitHub](https://github.com/flug/my-sofle-v2/discussions)
- Créer une issue avec le label "question"

Merci de contribuer ! 🎉
