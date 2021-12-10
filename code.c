/* Trabalho de Cálculo Numérico feito por: 
        - Gabriel Passos de Oliveira
        - Gabriella Alves de Oliveira
        - Thiago Henrique Uliame
Computação - Noturno */

#include <stdio.h>
#include <math.h>

//>>>>  PROTOTIPOS  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
float um_bisseccao();
float dois_bisseccao();
float tres_bisseccao();
float um_newton();
float dois_newton();
float tres_newton();
float um_derivada(float x);
float dois_derivada(float x);
float tres_derivada(float x);

//>>>>  MAIN  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
int main()
{

    
    int opcao1, opcao2; // opcao1= qual função utilizar; opcao2= qual método utilizar
    float raiz;

    printf("\n\n\t >>>  INICIO <<<\n");
    while(1) 
    {

        printf("\n 1- %c(x) = x-8", 159);
        printf("\n 2- %c(x) = 2x-tg(x)", 159);
        printf("\n 3- %c(x) = (2^x)-4x", 159);
        printf("\n\nEscolha a fun%c%co: ", 135, 198);
        scanf("%d", &opcao1);

        switch (opcao1)
        {
            case 1:
                printf("\n===============================================\n");
                printf("\n 1 - M%ctodo da Bissec%c%co",130, 135, 198);
                printf("\n 2 - M%ctodo de Newton", 130);
                printf("\n Escolha o m%ctodo de resolu%c%co: ",130, 135, 198);
                scanf("%d", &opcao2);
                switch(opcao2)
                {
                    case 1:
                        raiz = um_bisseccao();
                        printf("\nValor da raiz = %.4f\n", raiz);
                        printf("\n===============================================\n");
                        break;
                    case 2: 
                        raiz = um_newton();
                        printf("\nValor da raiz = %.4f\n", raiz);
                        printf("\n===============================================\n");
                        break;
                }
                break;
            case 2:
                printf("\n===============================================\n");
                printf("\n 1 - M%ctodo da Bissec%c%co",130, 135, 198);
                printf("\n 2 - M%ctodo de Newton", 130);
                printf("\n Escolha o m%ctodo de resolu%c%co: ",130, 135, 198);
                scanf("%d", &opcao2);
                switch(opcao2)
                {
                    case 1:
                        raiz = dois_bisseccao();
                        printf("\nValor da raiz = %.4f\n", raiz);
                        printf("\n===============================================\n");
                        break;
                    case 2: 
                        raiz = dois_newton();
                        printf("\nValor da raiz = %.4f\n", raiz);
                        printf("\n===============================================\n");
                        break;
                }
                break;
            case 3:
                printf("\n===============================================\n");
                printf("\n 1 - M%ctodo da Bissec%c%co",130, 135, 198);
                printf("\n 2 - M%ctodo de Newton", 130);
                printf("\n Escolha o m%ctodo de resolu%c%co: ",130, 135, 198);
                scanf("%d", &opcao2);
                
                switch(opcao2)
                {
                    case 1:
                        raiz = tres_bisseccao();
                        printf("\nValor da raiz = %.4f\n", raiz);
                        printf("\n===============================================\n");
                        break;
                    case 2: 
                        raiz = tres_newton();
                        printf("\nValor da raiz = %.4f\n", raiz);
                        printf("\n===============================================\n");
                        break;
                }
                break;
            case 0:
                printf("\nFinalizando programa... ");
                return 0;
            
            default:
                printf("\nErro - Op%c%co Inv%clida\n", 135, 198, 160);
                break;
        }
    }
}

//>>>>  FUNCOES  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
float um_bisseccao()
{
    // x-8
    float a, b, precisao, x0, x1;
    int num_max, i, itr=1;

    printf("\n===============================================\n");
    while(1)
    {
        printf("\nInsira o limite inferior: ");
        scanf("%f", &a);
        printf("\nInsira o limite superior: ");
        scanf("%f", &b);
        if((a-8)*(b-8) > 0){
            printf("\nERRO - limites inv%clidos", 160);
            continue;
        }
        else break;
    } 
    printf("\nInsira a precis%co desejada: ", 198);
    scanf("%f", &precisao);
    printf("\nInsira o n%cmero m%cximo de itera%c%ces: ", 163, 160, 135, 228);
    scanf("%d", &num_max);

    x0 = (a+b)/2;
    for (i=0; i<num_max; i++)
    {
        if ((x0-8)*(a-8)<0)
        {
            b=x0;
            x1 = (a+b)/2;
            itr++;
            
            if(fabs(x0-x1)/fabs(x1) < precisao){
                printf("\nN%cmero de itera%c%ces: %d", 163, 135, 228, itr);
                return x1;
            }
        }
        else if ((x0-8)*(a-8)>0)
        {
            a=x0;
            x1 = (a+b)/2;
            itr++;
        
            if(fabs(x0-x1)/fabs(x1) < precisao){
                printf("\nN%cmero de itera%c%ces: %d", 163, 135, 228, itr);
                return x1;
            }       
        }
        x0 = x1;
    }
    printf("\nN%cmero m%cximo de itera%c%ces atingida", 163, 160, 135, 228);
    return x1;
}
float dois_bisseccao()
{
    // 2x-tgx
    float a, b, precisao, x0, x1;
    int num_max, i, itr=1;

    printf("\n===============================================\n");
    while(1)
    {
        printf("\nInsira o limite inferior: ");
        scanf("%f", &a);
        printf("\nInsira o limite superior: ");
        scanf("%f", &b);
        if( ((2*b)-tan(b))*((2*a)-tan(a)) > 0 ){
            printf("\nERRO - limites inv%clidos", 160);
            continue;
        }
        else break;
    } 
    printf("\nInsira a precis%co desejada: ", 198);
    scanf("%f", &precisao);
    printf("\nInsira o n%cmero m%cximo de itera%c%ces: ", 163, 160, 135, 228);
    scanf("%d", &num_max);

    x0 = (a+b)/2;
    for (i=0; i<num_max; i++)
    {
        if (((2*x0)-tan(x0))*((2*a)-tan(a))<0)
        {
            b=x0;
            x1 = (a+b)/2;
            itr++;
            
            if(fabs(x0-x1)/fabs(x1) < precisao){
                printf("\nN%cmero de itera%c%ces: %d", 163, 135, 228, itr);
                return x1;
            }
        }
        else if (((2*x0)-tan(x0))*((2*a)-tan(a))>0)
        {
            a=x0;
            x1 = (a+b)/2;
            itr++;
            
            if(fabs(x0-x1)/fabs(x1) < precisao){
                printf("\nN%cmero de itera%c%ces: %d", 163, 135, 228, itr);
                return x1;
            }       
        }
        x0 = x1;
    }
    printf("\nN%cmero m%cximo de itera%c%ces atingida", 163, 160, 135, 228);
    return x1;
}
float tres_bisseccao()
{
    // (2^x)-4x
    float a, b, precisao, x0, x1;
    int num_max, i, itr=1;
    printf("\n===============================================\n");
    while(1)
    {
        printf("\nInsira o limite inferior: ");
        scanf("%f", &a);
        printf("\nInsira o limite superior: ");
        scanf("%f", &b);
        if((pow(2,a)-(4*a))*(pow(2,b)-(4*b)) > 0){
            printf("\nERRO - limites inv%clidos", 160);
            continue;
        }
        else break;
    } 
    printf("\nInsira a precis%co desejada: ", 198);
    scanf("%f", &precisao);
    printf("\nInsira o n%cmero m%cximo de itera%c%ces: ", 163, 160, 135, 228);
    scanf("%d", &num_max);

    x0 = (a+b)/2;
    for (i=0; i<num_max; i++)
    {
        if ((pow(2,x0)-(4*x0))*(pow(2,a)-(4*a)) < 0)
        {
            b=x0;
            x1 = (a+b)/2;
            itr++;
            
            if(fabs(x0-x1)/fabs(x1) < precisao){
                printf("\nN%cmero de itera%c%ces: %d", 163, 135, 228, itr);
                return x1;
            }
        }
        else if ((pow(2,x0)-(4*x0))*(pow(2,a)-(4*a)) > 0)
        {
            a=x0;
            x1 = (a+b)/2;
            itr++;

            if(fabs(x0-x1)/fabs(x1) < precisao){
                printf("\nN%cmero de itera%c%ces: %d", 163, 135, 228, itr);
                return x1;
            }       
        }
        x0 = x1;
    }
    printf("\nN%cmero m%cximo de itera%c%ces atingida", 163, 160, 135, 228);
    return x1;
}
float um_newton()
{
    // x-8
    float x0, x1, precisao;
    int itr=0, num_max, i;
    printf("\n===============================================\n");
    printf("\nInsira o valor inicial: ");
    scanf("%f", &x0);
    printf("\nInsira a precis%co desejada: ", 198);
    scanf("%f", &precisao);
    printf("\nInsira o n%cmero m%cximo de itera%c%ces: ", 163, 160, 135, 228);
    scanf("%d", &num_max);
    for(i=0; i<num_max; i++)
    {
        x1 = x0 - ((x0-8)/um_derivada(x0));
        itr++;

        if(fabs(x0-x1)/fabs(x1)<precisao)
        {
            printf("\nN%cmero de itera%c%ces: %d", 163, 135, 228, itr);
            return x1;
        }
        x0 = x1;
    }
    printf("\nN%cmero m%cximo de itera%c%ces atingida", 163, 160, 135, 228);
    return x1;
}
float dois_newton()
{
    // 2x-tg(x)
    float x0, x1, precisao;
    int itr=0, num_max, i;
    printf("\n===============================================\n");
    printf("\nInsira o valor inicial: ");
    scanf("%f", &x0);
    printf("\nInsira a precis%co desejada: ", 198);
    scanf("%f", &precisao);
    printf("\nInsira o n%cmero m%cximo de itera%c%ces: ", 163, 160, 135, 228);
    scanf("%d", &num_max);
    for(i=0; i<num_max; i++)
    {
        x1 = x0 - ((2*x0-tan(x0))/dois_derivada(x0));
        itr++;

        if(fabs(x0-x1)/fabs(x1)<precisao)
        {
            printf("\nN%cmero de itera%c%ces: %d", 163, 135, 228, itr);
            return x1;
        }
        x0 = x1;
    }
    printf("\nN%cmero m%cximo de itera%c%ces atingida", 163, 160, 135, 228);
    return x1;

}
float tres_newton()
{
    // (2^x)-4x
    float x0, x1, precisao;
    int itr=0, num_max, i;
    printf("\n===============================================\n");
    printf("\nInsira o valor inicial: ");
    scanf("%f", &x0);
    printf("\nInsira a precis%co desejada: ", 198);
    scanf("%f", &precisao);
    printf("\nInsira o n%cmero m%cximo de itera%c%ces: ", 163, 160, 135, 228);
    scanf("%d", &num_max);
    
    for(i=0; i<num_max; i++)
    {
        x1 = x0 - ((pow(2, x0) - 4*x0) / tres_derivada(x0));
        itr++;

        if(fabs(x0-x1)/fabs(x1)<precisao)
        {
            printf("\nN%cmero de itera%c%ces: %d", 163, 135, 228, itr);
            return x1;
        }
        x0 = x1;
    }
    printf("\nN%cmero m%cximo de itera%c%ces atingida", 163, 160, 135, 228);
    return x1;
    
}
float um_derivada(float x)
{
    // x-8
    return 1;
}
float dois_derivada(float x)
{
    // 2x-tan(x)
    return 2-pow((1/cos(x)),2);
}
float tres_derivada(float x)
{
    //2^x - 4x
    return log(2)*(pow(2, x)-4);
}
