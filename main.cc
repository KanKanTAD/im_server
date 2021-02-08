#include <csignal>
#include <functional>
#include <iostream>
#include <netinet/in.h>
#include <signal.h>
#include <spdlog/cfg/env.h>
#include <spdlog/common.h>
#include <spdlog/spdlog.h>
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

static void signal_handler(int);
static void handle_udp_msg(int);
static int server_fd = -1;

int main() {
  spdlog::set_level(spdlog::level::debug);
  spdlog::info(" im server is beginning");

  signal(SIGKILL, signal_handler);
  signal(SIGINT, signal_handler);

  server_fd = socket(AF_INET, SOCK_DGRAM, 0);
  spdlog::debug("create socket [{0}]", server_fd);
  if (server_fd < 0) {
    spdlog::error("create socket fail!");
    return -1;
  }
  Deter ser_deter_([&]() {
    spdlog::debug("server_fd[{0}] will be closed!", server_fd);
    close(server_fd);
  });

  sockaddr_in ser_addr;
  bzero(&ser_addr, sizeof(ser_addr));

  ser_addr.sin_family = AF_INET;
  ser_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  ser_addr.sin_port = htons(serv_port);

  int ret = bind(server_fd, reinterpret_cast<sockaddr *>(&ser_addr),
                 sizeof(ser_addr));
  if (ret < 0) {
    spdlog::error("socket bind fail !");
    return -1;
  }

  handle_udp_msg(server_fd);

  return 0;
}

void handle_udp_msg(int server_fd) {

  const static size_t buff_size = 2048;
  char buff[buff_size];

  while (true) {
    sockaddr_in client_addr;
    socklen_t len = sizeof(client_addr);
    bzero(buff, sizeof(buff));
    int count = recvfrom(server_fd, buff, sizeof(buff), 0,
                         reinterpret_cast<sockaddr *>(&client_addr), &len);
    if (count == -1) {
      spdlog::error("recieve data fail!");
      return;
    } else {
      buff[count] = '\0';
      spdlog::debug("recieve from host[{0:x}] port[{1}] len[{2}] msg[{3}]",
                    client_addr.sin_addr.s_addr, client_addr.sin_port, len,
                    buff);
    }
    sprintf(buff, "recieved\n");
    spdlog::debug("sendto client 'recieved'");
    sendto(server_fd, buff, buff_size, 0, (sockaddr *)&client_addr,
           sizeof(client_addr));
  }
}

void signal_handler(int signum) {
  spdlog::debug("signum:[{0}]!", signum);
  switch (signum) {
  case SIGINT:
  case SIGKILL:
    if (server_fd >= 0) {
      spdlog::debug("server_fd[{0}] will be closed!", server_fd);
      close(server_fd);
    }
    exit(0);
    break;
  default:
    break;
  }
}
