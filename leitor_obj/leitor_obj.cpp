#include "leitor_obj.hpp"

std::vector<Obj> ler_obj (std::string nome_obj)
{
    std::ifstream obj(nome_obj);
    std::vector<Obj> retorno;
    char lido[2];

    std::vector<lito::Vec_3f> pontos;
    std::vector<lito::Vec_3f> normais;
    std::vector<Face> faces;

    if (!obj.is_open()) {
        std::cerr << "Arquivo " << nome_obj << " não encontrado!!! :(" << std::endl;
        return retorno;
    }

    while (!obj.eof())
    {
        obj.read(lido, 2);
        switch (lido[0]) {
            case 'o':
                if (lido[1] == ' ') {
                    nome_objeto(obj);

                    if ( pontos.size() == 0
                    &&   normais.size() == 0
                    &&   faces.size() == 0 )
                        retorno.push_back( gerar_objeto(pontos, normais, faces) );
                    
                    pontos.clear();
                    normais.clear();
                    faces.clear();
                }
            case 'v':
                if (lido[1] == ' ')
                    ler_vetor_3p(obj);
                else if (lido[1] == 'n')
                    ler_vetor_3p(obj);
                else if (lido[1] == 't')
                    ler_vetor_2p(obj);
                break;
            case 'f':
                if (lido[1] == ' ')
                    ler_face(obj);
                break;
            default:
                obj.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    
    obj.close();
    return retorno;
}

/*===============================================================================================================================*/

std::string nome_objeto (std::ifstream &obj)
{
    std::string nome;
    std::getline(obj, nome);

    return nome;
}

/*===============================================================================================================================*/

lito::Vec_3f ler_vetor_3p (std::ifstream &obj)
{
    std::string linha;
    float p[3];
    size_t id_inicio_substring = 0;
    size_t id_inicio_proxima_sumstring = 0;

    std::getline(obj, linha);
    for (int i = 0; i < 3; i++) {
        p[i] = float(std::stof(linha.substr(id_inicio_substring) , &id_inicio_proxima_sumstring));
        id_inicio_substring += id_inicio_proxima_sumstring;
    }

    return lito::Vec_3f(p[0], p[1], p[2]);
}

/*===============================================================================================================================*/

lito::Vec_2f ler_vetor_2p (std::ifstream &obj)
{
    std::string linha;
    float p[2];
    size_t id_inicio_substring = 0;
    size_t id_inicio_proxima_sumstring = 0;

    std::getline(obj, linha);
    for (int i = 0; i < 2; i++) {
        p[i] = float(std::stof(linha.substr(id_inicio_substring) , &id_inicio_proxima_sumstring));
        id_inicio_substring += id_inicio_proxima_sumstring;
    }

    return lito::Vec_2f(p[0], p[1]);
}

/*===============================================================================================================================*/

Face ler_face (std::ifstream &obj)
{
    Face retorno;
    std::string linha;
    int ids[6];
    size_t id_inicio_substring = 0;
    size_t id_inicio_proxima_sumstring = 0;

    std::getline(obj, linha);
    for (auto& c : linha) {
        if (c == '/')
            c = ' ';
    }

    for (int i = 0; i < 6; i++) {
        ids[i] = std::stoi( linha.substr(id_inicio_substring), &id_inicio_proxima_sumstring);
        id_inicio_substring += id_inicio_proxima_sumstring;
    }

    memcpy(retorno.vertices, ids, sizeof(int) * 6);

    return retorno;
}

/*===============================================================================================================================*/

Obj gerar_objeto (std::vector<lito::Vec_3f> &pontos, std::vector<lito::Vec_3f> &normais, std::vector<Face> &faces)
{
    std::map<Face_Id, int> func_faces;
    Obj retorno;

    return retorno;
}

/*===============================================================================================================================*/
