#!/bin/bash
clear
function package_exists() {
    return dpkg "$1" &> /dev/null
}

echo "Compiling Linux Version..."

g++ HashCracker.cpp sha512.cpp md5.cpp -o Compiled/Linux/HashCracker_Linux

echo "Linux-Version compiled."
echo "Compiling Windows Version..."

g++ HashCracker.cpp sha512.cpp md5.cpp -o Compiled/Windows/HashCracker_Windows.exe

echo "Windows-Version compiled."
echo "Applying +x..."

chmod +x "Compiled/Linux/HashCracker_Linux"
chmod +x "Compiled/Windows/HashCracker_Windows.exe"

echo "Compiled Files saved in Directory 'Compiled'"

echo "All done!"
exit 0
