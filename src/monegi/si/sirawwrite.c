#include "PR/os_internal.h"
#include "siint.h"
#include "assert.h"

s32 __osSiRawWriteIo(u32 devAddr, u32 data) {
#ifdef _DEBUG
    assert((devAddr & 0x3) == 0);
#endif
    if (__osSiDeviceBusy()) {
        return -1;
    }

    IO_WRITE(devAddr, data);
    return 0;
}
