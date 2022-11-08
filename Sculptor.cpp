#include "Sculptor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz){
nx = _nx; ny = _ny; nz = _nz;
r = 1; g= 1; b = 1;

v = new Voxel**[nx]; // alocação_dinamica_da_matriz_em_3d
for (int i =0; i<nx; i++){ // "
v[i] = new Voxel*[ny]; // "
for (int j =0; j<ny; j++){ // "
v[i][j]= new Voxel[nz]; // "
}
}
}

Sculptor::~Sculptor(){
for(int i = 0; i < nx; i++){
for (int j = 0; j < ny; j++){
delete[] v[i][j];
}
}
for (int i=0; i <nx; i++){
delete[] v[i];
}

delete[] v;
    // resetando_coordenadas
nx = 0; ny = 0; nz = 0;
}

void Sculptor::setColor(float r, float g, float b, float alpha){
	// usuário_define_as_propriedades_do_voxel
Sculptor::r = r; Sculptor::g = g; Sculptor::b = b; Sculptor::a = alpha;
}

void Sculptor::putVoxel(int x, int y, int z){
// insere_um_voxel
v[x][y][z].show = true; 
// repassa_cor_e_transparencia_do_voxel
v[x][y][z].r = r; v[x][y][z].g = g; v[x][y][z].b = b; v[x][y][z].a = a;    

}

void Sculptor::cutVoxel(int x, int y, int z){
v[x][y][z].show = false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    // define_uma_sequencia_de_voxel
for(int x = x0; x<x1; x++){
for (int y = y0; y<y1; y++){
for (int z = z0; z<z1; z++){
 v[x][y][z].show=true;
    v[x][y][z].r = r;
      v[x][y][z].g = g;
        v[x][y][z].b = b;
          v[x][y][z].a = a;
}
 }
  }  
   }

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
  	
	// desativa_uma_sequencia_de_voxel
  for(int x = x0; x<x1; x++){
    for (int y = y0; y<y1; y++){
      for (int z = z0; z<z1; z++){
        v[x][y][z].show = false;
  }
   }
    }  
     }

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
// recebe_as_coordenadas_e_o_raio_da_esfera
	
  int i, j, k;
  
for( i = -radius; i<=radius; i++){ // pecorre_o_diametro
for(j = -radius; j<=radius; j++){
for(k = -radius; k<=radius; k++){
         
if ((i*i+j*j+k*k) < radius*radius){ // condicaho_da_esfera
putVoxel(i+xcenter,j+ycenter,k+zcenter); //adiciona_um_voxel
    }
   }
  }
 }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
// recebe_as_coordenadas_e_o_raio_da_esfera_e_desativa
// desativa_a_esfera
  int i, j, k;
	
for(i = -radius; i<radius; i++){
for(j = -radius; j<radius; j++){
for(k = -radius; k<radius; k++){
if((i*i+j*j+k*k) < radius*radius){
cutVoxel(i+xcenter,j+ycenter,k+zcenter);
    }
   }
  }
 }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
  // projeta_uma_elipsoide
   //recebe_as_coordenadas_das_dimensões_e_coordenadas_do_centro
   float newx, newy, newz;
   int x, y, z;

for ( x = 0; x < nx; x++){
for ( y = 0; y < ny; y++){
for ( z = 0; z < nz; z++){
newx = ((float)(x-xcenter)*(float)(x-xcenter))/(rx * rx);
newy = ((float)(y-ycenter)*(float)(y-ycenter))/(ry * ry);
newz = ((float)(z-zcenter)*(float)(z-zcenter))/(rz * rz);
// calculo_da_condicaho_de_existencia_da_elipsoid
if ((newx + newy + newz) < 1){
putVoxel(x,y,z);
    }
   }
  }
 }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
// desativa_a_elipsoid
   
double newx, newy, newz;
int x, y, z;
   
for ( x = 0; x < nx; x++){
for ( y = 0; y < ny; y++){
for ( z = 0; z < nz; z++){
newx = ((float)(x-xcenter)*(float)(x-xcenter))/(rx * rx);
newy = ((float)(y-ycenter)*(float)(y-ycenter))/(ry * ry);
newz = ((float)(z-zcenter)*(float)(z-zcenter))/(rz * rz);

if ((newx + newy + newz) < 1){ 
cutVoxel(x,y,z);
    }
   }
  }
 }
}

void Sculptor::writeOFF(const char *filename){
    int qtd_Voxel = 0;
    int ref;
    int  i, j, k, a, b, c; // variaveis_auxiliares
    float fix = 0.5;
    std::ofstream endArq;
    endArq.open(filename);
    if (endArq.is_open()){
        endArq<<"OFF\n"; // define_off_na_primeira_linha

        // percorre_todas_as_dimensoes_verificando_os_voxel_em_exibiçao
for (i = 0; i < nx; i++){
for (j = 0; j <ny; j++){
for (k = 0; k <nz; k++){
if(v[i][j][k].show == true){
qtd_Voxel++; // guarda_a_quantidade_de_voxel_ativos
   }
  }
 }
}
        endArq<<qtd_Voxel * 8<<" "<<qtd_Voxel * 6 << " " << "0" << "\n"; 
        // exibe_a_quantidade_total_de_vertices,_faces_e_arestas

        // pecorre_as_posições_a,_b,_c_e_exibe_as_coordenadas_do_voxel
        // no_primeiro_voxel_o_fix_será_o_valor_de_referencia
        for (a = 0; a < nx; a++){
            for (b = 0; b < ny; b++){
                for (c = 0; c < nz; c++){
                    if(v[a][b][c].show == true){
                        endArq << a - fix << " " << b + fix << " " << c - fix << "\n" << flush;
                        endArq << a - fix << " " << b - fix << " " << c - fix << "\n" << flush;
                        endArq << a + fix << " " << b - fix << " " << c - fix << "\n" << flush;
                        endArq << a + fix << " " << b + fix << " " << c - fix << "\n" << flush;
                        endArq << a - fix << " " << b + fix << " " << c + fix << "\n" << flush;
                        endArq << a - fix << " " << b - fix << " " << c + fix << "\n" << flush;
                        endArq << a + fix << " " << b - fix << " " << c + fix << "\n" << flush;
                        endArq << a + fix << " " << b + fix << " " << c + fix << "\n" << flush;
                    }
                }
            }
        }

        qtd_Voxel = 0; // reseta_a_quantidade_de_voxel

        // percorre_todas_as_dimensoes
        // verifica_o_voxel_ativo_e_exibe_as_linhas_com_numeros_de_faces_e_as_combinacoes_que_exibem_a_face
for (a= 0; a<nx; a++){
for (b = 0; b<ny; b++){
for (c= 0; c<nz; c++){
if(v[a][b][c].show == true){
ref = qtd_Voxel * 8;
endArq << fixed;

                    // construir_linha_que_monta_as_faces_a_partir_do_vertices:
                    // valores_exemplos_do_site_quando_ref_igual_a_0:
                    endArq << "4" << " " << 0+ref << " " << 3+ref << " " << 2+ref << " " << 1+ref << " ";
                    // propriedades_do_voxel:
                    endArq << setprecision(2)<<v[a][b][c].r << " " << setprecision(2)<<v[a][b][c].g <<" " << setprecision(2)<<v[a][b][c].b << " " << setprecision(2) << v[a][b][c].a << "\n";

                    endArq << "4" << " " << 4+ref << " " << 5+ref << " " << 6+ref << " " << 7+ref << " ";
                    endArq << setprecision(2)<<v[a][b][c].r << " " << setprecision(2)<<v[a][b][c].g <<" " << setprecision(2)<<v[a][b][c].b << " " << setprecision(2) << v[a][b][c].a << "\n";

                    endArq << "4" << " " << 0+ref << " " << 1+ref << " " << 5+ref << " " << 4+ref << " ";
                    endArq << setprecision(2)<<v[a][b][c].r << " " << setprecision(2)<<v[a][b][c].g <<" " << setprecision(2)<<v[a][b][c].b << " " << setprecision(2) << v[a][b][c].a << "\n";

                    endArq << "4" << " " << 0+ref << " " << 4+ref << " " << 7+ref << " " << 3+ref << " ";
                    endArq << setprecision(2)<<v[a][b][c].r << " " << setprecision(2)<<v[a][b][c].g <<" " << setprecision(2)<<v[a][b][c].b << " " << setprecision(2) << v[a][b][c].a << "\n";

                    endArq << "4" << " " << 3+ref << " " << 7+ref << " " << 6+ref << " " << 2+ref << " ";
                    endArq << setprecision(2)<<v[a][b][c].r << " " << setprecision(2)<<v[a][b][c].g <<" " << setprecision(2)<<v[a][b][c].b << " " << setprecision(2) << v[a][b][c].a << "\n";

                    endArq << "4" << " " << 1+ref << " " << 2+ref << " " << 6+ref << " " << 5+ref << " ";
                    endArq << setprecision(2)<<v[a][b][c].r << " " << setprecision(2)<<v[a][b][c].g <<" " << setprecision(2)<<v[a][b][c].b << " " << setprecision(2) << v[a][b][c].a << "\n";

                    qtd_Voxel++; // incrementa_a_quantidade_de_voxels
                    }
                }
            }
        }
    }
    else{
    cout << "Erro ao abrir arquivo de texto."; 
    }
    
    endArq.close();
}
