#include <iostream>
#include <fstream>
#include <string>
#include "Sculptor.h"

int main(void){

  Sculptor Barrettao(170,170,170);

	Barrettao.setColor(0.5,0.9,0.5,0.7);// cor_verde_claro
  Barrettao.putBox(14,161,0,1,36,156);// plano_que_estah_situado_o_estadio

  // CAMPO_DE_FUTEBOL_dimensões_45x90
  Barrettao.setColor(0.0,0.6,0.0,0.31); // cor_do_campo_verde_claro
  Barrettao.putBox(51,96,0,1,51,60); // cor_verde_claro
  Barrettao.putBox(51,96,0,1,69,78); // cor_verde_claro
  Barrettao.putBox(51,96,0,1,87,96); // cor_verde_claro
  Barrettao.putBox(51,96,0,1,105,114); // cor_verde_claro
  Barrettao.putBox(51,96,0,1,123,132); // cor_verde_claro
  
  Barrettao.setColor(0.0,0.5,0.0,0.25); // cor_do_campo_verde_escuro
  Barrettao.putBox(51,96,0,1,60,69); // cor_verde_escuro
  Barrettao.putBox(51,96,0,1,78,87); // cor_verde_escuro
  Barrettao.putBox(51,96,0,1,96,105); // cor_verde_escuro
  Barrettao.putBox(51,96,0,1,114,123); // cor_verde_escuro
  Barrettao.putBox(51,96,0,1,132,141); // cor_verde_escuro

  // MEIO_DO_CAMPO
  Barrettao.setColor(1.0,1.0,1.0,1.0); // cor_branca
  Barrettao.putBox(51,96,0,1,96,97); // listra_do_meio_campo

  //CIRCUNFERENCIA_DO_MEIO_DE_CAMPO
  Barrettao.setColor(1.0,1.0,1.0,1.0); // cor_branca
  Barrettao.putBox(68,79,0,1,87,88); // linha_de_cima
  Barrettao.putBox(68,79,0,1,104,105); // linha_de_baixo
  Barrettao.putBox(67,68,0,1,88,89); // cubo_unico_da_esquerda_de_cima
  Barrettao.putBox(66,67,0,1,89,90); // cubo_segundo_da_esquerda_de_cima
  Barrettao.putBox(65,66,0,1,90,91); // cubo_terceiro_da_esquerda_de_cima
  Barrettao.putBox(79,80,0,1,88,89); // cubo_unico_da_direita_de_cima
  Barrettao.putBox(80,81,0,1,89,90); // cubo_segundo_da_direita_de_cima
  Barrettao.putBox(81,82,0,1,90,91); // cubo_terceiro_da_direita_de_cima
  Barrettao.putBox(67,68,0,1,103,104); // cubo_unico_da_esquerda_de_baixo
  Barrettao.putBox(66,67,0,1,102,103); // cubo_segundo_da_esquerda_de_baixo
  Barrettao.putBox(65,66,0,1,101,102); // cubo_terceiro_da_esquerda_de_baixo
  Barrettao.putBox(79,80,0,1,103,104); // cubo_unico_da_direita_de_baixo
  Barrettao.putBox(80,81,0,1,102,103); // cubo_segundo_da_direita_de_baixo
  Barrettao.putBox(81,82,0,1,101,102); // cubo_terceiro_da_direita_de_baixo
  Barrettao.putBox(64,65,0,1,91,101); // linha_vertical_da_esquerda
  Barrettao.putBox(82,83,0,1,91,101); // linha_vertical_da_direita
  
  //GRANDE_AHREA_(AHREA_DO_GOLEIRO)
  Barrettao.setColor(1.0,1.0,1.0,1.0); // cor_branca
  Barrettao.putBox(66,81,0,1,59,60); // listra_horizontal
  Barrettao.putBox(66,81,0,1,132,133); // listra_horizontal
  Barrettao.putBox(66,67,0,1,51,60); // listra_vertical
  Barrettao.putBox(81,82,0,1,51,60); // listra_vertical
  Barrettao.putBox(66,67,0,1,132,141); // listra_vertical
  Barrettao.putBox(81,82,0,1,132,141); // listra_vertical
  
  //PEQUENA_AHREA_(AHREA DO TIRO DE META)
  Barrettao.setColor(1.0,1.0,1.0,1.0); // cor_branca
  Barrettao.putBox(70,77,0,1,136,137); // listra_horizontal
  Barrettao.putBox(70,77,0,1,55,56); // listra_horizontal
  Barrettao.putBox(70,71,0,1,51,56); // listra_vertical
  Barrettao.putBox(77,78,0,1,51,56); // listra_vertical
  Barrettao.putBox(70,71,0,1,136,141); // listra_vertical
  Barrettao.putBox(77,78,0,1,136,141); // listra_vertical

  //TRAVES_DA_PEQUENA_AHREA
  Barrettao.setColor(1.0,1.0,1.0,1.0); // cor_branca
  Barrettao.putBox(70,71,1,3,51,52); // trave
  Barrettao.putBox(77,78,1,3,51,52); // trave
  Barrettao.putBox(70,71,1,3,140,141); // trave
  Barrettao.putBox(77,78,1,3,140,141); // trave
  Barrettao.putBox(70,78,3,4,51,52); // travessao
  Barrettao.putBox(70,78,3,4,140,141); // travessao

  //PLACAS_DE_PUBLICIDADE
  Barrettao.setColor(1.0,1.0,0.0,0.5); // cor_marelo
  Barrettao.putBox(49,50,0,3,76,105); // local_que_estah_situado_no_estadio
  //amarelo_na_placa_central_junto_com_o_preto_e_vermelho
  Barrettao.putBox(97,98,0,3,56,61); // local_que_estah_situado_no_estadio
  Barrettao.putBox(97,98,0,3,129,133); // local_que_estah_situado_no_estadio
  Barrettao.setColor(0.0,0.0,1.0,0.5); // local_que_estah_situado_no_estadio
  Barrettao.putBox(49,50,0,3,62,76); // local_que_estah_situado_no_estadio
  Barrettao.putBox(49,50,0,3,105,119); // local_que_estah_situado_no_estadio
  Barrettao.setColor(1.0,0.6,0.0,0.5);// cor_laranja 
  Barrettao.putBox(51,71,0,3,49,50); // local_que_estah_situado_no_estadio
  Barrettao.putBox(76,95,0,3,142,143); // local_que_estah_situado_no_estadio
  Barrettao.setColor(0.6,0.8,0.9,0.8);// cor_azul_claro
  Barrettao.putBox(76,95,0,3,49,50); // local_que_estah_situado_no_estadio
  Barrettao.putBox(51,71,0,3,142,143); // local_que_estah_situado_no_estadio
  Barrettao.setColor(0.0,0.0,0.0,0.0);// cor_preto 
  Barrettao.putBox(97,98,0,3,81,110); // local_que_estah_situado_no_estadio
  Barrettao.setColor(1.0,0.0,0.0,0.5);// cor_vermelho
  Barrettao.putBox(97,98,0,3,61,81); // local_que_estah_situado_no_estadio
  Barrettao.putBox(97,98,0,3,110,129); // local_que_estah_situado_no_estadio

  //TRIBUNA_DE_IMPRENSA_E_TRANSMISSAO_DO_ESTAHDIO
  Barrettao.setColor(1.0,1.0,0.0,0.5); // cor_amarelo
  Barrettao.putBox(19,45,1,8,82,108); // tehrreo
  Barrettao.cutBox(40,45,1,6,84,89); // tehrreo_Entrada_1
  Barrettao.cutBox(40,45,1,6,93,98); // tehrreo_Entrada_2
  Barrettao.cutBox(40,45,1,6,102,106); // tehrreo_Entrada_3
  Barrettao.setColor(1.0,0.0,0.0,0.5); // cor_vermelho
  Barrettao.putBox(19,45,8,15,82,108); // primeiro_andar
  Barrettao.cutBox(40,45,10,13,85,93); // camarote_1
  Barrettao.cutBox(40,45,10,13,97,105); // camarote_2
  Barrettao.setColor(0.0,0.0,0.0,0.0); // cor_preto
  Barrettao.putBox(19,45,15,20,82,108); // segundo_andar
  Barrettao.cutBox(40,45,17,18,85,105); // tribuna_de_transmissão

  //ARQUIBANCADA
  Barrettao.setColor(0.8,0.8,0.8,0.8);// cor_cinza_claro
  Barrettao.putBox(102,151,0,1,41,151);// chao_da_arquibancada
  Barrettao.setColor(0.4,0.4,0.4,0.4);// cor_cinza_mais_escuro
  Barrettao.putBox(107,146,1,30,51,141);// arquibancada_casa
  Barrettao.cutBox(107,111,1,30,51,141);// arquibancada_casa
  Barrettao.cutBox(111,114,4,30,51,141);// arquibancada_casa
  Barrettao.cutBox(114,118,7,30,51,141);// arquibancada_casa
  Barrettao.cutBox(118,122,10,30,51,141);// arquibancada_casa
  Barrettao.cutBox(122,126,13,30,51,141);// arquibancada_casa
  Barrettao.cutBox(126,130,16,30,51,141);// arquibancada_casa
  Barrettao.cutBox(130,134,19,30,51,141);// arquibancada_casa
  Barrettao.cutBox(134,138,22,30,51,141);// arquibancada_casa
  Barrettao.cutBox(138,142,25,30,51,141);// arquibancada_casa
  Barrettao.cutBox(142,146,28,30,51,141);// arquibancada_casa

  //MURO_DA_ARQUIBANCADA
  Barrettao.setColor(0.8,0.8,0.8,0.8);// cor_cinza_claro
  Barrettao.putBox(102,103,1,6,37,155);// muro_da_arquibancada
  Barrettao.putBox(102,103,6,20,39,40);// alambrado_da_arquibancada
  Barrettao.putBox(102,103,6,20,58,59);// alambrado_da_arquibancada
  Barrettao.putBox(102,103,6,20,77,78);// alambradoo_da_arquibancada
  Barrettao.putBox(102,103,6,20,96,97);// alambrado_da_arquibancada
  Barrettao.putBox(102,103,6,20,114,115);// alambrado_da_arquibancada
  Barrettao.putBox(102,103,6,20,133,134);// alambrado_da_arquibancada
  Barrettao.putBox(102,103,6,20,152,153);// alambrado_da_arquibancada
  

  //MURO_DO_ESTAHDIO
  Barrettao.setColor(1.0,1.0,0.0,0.5); // cor_amarelo
  Barrettao.putBox(14,161,0,3,36,37); // muro_superior
  Barrettao.putBox(14,161,0,3,155,156); // muro_inferior
  Barrettao.putBox(14,15,0,3,37,155); // muro_lateral_esquerdo
  Barrettao.putBox(160,161,0,3,37,155); // muro_lateral_direito
  Barrettao.setColor(1.0,0.0,0.0,0.5); // cor_vermelho
  Barrettao.putBox(14,161,3,6,36,37); // muro_superior
  Barrettao.putBox(14,161,3,6,155,156); // muro_inferior
  Barrettao.putBox(14,15,3,6,37,155); // muro_lateral_esquerdo
  Barrettao.putBox(160,161,3,6,37,155); // muro_lateral_direito
  Barrettao.setColor(0.0,0.0,0.0,0.0); // cor_preto
  Barrettao.putBox(14,161,6,9,36,37); // muro_superior
  Barrettao.putBox(14,161,6,9,155,156); // muro_inferior
  Barrettao.putBox(14,15,6,9,37,155); // muro_lateral_esquerdo
  Barrettao.putBox(160,161,6,9,37,155); // muro_lateral_direito

  //ESCANTEIO
  Barrettao.setColor(1.0,1.0,1.0,1.0); // cor_branco
  Barrettao.putBox(51,53,0,1,52,53); // corner_esquerdo_superior
  Barrettao.putBox(94,96,0,1,52,53); // corner_direito_superior
  Barrettao.putBox(52,53,0,1,51,52); // corner_esquerdo_superior
  Barrettao.putBox(94,95,0,1,51,52); // corner_direito_superior
  Barrettao.putBox(51,53,0,1,139,140); // corner_esquerdo_inferior
  Barrettao.putBox(94,96,0,1,139,140); // corner_direito_inferior
  Barrettao.putBox(52,53,0,1,140,141); // corner_esquerdo_inferior
  Barrettao.putBox(94,95,0,1,140,141); // corner_direito_inferior

  //REFLETORES
  Barrettao.setColor(0.4,0.4,0.4,0.4);// cinza_mais_escuro
  Barrettao.putBox(150,151,1,50,50,51);// primeiro_refletor
  Barrettao.putBox(150,151,40,50,48,53);// primeiro_refletor
  Barrettao.putBox(150,151,1,50,72,73);// segundo_refletor
  Barrettao.putBox(150,151,40,50,70,75);// segundo_refletor
  Barrettao.putBox(150,151,1,50,96,97);// terceiro_refletor
  Barrettao.putBox(150,151,40,50,94,99);// terceiro_refletor
  Barrettao.putBox(150,151,1,50,118,119);// quarto_refletor
  Barrettao.putBox(150,151,40,50,116,121);// quarto_refletor
  Barrettao.putBox(150,151,1,50,140,141);// quinto_refletor
  Barrettao.putBox(150,151,40,50,138,143);// quinto_refletor

  //BANCO_DE_RESERVAS
  Barrettao.setColor(1.0,0.0,0.0,0.5); // cor_vermelho
  Barrettao.putBox(101,102,1,3,48,59); // banco_de_reserva_superior
  Barrettao.putBox(100,101,1,2,48,59); // banco_de_reserva_superior
  Barrettao.putBox(101,102,1,3,133,144); // banco_de_reserva_inferior
  Barrettao.putBox(100,101,1,2,133,144); // banco_de_reserva_inferior
  Barrettao.setColor(0.8,0.8,0.8,0.8);// cor_cinza_claro
  Barrettao.putBox(100,102,4,5,48,59); // cobertura_do_banco_de_reserva_superior
  Barrettao.putBox(100,102,4,5,133,144); // cobertura_do_banco_de_reserva_inferior
  Barrettao.putBox(98,99,1,2,48,59); // banco_de_reserva_superior
  Barrettao.putBox(98,99,1,2,133,144); // banco_de_reserva_inferior
  
  Barrettao.writeOFF((char*)"estadiobarrettao.off");


}
