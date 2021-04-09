
int main()
{
  	init();
  	
  	Serial.begin(9600);
      
    int numero = 0, can_cifras = 0, division = 1, cont = 1, sum_total = 0, num_mayor = 0, cont_mayor = 0; // Variables para operaciones en el programa


    Serial.print( "Ingrese un numero entero positivo -> ");//Parte del cogido para
	while(Serial.available()==0);						   //pedir numero por comsola
  	numero = Serial.parseInt();
  	Serial.println(numero);

    while(cont>=1){             //Parte del codigo
        cont=numero/division;   //donde se identifican
        if (cont>=1){           //la cantidad de cifras
            can_cifras++;       //que tiene el numero
        }                       //ingresado
        division = division*10; //
    }


    int cont1 = -1;
    int num = 0;
    int num_pot = 0;
  
    Serial.print( "La suma de los numeros ");


    for( int i = can_cifras; i >= 1; i--){      //Parte del codigo
        cont1 = cont1 + 1;                      //donde se busca
        cont = 1;                               //separar todos los
        for ( int c = 1; c < i; c++ ){          //numeros en unidades
            cont = cont *10;                    //para realizar la
        }                                       //operacion pedida
        if (cont1 != 0){                        //
            num = numero/cont*0.1;              //
        }                                       //
       num_pot = (numero/cont)-(num*10);


       if (num_mayor < num_pot){                //Parte del codigo
           num_mayor = num_pot;                 //para identificar
           cont_mayor = 0;                      //el numero mayor
       }                                        //y la cantidad
       if ( num_mayor == num_pot){              //de veces que
           cont_mayor = cont_mayor + 1;         //aparece
       }


       if ( i != 1 ){
          Serial.print( num_pot); 
          Serial.print("^"); 
          Serial.print(num_pot); 
          Serial.print( " + ");
       }
       else {
          Serial.print( num_pot); 
          Serial.print( "^"); 
          Serial.print( num_pot);
       }
       
       int num_prov = 0, pot = num_pot ;

                                                //Parte del codigo
       for( int i = 1; i < num_pot; i++){       //para calcular
           for ( int c = 0; c < num_pot ; c++){ //la potencia de un
               num_prov = num_prov + pot;       //numero
           }                                    //
           pot = num_prov;                      //
           num_prov = 0;                        //
       }
      sum_total = sum_total + pot;
    }


    Serial.print( " = "); 
    Serial.println( sum_total);
    Serial.print("El numero mayor encontrado es el ");    
    Serial.print( num_mayor); 
    Serial.print( " que aparece "); 
    Serial.print( cont_mayor); 
    Serial.println(" vez");
  
    while(1){}
  
    return 0;
}
