#include "usb_util_kb.h"

// Polling interval is statically set via USB_POLLING_INTERVAL_MS in config.h.
// This stub exists to satisfy call sites that previously used the Holy80
// custom usb_set_pollingInterva() from usb_util.h / usb_main.h.
void usb_set_pollingInterva(uint8_t ms) {
    (void)ms;
}
