# ⚡ Edge-Based Solar Analytics System

> A scalable distributed solar monitoring and analytics platform combining edge sensing, cloud ML, and zone-level anomaly detection.

---

## 🚀 Overview

Most solar monitoring systems act as passive data loggers. This project introduces a **distributed edge intelligence architecture** where each node actively structures sensor data and contributes to a scalable analytics network.

The system is designed to scale seamlessly:
> **Build one node correctly — scale to an entire solar park without redesign.**

---

## 🧱 System Architecture

The platform is composed of three intelligence layers:

### 1️⃣ Data Nodes — Sensing Layer

Each Data Node is responsible for reading electrical and environmental sensors, structuring data into fixed packets, tagging data with a unique `NodeID`, and transmitting to the controller.

**Packet Format:**
```
NodeID | Voltage | Current | Power | Temperature | Humidity | Light | Timestamp
```

> Initial prototyping uses **Arduino Mega** (for easier debugging). Final scalable nodes migrate to **ATtiny85**.

---

### 2️⃣ Main Node — Controller Layer

The Main Node receives packets from multiple Data Nodes, logs structured data locally (CSV / SD card), forwards data to the cloud API, and maintains multi-node synchronization.

---

### 3️⃣ Cloud Analytics Layer

- Stores incoming sensor streams
- Trains ML models on historical data
- Detects output anomalies, temperature-performance mismatches, zone underperformance, and long-term degradation
- Serves results to dashboard / API

---

## 📡 Sensor Stack

| Sensor | Measurement |
|--------|-------------|
| INA219 | Voltage, Current, Power |
| DHT11 | Temperature, Humidity |
| LDR | Light / Irradiance |

**Communication:** NRF24L01+ (lab testing) → LoRa (field scale)

---

## 🌐 Multi-Node Scaling Logic

Adding nodes requires no redesign:

```
Node 01 → Zone A
Node 02 → Zone B
Node 03 → Zone C
```

All analytics leverage `NodeID` for zone-level baselines, relative anomaly detection, and park-wide performance metrics.

---

## 📈 Key Capabilities

- ✅ Distributed node architecture
- ✅ Structured packet protocol
- ✅ Multi-zone performance comparison
- ✅ Cloud-based ML training & inference
- ✅ Anomaly detection
- ✅ Degradation tracking
- ✅ Scalable from single panel to solar park

---

## 🔧 Tech Stack

**Embedded**
- Arduino / Embedded C
- NRF24L01+ / LoRa

**Cloud & ML**
- Python
- Pandas, Scikit-learn
- REST API
- Time-series analytics

**Storage & Visualization**
- CSV / Database
- Dashboard *(planned)*

---

## 🛣 Development Roadmap

- [x] Sensor data acquisition
- [x] Packet protocol design
- [x] Single-node logging
- [x] Wireless multi-node pipeline
- [ ] Cloud ingestion API
- [ ] ML anomaly engine
- [ ] Zone comparison analytics
- [ ] Real-time dashboard
- [ ] Long-term degradation models

---

## 📌 Why This Project Matters

This system demonstrates real distributed embedded design, edge-to-cloud ML pipelines, scalable IoT architecture, and intelligent solar analytics.

**It is not a sensor demo — it is a full monitoring platform.**

---

## 📜 License

This project is licensed under the [MIT License](LICENSE).