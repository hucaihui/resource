@echo off
TITLE ����Win10���½�������ʱ����ʾ��By key9928 from 52pojie
ECHO ����Win10���½�������ʱ����ʾ��By key9928 from 52pojie
reg add "HKCU\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Advanced" /v ShowSecondsInSystemClock /t REG_DWORD /d 1 /f
TASKKILL /f /IM explorer.exe
pause&echo.
START %windir%\explorer.exe
echo.
pause