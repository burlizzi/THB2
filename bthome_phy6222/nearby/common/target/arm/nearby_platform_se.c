#include <stdint.h>
#include "nearby.h"
#include "ll.h"
#include "aes.h"
#include <stdlib.h>
#include "nearby_platform_se.h"

// Generates a random number.
uint8_t nearby_platform_Rand()
{
    uint8_t retval;
    LL_Rand(&retval,1);
    return retval;   
}

struct AES_ctx ctx;


// Computes the sha256 incrementally. Sha256Start() is called first, then
// Sha256Update() one or more times, and finally Sha256Finish().
nearby_platform_status nearby_platform_Sha256Start()
{
    return kNearbyStatusOK;
}

// Intermediate sha256 compute.
//
// data   - Block of data to compute into sha256.
// length - Length of data to process.
nearby_platform_status nearby_platform_Sha256Update(const void* data,
                                                    size_t length)
{
    AES_CBC_encrypt_buffer(&ctx,data,length);
    return kNearbyStatusOK;
}

// Finishes sha256 compute.
//
// out - Contains the final 256 bit sha.
nearby_platform_status nearby_platform_Sha256Finish(uint8_t out[32])
{
    #warning "nearby_platform_Sha256Finish not implemented"
    log_printf("nearby_platform_Sha256Finish not implemented\n");
    return kNearbyStatusOK;
}

// Encrypts a data block with AES128 in ECB mode.
//
// input - Input data block to be encrypted.
// output - Resulting encrypted block.
// key    - 128 bit key to use for encryption.
nearby_platform_status nearby_platform_Aes128Encrypt(
    const uint8_t input[AES_MESSAGE_SIZE_BYTES],
    uint8_t output[AES_MESSAGE_SIZE_BYTES],
    const uint8_t key[AES_MESSAGE_SIZE_BYTES])
{
    AES_init_ctx(&ctx,key);
    AES_ECB_encrypt(&ctx,output);
    return kNearbyStatusOK;
}

// Decrypts a data block with AES128 in ECB mode.
//
// input - Input data block to be decrypted.
// output - Resulting decrypted block.
// key    - 128 bit key to use for decryption.
nearby_platform_status nearby_platform_Aes128Decrypt(
    const uint8_t input[AES_MESSAGE_SIZE_BYTES],
    uint8_t output[AES_MESSAGE_SIZE_BYTES],
    const uint8_t key[AES_MESSAGE_SIZE_BYTES])
{
    AES_init_ctx(&ctx,key);
    AES_ECB_decrypt(&ctx,output);
    return kNearbyStatusOK;
}

// Generates a shared sec256p1 secret using remote party public key and this
// device's private key.
//
// remote_party_public_key - Remote key.
// secret                  - 256 bit shared secret.
nearby_platform_status nearby_platform_GenSec256r1Secret(
    const uint8_t remote_party_public_key[64], uint8_t secret[32])
{
    #warning "nearby_platform_GenSec256r1Secret not implemented"
    log_printf("nearby_platform_GenSec256r1Secret not implemented\n");
    return kNearbyStatusOK;
}

// Returns anti-spoofing 128 bit private key.
// Only used if the implementation also uses the
// nearby_platform_GenSec256r1Secret() routine defined in gen_secret.c.
// Return NULL if not implemented.
const uint8_t* nearby_platform_GetAntiSpoofingPrivateKey();

// Initializes secure element module
nearby_platform_status nearby_platform_SecureElementInit()
{
    return kNearbyStatusOK;
}

