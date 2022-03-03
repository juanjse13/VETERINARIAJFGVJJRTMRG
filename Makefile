all: compilar
compilar: propietario mascota propietarioXmascota directorio main
	g++ -o out PropietarioVeterinario.o Mascota.o PropietarioXMascota.o Directorio.o MainVeterinaria.o 
propietario: PropietarioVeterinario.cpp PropietarioVeterinario.h
	g++ -c PropietarioVeterinario.cpp
mascota: Mascota.cpp Mascota.h
	g++ -c Mascota.cpp
propietarioXmascota: PropietarioXMascota.cpp PropietarioXMascota.h PropietarioVeterinario.h Mascota.h 
	g++ -c PropietarioXMascota.cpp
directorio: Directorio.cpp Directorio.h PropietarioXMascota.h
	g++ -c Directorio.cpp
main: MainVeterinaria.cpp Directorio.h
	g++ -c MainVeterinaria.cpp
clean: //Comando para borrar los o.
	@echo "Cleaning Compilation..."
	del *.o