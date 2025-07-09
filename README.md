# LPC2148 EEPROM I2C Demo

This project demonstrates how to interface an **external EEPROM** with the **LPC2148 ARM7 microcontroller** using the **I2C protocol**, along with a **16x2 LCD display** for status output and **push buttons** for user interaction.

---

## 🧠 Project Summary

- Microcontroller: **LPC2148 (ARM7)**
- Communication Protocol: **I2C**
- Peripheral: **External EEPROM (e.g., 24C02)**
- Display: **16x2 LCD (4-bit mode)**
- Inputs: **Two push buttons (SW1, SW2)**
- Indicators: **Two LEDs (Write/Read Status)**

---

## 🔧 Features

- Press **SW1** to write the string `"Sanket"` to EEPROM.
- Press **SW2** to read the string back from EEPROM.
- LCD displays `"WRITE"` or `"READ"` operations.
- LEDs indicate the current operation:
  - LED1 ON → Write
  - LED2 ON → Read

---

## 📁 File Structure

.
├── main.c # Main code file
├── Lcd_4bit.h # LCD functions (4-bit mode)
├── I2C.h # I2C functions
├── PLL.h # PLL configuration
└── README.md # This file


---

## 🛠️ Hardware Connections

| Component   | Pin (LPC2148)     |
|-------------|-------------------|
| EEPROM SDA  | P0.27 (SDA)       |
| EEPROM SCL  | P0.28 (SCL)       |
| SW1         | P0.14             |
| SW2         | P0.15             |
| LED1        | P0.17             |
| LED2        | P0.18             |
| LCD         | Any GPIO (as per `Lcd_4bit.h`) |

---

## 🧪 How it Works

1. **Write Operation (SW1)**:
   - When SW1 is pressed, the string `"Sanket"` is written to EEPROM at address `0x09` via I2C.
   - LED1 lights up.
   - LCD shows `WRITE`.

2. **Read Operation (SW2)**:
   - When SW2 is pressed, 6 characters are read from EEPROM address `0x09`.
   - LED2 lights up.
   - LCD shows `READ` and displays the read string.

---

## 🚀 Getting Started

1. Open the project in **Keil uVision** or any suitable ARM7 IDE.
2. Compile and flash to the **LPC2148 development board**.
3. Connect push buttons, EEPROM, and LCD as per connections.
4. Monitor the LCD and LEDs as you press buttons.



## 🧑‍💻 Author

**Sanket Mali**  
Department of Electronics and Telecommunication (ENTC)  
GitHub: [Sanketmail3716](https://github.com/Sanketmail3716)

---

## 📜 License

This project is open-source and free to use for educational purposes.
