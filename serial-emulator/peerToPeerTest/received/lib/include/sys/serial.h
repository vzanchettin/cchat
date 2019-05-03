#ifndef SERIAL_H
#define SERIAL_H

extern void init_serial();
extern int serial_received();
extern char read_serial();
extern int is_transmit_empty();
extern void write_serial(char a);

#endif