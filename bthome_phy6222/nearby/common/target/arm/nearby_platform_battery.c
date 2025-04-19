

#include "nearby.h"
#include "nearby_platform_battery.h"
#include "sensors.h"

// Gets battery and charging info
//
// battery_info - Battery status structure.
nearby_platform_status nearby_platform_GetBatteryInfo(
    nearby_platform_BatteryInfo* battery_info)
{
  battery_info->is_charging = false;
  battery_info->left_bud_battery_level = measured_data.battery_mv;
  battery_info->right_bud_battery_level = measured_data.battery_mv;
  battery_info->charging_case_battery_level = measured_data.battery_mv;
  return kNearbyStatusOK;
}

// Initializes battery module
//
// battery_interface - Battery status callback events.
nearby_platform_status nearby_platform_BatteryInit(
    nearby_platform_BatteryInterface* battery_interface)
{
  return kNearbyStatusOK;
}
