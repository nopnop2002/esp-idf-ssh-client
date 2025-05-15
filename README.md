# esp-idf-ssh-client
ssh client for esp-idf.   
You can use the ssh API to execute remote command.   
This project use [this](https://gitlab.com/ch405labs/ch405labs_esp_libssh2) libssh2 library.   
libssh2 is a client-side C library implementing the SSH2 protocol.   
This is great work.   

# Software requirements
ESP-IDF V5.0 or later.   
ESP-IDF V4.4 release branch reached EOL in July 2024.   


# Installation
```
git clone https://github.com/nopnop2002/esp-idf-ssh-client
cd esp-idf-ssh-client/
idf.py menuconfig
idf.py flash
```

# Configuration   

![config-main](https://user-images.githubusercontent.com/6020549/120054821-3d755500-c06d-11eb-950c-d357d0a9fdef.jpg)
![config-app](https://user-images.githubusercontent.com/6020549/166416531-7fa74d94-86fc-4cac-a568-74de07d7a051.jpg)

- SSH Host   
IP address or mDNS host name.   

# ssh command list   
ssh command list is defined ssh/command.txt.
```
$ cat ssh/command.txt
uname -a
ls -l
cat /etc/os-release
```


# Screen Shot
![ssh-client-1](https://user-images.githubusercontent.com/6020549/120056024-b1ffc200-c074-11eb-8507-1bb566b0cc7c.jpg)

# Reference
https://github.com/nopnop2002/esp-idf-scp-client

You can use scp and ssh to do heavy processing that esp32 alone cannot.  
For example, image processing:   
- Take a picture using the esp32-cam.   
- Send image files to remote using scp-put.   
- Image processing such as shading is performed on the remote side using scp-client.   
- Receive image file from remote using scp-get.   

https://github.com/nopnop2002/esp-idf-telnet-client   
This also works with ESP-IDF V5.X.   
