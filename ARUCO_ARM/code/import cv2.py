import cv2
import cv2.aruco as aruco
import serial
import time

ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
time.sleep(2)

aruco_dict = aruco.getPredefinedDictionary(aruco.DICT_4X4_50)
parameters = aruco.DetectorParameters()

cap = cv2.VideoCapture(0)

last_sent_id = None          # store last sent ID
waiting_for_done = False     # block sending new ID until done

while True:
    ret, frame = cap.read()
    if not ret:
        break

    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    corners, ids, _ = aruco.detectMarkers(gray, aruco_dict, parameters=parameters)

    # ------------------------------
    # Listen for DONE from Arduino
    # ------------------------------
    if ser.in_waiting > 0:
        msg = ser.readline().decode().strip()
        if msg == "DONE":
            print("Arduino finished task.")
            waiting_for_done = False     # allow new ID to be sent
            last_sent_id = None          # reset ID

    # ------------------------------
    # If ArUco detected AND ready to send
    # ------------------------------
    if ids is not None and not waiting_for_done:
        detected_id = int(ids[0][0])

        # Send only if new ID (not repeatedly)
        if detected_id != last_sent_id:
            ser.write(f"{detected_id}\n".encode())
            print("Sent ID:", detected_id)

            last_sent_id = detected_id
            waiting_for_done = True      # wait until Arduino replies DONE

    cv2.imshow("Aruco", frame)

    if cv2.waitKey(1) & 0xFF == 27:
        break

cap.release()
cv2.destroyAllWindows()
