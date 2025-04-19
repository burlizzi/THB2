
#include "nearby.h"
#include "nearby_platform_os.h"
#include "config.h"
#include <thb2_main.h>
// Gets current time in ms.
unsigned int nearby_platform_GetCurrentTimeMs()
{
    return clkt.utc_time_tik*1000/32768;
}

void (*nearby_callback[2])()={0,0};
// Starts a timer. Returns an opaque timer handle or null on error.
//
// callback - Function to call when timer matures.
// delay_ms - Number of milliseconds to run the timer.
void* nearby_platform_StartTimer(uint16_t ev,void (*callback)(), unsigned int delay_ms)
{
  osal_start_reload_timer(simpleBLEPeripheral_TaskID, ev, delay_ms);
  switch (ev)
  {
    case ROTATE_MAC_EVT:
    nearby_callback[0] = callback;
    break;
    case WAIT_FOR_PAIRING_EVT:
    nearby_callback[1] = callback;
    break;
  
  default:
    break;
  }

  
}

// Cancels a timer
//
// timer - Timer handle returned by StartTimer.
nearby_platform_status nearby_platform_CancelTimer(void* timer)
{ 
    if(timer==nearby_callback[0])
    {
      nearby_callback[0]=0;
      osal_stop_timerEx(simpleBLEPeripheral_TaskID, ROTATE_MAC_EVT);
    }
    else if(timer==nearby_callback[1])
    {
      nearby_callback[1]=0;
      osal_stop_timerEx(simpleBLEPeripheral_TaskID, WAIT_FOR_PAIRING_EVT);
    }
    return kNearbyStatusOK;
}

// Initializes OS module
nearby_platform_status nearby_platform_OsInit()
{
    return kNearbyStatusOK;
}

// Starts ringing
//
// `command` - the requested ringing state as a bitmap:
// Bit 1 (0x01): ring right
// Bit 2 (0x02): ring left
// Bit 3 (0x04): ring case
// Alternatively, `command` hold a special value of 0xFF to ring all
// components that can ring.
// `timeout` - the timeout in deciseconds. The timeout overrides the one already
// in effect if any component of the device is already ringing.
nearby_platform_status nearby_platform_Ring(uint8_t command, uint16_t timeout);

