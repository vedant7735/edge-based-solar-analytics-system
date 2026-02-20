# ⚡ Edge-Based Solar Analytics System

![Status](https://img.shields.io/badge/status-active%20development-blue)
![Platform](https://img.shields.io/badge/platform-embedded%20%7C%20edge-orange)
![License](https://img.shields.io/badge/license-MIT-green)

> A distributed edge intelligence system for solar panel monitoring — built to scale from a single smart node to a full solar park analytics network.

---

## What is this?

Most solar monitoring systems are passive loggers. This system is different — each data node is a self-contained unit that acquires sensor data, structures it into a clean packet, and transmits it to a main node for local ML, anomaly detection, and analytics. The architecture is designed from the ground up to scale into a distributed network without any redesign.

The architecture follows a single principle: **build one node right, and the park scales itself.**

---

## Node Architecture

The system splits responsibilities across two tiers of hardware:

### Data Node — ATtiny85
The data node is intentionally minimal. Its only job is to:
- Read sensors (power, temperature, humidity, light)
- Structure the readings into a clean, labeled packet
- Stamp it with a unique `NodeID`
- Transmit it to the Main Node

```
NodeID | Power | Temperature | Humidity | Light | Timestamp
```

This keeps the data node lean, low-power, and cheap — purpose-built for sensing and packet scheduling, nothing more.

### Main Node — Arduino Mega
The main node is the intelligence layer. It:
- Receives structured packets from one or more Data Nodes
- Runs pre-trained model inference on-device — model trained offline on logged data, coefficients flashed onto hardware
- Performs anomaly detection
- Logs data to CSV on SD card
- Is ready to forward data upstream to an edge processor or cloud

**Local ML capabilities:**
- Next output estimate (time-series prediction)
- Trend tracking and expected vs. actual comparison
- Sudden output dip detection
- Overheating relative to output
- Weather-independent failure signatures
- Degradation detection over time

---

## Sensor Stack (per Data Node)

| Sensor | Captures |
|--------|----------|
| INA219 | Voltage, current, and power (computed internally via I2C) |
| LDR | Light / irradiance conditions |
| DHT11 | Temperature + humidity |

**Communication:** NRF24L01+ (lab) / LoRa (field deployment)

---

## What a Single Node Pair Demonstrates

Even with one Data Node + one Main Node, the system proves:

- Embedded systems design across two hardware tiers
- Sensor fusion (electrical + environmental)
- Structured packet protocol with NodeID field
- Time-series ML on edge hardware
- Anomaly detection without cloud dependency
- Scalable architecture ready for multi-node expansion

This is a complete intelligent system — not a partial demo.

---

## Scaling to a Distributed Solar Park

This is where the `NodeID` field becomes load-bearing.

### Step 1 — Add Identical Data Nodes

```
Data Node 1 (NodeID: 01) → Zone A
Data Node 2 (NodeID: 02) → Zone B
Data Node 3 (NodeID: 03) → Zone C
```

Same hardware. Same firmware. Different NodeID. No redesign required.

### Step 2 — Packets Flow to Main Node

```
NodeID | Power | Temp | Humidity | Light | Timestamp
```

The Main Node receives tagged packets from all zones, enabling cross-zone comparison and park-level baselines.

### Step 3 — Distributed Intelligence Layer

With multiple Data Nodes feeding one Main Node:
- **Distributed averaging** — park-level baseline generation
- **Relative anomaly detection** — one zone underperforming vs. others
- **Degradation tracking** — long-term cluster health monitoring

---

## Full Architecture

```
┌──────────────┐     ┌──────────────┐     ┌──────────────┐
│  Data Node A │     │  Data Node B │     │  Data Node C │
│  ATtiny85    │     │  ATtiny85    │     │  ATtiny85    │
│              │     │              │     │              │
│  sense →     │     │  sense →     │     │  sense →     │
│  structure → │     │  structure → │     │  structure → │
│  transmit    │     │  transmit    │     │  transmit    │
└──────┬───────┘     └──────┬───────┘     └──────┬───────┘
       │                    │                    │
       └────────────────────┼────────────────────┘
                            │  NRF24L01+ / LoRa
                   ┌────────▼────────┐
                   │   Main Node     │
                   │  Arduino Mega   │
                   │                 │
                   │  receive +      │
                   │  predict +      │
                   │  detect +       │
                   │  log            │
                   └────────┬────────┘
                            │
                   ┌────────▼────────┐
                   │  Edge Processor │
                   │  park baseline  │
                   │  zone compare   │
                   │  anomaly fusion │
                   └────────┬────────┘
                            │
                   ┌────────▼────────┐
                   │  (Optional)     │
                   │  Cloud / Viz    │
                   └─────────────────┘
```

| Layer | Hardware | Role |
|-------|----------|------|
| Data Nodes | ATtiny85 | Sensing, packet structuring, transmission |
| Main Node | Arduino Mega | Packet ingestion, local ML, anomaly detection, logging |
| Edge Processor | TBD | Park baseline, zone comparison, anomaly fusion |
| Cloud (optional) | — | Analytics, visualization, long-term storage |

---

## Tech Stack

- Embedded C / Arduino (node firmware)
- Sensors: INA219, LDR, DHT11
- Communication: NRF24L01+ (lab) / LoRa (field)
- ML: lightweight time-series models (on-device, Main Node)
- Storage: CSV on SD card
- Visualization: Python + Matplotlib / dashboard (planned)

---

## Roadmap

- [x] Single node design — sensing + packet structure
- [x] Local time-series prediction
- [x] Anomaly detection (dips, overheating, weather-independent)
- [ ] ATtiny85 → Mega wireless packet pipeline
- [ ] Multi-node wireless transmission
- [ ] Park-level baseline and zone comparison
- [ ] Degradation tracking over time
- [ ] Dashboard visualization

---

## Status

**Active development.** Single node architecture complete and functional. Multi-node distributed layer in progress.

---

## License

MIT
