# esp-idf-ssh-client
ssh client for esp-idf.   
You can use the ssh API to execute remote command.   
This project use [this](https://github.com/libssh2/libssh2) ssh library.   

# Software requirements
- esp-idf v4.4   
This is because this version supports ESP32-S3 and uses mbed TLS 2.16.11.   
ESP-IDF Ver5 has been updated to mbed TLS 3.1.0, but [this](https://github.com/libssh2/libssh2) ssh library does not support mbed TLS 3.1.0.   


# Installation

```
git clone https://github.com/nopnop2002/esp-idf-ssh-client
cd esp-idf-ssh-client/
git clone https://github.com/libssh2/libssh2 components/libssh2
cp esp-idf/libssh2_config.h components/libssh2/include
cp esp-idf/CMakeLists.txt components/libssh2
idf.py set-target {esp32/esp32s2/esp32s3/esp32c3}
idf.py menuconfig
idf.py flash
```

# Configuration   

![config-main](https://user-images.githubusercontent.com/6020549/120054821-3d755500-c06d-11eb-950c-d357d0a9fdef.jpg)
![config-app](https://user-images.githubusercontent.com/6020549/166416531-7fa74d94-86fc-4cac-a568-74de07d7a051.jpg)

- SSH Host   
IP address or mDNS name.   

# ssh command list   
ssh command list is defined ssh/command.txt.
```
$ cat ssh/command.txt
uname -a
ls -l
python --version
```


# Screen Shot
![ssh-client-1](https://user-images.githubusercontent.com/6020549/120056024-b1ffc200-c074-11eb-8507-1bb566b0cc7c.jpg)

# Reference
https://github.com/nopnop2002/esp-idf-scp-client

You can use scp and ssh to do heavy processing that esp32 alone cannot.  
- Copy file from esp32 to remote using scp-put.   
- Execute remote command using ssh-client.   
- The processing result is redirected to a file.   
- Copy file from remote to esp32 using scp-get.   

For example, image processing:   
- Take a picture using the esp32-cam.   
- Send image files to remote using scp-put.   
- Image processing such as shading is performed on the remote side using scp-client.   
- Receive image file from remote using scp-get.   

