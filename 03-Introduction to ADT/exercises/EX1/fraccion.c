#include <stdio.h>
#include <stdlib.h>
#include "fraccion.h"

fraccion crear(int numerador, int denominador){
    fraccion f;
    f.numerador = numerador;
    f.denominador = denominador;
    return f;
}

int numerador(fraccion f){
    return f.numerador;
}

int denominador(fraccion f){
    return f.denominador;
}

fraccion sumar(fraccion f1, fraccion f2){
    fraccion f;
    f.denominador = (f1.denominador * f2.denominador);
    f.numerador = (f1.numerador * f2.denominador + f2.numerador * f1.denominador);
    return f;
}

fraccion restar(fraccion f1, fraccion f2){
    fraccion f;
    f.denominador = (f1.denominador * f2.denominador);
    f.numerador = (f1.numerador * f2.denominador - f2.numerador * f1.denominador);
    return f;
}

fraccion multiplicar(fraccion f1, fraccion f2){
    fraccion f;
    f.numerador = f1.numerador * f2.numerador;
    f.denominador = f1.denominador * f2.denominador;
    return f;
}

fraccion dividir(fraccion f1, fraccion f2){
    fraccion f;
    f.numerador = f1.numerador * f2.denominador;
    f.denominador = f1.denominador * f2.numerador;
    return f;
}

fraccion simplificar(fraccion f){
    int mcd, divisor, dividendo, resto;

    dividendo = f.numerador;
    divisor = f.denominador;
    resto = dividendo % divisor;

    while (resto != 0){
        dividendo = divisor;
        divisor = resto;
        resto = dividendo % divisor;
    }
    mcd = divisor;

    f.numerador = (f.numerador) / mcd;
    f.denominador = (f.denominador) / mcd;
    return f;
}

int iguales(fraccion f1, fraccion f2){
    fraccion f1Simp = simplificar(f1);
    fraccion f2Simp = simplificar(f2);

    return (f1Simp.numerador == f2Simp.numerador && f1Simp.denominador == f2Simp.denominador);
}
