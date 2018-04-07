::@echo off

::git pull

if not exist fx_lib/include (
	if exist fx_lib rmdir /S /Q fx_lib
	git clone https://github.com/fx-github/fx_lib.git fx_lib
)

if [%1] == ["release"] set release=1
if [%1] == ['release'] set release=1
if [%1] == [release] set release=1
if [%release%] == [1] (
	set BUILD_TYPE=Release
	set BUILD_PATH=release
) else (
	set BUILD_TYPE=Debug
	set BUILD_PATH=debug
)

if not exist %BUILD_PATH% ( mkdir %BUILD_PATH% )

cd %BUILD_PATH%

if exist CMakeCache.txt (del CMakeCache.txt)

call "D:/Program Files (x86)/Microsoft Visual Studio/2017/Community/Common7/Tools/VsDevCmd.bat"

cmake -G "Visual Studio 15" -DCMAKE_BUILD_TYPE=%BUILD_TYPE% ../src

msbuild FXTetris_withAI.sln /m

cd ..

@echo on
