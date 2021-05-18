#ifndef LEITOR_OBJ_HPP
#define LEITOR_OBJ_HPP

#include <iostream>
#include <fstream>
#include <limits>

#include <string>
#include <vector>
#include <map>

#include <Vec_3.hpp>
#include <Vec_2.hpp>

struct Face {
    union {
        int vertices[6];
        struct {
            int v1; int n1;
            int v2; int n2;
            int v3; int n3;
        };
    };
};

struct Triangulo {
    union {
        int vertices[3];
        struct { int v1; int v2; int v3; };
    };
};

struct Dado {
    lito::Vec_3f ponto;
    lito::Vec_3f normal;
};

class Obj {
public:
    std::vector<Dado> dados;
    std::vector<Triangulo> faces;

    Obj ()
    {}

    Obj (std::vector<Dado> dados, std::vector<Triangulo> faces)
    : dados(dados)
    , faces(faces)
    {}
};

class Face_Id {
public:
    int id_ponto;
    int id_normal;
};

std::vector<Obj> ler_obj (std::string nome_obj);
std::string nome_objeto (std::ifstream &obj);
lito::Vec_3f ler_vetor_3p (std::ifstream &obj);
lito::Vec_2f ler_vetor_2p (std::ifstream &obj);
Face ler_face (std::ifstream &obj);
Obj gerar_objeto (std::vector<lito::Vec_3f> &pontos, std::vector<lito::Vec_3f> &normais, std::vector<Face> &faces);

#endif