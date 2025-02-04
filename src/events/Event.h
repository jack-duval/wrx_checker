//
// Created by Jack Duval on 1/25/25.
//
#pragma once

#include <string>
#include <memory>

#include "EventTypes.h"
#include "../Context.h"

namespace wrx_checker {

class Event {
 public:
  Event(EventTypes type, double time)
      : m_type(type), m_time(time) {}

  virtual ~Event() = default;

  std::string getType() const { return kEventTypeNames[m_type]; }
  double getTime() const { return m_time; }

  virtual void check(EventContext& context) = 0;

  void report();

  virtual std::string serializeToProto() const = 0;
  std::unique_ptr<Event> deserializeFromProto(const std::string &proto_data);

 protected:
  EventTypes m_type;
  double m_time;

};

} // namespace wrx_checker
