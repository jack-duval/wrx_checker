//
// Created by Jack Duval on 1/25/25.
//
#pragma once

enum class Severity {
  LOW,
  MEDIUM,
  HIGH
};

static std::unordered_map<Severity, std::string> kSeverityNames = {
  {Severity::LOW, "Low"},
  {Severity::MEDIUM, "Medium"},
  {Severity::HIGH, "High"},
};