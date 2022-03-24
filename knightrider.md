# KNIGHTRIDER

Demonstrates the digital and analog output abilities of the K8055 Velleman USB Experiment board.

# Requirement
apt install libusb
and the libk8055 library (included here but best to get from the source: https://github.com/rm-hull/k8055)

#Build
```
gcc knightrider.c -o knightrider -lk8055 -lusb -lm
```gcc knightrider.c -o knightrider -lk8055 -lusb -lm

#run
```
gcc knightrider.c -o knightrider -lk8055 -lusb -lm
gcc knightrider.c -o knightrider -lk8055 -lusb -lm
```