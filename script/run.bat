@echo off
pushd .

if not exist build/tests/training_main.exe (
	echo "training_main.exe not exists!"
	popd
	exit(1)
)

cd build/tests

training_main.exe

popd
