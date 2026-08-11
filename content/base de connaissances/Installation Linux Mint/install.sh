#!/bin/bash

if [[ $EUID -ne 0 ]]; then
	echo "Ce script doit etre executé comme root (sudo)" 
   exit 1
fi

#######################
### installation vscode
echo "code code/add-microsoft-repo boolean true" | debconf-set-selections
apt-get install wget gpg
wget -qO- https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor > microsoft.gpg
install -D -o root -g root -m 644 microsoft.gpg /usr/share/keyrings/microsoft.gpg
rm -f microsoft.gpg

echo "Types: deb
URIs: https://packages.microsoft.com/repos/code
Suites: stable
Components: main
Architectures: amd64,arm64,armhf
Signed-By: /usr/share/keyrings/microsoft.gpg" > /etc/apt/sources.list.d/vscode.sources

apt install apt-transport-https
apt update
apt install code 

############################
### Installation de vscodium
wget -qO - https://gitlab.com/paulcarroty/vscodium-deb-rpm-repo/raw/master/pub.gpg \
    | gpg --dearmor \
    | dd of=/usr/share/keyrings/vscodium-archive-keyring.gpg

echo -e 'Types: deb\nURIs: https://download.vscodium.com/debs\nSuites: vscodium\nComponents: main\nArchitectures: amd64 arm64\nSigned-by: /usr/share/keyrings/vscodium-archive-keyring.gpg' \
| tee /etc/apt/sources.list.d/vscodium.sources

apt update && sudo apt install codium

#################################
### Installation d'outils de base
apt install -y git
