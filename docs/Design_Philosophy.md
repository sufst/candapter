# CANdapter driver design philosophy

The main philosophy of the CANdapter driver is to abstract away *only* the
logic explicitly related to the CANdapter itself. We apply minimal layers
of abstraction over the top of this to afford a good degree of control to
the implementing code.

## Serial interface

The logic to interact with the device serial ports is provided by Boost ASIO.
This means we need to interact only with the exposed APIs from ASIO and not
directly with platform-specific functions. The driver should work on any
platform that Boost ASIO supports.

## Threading

The preferred method of multithreading employed by the driver is none, or where
it is required it should not be visible to the consuming code. This allows the
implementor to determine exactly how the driver should be executed in parallel
(if at all) and allows them to use their preferred method of threading (for example
if they use some UI framework that affords them its own threading system).