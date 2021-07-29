#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int simula_sims(int *fome,int *sede, int *banheiro, int *sono, int *tedio){
  int saida=1;
// criando cada uma das string da ação
char comer[20] ="comer";
char beber[20]="beber";
char dormir[20]="dormir";
char aliviar[20]= "se aliviar";
char jogar[20]="jogar videogame";
// ler a ação relizada
char *acao_realizada = calloc(20, sizeof(char));
fgets(acao_realizada,20,stdin);
acao_realizada[(int)strlen(acao_realizada)-1]= '\0';
int achar=10;
 // COMPARA A AÇÃO REALIZADA COM AS STRINGS #######
// compara com comer
achar = strcmp(acao_realizada,comer);
if (achar ==0){
  *fome +=30;
  *banheiro -=15;
  *sede-= 5;
  *sono-=5;
  *tedio-=5;
};
// compara com beber
achar = strcmp(acao_realizada,beber);
if (achar ==0){
  *sede +=30;
  *banheiro -=20;
  *sono -= 5; 
  *tedio -= 5;
  *fome -= 5;
};
// compara com dormir
achar = strcmp(acao_realizada,dormir);
if (achar ==0){
  *sono +=80;
  *tedio +=30;
  *fome -=30;
  *sede -=30;
  *banheiro-=30;
};
//compara com aliviar
achar = strcmp(acao_realizada,aliviar);
if (achar ==0){
  *banheiro+=100;
  *sono -=5;
  *tedio -=5;
  *sede -=5;
  *fome-=5;
};
//compara com jogar
achar = strcmp(acao_realizada,jogar);
if (achar ==0){
  *tedio+=80;
  *sono-=20;
  *fome -= 20;
  *sede -=20;
  *banheiro-=20;
};
// COLOCA AS VARIÁVEIS NO INTERVALO DE 0-100 ##########
  //ajeita tedio
if(*tedio>100)
*tedio=100;
if(*tedio<0)
*tedio=0;
  //ajeita sono
if(*sono>100)
*sono=100;
if(*sono<0)
*sono=0; 
  //ajeita fome
if(*fome>100)
*fome=100;
if(*fome<0)
*fome=0;
  //ajeita sede
if(*sede>100)
*sede=100;
if(*sede<0)
*sede=0;
  //ajeita banheiro
if(*banheiro>100)
*banheiro=100;
if(*banheiro<0)
*banheiro=0;
//VEFICA OS ALERTAS################
//vefifica tedio
if(*tedio >0 && *tedio<= 15)
printf("Alerta: tédio está com valor baixo\n");
//vefica sono
if(*sono >0 && *sono <=15)
printf("Alerta: sono está com valor baixo\n");
//verifica fome
if(*fome>0 && *fome <=15)
printf("Alerta: fome está com valor baixo\n");
//vefifica sede
if(*sede >0 && *sede<=15)
printf("Alerta: sede está com valor baixo\n");
//verifica banheiro
if(*banheiro>0 && *banheiro<=15)
printf("Alerta: banheiro está com valor baixo\n");

//VEFICA O GAMER OVER ###########
if(*fome ==0){
  printf("Game Over! Morreu de fome\n");
  saida= 0;
}
if(*sede ==0){
  printf("Game Over! Morreu de sede\n");
  saida= 0;
}
if(*banheiro==0){
  printf("Game Over! Morreu apertado…\n");
  saida= 0;
}

if (*sono ==0){
  printf("Game Over! Morreu dormindo…\n");
  saida= 0;
}
if (tedio ==0){
  printf("Game Over! Morreu deprimido…\n");
  saida= 0;
}

return saida;
}

void imprime_relatorio(int fome, int sede, int banheiro, int sono, int tedio){
  printf("Status final:\n");
  printf("Fome: %d\n", fome);
  printf("Sede: %d\n", sede);
  printf("Banheiro: %d\n", banheiro);
  printf("Sono: %d\n", sono);
  printf("Tédio: %d\n", tedio);
}


int main(){
    int fome, sede, banheiro, sono, tedio;
    int acoes;
    scanf("%d %d %d %d %d", &fome, &sede, &banheiro, &sono, &tedio);
    scanf("%d\n", &acoes);
    for(int i = 0; i<acoes; i++){
        int ret = simula_sims(&fome, &sede, &banheiro, &sono, &tedio);
        if(ret == 0) break;
    }
    imprime_relatorio(fome, sede, banheiro, sono, tedio);
    return 0;
}