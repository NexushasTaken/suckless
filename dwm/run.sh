sudo make install
Xephyr -br -ac -noreset -screen 1276x600 :1 &
sleep 0.2
sudo DISPLAY=:1 dwm
exit
