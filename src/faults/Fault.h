//
// Created by Jack Duval on 1/25/25.
//
#pragma once

#include <string>

#include "../events/Event.h"
#include "Severity.h"
#include "../events/EventTypes.h"

namespace wrx_checker {

class Fault : public Event {
 public:
  Fault(EventTypes type, double time, Severity& severity)
      : Event(type, time) {
    m_severity = severity;
  }

  virtual ~Fault() = default;

 protected:
  Severity m_severity;

};

} // namespace wrx_checker

