#include "ran.h"

#include <windows.h>
#include <wincrypt.h>

u64 ran_rand(void) {
    HCRYPTPROV handle;
    byte buffer[8];

    if (!(CryptAcquireContext(&handle, NULL, NULL, PROV_RSA_FULL, 0) &&
        CryptGenRandom(handle, sizeof(buffer), buffer))) {
        return U64_MAX; /* tough dicision */
    }

    CryptReleaseContext(handle, 0);

    return *(u64*)buffer;
}
