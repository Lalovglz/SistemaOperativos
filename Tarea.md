# ACTIVIDAD FINAL


## Sistemas de archivos

### Ejercicio 1: Concepto y noción de archivo real y virtual

####  Define el concepto de archivo real y archivo virtual.


El archivo virtual, es aquel que existen durante la ejecucion de algun programa, y por ende cuando este termina, el archivo es eliminado, tal es el caso de los archivos *.TMP, mientras que los archivos reales son onjetos que contienen programa o datos y existen de manera real, ocupando espacio en disco duro, teniendo un tamaño en bytes


#### Proporciona ejemplos de cómo los sistemas operativos manejan archivos reales y virtuales.

Ejemplo archivo real

Cuando guardamos un archico Word, el sistema operativo asgina un espacio fisico en el disco duro para el archivo, usa estrcuturas como tablas de archivos  para almacenar informacion sobre la ubicacion del archivo en el disco y su tamaño

Ejemplo archivo virtual

En Linux, los dispositivos de hardware (como /dev/sda o /dev/null) se representan como archivos virtuales. No son datos almacenados en el disco, sino interfaces para interactuar con dispositivos físicos del sistema operativo.


#### Explica un caso práctico donde un archivo virtual sea más útil que un archivo real.

Por ejemplo a la hora de realizar algun reporte de transacciones financieras, se analizan datos intermedios para oberservar las transacciones y sus detalles pero no es necesario conservar de forma real los datos intermedios despues de que el analisis termina, para asi maximizar la velocidad de procesamiento


### Ejercicio 2: Componentes de un sistema de archivos


#### Identifica los componentes clave de un sistema de archivos (por ejemplo, metadatos, tablas de asignación, etc.).

***Metadatos:***

Contienen información descriptiva sobre cada archivo, como su nombre, tamaño, fechas de creación y modificación, permisos, propietario, y tipo. Son esenciales para identificar y organizar los archivos; en sistemas Linux, estos se almacenan en estructuras llamadas inodes.


***Tablas de asignación de archivos:*** 

Mapean los bloques de datos físicos en el disco y los asocian con los archivos, permitiendo al sistema localizar y gestionar el espacio de almacenamiento; ejemplos incluyen FAT en sistemas Windows y MFT en NTFS.

***Bloques de datos:*** 

Son las unidades físicas que almacenan el contenido real de los archivos (como texto, imágenes o videos), siendo el núcleo del sistema de archivos. Su tamaño y disposición afectan el rendimiento general.

***Directorios:***

Actúan como contenedores jerárquicos que organizan archivos y otros directorios, facilitando su búsqueda y acceso. Representan la estructura lógica del sistema de archivos.

***Superbloque:*** 

Es una estructura central que contiene información global del sistema de archivos, como su tamaño, ubicación de metadatos y tablas de asignación, y estado general, siendo fundamental para montar y operar el sistema.

#### Crea un cuadro comparativo de cómo estos componentes funcionan en sistemas como EXT4 y NTFS.

| Componente                        | EXT4                                    |NTFS                                                 |
|-----------------------------------|-----------------------------------------|-----------------------------------------------------|
| Metadatos                         | Se almacenan en *inodes*, que incluyen información como tamaño, permisos y punteros a bloques. | Se gestionan en la *Master File Table (MFT)*, que contiene todos los atributos y ubicaciones de archivos. |
| Tablas de asignación | Utiliza un mapa de bits para rastrear bloques libres y asignados.                         | Usa la *Master File Table (MFT)*, que combina metadatos y asignaciones en un solo lugar. |
| Bloques de datos     | Los datos se dividen en bloques de tamaño fijo (típicamente 4 KB). EXT4 permite bloques grandes para optimizar el almacenamiento. | Los datos también se dividen en clusters (tamaño definido al formatear). Es altamente eficiente en fragmentación. |
| Directorios          | Organiza directorios jerárquicamente; los nombres de archivos están vinculados a sus inodes. | Los directorios son archivos especiales almacenados como entradas en la MFT.            |
| Superbloque          | Contiene información global del sistema de archivos, como tamaño, estado, y ubicación de tablas de asignación e inodes. | No tiene un superbloque explícito; utiliza estructuras redundantes dentro de la MFT para almacenar esta información. |


***EXT4***

***Ventajas:***

Alta eficiencia en discos con pocos archivos grandes.

Menor fragmentación debido a su asignación contigua de bloques.

Simplicidad en la estructura, fácil de gestionar.

Recuperación rápida en sistemas Linux con su mecanismo de journaling.

Buen rendimiento en lectura y escritura secuencial.

Estable y ampliamente soportado en sistemas Linux.

Maneja bien el espacio en discos de tamaño moderado.

***Desventajas:***

Menos eficiente en sistemas con muchos archivos pequeños.

Limitación en el número de inodes disponibles al formatear.

No ofrece características avanzadas como compresión o encriptación.

Puede sufrir fragmentación en discos con archivos pequeños.

No tan robusto en la gestión de discos de gran tamaño.

La recuperación ante fallos puede ser limitada sin herramientas adicionales.

No soporta la configuración avanzada de permisos de archivos como NTFS.

***NTFS***

***Ventajas:***

Excelente para grandes volúmenes de datos.

Soporta características avanzadas como compresión y encriptación.

Mejor manejo de la fragmentación en archivos grandes.

Sistema de archivos altamente confiable y redundante.

Soporta permisos avanzados y control de acceso.

Optimiza el espacio en discos grandes mediante la MFT.

Compatible con herramientas de recuperación y reparación robustas.

***Desventajas:***

Requiere más espacio debido a la Master File Table (MFT).

Menos eficiente con archivos pequeños, debido al tamaño de los clusters.

Su estructura más compleja puede afectar el rendimiento en discos con muchos archivos pequeños.

Puede volverse lento con grandes volúmenes de archivos pequeños.

Necesita más recursos de procesamiento para la gestión de metadatos.

Mayor uso de espacio en disco por la sobrecarga de la MFT.

Menos flexible en sistemas no Windows o en entornos de arranque dual.

### Ejercicio 3: Organización lógica y física de archivos

#### Diseña un árbol jerárquico que represente la organización lógica de directorios y subdirectorios.

![Jerarquia](imagenes/Captura%20de%20pantalla%202024-12-16%20135056.png "Jerarquia de directorios y subdirectorios")



#### Explica cómo se traduce la dirección lógica a la dirección física en el disco.

Partiendo de los conceptos de que la direccion logica es cuando el sistema de archivos organiza los datos en bloques, que son unidades abstractas que el sistema operativo gestiona, mientras que, la direccion fisica es cuando el disco tiene una estructura fisica real, donde se almacenan los datos

El sistema de archivos, usando estructuras como la MFT (NTFS) o los inodos (EXT4), mapea los bloques lógicos a bloques físicos específicos en el disco.

En discos duros, la traducción se basa en la geometría del disco (cilindros, cabezas y sectores). En SSDs, se realiza un mapeo lógico-físico mediante gestión de bloques lógicos y técnicas como nivelación de desgaste.

Para acceder a los datos una vez realizada la traduccion, el sistema operativo solicita al controlador del disco que acceda a los sectores físicos donde están almacenados los datos.

#### Proporciona un ejemplo práctico de cómo un archivo se almacena físicamente

Un video de 10 MB llamado gatito.mp4 se guarda en un SSD.

Fragmentación en Páginas:

El archivo se divide en bloques lógicos más pequeños, de 4 KB cada uno. En este caso, el archivo ocupa 2,560 páginas lógicas.

Mapeo Lógico-Físico:

El controlador del SSD utiliza una tabla de asignación interna (FTL, Flash Translation Layer) para asignar cada página lógica a un bloque físico en las celdas de memoria NAND. Ejemplo:
Página lógica 1 → Bloque físico A12.
Página lógica 2 → Bloque físico B45.

Nivelación de Desgaste:

El controlador distribuye las páginas a bloques NAND diferentes para evitar que una misma celda se desgaste con demasiadas escrituras.

Resultado:

El archivo gatito.mp4 está disperso en múltiples bloques NAND, pero el controlador del SSD gestiona la correspondencia lógica-física para el acceso rápido.


### Ejercicio 4: Mecanismos de acceso a los archivos

***Acceso Secuencial:*** 

En el acceso secuencial, los datos se leen o escriben en un orden continuo, uno tras otro, sin saltarse ninguna parte del archivo. Este tipo de acceso es común en medios como cintas magnéticas o archivos de registros, donde los datos se procesan de manera lineal, lo que puede ser menos eficiente si se necesita acceder a información específica sin seguir el orden.

***Acceso Aleatorio:*** 

El acceso aleatorio permite leer o escribir datos en cualquier parte del archivo sin seguir un orden secuencial. Esto es posible gracias a la estructura de direccionamiento del sistema de archivos y se utiliza en discos duros, SSDs y memoria RAM, lo que permite un acceso rápido y eficiente a cualquier bloque de datos, independientemente de su ubicación.

***Acceso por Paginación:*** 

Los datos se dividen en páginas de tamaño fijo, que pueden ser cargadas o almacenadas independientemente. Este mecanismo es común en sistemas de memoria virtual, donde las páginas se cargan a la memoria RAM bajo demanda, optimizando el uso de la memoria al almacenar solo las páginas activas en la memoria física, mientras que el resto se mantiene en el disco.

***Acceso Secuencial con Buffer:*** 

Utiliza un área de memoria temporal (buffer) para almacenar datos antes de transferirlos, lo que mejora el rendimiento al reducir la cantidad de accesos físicos al dispositivo de almacenamiento. Este mecanismo es común en aplicaciones como la transmisión de video, donde los datos se leen de manera secuencial desde el disco al buffer y luego se procesan desde allí.

***Acceso por Índices:*** 

Utiliza una tabla o estructura de índice que actúa como un "mapa" de las ubicaciones físicas de los datos en el disco. Este mecanismo permite acceder rápidamente a partes específicas de un archivo sin necesidad de leerlo secuencialmente, lo que es ideal para sistemas de bases de datos o sistemas de archivos que gestionan grandes volúmenes de datos dispersos.

***Acceso Secuencial con Prelectura:***

El sistema lee datos de manera anticipada antes de que se soliciten, basándose en patrones predecibles de acceso. Esto mejora la eficiencia al reducir el tiempo de espera durante la lectura, siendo útil en aplicaciones como la reproducción de música o video, donde los archivos se cargan en el buffer para asegurar una experiencia fluida.

***Acceso a través de Bloques o Clústeres:*** 

En sistemas como FAT32 o NTFS, los archivos se dividen en clústeres, que son unidades de almacenamiento más grandes que contienen varios bloques. El sistema de archivos gestiona el acceso a estos clústeres, lo que puede causar fragmentación si los archivos no se ajustan perfectamente a los límites de clústeres, aunque mejora la gestión del espacio de almacenamiento.

#### Un archivo secuencialmente.

1. INICIO
2. Iniciar el proceso de lectura del archivo "archivo.txt".
3. Abrir el archivo en modo lectura.
4. Comprobar si el archivo está disponible.
5. Iniciar un ciclo de lectura del archivo.
6. Leer el primer bloque de datos.
7. Procesar el bloque de datos leído.
8. Verificar si hay más datos para leer (comprobar si no se ha llegado al final del archivo).
9. Si no se ha llegado al final, ir al paso 5 (leer el siguiente bloque).
10. Si se ha llegado al final, salir del ciclo de lectura.
11. Cerrar el archivo y finalizar el proceso.
12. FIN

#### Un archivo directamente mediante su posición.

1. INICIO
2. Iniciar el proceso de lectura del archivo "gatito2.txt".
3. Abrir el archivo en modo lectura.
4. Comprobar si el archivo está disponible.
5. Definir la posición de inicio, especificando el byte o bloque que se desea leer (por ejemplo, byte 100 o bloque 15).
6. Posicionarse en la dirección física correspondiente en el archivo.
7. Leer el dato en la posición actual del archivo.
8. Procesar el dato leído.
9. Verificar si se desea leer más datos desde otras posiciones específicas.
10. Si se desean más lecturas, ir al paso 5 (otra ubicación).
11. Cerrar el archivo y finalizar el proceso.
12. FIN

#### Un archivo utilizando un índice

1. INICIO
2. Iniciar el proceso de acceso al archivo "archivo.txt".
3. Abrir el archivo en modo lectura.
4. Crear o cargar el índice (una tabla que mapea claves a posiciones en el archivo).
5. Comprobar si el archivo y el índice están disponibles.
6. Seleccionar la clave para la que se desea acceder al archivo (ID o nombre).
7. Buscar la clave en el índice y obtener la posición correspondiente en el archivo.
8. Posicionarse en la ubicación del archivo que corresponde a esa clave.
9. Leer el dato de esa ubicación en el archivo.
10. Procesar el dato leído.
11. Cerrar el archivo y finalizar el proceso.
12. FIN

#### Compara las ventajas de cada mecanismo dependiendo del caso de uso

***Acceso Secuencial:*** 

Este mecanismo lee los datos en un orden continuo, sin saltarse ninguna parte del archivo. Es eficiente para archivos grandes y de naturaleza secuencial, como logs o registros, donde se procesan las entradas una por una. La principal ventaja es su simplicidad y bajo consumo de recursos, ya que solo se lee un bloque de datos a la vez. Sin embargo, no permite acceder directamente a una ubicación específica, lo que lo hace menos adecuado para archivos que requieran acceso no lineal.

***Acceso Directo:***

El acceso directo permite leer o escribir datos en cualquier parte del archivo sin tener que recorrerlo secuencialmente. Este mecanismo es ideal para archivos grandes donde se necesita acceder rápidamente a ubicaciones específicas, como bases de datos o imágenes. Reduce el tiempo de espera al saltar directamente a la posición deseada. No obstante, su eficiencia depende de la organización del archivo y puede ser menos óptimo si el archivo está muy fragmentado.

***Acceso por Índice:*** 

Este mecanismo utiliza una estructura de índice para mapear claves a posiciones específicas en el archivo, permitiendo un acceso rápido y eficiente a los datos. Es ideal para bases de datos y archivos grandes y estructurados, ya que facilita la búsqueda y recuperación de información sin tener que leer el archivo entero. Aunque requiere más espacio para almacenar el índice, mejora significativamente el rendimiento en consultas y actualizaciones, especialmente en sistemas con grandes volúmenes de datos dispersos.


### Ejercicio 5: Modelo jerárquico y mecanismos de recuperación en caso de falla


#### Diseña un modelo jerárquico para un sistema de archivos con al menos tres niveles de directorios.

```
/ (Raíz)
├── /Documents
│   ├── /Personal
│   │   ├── cedula.docx
│   │   ├── ingresos.docx
│   ├── /Escuela
│   │   ├── the_last_dance.docx
│   │   ├── tareas.pdf
├── /Music
│   ├── /Rock
│   │   ├── Blackbird.mp3
│   │   ├── JustPretend.mp3
│   ├── /HIP-HOP
│   │   ├── DeboEntender.mp3
│   │   ├── Eres.mp3
├── /Pictures
│   ├── /Vacaciones
│   │   ├── ixtapa.jpg
│   │   ├── miranchito.jpg
│   ├── /Fiestas
│   │   ├── graduacion.jpg
│   │   ├── cumpleaños.jpg
```
#### Simula una falla en un directorio específico y describe los pasos necesarios para recuperarlo

Supongamos que, debido a una falla en sistema o por error humano, el directorio /Pictures/Vacaciones ha desaparecido o no se puede acceder. Los archivos que estaban en ese directorio, como ixtapa.jpg y miranchito.jpg, no son accesibles y al intentar acceder a ellos, se obtiene el mensaje "No such file or directory".


1. Verificar la Falla

* Primero, confirmamos que el directorio realmente ha desaparecido usando el comando ```ls```:  ```ls /Pictures/Vacaciones```

* Si el directorio no existe, el sistema devolverá un error similar a ***"No such file or directory"***.

2. Revisar los Permisos

* Verificamos si el problema es un error de permisos en lugar de la eliminación del directorio: ```ls -l /Pictures```

* Si ```/Pictures/Vacaciones``` sigue allí pero con permisos incorrectos, corregimos los permisos con: ```sudo chmod -R 755 /Pictures/Vacaciones```

3. Comprobar si los Archivos Están Perdidos o Eliminados4

* Usamos el comando find para verificar si los archivos aún existen en alguna parte del sistema: ```sudo find / -name "ixtapa.jpg"```

* Si los archivos son encontrados en alguna ubicación diferente, podemos moverlos de nuevo al directorio correcto.

4. Revisar el Sistema de Archivos

* Si el directorio y los archivos parecen haber desaparecido sin razón, puede ser un problema con el sistema de archivos. Para verificar y reparar cualquier error, usamos ```fsck```:

* Primero, identificamos la partición que contiene el directorio ```/Pictures```: ```df /Pictures```

* Luego, ejecutamos ```fsck``` en la partición correspondiente: ```sudo fsck /dev/sdX```

* Reemplazamos ```/dev/sdX``` con la partición correspondiente (por ejemplo, ```/dev/sda1```).

5. Recuperación de Archivos con TestDisk
* Si el sistema de archivos está dañado o los archivos han sido eliminados, podemos intentar usar ***TestDisk***, una herramienta de recuperación de datos:
* Instalamos TestDisk (si no está instalado): ```sudo apt install testdisk```

* Ejecutamos TestDisk: ```sudo testdisk```

* Seleccionamos la unidad correspondiente, luego "Analyse" y seguimos las instrucciones para intentar recuperar el directorio perdido.

6. Restauración desde Copias de Seguridad

* Si tienes configuradas copias de seguridad automáticas o manuales, puedes restaurar el directorio utilizando la herramienta correspondiente:

* Si usas ```rsync``` para respaldos locales, puedes restaurar desde un respaldo: ```rsync -av /mnt/backup/Pictures/Vacaciones /Pictures/```

* Si tienes una copia en la nube (por ejemplo, Google Drive), puedes usar herramientas como rclone para restaurar los archivos: ```rclone copy remote:/Pictures/Vacaciones /Pictures/```

7. Uso de ```extundelete``` para Recuperación de Archivos Eliminados

* Si el directorio fue eliminado y no tienes una copia de seguridad, puedes intentar recuperar los archivos con ```extundelete``` si usas un sistema de archivos ext3 o ext4:

* Asegúrate de que la partición no esté montada: ```sudo umount /dev/sdX1```

* Ejecuta ```extundelete``` para recuperar archivos: ```sudo extundelete /dev/sdX1 --restore-directory /Pictures/Vacaciones```

* Los archivos recuperados se guardarán en el directorio ```RECOVERED_FILES```.

8. Reparación de Archivos Dañados

* Si los archivos en el directorio ```/Pictures/Vacaciones``` están corruptos, podemos intentar repararlos usando herramientas como ```jpegoptim``` para imágenes: ```sudo apt install jpegoptim
jpegoptim --repair /Pictures/Vacaciones/*.jpg```

* Esto intentará reparar archivos JPEG dañados, si los había en el directorio.

9. Verificación Final

* Después de restaurar el directorio y los archivos, verificamos que todo esté en orden: ```ls /Pictures/Vacaciones```

* Asegúrate de que los archivos sean accesibles y estén intactos.

#### Explica qué herramientas o técnicas de respaldo (backup) utilizarías para evitar pérdida de datos

***Copias de seguridad en la nube***

* Google Drive / Dropbox / OneDrive: Estas plataformas de almacenamiento en la nube permiten subir archivos importantes para garantizar su protección. Muchos de estos servicios permiten sincronizar carpetas automáticamente.

* Backblaze / CrashPlan / Acronis: Servicios de respaldo en la nube específicamente diseñados para realizar copias de seguridad automáticas y regulares de todo el sistema o archivos específicos.


***Copias de seguridad en medios removibles***

* Software de copias de seguridad como Acronis True Image o Macrium Reflect: Estos programas permiten hacer imágenes completas del sistema, lo que incluye el sistema operativo, configuraciones y todos los archivos. Esto es útil para una restauración rápida en caso de fallo total del sistema.

* Copia de seguridad en discos externos o Blu-Ray: Hacer copias regulares de los archivos más importantes en discos duros externos o incluso en discos Blu-Ray. Aunque menos convenientes que la nube, estos medios físicos ofrecen una capa adicional de protección fuera del alcance de ataques en línea.


## Protección y Seguridad

### Ejercicio 1: Concepto y objetivos de protección y seguridad

#### *Define los conceptos de protección y seguridad en el contexto de sistemas operativos.

***Seguridad.***
Es la capacidad de un sistema para proteger sus recursos, datos y funcionalidades contra amenazas internas y externas, y garantizar la integridad, disponibilidad y confidencialidad de la información.

***Proteccion.***
Es la capacidad de un sistema para proteger sus recursos, datos y funcionalidades contra amenazas internas y externas, y garantizar la integridad, disponibilidad y confidencialidad de la información.

#### ***Identifica los objetivos principales de un sistema de protección y seguridad, como confidencialidad, integridad y disponibilidad.***

***Confidencialidad.***

* Garantiza que la información solo sea accesible para los usuarios o procesos autorizados. Protege los datos sensibles de accesos no autorizados, como contraseñas, documentos privados o información confidencial. Los mecanismos de confidencialidad incluyen la encriptación de datos y el control de acceso.

***Integridad.***

* Asegura que los datos no sean modificados, alterados ni destruidos de manera no autorizada. Esto significa que la información se mantiene exacta y completa. Los sistemas implementan sumas de verificación, firmas digitales y protocolos de auditoría para garantizar que los datos sean consistentes y no hayan sido comprometidos.

***Disponibilidad.***

* Asegura que los recursos y datos del sistema estén disponibles para los usuarios autorizados cuando los necesiten. La disponibilidad implica la resiliencia del sistema frente a fallos, ataques o interrupciones.

***Autenticidad.***
* Verifica que tanto los usuarios como los procesos sean quienes dicen ser. Esto se logra a través de mecanismos como autenticación de usuarios (contraseñas, biometría, tokens) y autenticación de mensajes (firmas digitales).

***No Repudio.***
* Garantiza que ninguna de las partes involucradas en una transacción pueda negar su participación. Esto se logra mediante registros de auditoría y firmas digitales que vinculan de manera irrefutable las acciones con las entidades que las realizaron.

#### ***Da un ejemplo práctico de cómo se aplican estos objetivos en un sistema operativo.***

Un usuario necesita acceder al sitio web para comprar boletos para el concierto de Santa Fe Klan.

* Confidencialidad

El usuario debe ingresar su contraseña para autenticar su identidad antes de poder realizar la compra de boletos. Si la contraseña es incorrecta, el sistema niega el acceso a la cuenta del usuario y a la opción de compra.

* Integridad

Antes de completar la compra, el sistema genera una suma de verificación de los detalles de la compra, como el número de boletos y la información de pago. Si algún dato ha sido alterado de manera no autorizada, la compra es rechazada y el sistema alerta al usuario sobre la posible alteración.

* Disponibilidad

Si el servidor principal experimenta un fallo técnico, el sistema se redirige automáticamente al servidor de respaldo, garantizando que el usuario pueda seguir comprando boletos sin interrupciones ni pérdida de datos.

* Autenticidad

Después de ingresar su contraseña, el sistema solicita un código temporal enviado al teléfono móvil del usuario. Solo si ambos factores son correctos, se permite al usuario acceder a la plataforma de compra y realizar la transacción.

* No repudio

Cuando el usuario finaliza la compra de boletos, el sistema registra la transacción en el log de auditoría, incluyendo el ID del usuario, la hora de la compra y los detalles de los boletos adquiridos. Esto asegura que el usuario no pueda negar haber realizado la compra en un futuro.


### Ejercicio 2: Clasificación aplicada a la seguridad

#### Investiga las clasificaciones comunes de la seguridad, como física, lógica y de red.

* Seguridad Física:

La seguridad física se refiere a las medidas que se implementan para proteger los componentes tangibles de un sistema de computadoras, redes y datos. Esto incluye la protección de los dispositivos, servidores y centros de datos contra accesos no autorizados, daños físicos, robos o desastres naturales.

* Seguridad Lógica:

La seguridad lógica se refiere a las medidas tecnológicas que protegen los sistemas de información contra accesos no autorizados, modificaciones no deseadas, o ataques cibernéticos. Esto incluye la protección de software, redes y bases de datos para garantizar que solo los usuarios o procesos autorizados puedan acceder a los recursos del sistema.

* Seguridad de Red:

La seguridad de red se enfoca en proteger las infraestructuras de red (como routers, switches, y conexiones de red) para garantizar que los datos viajen de manera segura entre dispositivos y sistemas. Esto incluye prevenir ataques a la red, proteger la privacidad de las comunicaciones y asegurar la disponibilidad de los servicios en la red.

#### Explica el papel de cada clasificación en la protección de un sistema operativo

* Seguridad Física

La seguridad física protege los componentes hardware del sistéma operativo, controlando el acceso a los servidores y dispositivos de almacenamiento. Medidas como cerraduras, cámaras de vigilancia y proteccion ante desastres son esenciales. Un acceso físico no autorizado podría comprometer los datos. Además, la redundancia energética asegura que el sistema funcione incluso ante fallos.

* Seguridad Lógica

La seguridad lógica protege el sistema operativo a nivel de software, usando contraseñas, cifrado de datos y autenticación multifactor. Listas de control de acceso (ACL) limitan los permisos de los usuarios. Monitorear y auditar actividades también es clave para prevenir intrusiones. Esta capa garantiza la confidencialidad e integridad de los datos.

* Seguridad de Red

La seguridad de red protege las comunicaciones entre dispositivos con firewalls y VPNs. Sistemas de detección de intruciones (IDS) previenen accesos no autorizados. Cifrado de datos mantiene la confidencialidad durante la transmisión. La segmentación de red limita los riesgos y mejora la protección de recursos críticos.

#### Proporciona ejemplos prácticos de herramientas o técnicas utilizadas en cada clasificación.

* Seguridad Física

***Barrera de seguridad eléctrica:*** 

Implementar un sistema de barreras de seguridad eléctrica alrededor de la zona de servidores para evitar que cualquier intruso acceda físicamente, activando una alarma si se cruza la línea delimitada.

***Brazaletes biométricos:*** 
Usar brazaletes biométricos para garantizar el acceso de los empleados a zonas restringidas, de manera que se registre no solo la identidad, sino también el patrón de actividad física del usuario.

***Revestimiento a prueba de sismos:*** 
Utilizar materiales especiales en los servidores y racks, como revestimientos a prueba de sismos que protejan los equipos de desastres naturales en regiones propensas a terremotos.

* Seguridad Lógica

***Token USB personalizado:*** 
Usar un token USB personalizado que se conecte al sistema para obtener acceso a archivos o aplicaciones, junto con un código de acceso único cada vez que se use, agregando una capa extra de seguridad.

***Búsqueda de anomalías en el comportamiento:*** 
Implementar una herramienta de inteligencia artificial que analice el comportamiento de los usuarios en el sistema, detectando patrones anómalos que podrían indicar un ataque interno, como el uso inusual de archivos confidenciales.

***Cifrado homomórfico:*** 
Usar cifrado homomórfico para procesar datos cifrados sin necesidad de descifrarlos, lo que permite realizar análisis sin exponer información sensible, protegiendo la integridad de los datos en entornos colaborativos.

* Seguridad de Red

***Análisis de tráfico con Inteligencia Artificial:*** 

Implementar IA para el análisis de tráfico de red, que no solo detecte patrones de tráfico maliciosos, sino que también sea capaz de adaptarse y aprender de nuevos ataques.

***Redes de perímetro dinámicas:*** 
Usar redes de perímetro dinámicas que cambian la configuración y reglas de seguridad basadas en la hora del día o la ubicación del usuario, dificultando la evasión de medidas de seguridad estáticas.

***Redes de “honey pots” de alto riesgo:*** Configurar honey pots de alto riesgo, sistemas que imitan servidores vulnerables, pero que en realidad están completamente controlados, y se utilizan para desviar a los atacantes mientras se recopilan datos sobre sus técnicas.


### Ejercicio 3: Funciones del sistema de protección

#### Describe cómo un sistema de protección controla el acceso a los recursos.

Un sistema de protección controla el acceso a los recursos del sistema, como archivos y dispositivos, garantizando que solo los usuarios o procesos autorizados puedan interactuar con ellos. Este control comienza con la autenticación, que verifica la identidad del usuario. Luego, se gestionan los permisos mediante autorización, determinando qué acciones puede realizar el usuario sobre los recursos. Finalmente, las auditorías registran las actividades de acceso para detectar posibles accesos no autorizados. Estos mecanismos aseguran que los recursos del sistema estén protegidos contra el acceso indebido y mantienen la integridad y seguridad de la información.


#### Explica las funciones principales como autenticación, autorización y auditoría.

* Autenticación

La autenticación es el proceso que permite verificar la identidad de un usuario o entidad que intenta acceder a un sistema. Su función principal es asegurarse de que quien solicita acceso sea quien dice ser, utilizando factores como contraseñas, biometría o tokens. Cuando un usuario ingresa sus credenciales, el sistema las compara con las almacenadas para confirmar su identidad. Es un paso crucial para prevenir el acceso no autorizado. Sin autenticación, sería imposible garantizar que los usuarios estén quienes dicen ser, poniendo en riesgo la seguridad del sistema.

* Autorización

La autorización se encarga de definir qué recursos puede acceder y qué acciones puede realizar un usuario dentro de un sistema, después de haber sido autenticado. Se basa en un conjunto de reglas y políticas, como listas de control de acceso (ACL) o roles, que limitan los privilegios de los usuarios. La autorización previene que los usuarios accedan o modifiquen recursos para los cuales no tienen permiso. Esto es fundamental para asegurar que los usuarios solo puedan realizar las acciones que su rol o nivel de privilegio les permite. Sin autorización, un usuario podría obtener acceso a información sensible o realizar cambios no deseados.

* Auditoría

La auditoría es el proceso de registrar y analizar las acciones realizadas por los usuarios dentro de un sistema. Su función principal es crear un registro detallado de eventos, como accesos, cambios de configuración o intentos de intrusión. Estos registros, conocidos como logs, permiten revisar y verificar qué actividades se realizaron, quién las realizó y cuándo. La auditoría es crucial para detectar comportamientos sospechosos o violaciones de políticas de seguridad. Además, ayuda en la resolución de incidentes y garantiza que las prácticas de seguridad se estén cumpliendo adecuadamente en todo momento.

#### Diseña un caso práctico donde se muestren las funciones de un sistema de protección en acción.

* Autenticación

La autenticación en el concierto de Santa Fe Klan se lleva a cabo cuando los asistentes presentan sus boletos para acceder al evento. Los boletos, que pueden ser digitales o físicos, contienen un código único que el sistema escanea al momento de la entrada. El sistema verifica que el código corresponda a una entrada legítima, asegurando que solo aquellos con boletos válidos puedan ingresar al evento. Este proceso es crucial para evitar que personas no autorizadas ingresen sin un pase adecuado.

* Autorización 

La autorización determina qué áreas del concierto pueden ser accesadas por los asistentes según el tipo de entrada que tienen. Aquellos con boletos generales solo pueden acceder a las áreas comunes, mientras que los asistentes con boletos VIP pueden acceder a zonas exclusivas, como el área cerca del escenario o el backstage. El personal encargado de la seguridad controla el acceso a estas zonas, asegurándose de que los asistentes solo puedan ingresar a las áreas para las cuales tienen permiso, garantizando el orden y la seguridad.

* Auditoría

La auditoría en el concierto se refiere al registro y monitoreo de todas las actividades relacionadas con el acceso y comportamiento dentro del evento. Todos los accesos son registrados, desde el momento en que los asistentes ingresan hasta cualquier cambio en las zonas autorizadas. Si se detecta alguna irregularidad, como un acceso no autorizado o el intento de entrar a una zona restringida, los registros de auditoría permiten rastrear el incidente. Este proceso es clave para la seguridad y para garantizar que se sigan todas las políticas del evento de manera adecuada.


### Ejercicio 4: Implantación de matrices de acceso

#### Diseña una matriz de acceso para un sistema con al menos 3 usuarios y 4 recursos.

Se muestra la tabla de la simulando la matriz, con el escenario de un cocierto en donde tenermos 3 usuarios y hay 4 difrentes recursos los cuales estan distibuido entre los usuarios  

| **Usuario / Recurso**     | **Recurso 1 (Entradas)**         | **Recurso 2 (Zonas del concierto)**  | **Recurso 3 (Backstage)** | **Recurso 4 (Sistema de impresión de boletos)** |
|---------------------------|----------------------------------|--------------------------------------|---------------------------|------------------------------------------------|
| **Asistente General**      | Lectura (Verificar boleto)       | Acceso general (zona pública)        | Ninguno                   | Ninguno                                         |
| **Asistente VIP**          | Lectura (Verificar boleto)       | Acceso VIP (zona cercana al escenario) | Acceso VIP (backstage)     | Ninguno                                         |
| **Personal de Seguridad**  | Ninguno                          | Acceso total (todas las zonas)       | Acceso total (backstage)   | Lectura (verificación de boletos)              |


#### Explica cómo esta matriz se utiliza para controlar el acceso en un sistema operativo.

Imaginamos que tenemos un sistema operativo que gestiona un sistema de archivos con diferentes directorios y archivos relacionados con un evento, similar a un concierto de Santa Fe Klan. La matriz de acceso en este contexto ayuda a gestionar el acceso a estos archivos y directorios.

**Recurso 1 (Entradas):**

* Asistente General:

Lectura: Puede ver el archivo del boleto digital o físico (equivalente a un archivo de entrada).
En el sistema operativo, esto se traduce en que el usuario tiene permiso de lectura sobre un archivo específico, lo que le permite 
ver su contenido (en este caso, el código QR o el número de boleto).

* Asistente VIP:

Lectura: El asistente VIP también tiene permiso para ver el boleto (en el sistema operativo, esto sería permitir que un usuario vea su archivo de entrada).

* Personal de Seguridad:

Ninguno: En un sistema operativo, el Personal de Seguridad no necesita interactuar directamente con las entradas (en el caso de un sistema de archivos), pero tiene permisos para verificar el acceso y el estado de los archivos de los boletos. Esto se traduciría en un permiso de verificación.

**Recurso 2 (Zonas del concierto):**

* Asistente General:

Acceso general: El asistente general solo tiene acceso a las zonas comunes del evento, como las áreas de público general. En un sistema operativo, esto equivaldría a un usuario con permisos limitados para acceder a ciertos directorios, pero no a otros más restringidos.

* Asistente VIP:

Acceso VIP: Un asistente VIP tiene permisos especiales para ingresar a áreas restringidas (zona cerca del escenario). En un sistema operativo, este tipo de acceso corresponde a un usuario con permisos avanzados que puede acceder a recursos adicionales, como directorios especiales o archivos privados.

* Personal de Seguridad:

Acceso total: El personal de seguridad tiene acceso total a todas las zonas del evento, como un administrador o root en un sistema operativo que puede acceder a cualquier archivo o proceso del sistema operativo sin restricciones.

**Recurso 3 (Backstage):**

* Asistente General:

Ninguno: El asistente general no tiene acceso a áreas VIP como el backstage. En términos de sistema operativo, esto sería como un usuario estándar que no tiene permisos para acceder a directorios o archivos restringidos.

* Asistente VIP:

Acceso VIP: El asistente VIP tiene acceso al backstage. Este es un privilegio especial que se otorga a usuarios con permisos avanzados. En un sistema operativo, esto sería equivalente a un usuario que tiene permisos especiales para modificar archivos o procesos importantes del sistema.

* Personal de Seguridad:

Acceso total: El personal de seguridad tiene acceso al backstage, lo que en un sistema operativo corresponde a un administrador del sistema o root, que tiene acceso sin restricciones a todo el sistema.

**Recurso 4 (Sistema de impresión de boletos):**

* Asistente General:

Ninguno: Un asistente general no necesita interactuar con el sistema de impresión de boletos en un sistema operativo, de manera similar a cómo no tendría permiso para acceder a dispositivos de impresión o configurar una impresora.

* Asistente VIP:

Ninguno: Al igual que el asistente general, el asistente VIP no tiene permisos para interactuar con la impresora.

* Personal de Seguridad:

Lectura: El personal de seguridad tiene permisos para verificar los boletos. En un sistema operativo, esto podría equivaler a verificar archivos de boletos, pero no necesariamente modificarlos.

#### Simula un escenario donde un usuario intenta acceder a un recurso no permitido y cómo la matriz lo bloquea.
 

**Paso 1: Usuario "Asistente General" intenta acceder al Backstage**

(Autenticacion)

El Asistente General, al intentar acceder al Backstage del concierto, realiza una solicitud al sistema para ingresar a esta área restringida. Este usuario tiene un permiso limitado, como se especifica en la matriz de acceso, donde se indica que no tiene acceso al Backstage. La solicitud que realiza el asistente es una acción del sistema que requiere verificación, pues intenta interactuar con un recurso al que no tiene autorización para acceder.

**Paso 2: Verificación del sistema operativo**

(Autorizacion)

El sistema operativo juega un rol fundamental en la verificación de acceso. Antes de permitir que cualquier usuario interactúe con un recurso, el sistema consulta la matriz de acceso, que tiene la información de qué usuarios tienen permisos sobre qué recursos. En este caso, al verificar la matriz, el sistema encuentra que el Asistente General tiene asignado un "Ninguno" en la columna del Backstage, lo que indica que no tiene acceso autorizado. Esto activa el proceso de bloqueo y denegación del acceso al recurso.

**Paso 3: Bloqueo de acceso**

(Autorizacion)

Al detectar que el Asistente General no tiene los permisos necesarios para acceder al Backstage, el sistema operativo bloquea inmediatamente la acción. El sistema no permite que el asistente ingrese a esa zona. Esta es una medida de seguridad implementada para evitar accesos no autorizados a áreas restringidas, asegurando que solo los usuarios con los permisos adecuados puedan interactuar con los recursos correspondientes. Como resultado, el asistente recibe un mensaje de error informándole que no tiene los permisos necesarios.

**Paso 4: Auditoría del acceso**

(Auditoria)

Tras el intento fallido de acceso, el sistema operativo genera un log de auditoría que registra el evento para futuras revisiones. El log incluye detalles sobre la fecha, hora, el usuario que intentó acceder y el recurso al que intentaba ingresar, así como el motivo del rechazo del acceso. Esta información es valiosa para el administrador del sistema, que puede usarla para detectar intentos de acceso no autorizado o actividades sospechosas dentro del sistema. Mantiendo un registro completo para fines de seguridad y control.

### Ejercicio 5: Protección basada en el lenguaje

#### Explica el concepto de protección basada en el lenguaje.

Es un enfoque de seguridad que utiliza las características del lenguaje de programación para controlar lo que un programa puede o no hacer en el sistema. Al establecer restricciones como los tipos de datos y las operaciones permitidas, se evita que un programa acceda o modifique información que no debería. Esto ayuda a prevenir errores y vulnerabilidades como el acceso no autorizado a memoria o recursos del sistema. La idea es hacer que el programa funcione dentro de un marco seguro, protegiendo así el sistema de posibles fallos o ataques.

#### Proporciona un ejemplo de cómo un lenguaje como Java o Rust asegura la memoria y evita accesos no autorizados.


En Java, la seguridad de la memoria se maneja principalmente con la gestión automática de memoria y un modelo de seguridad basado en tipos. Esto ayuda a evitar accesos no autorizados a la memoria. Un ejemplo claro es que en Java se usan referencias de objetos en lugar de punteros directos como en lenguajes como C o C++. Esto significa que no se puede manipular la memoria directamente, lo que previene varios problemas, como acceder a zonas de memoria no permitidas o causar errores de seguridad.

#### Compara este enfoque con otros mecanismos de protección en sistemas operativos.

Mientras que en java se usan los objetos, mientras que en un sistema operativo se usa la paginacion y la segmentacion con lo que protegen su memoria, la segmentacion divide la memoria en segmentos logicos y la paginacion la divide en paginas de tamaño fijo, la principal ventaja es que puede asignar espacio de memoria a diferentes procesos y proteger areas criticas en el sistema

### Ejercicio 6: Validación y amenazas al sistema

#### Investiga y describe al menos tres tipos de amenazas comunes

**Malware (Software Malicioso)** 

El malware es cualquier tipo de software diseñado para dañar o acceder a sistemas de manera no autorizada. Incluye virus, troyanos, ransomware, spyware, entre otros. Estos programas maliciosos pueden robar información sensible, bloquear archivos o sistemas, o incluso tomar control total del dispositivo afectado. La prevención incluye el uso de software antivirus actualizado y evitar descargar archivos o hacer clic en enlaces sospechosos.

**Ataques de Fuerza Bruta** 

Un ataque de fuerza bruta consiste en probar todas las combinaciones posibles de contraseñas o claves hasta encontrar la correcta. Este tipo de ataque es efectivo cuando las contraseñas son débiles o de corta longitud. Los riesgos incluyen el acceso no autorizado a cuentas o sistemas, lo que puede resultar en el robo de información. Para prevenirlo, se recomienda usar contraseñas complejas, activar la autenticación de dos factores (2FA) y limitar los intentos fallidos de inicio de sesión.

**Inyección de Código (SQL Injection)** 

La inyección de código, especialmente la inyección SQL, ocurre cuando un atacante inserta código malicioso en formularios o campos de entrada en aplicaciones web para acceder o manipular bases de datos. Este ataque puede permitir al atacante robar datos sensibles, eliminar información o incluso tomar control del servidor. La prevención se logra utilizando consultas SQL preparadas, validando y limpiando las entradas de los usuarios y aplicando principios de mínimos privilegios en las bases de datos.

#### Explica los mecanismos de validación como autenticación multifactor y control de integridad.


**Autenticación Multifactor (MFA)**

Es un mecanismo de seguridad que requiere que los usuarios proporcionen dos o más factores de verificación para acceder a un sistema, en lugar de solo una contraseña. Los factores de autenticación generalmente se dividen en tres categorías:

* Algo que sabes: La contraseña o PIN, es algo que el usuario conoce.

* Algo que tienes: Un dispositivo físico como un token de seguridad, una tarjeta inteligente o un teléfono móvil.

* Algo que eres: Características biométricas como huellas dactilares, reconocimiento facial o escaneo del iris.

**Control de Integridad**

El control de integridad es un conjunto de técnicas y mecanismos diseñados para garantizar que los datos no sean alterados, dañados o manipulados sin autorización.

Los mecanismos de control de integridad incluyen:

* Sumas de comprobación: Se utiliza un algoritmo para calcular una suma de comprobación sobre los datos. Si los datos se alteran de alguna manera, la suma de comprobación cambiará, lo que permitirá detectar la modificación.

* Funciones hash: Son algoritmos que convierten datos de tamaño variable en un valor fijo. Un cambio en cualquier parte de los datos producirá un hash completamente diferente. Esto se utiliza para verificar que los datos no hayan sido alterados durante su transmisión o almacenamiento.

* Firmas digitales: Utilizan criptografía para crear una "firma" única para los datos, lo que permite verificar tanto la integridad como la autenticidad de los datos. Si el contenido se altera, la firma digital ya no será válida.

#### Diseña un esquema de validación para un sistema operativo con múltiples usuarios

**Esquema de Validación para Acceso a un Concierto**

1. Venta de Boletos (Primer Nivel de Validación)

La validación comienza cuando el usuario compra un boleto en línea, proporcionando sus datos personales y de pago. Tras la verificación de la compra, se emite un código QR único vinculado a la compra, que se utilizará para el acceso al evento. El proceso de pago incluye medidas de seguridad como 3D Secure o autenticación multifactor para confirmar la identidad del comprador, asegurando que la transacción sea legítima.

2. Validación del Boleto en el Evento (Segundo Nivel de Validación)

Al llegar al evento, el asistente presenta su boleto con el código QR, que se escanea para verificar su validez. Si el código es válido, se permite el acceso; si es inválido o ya ha sido usado, se deniega el acceso. En caso de duda, se puede solicitar la verificación mediante una identificación oficial o un sistema biométrico, como huella dactilar, para confirmar la identidad del asistente.

3. Control de Acceso durante el Evento (Tercer Nivel de Validación)


Durante el evento, se utilizan pulseras electrónicas o tarjetas NFC/RFID para controlar el acceso a áreas restringidas, como zonas VIP. Estas pulseras, vinculadas al boleto, se escanean en puntos específicos, limitando el acceso a áreas no permitidas. Además, se implementan sistemas de monitoreo en tiempo real con cámaras y personal de seguridad para detectar accesos no autorizados y tomar medidas inmediatas.

4. Protección de Datos Personales (Cuarto Nivel de Validación)

Los datos personales y de pago deben ser cifrados mediante protocolos como SSL/TLS para proteger la información durante la compra. Además, la base de datos de boletos se asegura con acceso restringido y firewalls, evitando filtraciones de datos personales. Para mayor privacidad, se pueden anonimizar los datos, utilizando identificadores como números de referencia en lugar de nombres reales.

### Ejercicio 7: Cifrado

#### Define los conceptos de cifrado simétrico y asimétrico.

**Cifrado simétrico** 

Es cuando se usa la misma clave tanto para cifrar como para descifrar la información. Es decir, tanto el que manda el mensaje como el que lo recibe deben tener la misma clave secreta. El problema es que si alguien llega a interceptar esa clave, podría acceder a toda la información cifrada.

**Cifrado asimétrico** 

Aquí se usan dos claves: una clave pública y una clave privada. La clave pública se usa para cifrar el mensaje y la clave privada es la única que puede descifrarlo. Lo bueno de este tipo de cifrado es que no es necesario compartir la clave secreta, ya que la pública puede ser distribuida libremente, pero la privada solo la tiene el receptor. 


#### Proporciona un ejemplo práctico de cada tipo de cifrado aplicado en sistemas operativos.

**Ejemplo de Cifrado Simétrico**

Un sistema operativo que usa un software de respaldo automático para guardar archivos sensibles en un servidor remoto. Para proteger los archivos, el software utiliza cifrado simétrico con AES. Cuando el usuario hace una copia de seguridad, los archivos se cifran automáticamente con una clave secreta. Esta clave se usa tanto para cifrar los archivos antes de enviarlos como para descifrarlos cuando se necesitan. Es importante mantener segura esa clave, porque si alguien la obtiene, podrá acceder a los archivos cifrados.

**Ejemplo de Cifrado Asimétrico**

En un sistema operativo que maneja correos electrónicos, el cifrado asimétrico puede usarse para enviar mensajes seguros. Supongamos que un usuario quiere mandar un mensaje confidencial. Primero obtiene la clave pública de su destino, la cual se usa para cifrar el correo. Solo el destinatario, que tiene la clave privada correspondiente, puede descifrarlo. De esta manera, aunque el correo sea interceptado, nadie más podrá leerlo, ya que solo el destinatario tiene la clave privada.

#### Simula el proceso de cifrado y descifrado de un archivo con una clave dada.

1. **Preparación del Archivo y la Clave**

* Archivo Original: Tenemos un archivo de texto con el siguiente contenido:

```La seguridad es esencial para proteger la información.```

* Clave Secreta: Definimos una clave secreta que usaremos para cifrar y descifrar:

```SuperClaveSegura456```

2. **Proceso de Cifrado**

* Elección del algoritmo

Seleccionamos un algoritmo de cifrado simétrico, por ejemplo, AES, para realizar el cifrado de los datos.

* Conversión del archivo a formato binario

El archivo de texto se convierte en una secuencia de bytes, que es la representación binaria del contenido.

* Aplicación del cifrado

Usamos la clave secreta ```SuperClaveSegura456``` para cifrar esos bytes mediante el algoritmo AES. El resultado es un archivo ilegible, transformado a datos cifrados.

Ejemplo de archivo cifrado (hexadecimal):

```3f6a9d8e56c1a47b21d3f904e738c9a0```

Este es el archivo cifrado, que no puede leerse sin la clave correcta.

3. **Proceso de Descifrado**

* Recuperación del archivo cifrado

El archivo cifrado (hexadecimal) se recibe o se recupera para su descifrado:

```3f6a9d8e56c1a47b21d3f904e738c9a0```

* Uso del mismo algoritmo y clave

Para descifrar, usamos el mismo algoritmo (AES) y la misma clave secreta que se utilizó para el cifrado, en este caso ```SuperClaveSegura456```.

* Descifrado de los datos

Aplicamos el algoritmo de descifrado a los datos cifrados, lo que transforma los bytes cifrados nuevamente en su forma original.

* Conversión a texto legible

Finalmente, convertimos los bytes descifrados de vuelta al texto legible, recuperando el archivo original.

Resultado Final:

```La seguridad es esencial para proteger la información```.
