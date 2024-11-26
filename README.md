# Get Next Line

## Descripción

El objetivo de este proyecto es implementar la función `get_next_line` que permite leer líneas completas de un archivo utilizando un descriptor de archivo (file descriptor). Esta función se puede usar repetidamente para leer el contenido de un archivo línea por línea.

---

## Archivos y Funciones

### **1. `get_next_line_utils.c`**

Este archivo contiene las funciones auxiliares necesarias para implementar `get_next_line`.

#### **Funciones**

- **`ft_strlen(char *s)`**
  - **Propósito:** Devuelve la longitud de la cadena `s` hasta `'\0'`.
  - **Paso a paso:**
    1. Inicia un contador `i` en 0.
    2. Recorre la cadena mientras no se encuentre el carácter `'\0'`.
    3. Incrementa `i` por cada carácter.
    4. Retorna el valor de `i`.

- **`ft_strjoin(char *dst, char *src)`**
  - **Propósito:** Concatena dos cadenas (`dst` y `src`) en una nueva cadena dinámica.
  - **Paso a paso:**
    1. Si `dst` es NULL, la inicializa como una cadena vacía.
    2. Si `src` es NULL, retorna NULL.
    3. Reserva memoria suficiente para una nueva cadena que contenga `dst + src + '\0'`.
    4. Copia los caracteres de `dst` en la nueva cadena.
    5. Luego, copia los caracteres de `src` después de los de `dst`.
    6. Finaliza la nueva cadena con `'\0'`.
    7. Libera `dst` y retorna la nueva cadena.

- **`ft_strchr(char *s, int c)`**
  - **Propósito:** Busca la primera aparición del carácter `c` en la cadena `s`.
  - **Paso a paso:**
    1. Recorre la cadena carácter por carácter.
    2. Si encuentra `c`, retorna un puntero a esa posición en `s`.
    3. Si no encuentra `c`, retorna NULL.

- **`ft_substr(char *s, int start, int size)`**
  - **Propósito:** Extrae un substring de la cadena `s`, comenzando en `start` y con una longitud máxima de `size`.
  - **Paso a paso:**
    1. Verifica si `s` es NULL. Si lo es, retorna NULL.
    2. Calcula la longitud de `s` con `ft_strlen`.
    3. Ajusta el tamaño del substring si el tamaño solicitado excede la longitud disponible desde `start`.
    4. Si `start` está fuera de los límites de `s`, retorna una cadena vacía.
    5. Reserva memoria para el substring.
    6. Copia `size` caracteres desde `s[start]` al nuevo substring.
    7. Finaliza el substring con `'\0'`.
    8. Retorna el substring.

---

### **2. `get_next_line.h`**

Este archivo es el **header** que define las macros y declara las funciones utilizadas.

#### **Contenido**

- **`BUFFER_SIZE`**
  - Define el tamaño del buffer utilizado por la función `read`.
  - Si no se proporciona al compilar, se define como 10.

- **Librerías**
  - Incluye `fcntl.h`, `stdlib.h`, `unistd.h`, y `stdio.h` para usar funciones como `read`, `malloc`, y `free`.

- **Prototipos**
  - Declara las funciones definidas en los otros archivos:
    - `ft_strlen`
    - `ft_strjoin`
    - `ft_substr`
    - `ft_strchr`
    - `ft_freeall`
    - `get_next_line`

---

### **3. `get_next_line.c`**

Este archivo contiene la implementación principal de `get_next_line`.

#### **Funciones**

- **`ft_freeall(char **s)`**
  - **Propósito:** Libera la memoria apuntada por `s` y la pone a NULL.
  - **Paso a paso:**
    1. Usa `free` para liberar la memoria.
    2. Asigna `NULL` al puntero.

- **`ft_get_line(char *s)`**
  - **Propósito:** Extrae una línea completa (hasta `\n` o fin de cadena) desde `s`.
  - **Paso a paso:**
    1. Calcula la posición del primer `\n` o fin de cadena.
    2. Usa `ft_substr` para copiar los caracteres desde el inicio hasta esa posición.
    3. Retorna el nuevo substring.

- **`ft_cleanstr(char *s)`**
  - **Propósito:** Limpia la parte de la cadena `s` que ya ha sido leída.
  - **Paso a paso:**
    1. Encuentra la posición inmediatamente después del `\n`.
    2. Si no hay más datos, libera y retorna NULL.
    3. Usa `ft_substr` para copiar la parte restante.
    4. Libera la cadena original y retorna la nueva.

- **`ft_readbuffer(int fd, char *s)`**
  - **Propósito:** Lee datos del archivo y los acumula en `s` hasta encontrar un `\n` o el final.
  - **Paso a paso:**
    1. Reserva un buffer dinámico.
    2. Usa `read` para leer datos del `fd` en bloques de `BUFFER_SIZE`.
    3. Si ocurre un error o se alcanza el final, libera el buffer y retorna.
    4. Concatena el contenido leído a `s` con `ft_strjoin`.
    5. Continua hasta encontrar un `\n` o el final del archivo.
    6. Retorna la cadena acumulada.

- **`get_next_line(int fd)`**
  - **Propósito:** Función principal que controla el flujo de lectura.
  - **Paso a paso:**
    1. Verifica que `fd` y `BUFFER_SIZE` sean válidos.
    2. Llama a `ft_readbuffer` para leer datos del archivo.
    3. Usa `ft_get_line` para extraer la línea actual.
    4. Limpia la parte procesada de la cadena estática con `ft_cleanstr`.
    5. Retorna la línea leída o NULL si no hay más datos.

---

## Flujo Completo de `get_next_line`

1. **Inicio**
   - Valida los parámetros de entrada (`fd` y `BUFFER_SIZE`).
   - Usa la variable estática `str` para preservar datos entre llamadas.

2. **Lectura de datos**
   - `ft_readbuffer` lee el archivo y acumula datos en `str`.

3. **Extracción de línea**
   - `ft_get_line` extrae la primera línea completa de `str`.

4. **Limpieza**
   - `ft_cleanstr` elimina los datos ya procesados de `str`.

5. **Retorno**
   - Devuelve la línea leída o NULL si no hay más datos.

---

## Autor

- **@AndreaILara**
