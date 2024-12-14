@echo off
pushd .

call script\build.bat
if %errorlevel% neq 0 (
    echo There was an error during the build process.
) else (
    call script\run.bat
    if %errorlevel% neq 0 (
        echo There was an error running the application.
    )
)

popd
