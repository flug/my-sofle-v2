@echo off
echo Lancement de QMK MSYS pour compiler le firmware...
C:\QMK_MSYS\msys2_shell.cmd -mingw64 -defterm -no-start -here -c "make compile"
pause
