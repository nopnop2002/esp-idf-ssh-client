# CH405Labs ESP LIBSSH2

## Notes
Libssh needs to be used with pem keys, as the server only supports ed or pem.
You can convert ed keys to pem by ssh-keygen -p -m PEM -f ./id_rsa or generate
them directly using ssh-keygen -t rsa -b 4096 -m PEM and then openssl rsa -in id_rsa -outform pem > id_rsa.pem
or this ssh-keygen -f ~/.ssh/id_rsa.pub -e -m pem > ~/.ssh/id_rsa.pub.pem

Check out api guides for information, eg. https://github.com/espressif/esp-idf/blob/master/docs/en/api-guides/wifi.rst