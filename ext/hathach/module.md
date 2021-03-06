# TinyUSB

TinyUSB is an open-source cross-platform USB Host/Device stack for embedded
system, designed to be memory-safe with no dynamic allocation and thread-safe
with all interrupt events are deferred then handled in the non-ISR task
function.

This module provides a autogenerated port for TinyUSB, which includes the
correct interrupt mapping, a serial number based on the UID of the device,
as well as remapping the assertions of TinyUSB.


## Autogeneration of USB Descriptors

You can select the device classes you want to use via the `modm:tinyusb:config`
list option:

- `device.cdc`: Serial connection (uses **two** endpoints!)
- `device.msc`: Mass Storage class.
- `device.midi`: MIDI device.
- `device.vendor`: WebUSB device.
- `device.dfu`: DFU (runtime only).

Note that you can add multiple devices at the same time, as long as there are
enough endpoints and USB RAM available:

```xml
<!-- Using the CDC and MSC classes together -->
<option name="modm:tinyusb:config">device.cdc,device.msc</option>
<!-- Using two CDC ports! -->
<option name="modm:tinyusb:config">device.cdc,device.cdc</option>
```

modm will generate the USB descriptors automatically for the set of device
classes you've chosen. You can then implement your app via TinyUSB callbacks.


## Manual USB Descriptors

If you leave the `modm:tinyusb:config` option empty, no descriptors are
generated, so you can implement them yourself. Note that you must also
manually depend on the device classes you want to implement:

```xml
<module>modm:tinyusb:device:net</module>
<module>modm:tinyusb:device:hid</module>
<module>modm:tinyusb:device:usbtmc</module>
```


## Initializing USB

The `modm:platform:usb` module provides the correct way of initializing the USB
peripheral, however, you must connect the right signals too:

```cpp
// USB is timing-sensitive, so prioritize the IRQs accordingly
Usb::initialize<SystemClock>(/*priority=*/3);

// For Device-Only USB implementations, this is enough
Usb::connect<GpioA11::Dm, GpioA12::Dp>();

// But for On-The-Go (OTG) USB implementations, you need more:
Usb::connect<GpioA11::Dm, GpioA12::Dp, GpioA10::Id>();
// Enable hardware Vbus sensing on GpioA9 (this can be tricky to get right!)
USB_OTG_FS->GCCFG |= USB_OTG_GCCFG_VBDEN;
```

Note that depending on your specific hardware setup, you may need to fiddle
around to find the right VBus sensing mechanism.

!!! warning "USB shares resources with CAN"
	Note that on STM32F1 and STM32F3 the USB interrupts and RAM are shared with CAN,
	thus there are conflicts in IRQ definitions as well as resource limitions in
	hardware. On some STM32F3, the USB IRQs can be remapped, this is done
	automatically by our port.


## Debugging TinyUSB

Since we've made it so easy to add multiple device classes, it's also easy to
run out of endpoints or RAM. Therefore we reroute TinyUSBs assertions to
`modm_assert`, so make sure you have implemented the `modm_abandon` handler!
See the `modm:architecture:assert` module for details.

A TinyUSB assertion failure in release mode is fairly cryptic:

```
Assertion 'tu' failed!
Abandoning...
```

If you run this again in debug mode, you'll note a much more detailed assertion
description. In this example you've exhaused the number of endpoints:

```
Assertion 'tu' failed!
  modm/ext/tinyusb/portable/st/synopsys/dcd_synopsys.c:524 -> "epnum < 4U"
Abandoning...
```

To trace the TinyUSB core, you can add `CFG_TUSB_DEBUG=2` to your CPP flags and
the output will be forwarded to `MODM_LOG_DEBUG`.

```
<collect name="modm:build:cppdefines">CFG_TUSB_DEBUG=2</collect>
```
