/**
 * @file matrices.h
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Archivo de encabezado de la biblioteca matrices.
 * @version 0.1
 * @date 2025-10-08
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdbool.h>

#ifndef __MATRICES_H__
#define __MATRICES_H__

/// @brief Calcula el determinante de cualqueir matriz de 3x3
/// @param matrix La matriz
/// @return El determinante
int determinante(int matrix[3][3]);


/// @brief Calcula la transpuesta de una matrix de 3x3
/// @param matrix La matriz
/// @param tras La traspuesta
void traspuesta(int matrix[3][3], int tras[3][3]);

/// @brief Calcula la adjunta de una matrix de 3x3
/// @param matrix La matrix
/// @param adj La adjunta
void adjunta(int matrix[3][3], int adj[3][3]);

/// @brief Calcula la inversa de una matrix de 3x3
/// @param matrix La matrix
/// @param inv La inversa
/// @return True si tiene inversa. False si no tiene.
bool inversa(int matrix[3][3], float inv[3][3]);

/// @brief Imprime una matriz de 3x3 flotante
/// @param matrix La matriz a imprimir
void imprime_float(float matrix[3][3]);

/// @brief Imprime una matriz de 3x3 entera
/// @param matrix La matriz a imprimir
void imprime_int(int matrix[3][3]);

#endif