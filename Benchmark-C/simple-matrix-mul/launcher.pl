#!/usr/bin/perl

# Fichero para automatizacion de ejecucion por lotes, de un ejecutable,
# dados parametros de entrada.

$repetition = 30;
$path = "/home/sebastian/Backup/usa/Matrix-Multplication-C-Rust/Benchmark-C/simple-matrix-mul/";
@ejecutables = ("matrixApp");
@matrixSize = ("10");

foreach $exe (@ejecutables){
    foreach $size (@matrixSize){
        $fichero = "$path"."outputs/$exe-size$size.txt";
        for($i = 0; $i < $repetition; $i++){
            system("$path$exe.out $size $thread >> $fichero\n");
        }
        print("$exe-size$size DONE.\n");
    }
}

exit(1);
