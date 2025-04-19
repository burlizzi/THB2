
#include "nearby.h"

#include "nearby_platform_trace.h"
#include "log.h"
#include <stdarg.h>


// Processes assert. Processes a failed assertion.
//
// filename - Name of file calling assert.
// lineno   - Source line of assert call
// reason   - String message indicating reason for assert.
void nearby_platfrom_CrashOnAssert(const char *filename, int lineno,
                                   const char *reason)
{ 
  // Log the assert message.
  LOG("ASSERT: %s", reason);

  // Crash the system.
  while (1);
}

void nearby_platform_Trace(nearby_platform_TraceLevel level,
  const char *filename, int lineno, const char *fmt,
  ...)
  {
    va_list args;
    va_start(args, fmt);
    switch (level)
    {
    case kTraceLevelVerbose:
      LOG("VERBOSE: ");
      break;
    case kTraceLevelDebug:
      LOG("DEBUG: ");
      break;
    case kTraceLevelInfo:
      LOG("INFO: ");
      break;
    case kTraceLevelWarning:
      LOG("WARNING: ");
      break;
    case kTraceLevelError:
      LOG("ERROR: ");
      break;
    default:
      LOG("UNKNOWN: ");
      break;
    }
    dbg_printf("%s:%d: ", filename, lineno);
    dbg_printf(fmt, args);
    va_end(args);
  }

// Initializes trace module.
void nearby_platform_TraceInit(void);

