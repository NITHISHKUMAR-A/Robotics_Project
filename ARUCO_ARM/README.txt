# ArUco Marker Trigger System (Python + Arduino Nano)

This project implements a complete ArUco-based automation workflow using:

- **Python + OpenCV** for ArUco marker detection  
- **Serial Communication (USB)** for sending marker IDs  
- **Arduino Nano** to execute tasks based on detected IDs  
- A **handshake protocol** (`ID → DONE`) to prevent continuous sending

The system detects an ArUco marker, sends its ID only *once* to the Arduino, waits until the Arduino completes its task, and only then sends the next detected ID.

---

## 📸 System Workflow

1. Laptop detects an ArUco marker using webcam  
2. Python sends the marker ID **one time** through USB  
3. Arduino receives the ID and runs a specific task  
4. When finished, Arduino sends back **`DONE`**  
5. Python receives `DONE` and allows sending the next ID  

This ensures stable automation without repeated triggers.

---

## 🛠 Requirements

### Python
- Python 3.x  
- OpenCV with ArUco module  
- PySerial  

Install dependencies:

```bash
pip install opencv-python pyserial

