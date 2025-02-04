//
// Created by Jack Duval on 1/25/25.
//
#include "ACCompressorStatusChange.h"

namespace wrx_checker {

void ACCompressorStatusChange::check(EventContext& context) {
  if (context.prev == nullptr) {
    return;
  }

  if (context.prev->ACCompressorOn != context.curr->ACCompressorOn) {
    // Report fault;
    return;
  } else {
    return;
  }
}

} // namespace wrx_checker