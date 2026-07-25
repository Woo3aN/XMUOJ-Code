@echo off
cd /d "%~dp0"
start "" "C:\Windows\System32\cmd.exe" /c ""%~dp0main.exe" && pause"
exit
