# MPU Unmanned Aerial Vehicle

This project implements the software for an **Unmanned Aerial Vehicle (UAV)**, focusing on modularity, thread-safe communication, and real-time control. The system is designed to manage various components such as the flight controller, payload manager, sensor manager, and telemetry systems.

---

## **Requirements**

To build and run this project, you will need the following:

- **C++ Compiler**: A C++17-compatible compiler (e.g., GCC, Clang, or MSVC).
- **CMake**: Version 3.15 or higher.
- **Operating System**: Linux.
- **Development Tools**: Git for version control and a terminal for running commands.

- ***IMPORTANT***: All the Yocto project and build files are in a seperate git repo!!! ShayanEram/MPU_Linux-Drivers

---

## **Installation and Setup**

1. Clone the repository:
   ```sh
   git clone https://github.com/your-repo/MPU_Unmanned-Aerial-Vehicle.git
   cd MPU_Unmanned-Aerial-Vehicle
   ```

2. Install the required dependencies (if any). Ensure that CMake and a compatible compiler are installed on your system.

3. Configure the project using CMake:
   ```sh
   cmake -S . -B build
   ```

---

## **Building the Application**

1. Build the project using CMake:
   ```sh
   cmake --build build
   ```

2. Locate the executables in the [`build/`] directory.

3. Run the application:
   ```sh
   ./build/UAV
   ```

---

## **Expected Results**

When you run the application, the following components will be initialized and executed:

1. **Flight Controller**:
   - Periodically retrieves data from the battery, motor, remote controller, and sensors using asynchronous mechanisms.
   - Logs the status of the UAV to the console.

2. **Payload Manager**:
   - Manages payload operations and notifies the flight controller of updates using the `Observer<PayloadData>` mechanism.
   - Logs payload actions and IDs when updates occur.

3. **Sensor Manager**:
   - Collects and processes data from onboard sensors.
   - Publishes sensor data to a `MessageQueue<SensorData>` for other modules to consume.

4. **Telemetry System**:
   - Sends telemetry data to external systems for monitoring and analysis.

### **Example Output**
When the application is running, you can expect logs similar to the following:

```plaintext
FlightController running
Payload action: Drop
Payload ID: 42
FlightController running
```

If an error occurs during execution, the application will log the error and terminate with an appropriate error code.

---

## **Project Structure**

```
build/
    x64-debug/
CMakeLists.txt
CMakePresets.json
Inc/
    BatteryManager.hpp
    FlightController.hpp
    InterData.hpp
    main.hpp
    MessageQueue.hpp
    MotorController.hpp
    Observer.hpp
    PayloadManager.hpp
    RemoteController.hpp
    SensorManager.hpp
    SharedResource.hpp
    TelemetryManager.hpp
    ThreadManager.hpp
README.md
Src/
    BatteryManager.cpp
    FlightController.cpp
    main.cpp
    MotorController.cpp
    PayloadManager.cpp
    RemoteController.cpp
    SensorManager.cpp
    ...
```

### **Key Components**
- **Flight Controller**: Manages UAV operations, including motor control, battery monitoring, and remote commands.
- **Payload Manager**: Handles payload operations and communicates updates to the flight controller.
- **Sensor Manager**: Collects and processes sensor data for use by other modules.
- **Shared Resources and Communication**:
  - `SharedResource`: Provides thread-safe access to shared data.
  - `MessageQueue`: Implements a thread-safe queue for inter-thread communication.
  - `Observer`: Implements the observer pattern for event-driven communication between modules.
