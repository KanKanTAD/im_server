#include <functional>
#include <iostream>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

const static int serv_port = 6789;

struct Deter {
  std::function<void()> func;
  Deter(std::function<void()> f) : func(f) {}
  virtual ~Deter() { func(); }
};

void handle_udp_msg(int);

int main() {
  puts("hi");
  sleep(1);

  int server_fd = -1;
  sockaddr_in ser_addr;

  server_fd = socket(AF_INET, SOCK_DGRAM, 0);
  if (server_fd < 0) {
    std::cerr << "create socket fail!" << std::endl;
    return -1;
  }
  Deter ser_deter_([&]() { close(server_fd); });

  memset(&ser_addr, 0, sizeof(ser_addr));

  ser_addr.sin_family = AF_INET;
  ser_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  ser_addr.sin_port = htons(serv_port);

  int ret = bind(server_fd, reinterpret_cast<sockaddr *>(&ser_addr),
                 sizeof(ser_addr));
  if (ret < 0) {
    std::cerr << "socket bind fail !" << std::endl;
    return -1;
  }

  handle_udp_msg(server_fd);

  return 0;
}

void handle_udp_msg(int server_fd) {
  const static size_t buff_size = 2048;
  char buff[buff_size];
  socklen_t len;
  sockaddr_in client_addr;
  while (true) {
    memset(buff, 0, sizeof(buff));
    int count = recvfrom(server_fd, buff, sizeof(buff), 0,
                         (sockaddr *)&client_addr, &len);
    if (count == -1) {
      std::cerr << "recieve data fail!" << std::endl;
      return;
    }
    buff[count] = '\0';
    std::cout << " recieve data-> " << buff << std::endl;
    sprintf(buff, "recieved");
    sendto(server_fd, buff, buff_size, 0, (sockaddr *)&client_addr, len);
  }
}
