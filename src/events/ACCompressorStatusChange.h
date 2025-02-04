//
// Created by Jack Duval on 1/25/25.
//

#pragma once

#include "Event.h"
#include "ACCompressorStatusChangeProto.pb.h"
#include "../Context.h"

namespace wrx_checker {

class ACCompressorStatusChange : public Event {
 public:
  ACCompressorStatusChange(double time, bool compressor_status)
      : Event(EventTypes::ACCompressorStatusChange, time),
        m_compressor_status(compressor_status),
        m_prev_compressor_status(!compressor_status) {}

  std::string serializeToProto() const override {
    ACCompressorStatusChangeProto proto;
    proto.set_compressor_status(m_compressor_status);
    proto.set_prev_compressor_status(m_prev_compressor_status);
    proto.set_timestamp(m_time);
    proto.set_event_type(static_cast<int32_t>(m_type));
    return proto.SerializeAsString();
  }

  static std::unique_ptr<ACCompressorStatusChange> fromProto(const std::string& proto_data) {
    ACCompressorStatusChangeProto proto;
    if (!proto.ParseFromString(proto_data)) {
      throw std::runtime_error("Failed to parse ACCompressorStatusChangeProto.");
    }

    return std::make_unique<ACCompressorStatusChange> (
      proto.timestamp(), proto.compressor_status()
    );
  }

  void check(EventContext& context) override;

 protected:
  bool m_compressor_status;
  bool m_prev_compressor_status;
};

} // namespace wrx_checker
