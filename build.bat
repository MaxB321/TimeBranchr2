@echo off
setlocal

:: Handle argument
set CONFIG=%1

:: Default to Debug if no arg
if "%CONFIG%"=="" set CONFIG=Debug

:: Validate input
if /I not "%CONFIG%"=="Debug" if /I not "%CONFIG%"=="Release" (
    echo Error: Invalid build type "%1"
    echo.
    exit /b 1
)

set BUILD_DIR=build-%CONFIG%

if not exist %BUILD_DIR% mkdir %BUILD_DIR%

echo Building %CONFIG%...

:: Configure CMake
cmake -S . -B "%BUILD_DIR%" -A x64

if errorlevel 1 (
    echo CMake configuration failed.
    exit /b 1
)

:: Build project
cmake --build "%BUILD_DIR%" --config "%CONFIG%" --parallel

if errorlevel 1 (
    echo Build Failed.
    exit /b 1
)

echo.
echo Successfully built %CONFIG% in %BUILD_DIR%

endlocal