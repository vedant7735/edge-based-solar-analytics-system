# ⚡ Edge-Based Solar Analytics System

![Status](https://img.shields.io/badge/status-active%20development-blue)
![Platform](https://img.shields.io/badge/platform-embedded%20%7C%20edge-orange)
![License](https://img.shields.io/badge/license-MIT-green)

> A distributed edge intelligence system for solar panel monitoring — built to scale from a single smart node to a full solar park analytics network.

---

## What is this?

Most solar monitoring systems are passive loggers. This system is different — each node is a self-contained intelligent unit that acquires data, structures it, runs local ML, detects anomalies, and is designed from the ground up to scale into a distributed network without any redesign.

The architecture follows a single principle: **build one node right, and the park scales itself.**

---

## Single Node Architecture

Each node performs four roles independently:

### 1. Data Acquisition
Reads the full physical context of the panel:

| Sensor | Captures |
|--------|----------|
| Power (V × I) | Electrical output |
| Light intensity | Irradiance conditions |
| Temperature | Panel + ambient thermal state |
| Humidity | Environmental context |

### 2. Feature Structuring — Packet Design
Instead of raw unstructured sensor dumps, each node forms a clean, structured packet:

```
NodeID | Power | Temperature | Humidity | Light | Timestamp
```

This packet is:
- Efficient — minimal overhead
- Scalable — NodeID field makes multi-node expansion trivial
- Network-ready — drop-in compatible with any gateway or cloud
- Industry standard — structured for real deployments

Even with one node, the protocol is future-proof.

### 3. Local Intelligence (Edge ML)
The node runs ML directly on the embedded hardware — no cloud required:

**Time-series prediction:**
- Next output estimate
- Trend tracking
- Expected vs. actual comparison

**Anomaly detection:**
- Sudden output dips
- Overheating relative to output
- Weather-independent failures
- Degradation signatures

The node behaves like a smart sensor, not just a logger.

### 4. Logging & Analytics
- Data stored continuously to CSV on SD card
- Processed in real time on-device
- Ready for visualization or upstream ML pipelines

---

## What a Single Node Demonstrates

Even standalone, one node proves:

- Embedded systems design
- Sensor fusion (electrical + environmental)
- Time-series ML on edge hardware
- Anomaly detection
- Structured data protocols
- Edge intelligence without cloud dependency

This is a complete intelligent system — not a partial demo.

---

## Scaling to a Distributed Solar Park

This is where the `NodeID` field becomes powerful.

### Step 1 — Add Identical Nodes

```
Node 1 → Zone A
Node 2 → Zone B
Node 3 → Zone C
```

Same hardware. Same firmware. Different NodeID. No redesign required.

### Step 2 — Wireless Transmission

Packets flow to a central processor or gateway:

```
NodeID | Power | Temp | Humidity | Light | Timestamp
```

Now you can compare zones, average outputs, and detect spatial anomalies across the park.

### Step 3 — Distributed Intelligence Layer

With multiple nodes:
- **Distributed averaging** — park-level baseline generation
- **Relative anomaly detection** — one zone underperforming vs. others
- **Degradation tracking** — long-term cluster health monitoring

---

## Final Architecture

```
┌─────────────┐     ┌─────────────┐     ┌─────────────┐
│   Node A    │     │   Node B    │     │   Node C    │
│  sense +    │     │  sense +    │     │  sense +    │
│  predict +  │     │  predict +  │     │  predict +  │
│  detect     │     │  detect     │     │  detect     │
└──────┬──────┘     └──────┬──────┘     └──────┬──────┘
       │                   │                   │
       └───────────────────┼───────────────────┘
                           │
                  ┌────────▼────────┐
                  │  Edge Processor  │
                  │  park baseline   │
                  │  zone comparison │
                  │  anomaly fusion  │
                  └────────┬────────┘
                           │
                  ┌────────▼────────┐
                  │  (Optional)      │
                  │  Cloud / Viz     │
                  └─────────────────┘
```

| Layer | Role |
|-------|------|
| Data Nodes | Sensing, packet creation, local ML |
| Edge Processor | Prediction, anomaly detection, zone comparison |
| Cloud (optional) | Analytics, visualization, long-term storage |

---

## Tech Stack

- Embedded C / MicroPython (node firmware)
- Sensors: current/voltage, LDR, DHT/BME series
- Communication: UART / I2C / wireless (ESP32 / LoRa)
- ML: lightweight time-series models (on-device)
- Storage: CSV on SD card
- Visualization: Python + Matplotlib / dashboard (planned)

---

## Roadmap

- [x] Single node design — sensing + packet structure
- [x] Local time-series prediction
- [x] Anomaly detection (dips, overheating, weather-independent)
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
