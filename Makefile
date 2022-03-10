all: compilar
compilar: propietario mascota propietarioXmascota directorio main
	g++ -o out Propietario.o Mascota.o PropietarioXMascota.o Directorio.o MainVeterinaria.o 
propietario: Propietario.cpp Propietario.h
	g++ -c Propietario.cpp
mascota: Mascota.cpp Mascota.h
	g++ -c Mascota.cpp
propietarioXmascota: PropietarioXMascota.cpp PropietarioXMascota.h Propietario.h Mascota.h 
	g++ -c PropietarioXMascota.cpp
directorio: Directorio.cpp Directorio.h PropietarioXMascota.h
	g++ -c Directorio.cpp
main: MainVeterinaria.cpp Directorio.h
	g++ -c MainVeterinaria.cpp
clean: //Comando para borrar los o.
	@echo "Cleaning Compilation..."
	del *.o