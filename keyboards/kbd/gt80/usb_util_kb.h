#pragma once

#include <stdint.h>

// Stub for runtime polling interval adjustment.
// The interval is statically configured via USB_POLLING_INTERVAL_MS in config.h.
void usb_set_pollingInterva(uint8_t ms);
