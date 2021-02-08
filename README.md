# im_server

im_server

# depend

- spdlog
- cryptopp

## spdlog 

```bash 
git clone https://github.com/gabime/spdlog.git
cd spdlog
git checkout -b v1.8.2 v1.8.2
mkdir build
cd build && cmake ..
make && sudo make install 
```

## cryptopp

```bash
git clone https://github.com/weidai11/cryptopp.git
cd cryptopp
git checkout -b CRYPTOPP_8_4_0 CRYPTOPP_8_4_0
make 
sudo make install 
```

# build

```bash
mkdir build
cd build
cmake ..
make
```
