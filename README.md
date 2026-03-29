# Edge-Based Solar Intelligence System

> A distributed solar monitoring system with edge-deployed analytics, contextual fault detection, and multi-node intelligence.

---

## Overview

Most solar monitoring systems act as passive data loggers or rely heavily on cloud-based analytics. This project implements a **fully edge-based intelligence system** where data is processed, interpreted, and classified directly on the controller.

The system focuses on **context-aware decision making**, not just raw anomaly detection.

> **Train once, deploy as lightweight logic — no cloud dependency required.**

---

## System Architecture

The platform consists of two main layers:

### 1️. Data Nodes — Sensing Layer

Each Data Node collects electrical and environmental parameters, structures them into fixed packets, and transmits them to the controller.

**Packet Format:**
```
NodeID | Voltage | Current | Power | Temperature | Humidity | Light | Timestamp
```

> Prototype uses **Arduino Mega**. Scalable nodes can be implemented on **ATtiny85**.

---

### 2️. Main Node — Edge Intelligence Layer

The Main Node performs all computation and decision-making locally using RTOS-based task scheduling:
- Uses RTOS tasks for periodic, non-blocking sensor data acquisition

- Receives and parses multi-node data
- Computes derived features (efficiency, residuals, trends)
- Applies regression-based expected output estimation
- Runs classification logic (converted from trained models)
- Tracks time-based deviations
- Performs multi-node comparison

No cloud dependency — all intelligence runs on-device.

### RTOS-Based Scheduling

The system uses RTOS to schedule periodic tasks for sensor acquisition and processing.

- Each sensor is handled by an independent task
- Tasks run at fixed intervals (e.g., every 30 seconds)
- Non-blocking execution ensures continuous system responsiveness

This allows the system to scale across multiple sensors without sequential delays.

---

## ML & Decision Logic

### Model Strategy

Instead of deploying heavy models, the system uses:

- **Regression model**  
  Estimates expected power: 
  ```
  Power = f(Light, Temperature, Humidity)
  ```

- **Decision tree logic (converted to if–else rules)**  
Used for classification of system states

> Models are trained offline and deployed as lightweight logic on the edge device.

---

### Feature Engineering

**Raw Inputs:**
- Power
- Light (irradiance proxy)
- Temperature
- Humidity

**Derived Features:**
- Efficiency = Power / Light
- Residual = Actual − Expected Power
- Rate of change (Light, Power)
- Duration of deviation

---

### Context-Aware Classification

The system classifies conditions instead of flagging binary anomalies:

| Condition     | Meaning                              |
|--------------|--------------------------------------|
| NORMAL       | Expected performance                 |
| CLOUD        | Temporary drop due to low irradiance |
| DIRTY PANEL  | Long-term efficiency loss            |
| FAULT        | Unexpected mismatch                  |
| LOW LIGHT    | Night / very low irradiance          |

---

### Time-Based Intelligence

- Short deviations → ignored (e.g., passing clouds)
- Persistent deviations → flagged (e.g., dirt, faults)

Implements:
- Deviation counters
- Duration thresholds

---

### Multi-Node Comparison

Using `NodeID`, the system compares nodes under similar conditions:

- Detects underperforming panels
- Identifies zone-level issues
- Improves classification reliability

Example: 
```
Relative Score = Node Power / Average Power (all nodes)
```

---

## Sensor Stack

| Sensor | Measurement |
|--------|-------------|
| INA219 | Voltage, Current, Power |
| DHT11  | Temperature, Humidity |
| LDR    | Light / Irradiance |

**Communication:** NRF24L01+ (lab testing) → LoRa (field scale)

---

## Key Capabilities

- Fully edge-based intelligence (no cloud required)
- Context-aware multi-class classification
- Lightweight ML deployment (model → logic conversion)
- Multi-node comparison for improved accuracy
- Time-based anomaly filtering
- Scalable from single panel to solar park
- RTOS-based periodic task scheduling for non-blocking data acquisition

---

## Tech Stack

**Embedded**
- Arduino / Embedded C
- NRF24L01+

**Edge Analytics**
- Python (offline training)
- Scikit-learn (model development)
- Rule-based inference (on-device)

**Storage**
- CSV / SD card logging

---

## Development Roadmap

- [x] Sensor data acquisition
- [x] Packet protocol design
- [x] Multi-node wireless pipeline
- [x] Edge-based feature engineering
- [x] Regression + classification logic deployment
- [ ] Confidence scoring system
- [ ] Drift / degradation detection
- [ ] Visualization dashboard

---

## Why This Project Matters

This system demonstrates:

- Edge-deployed ML systems
- Interpretable decision logic
- Distributed IoT architecture
- Practical anomaly classification under real-world conditions

**It moves beyond data logging into actionable, on-device intelligence.**

---

## License

This project is licensed under the MIT License.