# Comandos de tarea

### Actividad 1: Listar dispositivos conectados

¿Qué tipos de dispositivos se muestran en la salida de `lsblk`?

Tengo un disco de 23 GB en mi sistema, en el cual está instalado el sistema operativo. Este disco tiene una pequeña partición de 1 MB y una partición principal de 23 GB. Además, tengo varias aplicaciones instaladas en un formato llamado Snap, que se encuentran montadas en mi sistema. Estas aplicaciones incluyen Firefox y otras herramientas del sistema. También hay una unidad virtual montada, que está relacionada con las herramientas de VirtualBox para mejorar la interacción entre mi sistema y la máquina virtual. Todo esto permite que mi sistema funcione de manera eficiente dentro de la máquina virtual.

```
eduardo-vargas@lalovglz-VirtualBox:~$ lsblk
NAME   MAJ:MIN RM   SIZE RO TYPE MOUNTPOINTS
loop0    7:0    0     4K  1 loop /snap/bare/5
loop1    7:1    0   273M  1 loop /snap/firefox/5273
loop2    7:2    0 273,7M  1 loop /snap/firefox/5437
loop3    7:3    0  73,9M  1 loop /snap/core22/1663
loop4    7:4    0  73,9M  1 loop /snap/core22/1722
loop5    7:5    0  10,7M  1 loop /snap/firmware-updater/127
loop6    7:6    0  11,1M  1 loop /snap/firmware-updater/147
loop7    7:7    0 505,1M  1 loop /snap/gnome-42-2204/176
loop8    7:8    0  91,7M  1 loop /snap/gtk-common-themes/1535
loop9    7:9    0  10,8M  1 loop /snap/snap-store/1244
loop10   7:10   0  38,8M  1 loop /snap/snapd/21759
loop11   7:11   0  10,7M  1 loop /snap/snap-store/1218
loop12   7:12   0  44,3M  1 loop /snap/snapd/23258
loop13   7:13   0   500K  1 loop /snap/snapd-desktop-integration/178
loop14   7:14   0   568K  1 loop /snap/snapd-desktop-integration/253
sda      8:0    0    23G  0 disk 
├─sda1   8:1    0     1M  0 part 
└─sda2   8:2    0    23G  0 part /
sr0     11:0    1  56,9M  0 rom  /media/eduardo-vargas/VBox_GAs_7.1.4 
```


¿Cuál es la diferencia entre `lsusb` y `lspci`?

El comando lsusb me muestra los dispositivos que tengo conectados a los puertos USB de mi sistema. En mi caso, veo un hub USB y un dispositivo llamado VirtualBox USB Tablet, que es algo relacionado con la máquina virtual que estoy usando.

El comando lspci me muestra los dispositivos internos de mi computadora, como la tarjeta gráfica, el controlador de red y algunos otros componentes que están conectados directamente a la placa base.

En resumen, lsusb muestra los dispositivos USB (externos y virtuales), mientras que lspci me da información sobre los dispositivos internos de mi computadora.

```
eduardo-vargas@lalovglz-VirtualBox:~$ lsusb
Bus 001 Device 001: ID 1d6b:0001 Linux Foundation 1.1 root hub
Bus 001 Device 002: ID 80ee:0021 VirtualBox USB Tablet
Bus 002 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub
eduardo-vargas@lalovglz-VirtualBox:~$ lspci
00:00.0 Host bridge: Intel Corporation 440FX - 82441FX PMC [Natoma] (rev 02)
00:01.0 ISA bridge: Intel Corporation 82371SB PIIX3 ISA [Natoma/Triton II]
00:01.1 IDE interface: Intel Corporation 82371AB/EB/MB PIIX4 IDE (rev 01)
00:02.0 VGA compatible controller: VMware SVGA II Adapter
00:03.0 Ethernet controller: Intel Corporation 82540EM Gigabit Ethernet Controller (rev 02)
00:04.0 System peripheral: InnoTek Systemberatung GmbH VirtualBox Guest Service
00:05.0 Multimedia audio controller: Intel Corporation 82801AA AC'97 Audio Controller (rev 01)
00:06.0 USB controller: Apple Inc. KeyLargo/Intrepid USB
00:07.0 Bridge: Intel Corporation 82371AB/EB/MB PIIX4 ACPI (rev 08)
00:0b.0 USB controller: Intel Corporation 82801FB/FBM/FR/FW/FRW (ICH6 Family) USB2 EHCI Controller
00:0d.0 SATA controller: Intel Corporation 82801HM/HEM (ICH8M/ICH8M-E) SATA Controller [AHCI mode] (rev 02)
```

¿Qué información adicional proporciona `dmesg | grep usb`?

El comando dmesg | grep usb me proporciona información adicional sobre los dispositivos USB conectados a mi sistema. Me muestra cuándo un dispositivo USB es detectado, junto con detalles como el ID del fabricante y del producto, lo que me ayuda a identificar el dispositivo. También puedo ver si se han cargado controladores necesarios para el funcionamiento de estos dispositivos, como los de entrada (ratones, teclados) o de almacenamiento. Además, me indica si un dispositivo ha sido conectado o desconectado del sistema, brindando un seguimiento de los eventos relacionados con los puertos USB.
```
eduardo-vargas@lalovglz-VirtualBox:~$ sudo dmesg | grep usb
[sudo] contraseña para eduardo-vargas: 
[    0.742834] usbcore: registered new interface driver usbfs
[    0.742838] usbcore: registered new interface driver hub
[    0.742841] usbcore: registered new device driver usb
[    0.957049] usb usb1: New USB device found, idVendor=1d6b, idProduct=0001, bcdDevice= 6.08
[    0.957049] usb usb1: New USB device strings: Mfr=3, Product=2, SerialNumber=1
[    0.957049] usb usb1: Product: OHCI PCI host controller
[    0.957049] usb usb1: Manufacturer: Linux 6.8.0-49-generic ohci_hcd
[    0.957049] usb usb1: SerialNumber: 0000:00:06.0
[    0.969865] usb usb2: New USB device found, idVendor=1d6b, idProduct=0002, bcdDevice= 6.08
[    0.969867] usb usb2: New USB device strings: Mfr=3, Product=2, SerialNumber=1
[    0.969868] usb usb2: Product: EHCI Host Controller
[    0.969869] usb usb2: Manufacturer: Linux 6.8.0-49-generic ehci_hcd
[    0.969870] usb usb2: SerialNumber: 0000:00:0b.0
[    1.298587] usb 1-1: new full-speed USB device number 2 using ohci-pci
[    1.546703] usb 1-1: New USB device found, idVendor=80ee, idProduct=0021, bcdDevice= 1.00
[    1.546709] usb 1-1: New USB device strings: Mfr=1, Product=3, SerialNumber=0
[    1.546710] usb 1-1: Product: USB Tablet
[    1.546711] usb 1-1: Manufacturer: VirtualBox
[    1.756420] usbcore: registered new interface driver usbhid
[    1.756429] usbhid: USB HID core driver
[    1.759386] input: VirtualBox USB Tablet as /devices/pci0000:00/0000:00:06.0/usb1/1-1/1-1:1.0/0003:80EE:0021.0001/input/input6
[    1.759502] hid-generic 0003:80EE:0021.0001: input,hidraw0: USB HID v1.10 Mouse [VirtualBox USB Tablet] on usb-0000:00:06.0-1/input0
[    6.375146] Modules linked in: snd rapl(+) vmwgfx(+) drm_ttm_helper vboxguest(OE) ttm joydev i2c_piix4 soundcore binfmt_misc input_leds mac_hid serio_raw sch_fq_codel msr parport_pc ppdev lp parport efi_pstore nfnetlink dmi_sysfs ip_tables x_tables autofs4 hid_generic usbhid hid ahci psmouse crc32_pclmul video libahci wmi e1000 pata_acpi
```


### Actividad 2: Verificar dispositivos de almacenamiento

¿Qué dispositivos de almacenamiento están conectados a mi sistema? 

En mi sistema están conectados varios dispositivos de almacenamiento, incluyendo discos virtuales como /dev/sda (un disco de 23GB) y unidades de tipo loop que corresponden a las aplicaciones de snap. También tengo un dispositivo de medios ópticos /dev/sr0, que es una unidad de CD-ROM, montada como "VBox_GAs_7.1.4".

¿Qué particiones están montadas actualmente? 

Las particiones montadas actualmente en mi sistema son:

    /dev/sda2, que es la partición principal de 23GB donde está instalado el sistema operativo, y está montada como "/".
    /dev/sr0, que es un dispositivo de medios ópticos montado en /media/eduardo-vargas/VBox_GAs_7.1.4.

¿Qué tipo de sistemas de archivos se usan en las particiones? 

El sistema de archivos utilizado en la partición /dev/sda2 es ext4, que es el sistema estándar para la mayoría de las distribuciones de Linux. La partición /dev/sr0 utiliza el sistema de archivos iso9660, que es común para los discos de solo lectura y las imágenes ISO.

```
eduardo-vargas@lalovglz-VirtualBox:~$ sudo fdisk -l
[sudo] contraseña para eduardo-vargas: 
Disco /dev/loop0: 4 KiB, 4096 bytes, 8 sectores
Unidades: sectores de 1 * 512 = 512 bytes
Tamaño de sector (lógico/físico): 512 bytes / 512 bytes
Tamaño de E/S (mínimo/óptimo): 512 bytes / 512 bytes


Disco /dev/loop1: 272,98 MiB, 286236672 bytes, 559056 sectores
Unidades: sectores de 1 * 512 = 512 bytes
Tamaño de sector (lógico/físico): 512 bytes / 512 bytes
Tamaño de E/S (mínimo/óptimo): 512 bytes / 512 bytes


Disco /dev/loop2: 273,68 MiB, 286969856 bytes, 560488 sectores
Unidades: sectores de 1 * 512 = 512 bytes
Tamaño de sector (lógico/físico): 512 bytes / 512 bytes
Tamaño de E/S (mínimo/óptimo): 512 bytes / 512 bytes


Disco /dev/loop3: 73,88 MiB, 77463552 bytes, 151296 sectores
Unidades: sectores de 1 * 512 = 512 bytes
Tamaño de sector (lógico/físico): 512 bytes / 512 bytes
Tamaño de E/S (mínimo/óptimo): 512 bytes / 512 bytes


Disco /dev/loop4: 73,87 MiB, 77459456 bytes, 151288 sectores
Unidades: sectores de 1 * 512 = 512 bytes
Tamaño de sector (lógico/físico): 512 bytes / 512 bytes
Tamaño de E/S (mínimo/óptimo): 512 bytes / 512 bytes


Disco /dev/loop5: 10,72 MiB, 11239424 bytes, 21952 sectores
Unidades: sectores de 1 * 512 = 512 bytes
Tamaño de sector (lógico/físico): 512 bytes / 512 bytes
Tamaño de E/S (mínimo/óptimo): 512 bytes / 512 bytes


Disco /dev/loop6: 11,11 MiB, 11649024 bytes, 22752 sectores
Unidades: sectores de 1 * 512 = 512 bytes
Tamaño de sector (lógico/físico): 512 bytes / 512 bytes
Tamaño de E/S (mínimo/óptimo): 512 bytes / 512 bytes


Disco /dev/loop7: 505,09 MiB, 529625088 bytes, 1034424 sectores
Unidades: sectores de 1 * 512 = 512 bytes
Tamaño de sector (lógico/físico): 512 bytes / 512 bytes
Tamaño de E/S (mínimo/óptimo): 512 bytes / 512 bytes


Disco /dev/sda: 23 GiB, 24696061952 bytes, 48234496 sectores
Disk model: VBOX HARDDISK   
Unidades: sectores de 1 * 512 = 512 bytes
Tamaño de sector (lógico/físico): 512 bytes / 512 bytes
Tamaño de E/S (mínimo/óptimo): 512 bytes / 512 bytes
Tipo de etiqueta de disco: gpt
Identificador del disco: AA7C9542-099A-466C-89E9-E88D9CCAB3BE

Dispositivo Comienzo    Final Sectores Tamaño Tipo
/dev/sda1       2048     4095     2048     1M Arranque de BIOS
/dev/sda2       4096 48232447 48228352    23G Sistema de ficheros de Linux


Disco /dev/loop8: 91,69 MiB, 96141312 bytes, 187776 sectores
Unidades: sectores de 1 * 512 = 512 bytes
Tamaño de sector (lógico/físico): 512 bytes / 512 bytes
Tamaño de E/S (mínimo/óptimo): 512 bytes / 512 bytes


Disco /dev/loop9: 10,76 MiB, 11280384 bytes, 22032 sectores
Unidades: sectores de 1 * 512 = 512 bytes
Tamaño de sector (lógico/físico): 512 bytes / 512 bytes
Tamaño de E/S (mínimo/óptimo): 512 bytes / 512 bytes


Disco /dev/loop10: 38,83 MiB, 40714240 bytes, 79520 sectores
Unidades: sectores de 1 * 512 = 512 bytes
Tamaño de sector (lógico/físico): 512 bytes / 512 bytes
Tamaño de E/S (mínimo/óptimo): 512 bytes / 512 bytes


Disco /dev/loop11: 10,67 MiB, 11186176 bytes, 21848 sectores
Unidades: sectores de 1 * 512 = 512 bytes
Tamaño de sector (lógico/físico): 512 bytes / 512 bytes
Tamaño de E/S (mínimo/óptimo): 512 bytes / 512 bytes


Disco /dev/loop12: 44,3 MiB, 46448640 bytes, 90720 sectores
Unidades: sectores de 1 * 512 = 512 bytes
Tamaño de sector (lógico/físico): 512 bytes / 512 bytes
Tamaño de E/S (mínimo/óptimo): 512 bytes / 512 bytes


Disco /dev/loop13: 500 KiB, 512000 bytes, 1000 sectores
Unidades: sectores de 1 * 512 = 512 bytes
Tamaño de sector (lógico/físico): 512 bytes / 512 bytes
Tamaño de E/S (mínimo/óptimo): 512 bytes / 512 bytes


Disco /dev/loop14: 568 KiB, 581632 bytes, 1136 sectores
Unidades: sectores de 1 * 512 = 512 bytes
Tamaño de sector (lógico/físico): 512 bytes / 512 bytes
Tamaño de E/S (mínimo/óptimo): 512 bytes / 512 bytes


Disco /dev/loop15: 63,7 MiB, 66789376 bytes, 130448 sectores
Unidades: sectores de 1 * 512 = 512 bytes
Tamaño de sector (lógico/físico): 512 bytes / 512 bytes
Tamaño de E/S (mínimo/óptimo): 512 bytes / 512 bytes


Disco /dev/loop16: 55,36 MiB, 58052608 bytes, 113384 sectores
Unidades: sectores de 1 * 512 = 512 bytes
Tamaño de sector (lógico/físico): 512 bytes / 512 bytes
Tamaño de E/S (mínimo/óptimo): 512 bytes / 512 bytes


Disco /dev/loop17: 85,57 MiB, 89731072 bytes, 175256 sectores
Unidades: sectores de 1 * 512 = 512 bytes
Tamaño de sector (lógico/físico): 512 bytes / 512 bytes
Tamaño de E/S (mínimo/óptimo): 512 bytes / 512 bytes


Disco /dev/loop18: 164,82 MiB, 172830720 bytes, 337560 sectores
Unidades: sectores de 1 * 512 = 512 bytes
Tamaño de sector (lógico/físico): 512 bytes / 512 bytes
Tamaño de E/S (mínimo/óptimo): 512 bytes / 512 bytes

eduardo-vargas@lalovglz-VirtualBox:~$ blkid
/dev/sda2: UUID="8c895996-cbff-469b-82b3-9c9b82370a49" BLOCK_SIZE="4096" TYPE="ext4" PARTUUID="fe302ca3-3a20-40cc-865a-72eb8a02ebe1"
/dev/sr0: BLOCK_SIZE="2048" UUID="2024-10-10-17-52-15-90" LABEL="VBox_GAs_7.1.4" TYPE="iso9660"

eduardo-vargas@lalovglz-VirtualBox:~$ df -h
S.ficheros     Tamaño Usados  Disp Uso% Montado en
tmpfs            392M   1,7M  390M   1% /run
/dev/sda2         23G    14G  7,8G  64% /
tmpfs            2,0G    34M  1,9G   2% /dev/shm
tmpfs            5,0M   8,0K  5,0M   1% /run/lock
tmpfs            392M   144K  392M   1% /run/user/1000
/dev/sr0          57M    57M     0 100% /media/eduardo-vargas/VBox_GAs_7.1.4
```

### Actividad 3: Explorar dispositivos de entrada


¿Qué eventos genera cada dispositivo al interactuar con ellos?

    Teclado (AT Translated Set 2 keyboard):
    El teclado genera eventos del tipo EV_KEY, que corresponden a las teclas que se presionan o liberan. Estos eventos incluyen códigos asociados a las teclas y se detectan como cambios en los valores de las teclas.

    Mouse (ImExPS/2 Generic Explorer Mouse):
    El mouse genera eventos de los tipos EV_KEY (para los botones del mouse, como los botones izquierdo, derecho y medio) y EV_REL (para los movimientos relativos, como el desplazamiento en los ejes X e Y). También incluye eventos para el desplazamiento de la rueda del mouse (REL_WHEEL) y el desplazamiento horizontal de la rueda (REL_HWHEEL).

    Controlador USB (VirtualBox USB Tablet):
    Este dispositivo genera eventos de tipo EV_KEY (para las teclas presionadas), EV_REL (para los movimientos relativos, como el desplazamiento en los ejes), y EV_ABS (para eventos de tipo absoluto, como el movimiento de un lápiz o cursor en una pantalla táctil). Además, también maneja eventos de MSC para los controles de medios.

2. ¿Cómo se identifican los dispositivos en /proc/bus/input/devices?

En /proc/bus/input/devices, cada dispositivo de entrada está identificado con una serie de parámetros que incluyen:

    Nombre (N: Name): El nombre del dispositivo, como "AT Translated Set 2 keyboard" o "ImExPS/2 Generic Explorer Mouse".
    Bus y Producto (I: Bus=..., Vendor=..., Product=...): El bus de comunicación (por ejemplo, 0011 para el teclado) y los identificadores de producto y proveedor.
    Ubicación física (P: Phys): Información sobre la ubicación física del dispositivo en el sistema.
    Manejo (H: Handlers): Los tipos de eventos que el dispositivo puede generar, como kbd (teclado), mouse0 (mouse), eventX (evento de entrada específico).
    Tipos de eventos (B: EV): Los tipos de eventos que el dispositivo puede generar, como EV_KEY para las teclas o EV_REL para el movimiento relativo.

```
eduardo-vargas@lalovglz-VirtualBox:~$ cat /proc/bus/input/devices
I: Bus=0019 Vendor=0000 Product=0001 Version=0000
N: Name="Power Button"
P: Phys=LNXPWRBN/button/input0
S: Sysfs=/devices/LNXSYSTM:00/LNXPWRBN:00/input/input0
U: Uniq=
H: Handlers=kbd event0 
B: PROP=0
B: EV=3
B: KEY=8000 10000000000000 0

I: Bus=0019 Vendor=0000 Product=0003 Version=0000
N: Name="Sleep Button"
P: Phys=LNXSLPBN/button/input0
S: Sysfs=/devices/LNXSYSTM:00/LNXSLPBN:00/input/input1
U: Uniq=
H: Handlers=kbd event1 
B: PROP=0
B: EV=3
B: KEY=4000 0 0

I: Bus=0011 Vendor=0001 Product=0001 Version=ab41
N: Name="AT Translated Set 2 keyboard"
P: Phys=isa0060/serio0/input0
S: Sysfs=/devices/platform/i8042/serio0/input/input2
U: Uniq=
H: Handlers=sysrq kbd event2 leds 
B: PROP=0
B: EV=120013
B: KEY=402000000 3803078f800d001 feffffdfffefffff fffffffffffffffe
B: MSC=10
B: LED=7

I: Bus=0019 Vendor=0000 Product=0006 Version=0000
N: Name="Video Bus"
P: Phys=LNXVIDEO/video/input0
S: Sysfs=/devices/LNXSYSTM:00/LNXSYBUS:00/PNP0A03:00/LNXVIDEO:00/input/input4
U: Uniq=
H: Handlers=kbd event3 
B: PROP=0
B: EV=3
B: KEY=3e000b00000000 0 0 0

I: Bus=0011 Vendor=0002 Product=0006 Version=0000
N: Name="ImExPS/2 Generic Explorer Mouse"
P: Phys=isa0060/serio1/input0
S: Sysfs=/devices/platform/i8042/serio1/input/input5
U: Uniq=
H: Handlers=mouse0 event4 
B: PROP=1
B: EV=7
B: KEY=1f0000 0 0 0 0
B: REL=143

I: Bus=0003 Vendor=80ee Product=0021 Version=0110
N: Name="VirtualBox USB Tablet"
P: Phys=usb-0000:00:06.0-1/input0
S: Sysfs=/devices/pci0000:00/0000:00:06.0/usb1/1-1/1-1:1.0/0003:80EE:0021.0001/input/input6
U: Uniq=
H: Handlers=mouse1 event5 js0 
B: PROP=0
B: EV=1f
B: KEY=1f0000 0 0 0 0
B: REL=1940
B: ABS=3
B: MSC=10

I: Bus=0001 Vendor=80ee Product=cafe Version=0701
N: Name="VirtualBox mouse integration"
P: Phys=
S: Sysfs=/devices/pci0000:00/0000:00:04.0/input/input7
U: Uniq=
H: Handlers=mouse2 event6 js1 
B: PROP=0
B: EV=f
B: KEY=1f0000 0 0 0 0
B: REL=140
B: ABS=3

eduardo-vargas@lalovglz-VirtualBox:~$ sudo evtest
No device specified, trying to scan all of /dev/input/event*
Available devices:
/dev/input/event0:	Power Button
/dev/input/event1:	Sleep Button
/dev/input/event2:	AT Translated Set 2 keyboard
/dev/input/event3:	Video Bus
/dev/input/event4:	ImExPS/2 Generic Explorer Mouse
/dev/input/event5:	VirtualBox USB Tablet
/dev/input/event6:	VirtualBox mouse integration
Select the device event number [0-6]: 
4
Input driver version is 1.0.1
Input device ID: bus 0x11 vendor 0x2 product 0x6 version 0x0
Input device name: "ImExPS/2 Generic Explorer Mouse"
Supported events:
  Event type 0 (EV_SYN)
  Event type 1 (EV_KEY)
    Event code 272 (BTN_LEFT)
    Event code 273 (BTN_RIGHT)
    Event code 274 (BTN_MIDDLE)
    Event code 275 (BTN_SIDE)
    Event code 276 (BTN_EXTRA)
  Event type 2 (EV_REL)
    Event code 0 (REL_X)
    Event code 1 (REL_Y)
    Event code 6 (REL_HWHEEL)
    Event code 8 (REL_WHEEL)
Properties:
  Property type 0 (INPUT_PROP_POINTER)
Testing ... (interrupt to exit)
```

### Actividad 4: Examinar dispositivos de salida


¿Qué salidas de video están disponibles en su sistema?

    En el sistema, hay una salida de video disponible llamada Virtual-1, con una resolución actual de 1920x997. Esta salida también soporta varias resoluciones adicionales, como 1280x960, 1152x864, 1024x768, 800x600, entre otras.

¿Qué dispositivos de sonido se detectaron?

    El dispositivo de sonido detectado en el sistema es la tarjeta Intel 82801AA-ICH, con el dispositivo Intel ICH como el principal, bajo la tarjeta número 0. Este dispositivo tiene un subdispositivo, el cual está habilitado para su uso.

¿Qué procesos están usando la tarjeta de sonido?

    Los procesos que están utilizando la tarjeta de sonido en este momento son:
        pipewire (PID 1924), que tiene abiertos dos archivos relacionados con el dispositivo de sonido /dev/snd/seq.
        wireplumb (PID 1934), que está utilizando el archivo /dev/snd/controlC0 para controlar el dispositivo de sonido.

```
eduardo-vargas@lalovglz-VirtualBox:~$ xrandr
Screen 0: minimum 16 x 16, current 1920 x 997, maximum 32767 x 32767
Virtual-1 connected primary 1920x997+0+0 (normal left inverted right x axis y axis) 0mm x 0mm
   1920x997      59.91*+
   1280x960      59.94  
   1152x864      59.96  
   1024x768      59.92  
   800x600       59.86  
   640x480       59.38  
   320x240       59.52  
   1440x900      59.89  
   1280x800      59.81  
   1152x720      59.75  
   960x600       59.63  
   928x580       59.88  
   800x500       59.50  
   768x480       59.90  
   720x480       59.71  
   640x400       59.95  
   320x200       58.96  
   1600x900      59.95  
   1368x768      59.88  
   1280x720      59.86  
   1024x576      59.90  
   864x486       59.92  
   720x400       59.55  
   640x350       59.77  
   
eduardo-vargas@lalovglz-VirtualBox:~$ aplay -l
**** Lista de PLAYBACK dispositivos hardware ****
tarjeta 0: I82801AAICH [Intel 82801AA-ICH], dispositivo 0: Intel ICH [Intel 82801AA-ICH]
  Subdispositivos: 1/1
  Subdispositivo #0: subdevice #0
  
eduardo-vargas@lalovglz-VirtualBox:~$ lsof /dev/snd/*
COMMAND    PID           USER   FD   TYPE DEVICE SIZE/OFF NODE NAME
pipewire  1924 eduardo-vargas   59u   CHR  116,1      0t0  418 /dev/snd/seq
pipewire  1924 eduardo-vargas   60u   CHR  116,1      0t0  418 /dev/snd/seq
wireplumb 1934 eduardo-vargas   35u   CHR  116,5      0t0  691 /dev/snd/controlC0
```

### Actividad 5: Crear un script de resumen


¿Qué ventajas tiene usar un script para recopilar esta información?

    Automatización: Permite ejecutar un conjunto de comandos de manera automática y ordenada, sin tener que escribir cada comando manualmente.
    Repetibilidad: El script puede ejecutarse tantas veces como sea necesario sin tener que reconfigurar o recordar los comandos.
    Facilidad de uso: Los usuarios pueden ejecutar el script sin necesidad de conocer los comandos específicos.
    Organización: La salida se genera de manera estructurada y, en este caso, se guarda en un archivo para revisión posterior.

¿Qué cambios realizaría para personalizar el script?

    Personalización de las salidas: Podría modificar el contenido del archivo resumendispositivos.txt para agregar más información relevante, como las fechas, nombres de usuario, o el tipo de sistema operativo. 

Agregar filtros: Si quiero obtener información más específica, podría usar filtros de grep, por ejemplo:

lsusb | grep "ID"


```
eduardo-vargas@lalovglz-VirtualBox:~$ nano dispositivos.sh
eduardo-vargas@lalovglz-VirtualBox:~$ chmod +x dispositivos.sh
eduardo-vargas@lalovglz-VirtualBox:~$ 
eduardo-vargas@lalovglz-VirtualBox:~$ bash dispositivos.sh
Dispositivos de bloque:
NAME   MAJ:MIN RM   SIZE RO TYPE MOUNTPOINTS
loop0    7:0    0     4K  1 loop /snap/bare/5
loop1    7:1    0   273M  1 loop /snap/firefox/5273
loop2    7:2    0 273,7M  1 loop /snap/firefox/5437
loop3    7:3    0  73,9M  1 loop /snap/core22/1663
loop4    7:4    0  73,9M  1 loop /snap/core22/1722
loop5    7:5    0  10,7M  1 loop /snap/firmware-updater/127
loop6    7:6    0  11,1M  1 loop /snap/firmware-updater/147
loop7    7:7    0 505,1M  1 loop /snap/gnome-42-2204/176
loop8    7:8    0  91,7M  1 loop /snap/gtk-common-themes/1535
loop9    7:9    0  10,8M  1 loop /snap/snap-store/1244
loop10   7:10   0  38,8M  1 loop /snap/snapd/21759
loop11   7:11   0  10,7M  1 loop /snap/snap-store/1218
loop12   7:12   0  44,3M  1 loop /snap/snapd/23258
loop13   7:13   0   500K  1 loop /snap/snapd-desktop-integration/178
loop14   7:14   0   568K  1 loop /snap/snapd-desktop-integration/253
loop15   7:15   0  63,7M  1 loop /snap/core20/2434
loop16   7:16   0  55,4M  1 loop /snap/core18/2846
loop17   7:17   0  85,6M  1 loop /snap/whatsapp-linux-app/2
loop18   7:18   0 164,8M  1 loop /snap/gnome-3-28-1804/198
sda      8:0    0    23G  0 disk 
├─sda1   8:1    0     1M  0 part 
└─sda2   8:2    0    23G  0 part /
sr0     11:0    1  56,9M  0 rom  /media/eduardo-vargas/VBox_GAs_7.1.4
Dispositivos USB:
Bus 001 Device 001: ID 1d6b:0001 Linux Foundation 1.1 root hub
Bus 001 Device 002: ID 80ee:0021 VirtualBox USB Tablet
Bus 002 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub
Dispositivos PCI:
00:00.0 Host bridge: Intel Corporation 440FX - 82441FX PMC [Natoma] (rev 02)
00:01.0 ISA bridge: Intel Corporation 82371SB PIIX3 ISA [Natoma/Triton II]
00:01.1 IDE interface: Intel Corporation 82371AB/EB/MB PIIX4 IDE (rev 01)
00:02.0 VGA compatible controller: VMware SVGA II Adapter
00:03.0 Ethernet controller: Intel Corporation 82540EM Gigabit Ethernet Controller (rev 02)
00:04.0 System peripheral: InnoTek Systemberatung GmbH VirtualBox Guest Service
00:05.0 Multimedia audio controller: Intel Corporation 82801AA AC'97 Audio Controller (rev 01)
00:06.0 USB controller: Apple Inc. KeyLargo/Intrepid USB
00:07.0 Bridge: Intel Corporation 82371AB/EB/MB PIIX4 ACPI (rev 08)
00:0b.0 USB controller: Intel Corporation 82801FB/FBM/FR/FW/FRW (ICH6 Family) USB2 EHCI Controller
00:0d.0 SATA controller: Intel Corporation 82801HM/HEM (ICH8M/ICH8M-E) SATA Controller [AHCI mode] (rev 02)
Dispositivos de entrada:
I: Bus=0019 Vendor=0000 Product=0001 Version=0000
N: Name="Power Button"
P: Phys=LNXPWRBN/button/input0
S: Sysfs=/devices/LNXSYSTM:00/LNXPWRBN:00/input/input0
U: Uniq=
H: Handlers=kbd event0 
B: PROP=0
B: EV=3
B: KEY=8000 10000000000000 0

I: Bus=0019 Vendor=0000 Product=0003 Version=0000
N: Name="Sleep Button"
P: Phys=LNXSLPBN/button/input0
S: Sysfs=/devices/LNXSYSTM:00/LNXSLPBN:00/input/input1
U: Uniq=
H: Handlers=kbd event1 
B: PROP=0
B: EV=3
B: KEY=4000 0 0

I: Bus=0011 Vendor=0001 Product=0001 Version=ab41
N: Name="AT Translated Set 2 keyboard"
P: Phys=isa0060/serio0/input0
S: Sysfs=/devices/platform/i8042/serio0/input/input2
U: Uniq=
H: Handlers=sysrq kbd event2 leds 
B: PROP=0
B: EV=120013
B: KEY=402000000 3803078f800d001 feffffdfffefffff fffffffffffffffe
B: MSC=10
B: LED=7

I: Bus=0019 Vendor=0000 Product=0006 Version=0000
N: Name="Video Bus"
P: Phys=LNXVIDEO/video/input0
S: Sysfs=/devices/LNXSYSTM:00/LNXSYBUS:00/PNP0A03:00/LNXVIDEO:00/input/input4
U: Uniq=
H: Handlers=kbd event3 
B: PROP=0
B: EV=3
B: KEY=3e000b00000000 0 0 0

I: Bus=0011 Vendor=0002 Product=0006 Version=0000
N: Name="ImExPS/2 Generic Explorer Mouse"
P: Phys=isa0060/serio1/input0
S: Sysfs=/devices/platform/i8042/serio1/input/input5
U: Uniq=
H: Handlers=mouse0 event4 
B: PROP=1
B: EV=7
B: KEY=1f0000 0 0 0 0
B: REL=143

I: Bus=0003 Vendor=80ee Product=0021 Version=0110
N: Name="VirtualBox USB Tablet"
P: Phys=usb-0000:00:06.0-1/input0
S: Sysfs=/devices/pci0000:00/0000:00:06.0/usb1/1-1/1-1:1.0/0003:80EE:0021.0001/input/input6
U: Uniq=
H: Handlers=mouse1 event5 js0 
B: PROP=0
B: EV=1f
B: KEY=1f0000 0 0 0 0
B: REL=1940
B: ABS=3
B: MSC=10

I: Bus=0001 Vendor=80ee Product=cafe Version=0701
N: Name="VirtualBox mouse integration"
P: Phys=
S: Sysfs=/devices/pci0000:00/0000:00:04.0/input/input7
U: Uniq=
H: Handlers=mouse2 event6 js1 
B: PROP=0
B: EV=f
B: KEY=1f0000 0 0 0 0
B: REL=140
B: ABS=3

Salidas de video:
Screen 0: minimum 16 x 16, current 1920 x 997, maximum 32767 x 32767
Virtual-1 connected primary 1920x997+0+0 (normal left inverted right x axis y axis) 0mm x 0mm
   1920x997      59.91*+
   1280x960      59.94  
   1152x864      59.96  
   1024x768      59.92  
   800x600       59.86  
   640x480       59.38  
   320x240       59.52  
   1440x900      59.89  
   1280x800      59.81  
   1152x720      59.75  
   960x600       59.63  
   928x580       59.88  
   800x500       59.50  
   768x480       59.90  
   720x480       59.71  
   640x400       59.95  
   320x200       58.96  
   1600x900      59.95  
   1368x768      59.88  
   1280x720      59.86  
   1024x576      59.90  
   864x486       59.92  
   720x400       59.55  
   640x350       59.77  
Tarjetas de sonido:
**** Lista de PLAYBACK dispositivos hardware ****
tarjeta 0: I82801AAICH [Intel 82801AA-ICH], dispositivo 0: Intel ICH [Intel 82801AA-ICH]
  Subdispositivos: 1/1
  Subdispositivo #0: subdevice #0
eduardo-vargas@lalovglz-VirtualBox:~$ nano dispositivos.sh
eduardo-vargas@lalovglz-VirtualBox:~$ bash dispositivos.sh
Dispositivos de bloque:
NAME   MAJ:MIN RM   SIZE RO TYPE MOUNTPOINTS
loop0    7:0    0     4K  1 loop /snap/bare/5
loop1    7:1    0   273M  1 loop /snap/firefox/5273
loop2    7:2    0 273,7M  1 loop /snap/firefox/5437
loop3    7:3    0  73,9M  1 loop /snap/core22/1663
loop4    7:4    0  73,9M  1 loop /snap/core22/1722
loop5    7:5    0  10,7M  1 loop /snap/firmware-updater/127
loop6    7:6    0  11,1M  1 loop /snap/firmware-updater/147
loop7    7:7    0 505,1M  1 loop /snap/gnome-42-2204/176
loop8    7:8    0  91,7M  1 loop /snap/gtk-common-themes/1535
loop9    7:9    0  10,8M  1 loop /snap/snap-store/1244
loop10   7:10   0  38,8M  1 loop /snap/snapd/21759
loop11   7:11   0  10,7M  1 loop /snap/snap-store/1218
loop12   7:12   0  44,3M  1 loop /snap/snapd/23258
loop13   7:13   0   500K  1 loop /snap/snapd-desktop-integration/178
loop14   7:14   0   568K  1 loop /snap/snapd-desktop-integration/253
loop15   7:15   0  63,7M  1 loop /snap/core20/2434
loop16   7:16   0  55,4M  1 loop /snap/core18/2846
loop17   7:17   0  85,6M  1 loop /snap/whatsapp-linux-app/2
loop18   7:18   0 164,8M  1 loop /snap/gnome-3-28-1804/198
sda      8:0    0    23G  0 disk 
├─sda1   8:1    0     1M  0 part 
└─sda2   8:2    0    23G  0 part /
sr0     11:0    1  56,9M  0 rom  /media/eduardo-vargas/VBox_GAs_7.1.4
Dispositivos USB:
Bus 001 Device 001: ID 1d6b:0001 Linux Foundation 1.1 root hub
Bus 001 Device 002: ID 80ee:0021 VirtualBox USB Tablet
Bus 002 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub
Dispositivos PCI:
00:00.0 Host bridge: Intel Corporation 440FX - 82441FX PMC [Natoma] (rev 02)
00:01.0 ISA bridge: Intel Corporation 82371SB PIIX3 ISA [Natoma/Triton II]
00:01.1 IDE interface: Intel Corporation 82371AB/EB/MB PIIX4 IDE (rev 01)
00:02.0 VGA compatible controller: VMware SVGA II Adapter
00:03.0 Ethernet controller: Intel Corporation 82540EM Gigabit Ethernet Controller (rev 02)
00:04.0 System peripheral: InnoTek Systemberatung GmbH VirtualBox Guest Service
00:05.0 Multimedia audio controller: Intel Corporation 82801AA AC'97 Audio Controller (rev 01)
00:06.0 USB controller: Apple Inc. KeyLargo/Intrepid USB
00:07.0 Bridge: Intel Corporation 82371AB/EB/MB PIIX4 ACPI (rev 08)
00:0b.0 USB controller: Intel Corporation 82801FB/FBM/FR/FW/FRW (ICH6 Family) USB2 EHCI Controller
00:0d.0 SATA controller: Intel Corporation 82801HM/HEM (ICH8M/ICH8M-E) SATA Controller [AHCI mode] (rev 02)
Dispositivos de entrada:
I: Bus=0019 Vendor=0000 Product=0001 Version=0000
N: Name="Power Button"
P: Phys=LNXPWRBN/button/input0
S: Sysfs=/devices/LNXSYSTM:00/LNXPWRBN:00/input/input0
U: Uniq=
H: Handlers=kbd event0 
B: PROP=0
B: EV=3
B: KEY=8000 10000000000000 0

I: Bus=0019 Vendor=0000 Product=0003 Version=0000
N: Name="Sleep Button"
P: Phys=LNXSLPBN/button/input0
S: Sysfs=/devices/LNXSYSTM:00/LNXSLPBN:00/input/input1
U: Uniq=
H: Handlers=kbd event1 
B: PROP=0
B: EV=3
B: KEY=4000 0 0

I: Bus=0011 Vendor=0001 Product=0001 Version=ab41
N: Name="AT Translated Set 2 keyboard"
P: Phys=isa0060/serio0/input0
S: Sysfs=/devices/platform/i8042/serio0/input/input2
U: Uniq=
H: Handlers=sysrq kbd event2 leds 
B: PROP=0
B: EV=120013
B: KEY=402000000 3803078f800d001 feffffdfffefffff fffffffffffffffe
B: MSC=10
B: LED=7

I: Bus=0019 Vendor=0000 Product=0006 Version=0000
N: Name="Video Bus"
P: Phys=LNXVIDEO/video/input0
S: Sysfs=/devices/LNXSYSTM:00/LNXSYBUS:00/PNP0A03:00/LNXVIDEO:00/input/input4
U: Uniq=
H: Handlers=kbd event3 
B: PROP=0
B: EV=3
B: KEY=3e000b00000000 0 0 0

I: Bus=0011 Vendor=0002 Product=0006 Version=0000
N: Name="ImExPS/2 Generic Explorer Mouse"
P: Phys=isa0060/serio1/input0
S: Sysfs=/devices/platform/i8042/serio1/input/input5
U: Uniq=
H: Handlers=mouse0 event4 
B: PROP=1
B: EV=7
B: KEY=1f0000 0 0 0 0
B: REL=143

I: Bus=0003 Vendor=80ee Product=0021 Version=0110
N: Name="VirtualBox USB Tablet"
P: Phys=usb-0000:00:06.0-1/input0
S: Sysfs=/devices/pci0000:00/0000:00:06.0/usb1/1-1/1-1:1.0/0003:80EE:0021.0001/input/input6
U: Uniq=
H: Handlers=mouse1 event5 js0 
B: PROP=0
B: EV=1f
B: KEY=1f0000 0 0 0 0
B: REL=1940
B: ABS=3
B: MSC=10

I: Bus=0001 Vendor=80ee Product=cafe Version=0701
N: Name="VirtualBox mouse integration"
P: Phys=
S: Sysfs=/devices/pci0000:00/0000:00:04.0/input/input7
U: Uniq=
H: Handlers=mouse2 event6 js1 
B: PROP=0
B: EV=f
B: KEY=1f0000 0 0 0 0
B: REL=140
B: ABS=3

Salidas de video:
Screen 0: minimum 16 x 16, current 1920 x 997, maximum 32767 x 32767
Virtual-1 connected primary 1920x997+0+0 (normal left inverted right x axis y axis) 0mm x 0mm
   1920x997      59.91*+
   1280x960      59.94  
   1152x864      59.96  
   1024x768      59.92  
   800x600       59.86  
   640x480       59.38  
   320x240       59.52  
   1440x900      59.89  
   1280x800      59.81  
   1152x720      59.75  
   960x600       59.63  
   928x580       59.88  
   800x500       59.50  
   768x480       59.90  
   720x480       59.71  
   640x400       59.95  
   320x200       58.96  
   1600x900      59.95  
   1368x768      59.88  
   1280x720      59.86  
   1024x576      59.90  
   864x486       59.92  
   720x400       59.55  
   640x350       59.77  
Tarjetas de sonido:
**** Lista de PLAYBACK dispositivos hardware ****
tarjeta 0: I82801AAICH [Intel 82801AA-ICH], dispositivo 0: Intel ICH [Intel 82801AA-ICH]
  Subdispositivos: 1/1
  Subdispositivo #0: subdevice #0
```
### Actividad 6: Reflexión y discusión


  1. ¿Qué comando encontré más útil y por qué?

El comando que encontré más útil fue lsblk, ya que me permite listar y visualizar de forma clara todos los dispositivos de almacenamiento conectados y sus particiones. Es fundamental para la administración de discos, ya que puedo ver qué particiones están montadas, su tamaño y cómo están organizadas. Esto facilita la gestión del espacio en disco, la creación o modificación de particiones y el diagnóstico de problemas relacionados con el almacenamiento. Es una herramienta clave para mantener el sistema bien organizado.

2. ¿Qué tan importante es conocer los dispositivos conectados al sistema?

Es muy importante conocer los dispositivos conectados al sistema porque me permite tener un control total sobre los recursos. Esto facilita la gestión de hardware, la resolución de problemas y la optimización de los recursos disponibles. Saber qué dispositivos están conectados también ayuda a identificar fallos rápidamente, como en el caso de un disco duro dañado o una pantalla que no se detecta. Además, es crucial para garantizar la seguridad del sistema, ya que puedo detectar dispositivos no autorizados o maliciosos.

3. ¿Cómo podrían estos conocimientos aplicarse en la administración de sistemas?

Estos conocimientos son esenciales para la administración eficiente de sistemas, ya que permiten gestionar los recursos de hardware de manera efectiva. Conocer los dispositivos conectados me permite realizar tareas de mantenimiento como el monitoreo de discos, la gestión de particiones o la configuración de pantallas. También me ayuda a resolver problemas rápidamente, como el diagnóstico de fallos en dispositivos de entrada o almacenamiento. Además, este conocimiento es útil para la seguridad, al identificar dispositivos no autorizados que podrían comprometer el sistema.
