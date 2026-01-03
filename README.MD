# Arduino Experiments 🧪🔧

This repository contains a collection of **Arduino / AVR microcontroller experiments**, implemented mostly using **bare-metal C/C++ (avr-gcc)** along with some Arduino IDE–based tests.

The goal of this repository is:
- To understand **microcontroller fundamentals**
- To move beyond Arduino abstractions
- To experiment with **hardware peripherals** like GPIO, LCDs, Bluetooth, etc.
- To document learning in a structured, reproducible way

Each experiment lives in its **own folder** and is self-contained.

---

## 🧠 Philosophy

Unlike typical Arduino sketches, many of these experiments:
- Directly manipulate **AVR registers**
- Avoid Arduino helper functions where possible
- Focus on **how things work internally**
- Are suitable for learning embedded systems from first principles

---

## 📁 Repository Structure

Each folder contains:
- Source code
- Build instructions
- Notes specific to that experiment

---

## 🧪 Experiments Included

### 1️⃣ LED Blink (Bare-Metal GPIO)

📂 **Folder:** `led_blink/`

**Concepts covered:**
- AVR GPIO registers (`DDR`, `PORT`, `PIN`)
- Bitwise operations
- Timing using `_delay_ms()`
- Understanding Arduino Uno pin mapping (PB5 → LED)

This is the foundational experiment to verify:
- Toolchain
- Board
- Flashing process

---

### 2️⃣ LCD Interface (16x2 HD44780)

📂 **Folder:** `lcd/`

**Concepts covered:**
- Parallel communication (4-bit mode)
- LCD command vs data registers
- Timing constraints
- Cursor positioning
- String handling in embedded C

**Hardware:**
- 16x2 LCD (HD44780 compatible)
- Arduino Uno

---

### 3️⃣ Bluetooth Communication (HC-05)

📂 **Folder:** `bluetooth/`

**Concepts covered:**
- UART configuration using registers
- Serial communication fundamentals
- Bluetooth SPP profile
- Handling string input without newline (`\n`)
- Buffer management and message termination
- Displaying Bluetooth data on LCD

**Hardware:**
- HC-05 Bluetooth module
- Arduino Uno
- Android phone (Bluetooth terminal app)

---

## 🛠️ Toolchain Used

- **avr-gcc**
- **avr-libc**
- **avrdude**
- Arduino Uno (ATmega328P)

Example MCU: