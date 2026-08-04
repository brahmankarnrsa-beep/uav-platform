# Platform Core Architecture

## Purpose

The Platform Core package forms the foundation of the UAV Platform software architecture.

Its purpose is to provide reusable infrastructure that is common across all software modules while keeping mission logic and hardware-specific implementations independent.

Rather than implementing the same functionality repeatedly inside every ROS 2 node, Platform Core provides a common framework that all managers inherit from or utilize.

The goal is to ensure consistency, maintainability, scalability and reliability throughout the software platform.

---

# Software Layering

The software platform follows a layered architecture.

```
Applications
│
├── Mission Supervisor
│
├── Operational State Engine
│
────────────────────────────────────

Service Layer

├── Perception
├── Navigation
├── Communication
├── Diagnostics
├── Logging

────────────────────────────────────

Hardware Manager Layer

├── Camera Manager
├── LiDAR Manager
├── AI Manager
├── Communication Manager
├── Vehicle Interface

────────────────────────────────────

Platform Core

├── BaseManager
├── ParameterManager
├── Logger
├── Heartbeat
├── Diagnostics
├── Watchdog
├── Utilities

────────────────────────────────────

ROS 2 Middleware

────────────────────────────────────

Linux Operating System

────────────────────────────────────

Hardware
```

Each layer has clearly defined responsibilities.

Higher layers never communicate directly with hardware.

Hardware-specific implementations are isolated inside the Hardware Manager Layer.

---

# Design Philosophy

Platform Core exists to prevent duplication.

Every subsystem should focus only on its own responsibility.

Common functionality should exist only once.

Examples include:

- Parameter loading
- Diagnostics
- Heartbeat publishing
- Logging
- Lifecycle management
- Error handling
- Watchdog mechanisms

---

# BaseManager

Every manager within the platform should inherit from BaseManager.

The BaseManager provides:

- Node initialization
- Common startup sequence
- Periodic update loop
- Standard shutdown interface
- Common timer infrastructure

Each derived manager implements only:

- initialize()
- update()
- shutdown()

This minimizes duplicated code and establishes a consistent lifecycle for all managers.

---

# ParameterManager

The ParameterManager is responsible for loading and managing configuration values.

No hardware-specific constants should be hardcoded within the source code.

Examples include:

- Camera resolution
- Camera frame rate
- Serial port names
- Baud rates
- Communication parameters
- Network settings
- AI model locations

All configuration should reside within YAML files.

---

# Logger

Platform Core will eventually provide a unified logging framework.

Rather than allowing each module to implement independent logging styles, every subsystem should use the same logging interface.

Future capabilities include:

- Log levels
- Timestamped logging
- File logging
- Remote logging
- Structured log formatting

---

# Heartbeat Framework

Every manager should periodically publish its operational status.

The heartbeat framework enables higher-level software to determine whether each subsystem is functioning correctly.

Heartbeat information may include:

- Alive status
- Timestamp
- Current state
- Error code
- Health status

Mission Supervisor should rely on heartbeat information instead of assuming every subsystem is operational.

---

# Diagnostics Framework

Diagnostics provide continuous visibility into platform health.

Future diagnostics include:

- CPU usage
- Memory usage
- Temperature
- Processing frequency
- Sensor status
- Communication status
- Frame rates
- AI inference timing

---

# Watchdog

Each subsystem should be monitored independently.

When possible, failures should be recovered locally.

Example:

Camera Manager fails

↓

Restart Camera Manager

↓

Continue Mission

instead of restarting the complete software stack.

---

# Engineering Principles

Platform Core follows several principles.

- Single Responsibility Principle
- Separation of Concerns
- Reusability
- Scalability
- Reliability
- Maintainability
- Hardware Abstraction

These principles guide every future software component developed within the UAV Platform.

---

# Future Evolution

Platform Core will continue to evolve throughout the project.

Future additions include:

- Lifecycle Management
- Plugin Framework
- Component Registry
- Resource Manager
- Performance Monitor
- Time Synchronization
- Memory Pool Management
- Inter-Manager Communication Utilities

The long-term objective is to establish Platform Core as the reusable foundation upon which every autonomous capability within the UAV Platform is built.
