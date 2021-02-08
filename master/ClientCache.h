#pragma once

class ClientAddr {};

class ClientCache final {
  ClientCache();
  ClientCache(const ClientCache &) = delete;
  ClientCache(const ClientCache &&) = delete;
  virtual ~ClientCache();
  ClientCache &operator=(const ClientCache &) = delete;
  ClientCache &operator=(const ClientCache &&) = delete;

public:
  typedef unsigned long IdType;

public:
  static ClientCache &instance();
  ClientAddr *find(IdType);
  IdType save(ClientAddr &);
  IdType beat_save(ClientAddr &);
  void beat_save(IdType, ClientAddr &);

protected:
  struct Private_;

private:
  Private_ *self;
};
