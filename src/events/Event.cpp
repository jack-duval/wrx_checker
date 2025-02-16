//
// Created by Jack Duval on 1/25/25.
//

#include "Event.h"
#include "EventTypes.h"
#include "ACCompressorStatusChange.h"

namespace wrx_checker {
void Event::report() {
  // Report entry to events DB with type, time, and serialized proto data

}

std::unique_ptr<Event> Event::deserializeFromProto(const std::string& proto_data) {
  switch (m_type) {
    case EventTypes::ACCompressorStatusChange:
      return ACCompressorStatusChange::fromProto(proto_data);
    default:
      return nullptr;
  }
}

} // namespace wrx_checker