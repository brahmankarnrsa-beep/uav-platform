#!/bin/bash

set -e

echo "========================================"
echo "UAV Platform Dependency Installer"
echo "========================================"

sudo apt update

# Build tools
sudo apt install -y \
build-essential \
cmake \
git \
curl \
wget \
pkg-config

# ROS utilities
sudo apt install -y \
python3-colcon-common-extensions \
python3-rosdep \
python3-vcstool

# Camera
sudo apt install -y \
python3-opencv \
v4l-utils

# Serial
sudo apt install -y \
minicom \
screen \
python3-serial

# USB
sudo apt install -y \
usbutils

# Networking
sudo apt install -y \
network-manager \
modemmanager \
ppp

# Diagnostics
sudo apt install -y \
htop \
neofetch \
tree

echo
echo "Dependencies Installed Successfully."
