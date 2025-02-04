//
// Created by Jack Duval on 1/25/25.
//
#pragma once

#include <vector>
#include <variant>
#include <string>
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
};

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

/* Time (sec),AC Compressor Sw (on/off),AF Correction 1 (%),AF Correction 3 (%),AF Learning 1 (%),
 * AF Learning 3 (%),AF Sens 1 Ratio (AFR),AVCS Exh Left (deg),AVCS In Left (deg),Accel Position (%),
 * Baro Pressure (psi),Battery Volts (V),Boost (psi),Boost Extended (psi),CL Fuel Target (AFR),
 * Calculated Load (g/rev),Calculated Load Ext (g/rev),Comm Fuel Final (AFR),Coolant Temp (F),
 * Dyn Adv Mult (DAM),EGR Commanded (steps),Feedback Knock (deg),Fine Knock Learn (deg),
 * Fuel Cut (cylinders),Fuel Pressure (psi),Fuel Pressure Target (psi),Gear Position (gear),
 * Ign Comp IAT (deg),Ignition Timing (deg),Inj Duty Cycle (%),Inj PW (ms),Inj Timing H SOI (deg),
 * Intake Temp (F),Intake Temp Manifold (F),MAF Corr Final (g/s),MAF Volts (V),Man Abs Press (psi),
 * Oil Temp (F),RPM (RPM),Req Torque (Nm),TD Boost Error Ext (psi),TD Integral (%),TD Proportional (%),
 * TGV Map Ratio (mult),Target Boost Final Rel Ext (psi),Throttle Pos (%),Vehicle Speed (mph),
 * Wastegate Duty (%),
 * "AP Info:[AP3-SUB-004 v1.7.5.0-25420][2021 USDM WRX MT COBB Custom Features Gen2][Reflash: Stage1 91 v400.ptm - Realtime: Stage1 91 v400.ptm]"

 *
 */

} // namespace wrx_checker