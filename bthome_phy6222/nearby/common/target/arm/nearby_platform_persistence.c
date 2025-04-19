
#include "nearby.h"
#include "nearby_platform_persistence.h"
// Loads stored key
//
// key    - Type of key to fetch.
// output - Buffer to contain retrieved key.
// length - On input, contains the size of the output buffer.
//          On output, contains the Length of key.
nearby_platform_status nearby_platform_LoadValue(nearby_fp_StoredKey key,
                                                 uint8_t* output,
                                                 size_t* length)
{
  *length=flash_read_cfg(output, key, *length);
  dbg_printf("flash_read_cfg %d, %s\n",key,output);

    return kNearbyStatusOK;
}

// Saves stored key
//
// key    - Type of key to store.
// output - Buffer containing key to store.
// length - Length of key.
nearby_platform_status nearby_platform_SaveValue(nearby_fp_StoredKey key,
                                                 const uint8_t* input,
                                                 size_t length)
{
  dbg_printf("flash_write_cfg %d, %s\n",key,input);

  if(flash_write_cfg(input, key, length))
    return kNearbyStatusOK;
  
  return kNearbyStatusError;
}
// Initializes persistence module
nearby_platform_status nearby_platform_PersistenceInit(){
  return kNearbyStatusOK;
}


void *memmove(void *dest_str, const void *src_str, size_t numBytes)
{
  unsigned char *dest = dest_str;
  const unsigned char *src = src_str;
  size_t i;

  if (dest < src)
  {
    for (i = 0; i < numBytes; i++)
    {
      dest[i] = src[i];
    }
  }
  else
  {
    for (i = numBytes; i != 0; i--)
    {
      dest[i - 1] = src[i - 1];
    }
  }

  return dest_str;
}