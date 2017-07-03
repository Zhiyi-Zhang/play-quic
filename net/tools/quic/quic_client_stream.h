#ifndef NET_TOOLS_QUIC_CLIENT_STREAM_H_
#define NET_TOOLS_QUIC_CLIENT_STREAM_H_

#include <stdint.h>
#include <memory>
#include "net/quic/core/crypto/crypto_framer.h"
#include "net/quic/core/crypto/crypto_utils.h"
#include "net/quic/core/quic_config.h"
#include "net/quic/core/quic_protocol.h"
#include "net/quic/core/reliable_quic_stream.h"

namespace net {
  namespace tools {

    class QuicClientStream: public ReliableQuicStream {
    public:
      QuicClientStream(QuicStreamId id, QuicSession* session);
      ~QuicClientStream();

      uint32 ProcessRawData(const char* data, uint32_t data_len);

      QuicPriority EffectivePriority() const override;

      void WriteStringPiece(base::StringPiece data, bool fin);
    };
  }
}

#endif // NET_TOOLS_QUIC_CLIENT_STREAM_H_
