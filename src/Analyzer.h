//
// Created by Jack Duval on 2/1/25.
//
#pragma once

#include "Context.h"
#include "events/Event.h"
#include "faults/Fault.h"

namespace wrx_checker {

class Analyzer {
public:
  Analyzer(const std::vector<RowContext>& data) : m_data(data){
    if (m_data.empty()) { return; }

    m_event_context.prev = nullptr;
    m_event_context.curr = std::make_unique<RowContext>(m_data[0]);

    m_fault_context.prev = nullptr;
    m_fault_context.curr = std::make_unique<RowContext>(m_data[0]);
    m_fault_context.next = nullptr;
  }

  void analyze();

 private:
  std::vector<RowContext> m_data;
  EventContext m_event_context;
  FaultContext m_fault_context;

  std::vector<Event> m_events;
  std::vector<Fault> m_faults;


};

} // namespace wrx_checker