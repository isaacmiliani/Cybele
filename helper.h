#ifndef HELPER_H
#define HELPER_H
#include <fstream>
#include <Assimp/scene.h>
using namespace std;

class helper
{
public:
    helper();
    // Credits -> http://www.lighthouse3d.com/cg-topics/code-samples/importing-3d-models-with-assimp/
    bool Import3DFromFile( const std::string& pFile);
    bool Export(const aiScene* scene, const std::string fileFormat, const std::string fileName);
};

#endif // HELPER_H
