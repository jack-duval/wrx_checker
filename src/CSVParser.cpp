//
// Created by Jack Duval on 1/25/25.
//

#include "CSVParser.h"

namespace wrx_checker {

bool CSVParser::load() {
  std::ifstream file(m_path);
  if (!file.is_open()) {
    std::cerr << "Could not open the CSV File at " << m_path << "..." << std::endl;
    return false;
  }

  m_data.clear();
  std::string l;
  bool is_header = true;
  while (std::getline(file, l)) {
    if (is_header) {
      is_header = false;
      continue;
    }

    if (!l.empty()) {
      m_data.emplace_back(parse_line(l));
    }
  }
  return true;
}

RowContext CSVParser::parse_line(const std::string &l) {
  size_t start = 0, end;
  std::string val;
  std::vector<std::string> fields ;

  while ((end = l.find(m_delimiter, start)) != std::string::npos) {
    val = l.substr(start, end-start);
    start = end + 1;
    fields.push_back(val);
  }

  RowContext row;

  row.t = stod(fields[0]);
  row.ACCompressorOn = fields[1] == "on";
  row.AFCorrection1 = stod(fields[2]);
  row.AFCorrection3 = stod(fields[3]);
  row.AFLearning1 = stod(fields[4]);
  row.AFLearning3 = stod(fields[5]);
  row.AFSens1Ratio = stod(fields[6]);
  row.AVCSExhLeft = stoi(fields[7]);
  row.AVCSInLeft = stoi(fields[8]);
  row.AccelPos = stod(fields[9]);
  row.BaroPressure = stod(fields[10]);
  row.BatteryVolts = stod(fields[11]);
  row.Boost = stod(fields[12]);
  row.BoostExtended = stod(fields[13]);
  row.CLFuelTarget = stod(fields[14]);
  row.CalculatedLoad = stod(fields[15]);
  row.CalculatedLoadExt = stod(fields[16]);
  row.CommFuelFinal = stod(fields[17]);
  row.CoolantTemp = stod(fields[18]);
  row.DAM = stod(fields[19]);
  row.EGRCommaneded = stod(fields[20]);
  row.FBK = stod(fields[21]);
  row.FKL = stod(fields[22]);
  row.FuelCut = stod(fields[23]);
  row.FuelPressure = stod(fields[24]);
  row.FuelPressureTarget = stod(fields[25]);
  row.GearPosition = stoi(fields[26]);
  row.IgnitionComp = stod(fields[27]);
  row.IgnitionTiming = stod(fields[28]);
  row.InjectionDutyCycle = stod(fields[29]);
  row.InjectionPW = stod(fields[30]);
  row.InjectionTimingHSOI = stod(fields[31]);
  row.IntakeTemp = stod(fields[32]);
  row.IntakeTempManifold = stod(fields[33]);
  row.MAFCorrectionFinal = stod(fields[34]);
  row.MAFVolts = stod(fields[35]);
  row.ManifoldAbsolutePressure = stod(fields[36]);
  row.OilTemp = stod(fields[37]);
  row.RPM = stoi(fields[38]);
  row.ReqTorque = stod(fields[39]);
  row.TDBoostError = stod(fields[40]);
  row.TDIntegral = stod(fields[41]);
  row.TDProportional = stod(fields[42]);
  row.TGVMapRatio = stod(fields[43]);
  row.TargetBoostFinalRelExt = stod(fields[44]);
  row.ThrottlePos = stod(fields[45]);
  row.VehicleSpeed = stoi(fields[46]);
  row.WastegateDuty = stod(fields[47]);

  return row;
}

void CSVParser::print() {
  for (RowContext& row : m_data) {
    row.print();
  }
}

} // namespace wrx_checker