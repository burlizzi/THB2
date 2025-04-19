/**************************************************************************************************
  Filename:      thb2_main.h
  Revised:
  Revision:

  Description:    This file contains the Simple BLE Peripheral sample application
                  definitions and prototypes.

**************************************************************************************************/

#ifndef _THB2_MAIN_H_
#define _THB2_MAIN_H_

#ifdef __cplusplus
extern "C"
{
#endif

/*********************************************************************
 * INCLUDES
 */

/*********************************************************************
 * CONSTANTS
 */
#define DEF_ADV_INERVAL  			2000 // = 5 sec, actual time = advInt * 625us
#define DEF_ADV_INERVAL_MS 			((DEF_ADV_INERVAL*625)/1000) // 5000 ms

#define DEF_CON_ADV_INTERVAL 		2500 // 1.5625 sec
#define DEF_CON_ADV_INTERVAL_MS 		((DEF_CON_ADV_INTERVAL*625)/1000) // 1562 ms
#if	(DEV_SERVICES & SERVICE_BUTTON)
#define DEF_EVENT_ADV_INERVAL 		200 // 95 ms
#define RDS_EVENT_ADV_COUNT			32  // 32*95 = 3040 ms
#else
#define DEF_EVENT_ADV_INERVAL 		80  // 50 ms
#define RDS_EVENT_ADV_COUNT			16  // 16*50 = 800 ms
#endif
#define DEF_EVENT_ADV_INERVAL_MS 	((DEF_EVENT_ADV_INERVAL*625)/1000) // 50 ms
#define DEF_OTA_ADV_INERVAL 		1600 // 1 sec
#define DEF_OTA_ADV_INERVAL_MS 		((DEF_OTA_ADV_INERVAL*625)/1000) // 1000 ms

// adv. event
#define RDS_EVENT_STEP_SEC		1800 // шаг передачи (дублирование состояния) RDS 30 минут без событий
#define RDS_EVENT_DOUBLE_SEC	(RDS_EVENT_STEP_SEC - 12) // передача (дублирование состояния) RDS через 12 сек после события
#define RDS_EVENT_START_SEC		(RDS_EVENT_STEP_SEC - 120) // передача (дублирование состояния) RDS от старта питания - 2 минуты

// How often to perform periodic event
#define SBP_PERIODIC_EVT_PERIOD		1000

#define DEVINFO_SYSTEM_ID_LEN		8
#define DEVINFO_SYSTEM_ID			0

#define DEFAULT_DISCOVERABLE_MODE	GAP_ADTYPE_FLAGS_GENERAL

// Whether to enable automatic parameter update request when a connection is formed
#define DEFAULT_ENABLE_UPDATE_REQUEST			TRUE
// Connection Pause Peripheral time value (in seconds)
#define DEFAULT_CONN_PAUSE_PERIPHERAL			2

// Simple BLE Peripheral Task Events
#define SBP_START_DEVICE_EVT  0x0001  // start
#define SBP_RESET_ADV_EVT     0x0002  // enable adv (from gaprole_start)
#define SBP_CMDDATA           0x0004  // receive command data
#define TIMER_BATT_EVT        0x0008  // for battery detect
#define BATT_VALUE_EVT        0x0010  // Event for battery voltage value update
#define ADV_BROADCAST_EVT     0x0020  // Advent. Event Done Notice
#define WRK_NOTIFY_EVT        0x0040  // work notify
#define PIN_INPUT_EVT         0x0080  // pin input event
#define BUZZER_TONE_EVT       0x0100  // Buzzer new tone
#define KEY_CHANGE_EVT        0x0200  // Key press/release event from interrupt
#define LCD_TIMER_EVT         0x0400  // Timer related to display sleep and key long press feature expired
#define	ROTATE_MAC_EVT				0x0800  // rotate mac
#define	WAIT_FOR_PAIRING_EVT	0x1000  // wait for pairing

/*********************************************************************
 * MACROS
 */
// #define MAC_DATA_LEN				6

/*********************************************************************
 * FUNCTIONS
 */

/*********************************************************************
*********************************************************************/

#define MAC_LEN		6
extern uint8_t ownPublicAddr[MAC_LEN];
extern uint8_t	simpleBLEPeripheral_TaskID;	  // Task ID for internal task/event processing

void SimpleBLEPeripheral_Init( uint8_t task_id );

uint16_t BLEPeripheral_ProcessEvent( uint8_t task_id, uint16_t events );

void swap_mac(uint8_t * d, uint8_t * s);

void set_def_name(void);

void set_dev_name(void);

#if (DEV_SERVICES & SERVICE_SCREEN)
void start_display_sleep_timer(void);
#endif

#ifdef __cplusplus
}

#endif

#endif /* _THB2_MAIN_H_ */
