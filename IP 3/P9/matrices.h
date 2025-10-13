/**
 * @file matrices.h
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi segunda biblioteca de funciones :)
 * @version 0.1
 * @date 2025-10-13 
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __MATRICES_H__
#define __MATRICES_H__

#include<stdbool.h>
/// @brief Calcula el determinante de una matrix de 3x3
/// @param matrix La matrix
/// @return El determinante
int determinante(int matrix[3][3]);

/// @brief Calcula la traspuesta de una matrix de 3x3
/// @param matrix La matrix
/// @param tras La traspuesta
void traspuesta(int matrix[3][3], int tras[3][3]);

/// @brief Calcula la adjunta de una matrix de 3x3
/// @param matrix La matrix
/// @param adj La adjunta
void adjunta(int matrix[3][3], int adj[3][3]);

/// @brief Calcula la inversa de una matriz de 3x3
/// @param matrix La matriz
/// @param inv La inversa
/// @return True si se pudo calcular. False si no tiene inversa.
bool inversa(int matrix[3][3], float inv[3][3]);

#endif