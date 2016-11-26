#ifndef CONFIG_DEFINITIONS_H
#define CONFIG_DEFINITIONS_H

/* diode directions */
#define COL2ROW 0
#define ROW2COL 1
/* I/O pins */
#define B0 0x30
#define B1 0x31
#define B2 0x32
#define B3 0x33
#define B4 0x34
#define B5 0x35
#define B6 0x36
#define B7 0x37
#define C0 0x60
#define C1 0x61
#define C2 0x62
#define C3 0x63
#define C4 0x64
#define C5 0x65
#define C6 0x66
#define C7 0x67
#define D0 0x90
#define D1 0x91
#define D2 0x92
#define D3 0x93
#define D4 0x94
#define D5 0x95
#define D6 0x96
#define D7 0x97
#define E0 0xC0
#define E1 0xC1
#define E2 0xC2
#define E3 0xC3
#define E4 0xC4
#define E5 0xC5
#define E6 0xC6
#define E7 0xC7
#define F0 0xF0
#define F1 0xF1
#define F2 0xF2
#define F3 0xF3
#define F4 0xF4
#define F5 0xF5
#define F6 0xF6
#define F7 0xF7
#define A0 0x00
#define A1 0x01
#define A2 0x02
#define A3 0x03
#define A4 0x04
#define A5 0x05
#define A6 0x06
#define A7 0x07


/* USART configuration */
#ifdef BLUETOOTH_ENABLE
#   ifdef __AVR_ATmega32U4__
#      define SERIAL_UART_BAUD 9600
#      define SERIAL_UART_DATA UDR1
#      define SERIAL_UART_UBRR (F_CPU / (16UL * SERIAL_UART_BAUD) - 1)
#      define SERIAL_UART_RXD_VECT USART1_RX_vect
#      define SERIAL_UART_TXD_READY (UCSR1A & _BV(UDRE1))
#      define SERIAL_UART_INIT() do { \
            /* baud rate */ \
            UBRR1L = SERIAL_UART_UBRR; \
            /* baud rate */ \
            UBRR1H = SERIAL_UART_UBRR >> 8; \
            /* enable TX */ \
            UCSR1B = _BV(TXEN1); \
            /* 8-bit data */ \
            UCSR1C = _BV(UCSZ11) | _BV(UCSZ10); \
            sei(); \
        } while(0)
#   else
#       error "USART configuration is needed."
#   endif
#endif

#ifdef PS2_USE_BUSYWAIT
#   ifndef PS2_CLOCK_PORT
#       error "PS2_CLOCK_PORT has to be defined"
#   endif
#   ifndef PS2_CLOCK_PIN
#       error "PS2_CLOCK_PIN has to be defined"
#   endif
#   ifndef PS2_CLOCK_DDR
#       error "PS2_CLOCK_DDR has to be defined"
#   endif
#   ifndef PS2_CLOCK_BIT
#       error "PS2_CLOCK_BIT has to be defined"
#   endif
#   ifndef PS2_DATA_PORT
#       error "PS2_DATA_PORT has to be defined"
#   endif
#   ifndef PS2_DATA_PIN
#       error "PS2_DATA_PIN has to be defined"
#   endif
#   ifndef PS2_DATA_DDR
#       error "PS2_DATA_DDR has to be defined"
#   endif
#   ifndef PS2_DATA_BIT
#       error "PS2_DATA_BIT has to be defined"
#   endif
#endif

#ifdef PS2_USE_INT
#   ifndef PS2_CLOCK_PORT
#       error "PS2_CLOCK_PORT has to be defined"
#   endif
#   ifndef PS2_CLOCK_PIN
#       error "PS2_CLOCK_PIN has to be defined"
#   endif
#   ifndef PS2_CLOCK_DDR
#       error "PS2_CLOCK_DDR has to be defined"
#   endif
#   ifndef PS2_CLOCK_BIT
#       error "PS2_CLOCK_BIT has to be defined"
#   endif
#   ifndef PS2_DATA_PORT
#       error "PS2_DATA_PORT has to be defined"
#   endif
#   ifndef PS2_DATA_PIN
#       error "PS2_DATA_PIN has to be defined"
#   endif
#   ifndef PS2_DATA_DDR
#       error "PS2_DATA_DDR has to be defined"
#   endif
#   ifndef PS2_DATA_BIT
#       error "PS2_DATA_BIT has to be defined"
#   endif
#   ifndef PS2_INT_INIT
#       error "PS2_INT_INIT has to be defined"
#   endif
#   ifndef PS2_INT_ON
#       error "PS2_INT_ON has to be defined"
#   endif
#   ifndef PS2_INT_OFF
#       error "PS2_INT_OFF has to be defined"
#   endif
#   ifndef PS2_INT_VECT
#       error "PS2_INT_VECT has to be defined"
#   endif
#endif

#ifdef PS2_USE_USART
#   ifndef PS2_CLOCK_PORT
#       error "PS2_CLOCK_PORT has to be defined"
#   endif
#   ifndef PS2_CLOCK_PIN
#       error "PS2_CLOCK_PIN has to be defined"
#   endif
#   ifndef PS2_CLOCK_DDR
#       error "PS2_CLOCK_DDR has to be defined"
#   endif
#   ifndef PS2_CLOCK_BIT
#       error "PS2_CLOCK_BIT has to be defined"
#   endif
#   ifndef PS2_DATA_PORT
#       error "PS2_DATA_PORT has to be defined"
#   endif
#   ifndef PS2_DATA_PIN
#       error "PS2_DATA_PIN has to be defined"
#   endif
#   ifndef PS2_DATA_DDR
#       error "PS2_DATA_DDR has to be defined"
#   endif
#   ifndef PS2_DATA_BIT
#       error "PS2_DATA_BIT has to be defined"
#   endif
#   ifndef PS2_USART_INIT
#       error "PS2_USART_INIT has to be defined"
#   endif
#   ifndef PS2_USART_RX_INT_ON
#       error "PS2_USART_RX_INT_ON has to be defined"
#   endif
#   ifndef PS2_USART_RX_POLL_ON
#       error "PS2_USART_RX_POLL_ON has to be defined"
#   endif
#   ifndef PS2_USART_OFF
#       error "PS2_USART_OFF has to be defined"
#   endif
#   ifndef PS2_USART_RX_READY
#       error "PS2_USART_RX_READY has to be defined"
#   endif
#   ifndef PS2_USART_RX_DATA
#       error "PS2_USART_RX_DATA has to be defined"
#   endif
#   ifndef PS2_USART_ERROR
#       error "PS2_USART_ERROR has to be defined"
#   endif
#   ifndef PS2_USART_RX_VECT
#       error "PS2_USART_RX_VECT has to be defined"
#   endif
#endif


#endif