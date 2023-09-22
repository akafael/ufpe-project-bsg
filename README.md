# BSG Project
[![](https://github.com/akafael/ufpe-project-bsg/actions/workflows/c-cpp.yml/badge.svg)](https://github.com/akafael/ufpe-project-bsg/actions/workflows/c-cpp.yml)

Belt Starter Generator project.

As our final project in this residency program, we were tasked with developing the control software for an automotive BSG (Belt Starter Generator). We decided to use this final project for the course as our starting point in development, by designing and applying all the tools that were introduced during the course.
Effective Supply Chain Management (SCM) practices and collaboration are not limited to physical components but also play a significant role in software engineering projects, particularly in the development of software systems for automotive applications like the Belt-Driven Starter Generator (BSG). This document outlines the SCM practices and collaboration methods employed during the software engineering phase of the BSG automotive project and discusses key insights gained.
An Automotive Belt Starter Generator (BSG) is a hybrid vehicle component that combines the functions of a starter motor and a generator into a single unit. It is typically connected to the engine via a belt drive system. The BSG serves two primary purposes in a vehicle:

Starting the Engine: When a vehicle is initially started, the BSG acts as a starter motor, providing the initial mechanical power to turn the engine's crankshaft and start the combustion process.
Generating Electricity: Once the engine is running, the BSG functions as a generator, producing electrical energy to charge the vehicle's battery and power various electrical systems within the vehicle, including lights, infotainment, and sensors. This electrical generation contributes to improved fuel efficiency and reduced emissions in hybrid and mild hybrid vehicles.

In summary, an automotive BSG plays a dual role as a starter and generator, contributing to both the starting and electrical power needs of a vehicle, ultimately enhancing its overall efficiency and performance.

## Requirements

 * Models: Matlab, Simulink
 * Source code: gcc
 * Coverage reports: lcov, gcovr
 * Documentation: Doxygen
 * SAST: pre-commit
 * Build: GNU make
 * Dependence management: git

## Folder Structure
 1. [REQ](req): requirements documents.
 2. [MODELS](models): Models.
 3. [CODE](code): Source code and unit tests
 4. [DOCS](docs): System documentation.
 5. [REF](ref): Datashet, whitepaper and other documents for reference.

## Setup

This project uses [Makefile](Makefile) for all build and automation steps.

### Build code

Build code using gcc and generate shared library.
```bash
make build
```

### Run tests

Build code and run tests:
```bash
make test
```

### Coverage

Generate coverage reports using gcov and lcov.

```bash
make clear && \
make test coverage
```

### Code documentation

Generate documentation using Doxygen.
```bash
make docs
```

### Troubleshout

To include new files in [utest.h](https://github.com/sheredom/utest.h) tests,run in your main directory:

```bash
git submodule update --init --recursive
```

To install Pre commit instance in branchs, run :

```bash
pip install pre-commit
pre-commit install -c .pre-commit-config.yaml
```

end of files error:

```bash
pre-commit run --all
```
