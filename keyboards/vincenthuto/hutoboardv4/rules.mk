# MCU name
MCU = atmega32u4
LTO_ENABLE = yes
# Bootloader selection
BOOTLOADER = caterina

SPLIT_KEYBOARD = yes
UNICODE_ENABLE = yes

OLED_ENABLE = yes
OLED_DRIVER_ENABLE = yes
OLED_DRIVER = SSD1306
WPM_ENABLE = yes

MAGIC_ENABLE = no
AUTOCORRECT_ENABLE = yes
#SRC += analog.c
#SRC += thumbstick.c