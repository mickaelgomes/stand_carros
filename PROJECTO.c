#include <stdio.h>
#include <stdlib.h>

#define MAX 1500

typedef enum {vendido ,disponivel} ESTADO;
typedef enum {gasolina, gasoleo, gas} COMBUSTIVEL;

//struct que vai guardar a informação sobre cada carro
typedef struct{
	char marca[20];
	char matricula[15];
	char dmatricula[10];
	COMBUSTIVEL t_comb;
	int cilindrada;
	float preco;
	ESTADO disponibilidade;
}AUTOMOVEL;

//struct que vai guardar a informação sobre cada cliente
typedef struct{
	char nome[50];
	int num_ident;
	int nif;
	char morada[200];
	int tel;
}CLIENTE;


//struct que irá guardar a informação sobre cada venda
typedef struct{
	CLIENTE nome;
	AUTOMOVEL carro;
	char dataVenda;
	float precoFinal;
}VENDA;

//Vectores que vão guardar as listagens
typedef AUTOMOVEL VECTCAR[MAX];
typedef CLIENTE VECTCLI[MAX];
typedef VENDA VECTVEN[MAX];



int menu(void);
int menucarro(void);
int menucliente(void);
int menuvenda(void);
CLIENTE editCli(VECTCLI clientes, int tclientes);
CLIENTE insertCli(void);
void showClient(VECTCLI v_clientes, int nclientes);
AUTOMOVEL insertAut(void);
int main()
{
  VECTCLI v_clientes;
  VECTVEN vendas;
  VECTCAR carros;
  int opcao,opcaocarro,opcaocliente,opcaovenda;
  int n_clientes = 0;

  do
  {
  opcao=menu();
  switch(opcao)
  {
  case 1:
  opcaocarro = menucarro();
  break;
  case 2:
    do{
    opcaocliente = menucliente();
    if(opcaocliente >= 2 && opcaocliente <= 3 && n_clientes == 0){
        printf("Impossivel não existem clientes registados");
    }else{

        switch (opcaocliente)
        {
        	case 1:
                    if(n_clientes < MAX){
                        v_clientes[n_clientes++] = insertCli();
                    }else{

                        printf("já chegou ao limite de clientes");
                    }
        		break;
            case 2:
                break;
            case 3:
                showClient(v_clientes, n_clientes);

                break;
        	default:
        		break;
        }


    }
    }while(opcaocliente < 4);
  break;
  case 3:
  opcaovenda = menuvenda();
  break;
  }//switch
printf("\n Pressione qualquer tecla para continuar");
//getch();
}while(opcao!=0);
return 0;

}

int menu(void)
{
int opcao;
do{
//system("cls");
printf("\n   ########################");
printf("\n   #                      #");
printf("\n   #  STANT DE AUTOMOVEL  #");
printf("\n   #   By Mike&Rubem      #");
printf("\n   ########################");
printf("\n\n      1 - Menu Carros");
printf("\n      2 - Menu Clientes");
printf("\n      3 - Menu Vendas");
printf("\n      0 - Salvar e Sair");
printf("\n\n   Escolha uma opcao: ");
scanf("%d", &opcao);
if(opcao< 0 || opcao>3)
{
printf("ERRO_ Opção inválida");
//getch();
}
}while(opcao< 0 ||opcao> 3);
return(opcao);
}

int menucarro(void)
{
int opcaocarro;
int tautomovel = 0;
VECTCAR v_automovel;
do{
//system("cls");
printf("\n 1 - Inserir Carro");
printf("\n 2 - Visualizar Informacao de um carro");
printf("\n 3 - Editar Carro");
printf("\n 4 - Listar Carro");
printf("\n 5 - Pesquisar Carro pela matricula");
printf("\n 0 - Sair do Menu Carro");
printf("\n\n Escolha uma opcao: ");
fflush(stdin);
scanf("%d", &opcaocarro);

if(opcaocarro< 0 || opcaocarro> 5 )
{
printf("ERRO: Opcao invalida");
//getch();
}
}while(opcaocarro< 0  ||opcaocarro> 5 );

return(opcaocarro);
}


int menucliente(void)
{
int opcaocliente;
int tclientes = 0;
VECTCLI v_clientes;
char nome[25];
do{
//system("cls");
printf("\n 1 - Inserir Cliente");
printf("\n 2 - Editar Cliente");
printf("\n 3 - Listar Cliente");
printf("\n 4 - Pesquisar Cliente por nome");
printf("\n 0 - Sair do Menu Cliente");
printf("\n\n Escolha uma opcao:");
fflush(stdin);
scanf("%d", &opcaocliente);

if(opcaocliente< 0 || opcaocliente> 4)
{
printf("ERRO: Opcao invalida");
//getch();
}
}
while(opcaocliente< 0 ||opcaocliente>4);
return(opcaocliente);
}



int menuvenda(void)
{
int opcaovenda;
do{
//system("cls");
printf("\n 1 - Inserir Venda");
printf("\n 2 - Total Facturado");
printf("\n 3 - Vendas Ultimo mes");
printf("\n 4 - Vendas mais alta");
printf("\n 5 - Vendas mais baixa");
printf("\n 6 - Percentagem de vendas por combustivel");
printf("\n 7 - Vendas de um cliente");
printf("\n 0 - Sair do menu vendas");
printf("\n\n Escolha uma opcao: ");
scanf("%d", &opcaovenda);
if(opcaovenda< 0 || opcaovenda> 7)
{
printf("ERRO: Opcao invalida");
//getch();
}
}while(opcaovenda< 0 ||opcaovenda> 7);
return(opcaovenda);
}

//Inserir Cliente -> feito
//Editar Cliente");
//Listar Cliente"); -> feito


CLIENTE insertCli(void){
	CLIENTE info;
	printf("Insira o nome do cliente:");
	scanf("%s", info.nome);
	printf("Introduza o número do cartao de cidadão/BI:");
	scanf("%d", &info.num_ident);
	printf("Introduza o NIF do cliente");
	scanf("%d", &info.nif);
	printf("Introduza a morado do cliente:");
	scanf("%s", info.morada);
	printf("Introduza o telefone/telemovel do cliente:");
	scanf("%d", &info.tel);

	return(info);
}

//funcao auxiliar para correr o vector de clientes

void listCli(CLIENTE client_info){
    printf("Nome do Cliente: %s \n", client_info.nome);
    printf("Morada do Cliente: %s \n", client_info.morada);
    printf("Nif do cliente: %d \n", client_info.nif);
    printf("BI do cliente: %d \n", client_info.num_ident);
    printf("Número de telefone do cliente: %d \n", client_info.tel);

}

//função que vai pesquisar um cliente pelo nome
void showClient(VECTCLI v_clientes, int nclientes){
    int i, flag;
    char nome[25];
     printf("Introduza o nome do Cliente:");
     scanf("%s", nome);
     printf("%s", nome);
    for (i=0;i<nclientes;i++){
        flag = strcmp(v_clientes[i].nome , nome);
        printf("%d", flag);
            if(flag == 0){

            printf("As informações sobre o cliente são as seguintes:");
            listCli(v_clientes[i]);

        }else{
            printf("Nome não encontrado!");
        }


   }

}


//Inserir Carro
AUTOMOVEL insertAut(void){
	AUTOMOVEL infoA;
	printf("Insira a marca do carro: ");
	scanf("%s", infoA.marca);
	printf("Introduza a matricula do carro: ");
	scanf("%s", &infoA.matricula);
	printf("Introduza a data da primeira matricula: ");
	scanf("%d", &infoA.dmatricula);
	printf("Introduza o combustivel do carro: ");
	scanf("%s", infoA.t_comb);
	printf("Introduza a cilindrada do carro: ");
	scanf("%d", &infoA.cilindrada);
	printf("Introduza o preco do carro: ");
	scanf("%2.f", &infoA.preco);
    printf("Introduza o estado do carro: ");
	scanf("%s", &infoA.disponibilidade);
	return(infoA);
}


