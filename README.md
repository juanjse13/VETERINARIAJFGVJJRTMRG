# Veterinaria Totti-Ramirez-Restrepo

## Integrantes del equipo:

> Juan Francesco García Vargas ~ 8963676 ||
> Juan Jose Restrepo Toro ~ 8945973 ||
> Mateo Ramírez Gutierrez ~ 8962655 

## Descripción General:

La **veterinaria T-R-R** es una aplicación basada en C++, creada con el fin de almacenar y administrar los datos de usuarios y sus mascotas en varios sistemas de información para veterinarias. Está elaborado de manera que se pueda trabajar de manera sincrónica entre el mundo físico y el digital con suprema facilidad.

## Características y Funcionalidades:

Algunas capacidades que este programa tiene son las siguientes:

- Almacenamiento seguro de los datos clave de las mascotas y sus propietarios 
- Gestión avanzada de los datos (Agregar, modificar, eliminar y listar) por medio del directorio
- Visibilidad facilitada de la información específica de las mascotas y los propietarios registrados en el directorio
- Flexibilidad ante la cantidad de propietarios que tiene una mascota, y viceversa
- Autenticidad total de los números de identidad (Relacionados a la seguridad del almacenamiento) de propietarios y mascotas

El **diagrama UML** del programa se puede visualizar aquí: 

![UML](https://github.com/juanjse13/VETERINARIAJFGVJJRTMRG/blob/ClinicaFinalVersion/Project%20UML%20%283-9-2022%29.png)


## Métodos, entradas y salidas que se deben tomar en cuenta 

>Nota: La siguiente información es para desarrolladores.

Las clases primarias (**Propietario**, **Mascota**, y **PropietarioXMascota**) tienen el rol de guardar la información importante y poseer los métodos básicos que luego se utilizan en los del directorio. Es por ello que se repite la serie de gets/sets, mostrarDatos*NombreClase*,  y los constructores en cada uno.
 
En el **Directorio** tenemos las acciones principales que se describen a superficie en la sección de Características y Funcionalidades, las cuales se pueden resumir de la siguiente manera:
 - Los métodos de *agregarPropietario* y *agregarMascota* necesitan como entrada la clase instanciada para poder meterla dentro del mapa donde se almacenará la información. Es aquí donde están los condicionales que aseguran la "autenticidad total de los números de identidad" del sistema.
 - Los otros métodos de *agregar*, además los de *modificar* y *eliminar* toman como entrada el número de identificación del propietario/de la mascota (Respectivamente) y hacen lo que su nombre respectivo dice, sin ninguna salida en específico, además de los mensajes que confirman que la acción se ha realizado exitosamente. 
 - Los métodos de *listar* no toman ninguna entrada en especial, pero como salida imprimen sus respectivas clases que estén registradas en el directorio. 
 - Los métodos de *consultarPropietariosParaMascota* y *consultarMascotasParaPropietario* funcionan de manera muy similar a las anteriores. Usando el número de identificación como entrada, estos revisan las instancias de la clase opuesta a la que se dió por entrada, que a la vez están vinculadas a esta por medio del vector y va mostrando los datos de estas.
 - Los métodos de *pedirDatos* pueden ser denominados como los primarios del Directorio, pues son con estos que se ingresan los datos específicos de una nueva instancia de clase y al final se añaden al mapa de clase respectivo.
 - Los métodos *getCantidadPropietarios* y *cambiarEstadoMascota* son los unicos que difieren con "el molde" de los demás. El primero no tiene entrada, solo retorna el numero de propietarios que hay en el mapa. El segundo se utiliza cuando una mascota fallece, de modo que se pasan el número de identificación y la fecha de defunción para buscar a la mascota y registrar la fecha de defunción. 
