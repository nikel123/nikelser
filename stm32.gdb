printf "\nstart openocd\n"
target remote | openocd
printf "\nmonitor reset halt\n"
monitor reset halt
printf "\nload\n"
load

