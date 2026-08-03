# Project History

## Introduction

This document captures the evolution of the UAV Platform project, from its initial conception to its current implementation. Rather than serving as a changelog, it documents the reasoning, design decisions, lessons learned, and major milestones that shaped the project.

The objective is to preserve not only what was built, but also why certain decisions were made, how the architecture evolved, and what engineering principles guided the development. This document will continue to evolve throughout the lifecycle of the project.

---

# Phase 1 – Initial Motivation

The project did not begin with the intention of building a competition drone or a final-year engineering project. Instead, it originated from a much broader question:

> *How should an autonomous UAV software system be architected so that it remains modular, scalable, reusable, and suitable for research as well as industrial applications?*

While developing UAVs for student competitions, it became evident that most software architectures were highly application-specific. Components were tightly coupled, difficult to extend, and often rewritten for every new mission.

This led to the realization that a UAV should be viewed as a robotic platform rather than simply an aircraft. The companion computer should therefore be capable of managing perception, mission logic, communication, autonomy, and future capabilities through a layered software architecture instead of a collection of standalone scripts.

The long-term vision became the development of a reusable UAV software platform that could serve as the foundation for multiple autonomous missions.

---

# Phase 2 – Competition Experience

Participation in autonomous UAV competitions provided practical experience with real-world autonomous systems and exposed several challenges that are often overlooked in classroom projects.

These included:

- System integration between multiple hardware components.
- Reliable communication between the flight controller and companion computer.
- GPS-based navigation.
- Mission execution.
- Sensor integration.
- Autonomous payload delivery.
- Precision landing.
- Field testing and validation.

More importantly, these competitions demonstrated that software architecture often becomes the limiting factor as mission complexity increases.

This experience motivated a shift from building a competition-specific solution toward designing a modular autonomy platform.

---

# Phase 3 – Research and Architectural Exploration

Following the competition phase, significant effort was invested in studying existing robotics software ecosystems and industrial practices.

Areas explored included:

- Robot Operating System (ROS 2)
- MAVROS
- MAVSDK
- ArduPilot ecosystem
- PX4 ecosystem
- Robotics middleware
- Modular robotics architectures
- Companion computer frameworks
- Software design patterns for autonomous systems

During this phase, the focus shifted away from writing code and toward understanding how modern robotic systems are architected.

The objective became identifying an architecture capable of supporting future expansion without requiring fundamental redesign.

---

# Current Status

The project has now transitioned from concept exploration into implementation.

A layered ROS 2 software architecture has been established as the foundation of the platform.

Current implemented subsystems include:

- Vehicle Interface
- Operational State Engine
- Mission Supervisor
- UAV Interface Messages
- UAV Bringup Package
- MAVROS Integration

The platform is now capable of communicating with the flight controller, acquiring vehicle telemetry, publishing internal vehicle status, and supporting higher-level autonomous decision-making through modular software components.

This marks the completion of the initial platform foundation and the beginning of autonomous mission development.

---

# Future Evolution

Future development will expand the platform with perception, planning, navigation, precision landing, computer vision, communication, AI acceleration, and autonomous mission execution.

Rather than developing isolated features, every new capability will be integrated into the existing architecture while maintaining modularity, scalability, and maintainability.

The long-term objective is to evolve this repository into a reusable UAV companion computer framework suitable for research, industrial prototyping, and autonomous aerial robotics.
