#include "DocumentManager.h"

void DocumentManager::addPatron(int patronID){
    patrons.insert(patronID);
}

int DocumentManager::search(std::string name){
    if (name_to_docid.count(name) > 0){
        return name_to_docid[name];
    }
    return 0;
}

void DocumentManager::addDocument(string name, int id, int license_limit){
    return;
}

bool DocumentManager::borrowDocument(int docid, int patronID){
    return true;
}

void DocumentManager:: returnDocument(int docid, int patronID){
    return;
}