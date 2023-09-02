    for(int i=0; i<n; i++) {
        aux_ab=0, aux_ba=0;
        for (int j=0; j<n; j++){
            aux_ab+= A[i][j]*B[j][i];
            aux_ba+= B[i][j]*A[j][i];
        }
        if (aux_ab!=aux_ba){
            val = false;
            break;
        }
    }