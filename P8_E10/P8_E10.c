/*
    Autor: Zuliani,Agustin
    Fecha: 05/08/21
    Programa: Practica 8 Ejercicio 10
*/

/*
    Entrada:
        - Recivimos del archivo RESULTADOS.DAT --> Nro Estudiante,Nro Ejercicio, Nota
    Salida:
        - 
    Metodologia:
        - Inicializamos el registro todo en cero
        - Cargamos los datos en CREAR --> Carga todo el archivo en el registro RES
        - Mostrar por pantalla el alumno con la mayor calificacion en MAYOR
        - Calcular y mostrar el porcentaje de alumnos desaprobados, para esto debe acceder a la funcion PORCENTAJE

    Constante:
        CANT_ALUMNOS = 50
        CANT_EVALUACIONES = 5
    
    Tipo Registro RES = 
        Entero: NroEst
        Real: Nota[CANT_EVALUACIONES]
        Real: Calif_final
    fin tipo

    Algortimo: P8_E10

        Variables:
            RES: ListaAlumnos[CANT_ALUMNOS]
            Real: Porc_des
        
        Inicio:
            INICIALIZAR (ListaAlumnos)
            CREAR (ListaAlumnos)
            MAYOR (ListaAlumnos)
            Porc_des <-- PORCETANJE (ListaAlumnos)
            Escribir ("El porcentaje de alumnos desaprobados fue:",Porc_des)
    Fin.

    Subrutina INICIALIZAR (E/S: A[CANT_ALUMNOS]:RES)
        Variables:
            Entero: i,j
        Inicio:
            Repetir para i <-- 1,CANT_ALUMNOS
                A[i].Calif_final <-- 0
                A[i].NroEst <-- 0
                Repetir para j <-- 1,CANT_EVALUACIONES
                    A[i].Nota[j] <-- 0
                fin para.
            fin para.                 
    Fin subrutina INICIALIZAR

    Subrutina CREAR (E/S: A[CANT_ALUMNOS]:RES)
        Variables:
            Archivo: *F
            Entero: NroEjer
            Entero: NroEstudiante
            Real: Nota
            Entero: i
        Inicio:
            Abrir(F,"RESULTADO.DAT","lectura")
            i <-- 1
            Leer(F,NroEstudiante,NroEjer,Nota)
            A[i].NroEst <-- NroEstudiante
            A[i].Nota[NroEjer] <-- Nota
            Repetir mientras (NO(EOF(F)))
                i <-- i + 1
                Leer(F,NroEstudiante,NroEjer,Nota)
                A[i].NroEst <-- NroEstudiante
                A[i].Nota[Nroejer] <-- Nota
            fin mientras.
            Cerrar(F)
    Fin subrutina CREAR

    Subrutina MAYOR (E/S: A[CANT_ALUMNOS]:RES)
        Variables:
            Entero: alumno,nota,cant
            Entero: ind_mayor[CANT_ALUMNOS],i,j
            Real: mayor
        Inicio:
            Repetir para alumno <-- 1,CANT_ALUMNOS
                A[alumno].Calif_final <-- 0
                ind_mayor[alumno] <-- -1
                Repetir para nota <-- 1,CANT_EVALUACIONES
                    A[alumno].Calif_final <-- A[alumno].Calif_final + A[alumno].Nota[nota]
                fin para.
                A[alumno].Calif_final <-- A[alumno].Calif_final / 5.0
            fin para.

            cant <-- 1
            i <-- 1
            Repetir para alumno <-- 1,CANT_ALUMNOS
                Si (alumno = 1) entonces
                    mayor <-- A[alumno].Calif_final
                    i <-- alumno
                fin si.
                Si (A[alumno].Calif_final > mayor) entonces
                    mayor <-- A[alumno].Calif_final
                    i <-- alumno
                fin si.
            fin para.

            Repetir para alumno <-- 1,CANT_ALUMNOS
                Si (A[alumno].Calif_final = mayor) entonces
                    ind_mayor[cant] <-- alumno
                    cant <-- cant + 1
                fin si.
            fin para.

            Si (cant = 1) entonces
                Escribir ("La maxima clasificacion obtenida en la competencia fue ",A[i].Calif_final,"y la obtuvo el estudiante ",i)
            Sino
                Escribir ("La maxima claisifcaion obtenida en la competencia fue ",A[i].Calif_final,"y lo obtuvieron los estudiantes ")
                Repetir para j <-- 1,cant
                    Si (j = 1) entonces:
                        Escribir (ind_mayor[j])
                fin para.
    Fin subrutina MAYOR.

    Funcion PORCENTAJE (RES:A[CANT_ALUMNOS]): Real
        Variables:
            Entero: alumno
            Entero: cant_des
        Inicio:
            Repetir para alumno <-- 1,CANT_ALUMNOS
                Si (A[alumno].Calif_final < 6) entonces
                    cant_des <-- cant_des + 1
                fin si.
        Devolver ((cant_des*100.0)/(CANT_ALUMNOS*1.0))
    Fin funcion PORCENTAJE
*/