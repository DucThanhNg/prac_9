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

bool DocumentManager::borrowDocument(int docid, int patronID){
    return false;
}