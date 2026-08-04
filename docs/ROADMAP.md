# UAV Platform Roadmap

This document tracks the long-term development of the UAV Platform.

The roadmap is organized into engineering milestones rather than individual coding tasks.

---

# Phase 0 — Foundation ✅

- [x] ROS 2 Workspace
- [x] GitHub Repository
- [x] Documentation Framework
- [x] UAV Interfaces
- [x] Vehicle Interface
- [x] Operational State Engine
- [x] Mission Supervisor
- [x] UAV Bringup
- [x] Platform Core Package

---

# Phase 1 — Platform Core

## Core Framework

- [x] BaseManager (Initial)
- [ ] ParameterManager
- [ ] Logger
- [ ] Heartbeat Framework
- [ ] Diagnostics Framework
- [ ] Watchdog
- [ ] Lifecycle Management
- [ ] Exception Framework

---

# Phase 2 — Hardware Managers

## Vehicle

- [x] Vehicle Interface
- [ ] Vehicle Commands
- [ ] Vehicle Health Monitor

## Camera

- [ ] Camera Manager
- [ ] IMX708 Integration
- [ ] HQ Camera Integration
- [ ] Multi-camera Support

## LiDAR

- [ ] STL-19 Integration
- [ ] Scan Processing
- [ ] Obstacle Publisher

## AI

- [ ] Hailo Runtime
- [ ] Model Loader
- [ ] Inference Manager

## Communication

- [ ] SIM7600 Integration
- [ ] Internet Connectivity
- [ ] VPN
- [ ] Telemetry Streaming

---

# Phase 3 — Perception

- [ ] QR Detection
- [ ] QR Decoding
- [ ] Target Localization
- [ ] Visual Servoing
- [ ] Object Detection
- [ ] Camera Calibration

---

# Phase 4 — Navigation

- [ ] Local Planner
- [ ] Obstacle Avoidance
- [ ] Precision Landing
- [ ] Waypoint Navigation
- [ ] Recovery Behaviours

---

# Phase 5 — Mission Layer

- [ ] Mission Sequencer
- [ ] Search Mission
- [ ] Landing Mission
- [ ] Payload Mission
- [ ] Autonomous Recovery

---

# Phase 6 — Validation

- [ ] Unit Testing
- [ ] Integration Testing
- [ ] Hardware-in-the-Loop
- [ ] Field Testing
- [ ] Performance Benchmarking

---

# Phase 7 — Optimization

- [ ] CPU Optimization
- [ ] AI Acceleration
- [ ] Memory Optimization
- [ ] Thermal Optimization
- [ ] Power Optimization

---

# Long-Term Vision

The objective is to develop a modular UAV autonomy framework that can be reused across multiple aircraft, missions and research projects while maintaining a clean, scalable and maintainable software architecture.
