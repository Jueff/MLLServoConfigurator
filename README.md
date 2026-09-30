# MLLServoConfigurator

## English

(deutsche Bescheibung weiter unten)

### Summary
MLLServoConfigurator is an Arduino/Pico library for controlling and configuring up to three servo channels. ServoConfigurator implements a state machine for configuring up to three servo channels. It translates LED PWM signals into control commands, allows setting min/max limits, speed, and positions, and stores them persistently in flash memory. The class uses StatefulServoController instances for individual servo management and expects regular calls to process() for updates.

The ServoController class manages a single servo motor using PWM on a specified pin. It handles target and current positions, speed limiting, minimum and maximum bounds, and optional inversion. The class supports smooth movement towards target positions, disabling the PWM signal, and manages multiple instances via a linked list. Servo positions are updated periodically using a timer callback.

### Main files / dependencies
- Dependencies: `RP2040_PWM`, `PicoFlashStorage`

### Contact / Reference
- Project-Repo: `https://github.com/Jueff/MLLServoConfigurator`

---

## Deutsch

### Kurzfassung
MLLServoConfigurator ist eine Arduino/Pico-Bibliothek zur Steuerung und Konfiguration von bis zu drei Servo-Kanälen. Sie realisiert eine Zustandsmaschine zur Konfiguration von bis zu drei Servo-Kanälen. Sie übersetzt LED-PWM-Signale in Steuerbefehle, ermöglicht die Einstellung von Min/Max-Grenzen, Geschwindigkeit und Positionen, und speichert diese persistent im Flash-Speicher. Die Klasse nutzt StatefulServoController-Instanzen für die individuelle Servo-Verwaltung und erwartet regelmäßige Aufrufe von process() zur Aktualisierung.

Die ServoController-Klasse verwaltet einen einzelnen Servo-Motor über PWM auf einem spezifizierten Pin. Sie handhabt Ziel- und aktuelle Positionen, Geschwindigkeitsbegrenzung, Minimum- und Maximum-Grenzen sowie optionale Inversion. Die Klasse unterstützt weiche Bewegung zu Zielpositionen, Deaktivierung des PWM-Signals und Verwaltung mehrerer Instanzen über eine verkettete Liste. Servo-Positionen werden periodisch über einen Timer-Callback aktualisiert.

### Wesentliche Dateien / Abhängigkeiten
- Abhängigkeiten: `RP2040_PWM`, `PicoFlashStorage` 

### Kontakt / Referenz
- Projekt-Repo: `https://github.com/Jueff/MLLServoConfigurator`

## Release Notes

### Version 1.2.0

#### English
- `ServoConfigurator` now supports runtime-sized servo channel arrays based on `numberOfServos` (instead of fixed compile-time arrays).
- Clarified command/value interpretation for setup mode:
  - `0` => `None` (returns configurator to `Init`)
  - `223..255` => setup actions (`Servo0..Ok`)
  - `1..222` => normal control range
- Internal state-machine behavior in selection/setup flow was cleaned up for more predictable servo selection handling.

#### Deutsch
- Paket-Metadaten auf `1.2.0` aktualisiert (`library.properties` und `library.json`).
- `ServoConfigurator` unterstützt jetzt zur Laufzeit dimensionierte Servo-Kanal-Arrays basierend auf `numberOfServos` (statt fest verdrahteter Compile-Time-Arrays).
- Auswertung von Befehls-/Wertebereichen für den Setup-Modus präzisiert:
  - `0` => `None` (setzt den Configurator auf `Init` zurück)
  - `223..255` => Setup-Aktionen (`Servo0..Ok`)
  - `1..222` => normaler Steuerbereich
- Internes Verhalten der Zustandsmaschine im Selektions-/Setup-Ablauf bereinigt, um die Servo-Selektion vorhersagbarer zu machen.


