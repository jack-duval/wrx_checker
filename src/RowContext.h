//
// Created by Jack Duval on 1/25/25.
//
#pragma once

#include <vector>
#include <variant>
#include <string>
#include <unordered_map>

namespace wrx_checker {
//  struct RowContext {
//    double t;
//    bool ACCompressorOn; // on/off
//    double AFCorrection1; // Percentage
//    double AFCorrection3; // Percentage
//    double AFLearning1; // Percentage
//    double AFLearning3; // Percentage
//    double AFSens1Ratio; // Ratio
//    int AVCSExhLeft; //
//    int AVCSInLeft; //
//
//  };



  class RowContext {
   public:
    RowContext(std::vector<std::string>& row);

    static void set_column_map
   protected:
    // since our data can have many types, I want to use variants.
    // A static struct was too unwieldy, as was something like a proto
    std::vector<std::variant<int, double, std::string, bool>> m_vals;

    // Map column names to vector indices
    static std::unordered_map<std::string, size_t> col_map;
  };

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