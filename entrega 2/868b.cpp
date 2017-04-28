/*-laberinto (nxn)
-filas columnas
-matriz de visitados (nxn)

*/




backtrack(fila, col, proximo, limite){
  si fila o col invalida ||
    visitado[fila][col] || proximo =! laberinto[fila][col]
    {return //fracaso
    }

    si fila = FILAS //si es la última fila
      {return col //exito, retorna la columna x la cual sale
      }

    proximo++;
    if(proximo > limite) {
      proximo = 1;
      limite++;
    }
    marcar visitado [fila][col]
    backtrack(fila-1,col, proximo, limite);

}


int main(){
  //no conocemos la columna
  backtrack(1, c, 1, 1);
}
