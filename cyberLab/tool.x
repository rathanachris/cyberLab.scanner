#!/data/data/com.termux/files/usr/bin/bash

# =========================
# MINI CYBER TOOL-KIT 😈
# =========================

# -------- COLORS --------
R="\033[1;31m"
G="\033[1;32m"
Y="\033[1;33m"
B="\033[1;34m"
C="\033[1;36m"
W="\033[1;37m"
X="\033[0m"

# -------- START --------
clear

# check tools
command -v figlet >/dev/null 2>&1 || pkg install figlet -y
command -v lolcat >/dev/null 2>&1 || gem install lolcat
command -v curl >/dev/null 2>&1 || pkg install curl -y

# -------- LOGO --------
echo -e "$C"
figlet "TOOL.X" | lolcat
echo -e "$Y==== MINI CYBER TOOL-KIT ====$X"
echo

sleep 1

echo -e "${G}[✔] Initializing system...${X}"
sleep 0.5
echo -e "${G}[✔] Loading modules...${X}"
sleep 0.5
echo -e "${G}[✔] Establishing secure shell...${X}"
sleep 0.5
echo -e "${G}[✔] Access Granted${X}"

sleep 1

# -------- MENU --------
while true; do

echo
echo -e "$C[1] System Info"
echo -e "[2] Network Check"
echo -e "[3] API Test"
echo -e "[4] Storage Info"
echo -e "[5] Matrix Mode"
echo -e "[0] Exit$X"
echo

read -p "Select option > " choice

case $choice in

1)
    clear
    echo -e "$Y=== SYSTEM INFO ===$X"
    uname -a
    echo
    termux-battery-status 2>/dev/null
    ;;

2)
    clear
    echo -e "$Y=== NETWORK CHECK ===$X"
    curl -I https://google.com
    ;;

3)
    clear
    echo -e "$Y=== API TEST ===$X"
    read -p "Enter URL > " url
    echo
    curl -s "$url"
    ;;

4)
    clear
    echo -e "$Y=== STORAGE INFO ===$X"
    df -h
    ;;

5)
    clear
    command -v cmatrix >/dev/null 2>&1 || pkg install cmatrix -y
    cmatrix -b -u 4 -C green
    clear
    ;;

0)
    echo -e "$R[ EXIT TOOL.X ]$X"
    exit
    ;;

*)
    echo -e "$R[ INVALID OPTION ]$X"
    ;;

esac

done


