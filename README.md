# esp-idf-ssh-client
ssh client for esp-idf.   
This project use [this](https://github.com/libssh2/libssh2) ssh library.   

# Software requirements
esp-idf v4.4 or later.   

# Installation for ESP32

```
git clone https://github.com/nopnop2002/esp-idf-ssh-client
cd esp-idf-ssh-client/
git clone https://github.com/libssh2/libssh2 components/libssh2
cp esp-idf/libssh2_config.h components/libssh2/include
cp esp-idf/CMakeLists.txt components/libssh2
idf.py set-target esp32
idf.py menuconfig
idf.py flash
```

# Installation for ESP32-S2

```
git clone https://github.com/nopnop2002/esp-idf-ssh-client
cd esp-idf-ssh-client/
git clone https://github.com/libssh2/libssh2 components/libssh2
cp esp-idf/libssh2_config.h components/libssh2/include
cp esp-idf/CMakeLists.txt components/libssh2
idf.py set-target esp32s2
idf.py menuconfig
idf.py flash
```

# Configuration   
You have to set this config value with menuconfig.   
- CONFIG_ESP_WIFI_SSID   
SSID (network name) to connect to.
- CONFIG_ESP_WIFI_PASSWORD   
WiFi password (WPA or WPA2) to use.
- CONFIG_ESP_MAXIMUM_RETRY   
Set the Maximum retry to avoid station reconnecting to the AP unlimited when the AP is really inexistent.
- CONFIG_SSH_USER   
Username of SSH.
- CONFIG_SSH_PASSWORD   
Password of SSH.
- CONFIG_SSH_HOST   
IP address of SSH host.   
__mDMS name cannot be used.__   
- CONFIG_SSH_COMMAND1   
The first command to execute.   
- CONFIG_SSH_COMMAND2   
The second command to execute.   

![config-main](https://user-images.githubusercontent.com/6020549/120054821-3d755500-c06d-11eb-950c-d357d0a9fdef.jpg)
![config-app](https://user-images.githubusercontent.com/6020549/131046949-dd3c130d-bf7b-43e0-b1f0-a3c634c8af1f.jpg)

# Screen Shot
![ssh-client-1](https://user-images.githubusercontent.com/6020549/120056024-b1ffc200-c074-11eb-8507-1bb566b0cc7c.jpg)

# Reference
https://github.com/nopnop2002/esp-idf-scp-client

You can use scp and ssh to do heavy processing that esp32 alone cannot.  
- Execute server-side command with ssh.   
- Output the processing result to a file.   
- Copy file from server using scp-get.   


