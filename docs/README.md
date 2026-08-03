# UAV Platform

*A modular companion computer software platform for autonomous UAVs built using ROS 2, MAVROS and ArduPilot.*

---

## Overview

UAV Platform is an ongoing engineering project focused on developing a modular, scalable and reusable autonomy framework for unmanned aerial vehicles (UAVs).

Rather than developing software for a single competition or mission, this repository aims to establish a reusable software architecture capable of supporting multiple autonomous capabilities through well-defined software layers.

The project follows industrial software engineering principles to ensure that new features can be integrated without redesigning the entire system.

---

## Why this project?

Many student UAV projects evolve into collections of tightly coupled scripts that become increasingly difficult to maintain as mission complexity grows.

This project takes a different approach.

The objective is to build a layered autonomy stack in which every subsystem has a clearly defined responsibility and communicates through standardized interfaces.

The emphasis is placed on architecture before implementation.

---

## Project Objectives

- Build a reusable companion computer framework for autonomous UAVs.
- Develop modular ROS 2 software components.
- Support multiple autonomous missions through reusable software layers.
- Enable future integration of AI, computer vision and advanced navigation.
- Apply industrial software engineering practices throughout development.

---

## Current Architecture

```
Mission Supervisor
        │
        ▼
Operational State Engine
        │
        ▼
Vehicle Interface
        │
        ▼
MAVROS
        │
        ▼
ArduPilot
        │
        ▼
Flight Controller
```

Each layer performs a single responsibility while remaining independent from the implementation details of the layers below it.

---

## Current Features

- ROS 2 Humble workspace
- MAVROS integration
- Automatic MAVLink stream rate initialization
- Vehicle telemetry interface
- Operational State Engine
- Mission Supervisor
- Unified UAV interface messages
- Modular launch system
- GitHub-based documentation

---

## Planned Capabilities

- Mission execution
- Precision landing
- QR code detection
- Visual servoing
- Multi-camera perception
- LiDAR integration
- AI accelerator integration
- Autonomous navigation
- Obstacle avoidance
- Remote telemetry
- Cloud connectivity
- Swarm-ready architecture

---

## Repository Structure

```
docs/
src/
launch/
scripts/
```

Additional documentation describing the architecture, hardware, development history and subsystem design is available in the `docs/` directory.

---

## Development Philosophy

This project is developed with the belief that autonomous UAV software should be designed as an extensible robotics platform rather than a mission-specific implementation.

Every design decision prioritizes:

- Modularity
- Scalability
- Reliability
- Maintainability
- Testability

---

## Project Status

🚧 Active Development

The current phase focuses on establishing a robust software foundation before integrating perception, navigation and autonomous mission capabilities.

---

## License

This repository is released under the MIT License.
