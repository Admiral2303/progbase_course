     if(i < -10 || i > 10){
        while(1){ 
            if(i > -10 && i < 10){
                break;
            }
            if(i < -10 ){
                i = i / k;
                k = 10;
            }
            if(i > 10){
                i = i / k;
                k = 10;
            }
            
        }
     }
     k = 10;
    if( j > 10 || j < -10){
        while(j < -10 || j > 10){
            
            if(j < -10 ){
                j = j / k;
            }
            if(j > 10){
                j = j / k;
            }
            
            k = 10;
        }
    }
    printf("%i --- %i +++", i , j);

    if(i<j){
        return -1;
    }
    else{
        return 1;
    }