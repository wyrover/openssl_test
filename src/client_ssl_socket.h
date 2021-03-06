// OpenSSLTest

#ifndef SSL_SOCKET_H_
#define SSL_SOCKET_H_

#include <openssl/ssl.h>
#include "client_socket.h"

namespace net {

class ClientSSLSocket : public ClientSocket {
public:
  ClientSSLSocket();
  virtual ~ClientSSLSocket();

  // Override ClientSocket
  virtual bool Connect(std::string hostAndPort) override;
  virtual void Disconnect() override;
  virtual bool Read(char* buffer, int bufferSize, int* bytesRead) override;
  virtual bool Write(const char* buffer, int bufferSize,
                     int* bytesWritten) override;

private:
  ScopedOpenSSL<BIO, BIO_free_all> _bio;
  ScopedOpenSSL<SSL_CTX, SSL_CTX_free> _ctx;
};

}  // namespace net

#endif  // SSL_SOCKET_H_
