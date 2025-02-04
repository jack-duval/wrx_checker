//
// Created by Jack Duval on 2/1/25.
//

#pragma once

#include <vector>
#include <variant>
#include <string>
#include <iostream>
#include <memory>
#include <optional>
#include <unordered_map>

namespace wrx_checker {
struct RowContext {
  double t;
  bool ACCompressorOn; // on/off
  double AFCorrection1; // Percentage
  double AFCorrection3; // Percentage
  double AFLearning1; // Percentage
  double AFLearning3; // Percentage
  double AFSens1Ratio; // Ratio
  int AVCSExhLeft; //
  int AVCSInLeft; //
  double AccelPos; // Percentage
  double BaroPressure; // PSI
  double BatteryVolts; // Volts
  double Boost; // PSI
  double BoostExtended; // PSI
  double CLFuelTarget; // AFR
  double CalculatedLoad; // g/rev
  double CalculatedLoadExt; // g/rev
  double CommFuelFinal; // AFR
  double CoolantTemp; // Degrees F
  double DAM; // Dynamic Advanced Multiplier
  double EGRCommaneded; // Steps
  double FBK; // Feedback Knock, degrees
  double FKL; // Fine Knock Learn, degrees
  double FuelCut; // cylinders
  double FuelPressure; // psi
  double FuelPressureTarget; // psi
  int GearPosition; // Gear
  double IgnitionComp; // Ignition Comp, Degrees
  double IgnitionTiming; // Degrees
  double InjectionDutyCycle; // Percentage
  double InjectionPW; // milliseconds
  double InjectionTimingHSOI; // degrees
  double IntakeTemp; // Degrees, Fahrenheit
  double IntakeTempManifold; // Degrees, Fahrenheit
  double MAFCorrectionFinal; // g/s
  double MAFVolts; // Volts
  double ManifoldAbsolutePressure; // PSI
  double OilTemp; // Degrees, Fahrenheit
  int RPM; // rpm
  double ReqTorque; // Nm
  double TDBoostError; // PSI
  double TDIntegral; // Percentage
  double TDProportional; // Percentage
  double TGVMapRatio; // multiplier, scalar
  double TargetBoostFinalRelExt; // PSI
  double ThrottlePos; // Percentage
  int VehicleSpeed; // MPH
  double WastegateDuty; // PCT
  std::string APInfo; // AP info

  void print() {
    // spot check some random values
    std::cout << t << ", " << OilTemp << ", " << RPM << ", " << BoostExtended << std::endl;
  }

// maybe easier to use a vec of variant
//  class RowContext {
//   public:
//    RowContext(std::vector<std::string>& row);
//
//    static void set_column_map
//   protected:
//    // since our data can have many types, I want to use variants.
//    // A static struct was too unwieldy, as was something like a proto
//    std::vector<std::variant<int, double, std::string, bool>> m_vals;
//
//    // Map column names to vector indices
//    static std::unordered_map<std::string, size_t> col_map;
//  };

};

struct EventContext {
  std::unique_ptr<RowContext> prev;
  std::unique_ptr<RowContext> curr;

};

struct FaultContext {
  std::unique_ptr<RowContext> prev;
  std::unique_ptr<RowContext> curr;
  std::unique_ptr<RowContext> next;
};

} // namespace wrx_checker