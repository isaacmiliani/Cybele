#include "helper.h"
#include <QString>
#include <QDebug>
#include <assimp/Importer.hpp>
#include <assimp/Exporter.hpp>
#include <Assimp/postprocess.h>


helper::helper()
{

}

bool helper::Import3DFromFile( const std::string& pFile)
{

    Assimp::Importer importer;
    const aiScene* scene;
    float scaleFactor;
    //check if file exists
    std::ifstream fin(pFile.c_str());
    if(!fin.fail()) {
        fin.close();
    }
    else{
        printf("Couldn't open file: %s\n", pFile.c_str());
        printf("%s\n", importer.GetErrorString());
        return false;
    }

    scene = importer.ReadFile( pFile, aiProcessPreset_TargetRealtime_Quality);

    // If the import failed, report it
    if( !scene)
    {
        printf("%s\n", importer.GetErrorString());
        return false;
    }

    // Now we can access the file's contents.
    printf("Import of scene %s succeeded.",pFile.c_str());

    aiVector3D scene_min, scene_max, scene_center;
    float tmp;
    tmp = scene_max.x-scene_min.x;
    tmp = scene_max.y - scene_min.y > tmp?scene_max.y - scene_min.y:tmp;
    tmp = scene_max.z - scene_min.z > tmp?scene_max.z - scene_min.z:tmp;
    scaleFactor = 1.f / tmp;


    QString fileFormat, fileName;
    fileFormat = "off";
    fileName = "Test215.off";
    this->Export(scene,fileFormat.toStdString(),fileName.toStdString());

    // We're done. Everything will be cleaned up by the importer destructor
    return true;
}
bool helper::Export(const aiScene* scene, const std::string fileFormat, const std::string fileName){
    Assimp::Exporter *exporter = new Assimp::Exporter();
    const aiExportFormatDesc *exportFormatDesc = new aiExportFormatDesc();
    // qDebug() << "GetExportFormatCount :" << exporter->GetExportFormatCount();
    exportFormatDesc = exporter->GetExportFormatDescription(1);
    qDebug() << "export format description:" << exportFormatDesc->description << exportFormatDesc->fileExtension ;
    std::string c = fileName + exportFormatDesc->fileExtension;
    //strcat(fileName,exportFormatDesc->fileExtension);

    bool hr = exporter->Export(scene,"off",fileName);
    return hr;
}

