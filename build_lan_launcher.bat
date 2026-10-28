@echo off
cd /d "%~dp0"

pyinstaller --noconfirm --onefile --windowed --name "LAN Launcher" --icon "LAN Launcher.ico" ^
    --add-data "mpmissions;mpmissions" ^
    --add-data "CONFIGS;CONFIGS" ^
    --add-data "INSTRUCTIONS;INSTRUCTIONS" ^
    LAN.py

robocopy "mpmissions" "dist\mpmissions" /MIR
robocopy "CONFIGS" "dist\CONFIGS" /MIR
robocopy "INSTRUCTIONS" "dist\INSTRUCTIONS" /MIR
robocopy "DayZServer" "dist\DayZServer" /MIR
copy /Y "Buttons.txt" "dist\Buttons.txt"
copy /Y "READ ME.txt" "dist\READ ME.txt"

echo.
echo Build finished. Check the dist folder for LAN Launcher.exe and support folders.
pause

