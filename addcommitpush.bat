@echo off
cd /d %~dp0
REM Optional: Navigate to your project directory
REM cd path\to\your\project

REM Staging changes
git add .

REM Committing changes. Customize the commit message as needed.
SET /P commitMessage="Enter commit message: "
git commit -m "%commitMessage%"

REM Pushing changes
FOR /f "tokens=*" %%i IN ('git symbolic-ref --short HEAD') DO SET gitBranch=%%i
git push -u origin %gitBranch%

echo Changes pushed to %gitBranch%
