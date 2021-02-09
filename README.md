# im_server

im_server

# depend

- gtest
- spdlog
- cryptopp
- nlohmann/json

## gtest

```bash 
git clone https://github.com/google/googletest.git
cd googletest
git checkout -b release-1.8.1 release-1.8.1
mkdir build
cd build && cmake ..
make 
sudo make install
```

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

## nlohmann/json

```bash
git clone https://github.com/nlohmann/json.git
cd json 
git checkout -b v3.9.1 v3.9.1 
mkdir build 
cd build && cmake ..
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
