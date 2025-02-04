//
// Created by Jack Duval on 1/25/25.
//
#pragma once

#include <unordered_map>

enum class EventTypes {
  ACCompressorStatusChange,
  TestEvent,
  TestFault,
};

static std::unordered_map<EventTypes, std::string> kEventTypeNames = {
  {EventTypes::ACCompressorStatusChange, "ACCompressorStatusChange"},
};
