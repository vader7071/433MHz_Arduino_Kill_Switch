# 433MHz_Arduino_Kill_Switch
A basic dead-man switch based on the Arduino Nano and the 433MHz wireless module

The code uses the ezButton library and the RH_ASK library to make everything work.

The premise, as long as the button is pressed on the TX module, it will transmit a constant character.  As long as the RX module receives the signal, it will keep the
"output pin" high, triggering the relay module.  When the signal is lost for any reason (the switch is no longer pressed, out of range, etc) the RX module will set the
"output pin" to low, releasing the relay module.

This is version 1.  Plans are to add a deadband timer to allow for skipped signals.  Current configuration is a direct copy of whatever the RX module sends.  If the 
TX module begins to "chatter", the RX module will chatter as well.
